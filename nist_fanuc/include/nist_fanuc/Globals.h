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

class CGlobals
{
public:
    std::map< std::string, std::string> _appproperties;
    enum TimeFormat
    {
        HUM_READ,
        GMT,
        GMT_UV_SEC,
        LOCAL
    };

    CGlobals( )
        : Debug(Logger.DebugLevel( ) ) // ,        DbgConsole(GLogger.OutputConsole())
    {
        ServerRate          = 2000;
 //       Logger.Timestamp( ) = true;
        Debug       = 0;
        QueryServer = 10000;
        SocketPort  = "64444";
    }

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

    void Dump ( )
    {
        std::stringstream sstr;

        sstr << "Globals SocketPort " << SocketPort << std::endl;
        sstr << "Globals Debug " << Debug << std::endl;
        sstr << "Globals QueryServer " << QueryServer << std::endl;
        sstr << "Globals ServerRate " << ServerRate << std::endl;
        sstr << "Globals Inifile " << inifile << std::endl;
        sstr << "Globals ExeDirectory " << ExeDirectory << std::endl;
        Logger.Fatal(sstr.str( ).c_str( ) );
    }

    void Sleep (unsigned int ms)
    {
        boost::this_thread::sleep(boost::posix_time::milliseconds(ms) );
    }

    bool          ReadFile (std::string filename, std::string & contents);
    void          WriteFile (std::string filename, std::string & contents);
    void          AppendFile (std::string filename, std::string  contents);
    std::string   Trim (std::string  s);
    unsigned int  DebugMessage (std::string errmsg);
    unsigned int  ErrorMessage (std::string errmsg);
    unsigned int  DebugStrFormat (const char *fmt, ...);
//	std::string GetUserDomain();
//	std::string GetUserName();
    std::string   GetTimeStamp (TimeFormat format = GMT_UV_SEC);

    // -----------------------------------------
    int &       Debug;
    int         QueryServer;
    int         ServerRate;
    std::string ExeDirectory;
    std::string inifile;
    std::string SocketPort;
};
extern  CGlobals Globals;
extern   void          DebugBreak( );

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
