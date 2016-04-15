// Globals.h

/*
* DISCLAIMER:
* This software was produced by the National Institute of Standards
* and Technology (NIST), an agency of the U.S. government, and by statute is
* not subject to copyright in the United States.  Recipients of this software
* assume all responsibility associated with its operation, modification,
* maintenance, and subsequent redistribution.
*
* See NIST Administration Manual 4.09.07 b and Appendix I.
*/

#pragma once
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <boost/thread.hpp>
#include <ctime>
#include <stdarg.h>
#include <sstream>
#include <time.h>
#include "Logging.h"
extern ALogger LogFile;

// #ifdef DUMPCANON_STATUSREPLYCRCLJOINTS
// #ifdef HEAVYDEBUG
//#ifdef DEBUGJOINTSTATUSCRCLUPDATE


// #define DEBUG
#if defined DEBUG
#define IfDebug(arg)    arg
#else
#define IfDebug(arg)
#endif

#ifdef WIN32
#define strncasecmp(x, y, z)    _strnicmp(x, y, z)
#else
#define _strnicmp strncasecmp
#define S_OK 0
#define E_FAIL -1
#endif

#ifndef CLEANSTORE
#define CLEANSTORE(Y, X, Z) \
	try{ Y = X; }           \
	catch ( ... ) { Y = Z; }
#define VALIDSTORE(Y, X) \
	try{ Y = X; }        \
	catch ( ... ) { }
#endif

// Up to user to mutex these accessor functions
#ifndef VAR
#define VAR(X, Y)    \
protected: Y _ ## X; \
public: Y & X( ) { return _ ## X; }

#define NVAR(X, Y, Z) \
protected: Y Z;       \
public: Y & X( ) { return Z; }
#endif

#ifndef FOREACH
#define FOREACH(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#endif
/**
* \brief CGlobals is a catch-all data structure for collecting global functions, extensions, parameters, etc.
*  Functions here usually vary between windows and linux, or
* there is no easy mechanism in C++ to extend classes (e.g., string) like in C#
*/
class CGlobals
{
public:
	enum TimeFormat
	{
		HUM_READ,
		GMT,
		GMT_UV_SEC,
		LOCAL
	};
	/*!
	* \brief Constructor for globals function. Functions here usually vary between windows and linux, or
	* there is no easy mechanism in C++ to extend classes (e.g., string) like in C#.
	*/
	CGlobals( )
		: Debug(Logger.DebugLevel( ) ) // ,        DbgConsole(GLogger.OutputConsole())
	{
		Debug       = 0;		
		SocketPort  = "64444";
	}

	/*!
	* \brief StrFormat  accepts a traditional C format string and expects parameter to follow on calling stack and will
	* produce a string from it.
	* \param fmt is the C format string.
	*/
	std::string StrFormat (const char *fmt, ...)
	{
		va_list argptr;
		va_start(argptr, fmt);
		int m;
		int n = (int) strlen(fmt) + 1028;
		std::string tmp(n, '0');
		while ( ( m = vsnprintf(&tmp[0], n - 1, fmt, argptr) ) < 0 )
		{
			n = n + 1028;
			tmp.resize(n, '0');
		}
		va_end(argptr);
		return tmp.substr(0, m);
	}

	bool IsDebug ( )
	{
		return Debug > 3;
	}
	/*!
	* \brief dumps to std out global parameters set at runtime parameters.
	*/
	void Dump ( )
	{
		std::stringstream sstr;

		sstr << "Globals SocketPort " << SocketPort << std::endl;
		sstr << "Globals Debug " << Debug << std::endl;
		sstr << "Globals Inifile " << inifile << std::endl;
		sstr << "Globals ExeDirectory " << ExeDirectory << std::endl;
		Logger.Fatal(sstr.str( ).c_str( ) );
	}

	/*!
	* \brief sleep milliseconds. Equivalent to Sleep in windows.
	* \param ms number of milliseconds to sleep
	*/
	void Sleep (unsigned int ms)
	{
		boost::this_thread::sleep(boost::posix_time::milliseconds(ms) );
	}
	/*!
	* \brief Reads a file all at once into a string. Include file open, read, close. If fails, empty string is only diagnostic.
	* \param filename is the name of the file to read from
	* \param contents is a reference to a string in which to store file contents.
	*/
	bool          ReadFile (std::string filename, std::string & contents);

	/*!
	* \brief Writes entire string contents to a file all at once. Include file open, write, close.
	* No error messages.
	* \param filename is the name of the file to write to
	* \param contents is a reference to a string in which to write string.
	*/
	void          WriteFile (std::string filename, std::string & contents);

	/*!
	* \brief Appends entire string contents to a file all at once. Include file open, write, close.
	* No error messages.
	* \param filename is the name of the file to write to
	* \param contents is a reference to a string in which to write string.
	*/
	void          AppendFile (std::string filename, std::string  contents);

	/*!
	* \brief Trim cleans blank characters from the front and back of a string. 
	* Blank chars are white space, tab, carriage return.
	* \param str is the string to trim. Will trim a copy.
	* \return a new trimmed string 
	*/
	std::string   Trim (std::string  s);

	/*!
	* \brief Prints an diagnostic message to the debug reporting mechanism. (cout or OutputDebugString)
	* \param str errmsg is the error message that is posted to the debug reporting mechanism.
	* \return a error result integer. (e.g., E_FAIL or -1). 
	*/
	unsigned int  DebugMessage (std::string errmsg);

	/*!
	* \brief Prints an error message to the error reporting mechanism. 
	* \param str errmsg is the error message that is posted to the error reporting mechanism.
	* \return a error result integer. (e.g., E_FAIL or -1). 
	*/
	unsigned int  ErrorMessage (std::string errmsg);

	/*!
	* \brief Prints a format string and arguments as a diagnostic message to the debug reporting mechanism. (cout or OutputDebugString)
	* \param  fmt is the error format statement that uses parameters that follow and is posted to the debug reporting mechanism.
	* \return a error result integer. (e.g., E_FAIL or -1). 
	*/
	unsigned int  DebugStrFormat (const char *fmt, ...);

	/*!
	* \brief GetTimeStamp returns a timestamp string depending on the input format.
	* \param  format is one of an enumeration describing how to format timestamp.
	* \return a formated timestamp string. 
	*/
	std::string   GetTimeStamp (TimeFormat format = GMT_UV_SEC);

	// -----------------------------------------
	std::map< std::string, std::string> _appproperties; /**<map of application properties, e.g., ["prop"]="value" */
	int &       Debug;
	std::string ExeDirectory; /**< the path to directory where exe is located  */
	std::string inifile; /**< inifile path name  */
	std::string SocketPort; /**< socket port to listen for Crcl clients  */
};
extern  CGlobals Globals; /**< global definition of globals  */
extern   void          DebugBreak( ); /**< global definition of windows DebugBreak equivalent.  */

template<typename T>
inline std::string VectorDump (std::vector<T> v)
{
	std::stringstream s;

	for ( size_t i = 0; i < v.size( ); i++ )
	{
		s << v[i] << ":";
	}
	s << std::endl;
	return s.str();
}

template<typename T>
inline std::vector<T> ToVector (int n,  ...)
{
	std::vector<T> ds;
	va_list        args; // define argument list variable
	va_start(args, n);   // init list; point to last
	//   defined argument

	for ( int i = 0; i < n; i++ )
	{
		double d = va_arg(args, T); // get next argument
		ds.push_back(d);
	}
	va_end(args);   // clean up the system stack
	return ds;
}
