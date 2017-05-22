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
#include <stdarg.h>
#include <time.h>

#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <sstream>
#include <assert.h>
#include <sys/time.h>

#include <thread>
#include <chrono>
#include <QString>
#include "RobotDefinition.h"

enum {
    DEBUG_NONE = 0x00,
    DEBUG_REPLY = 0x01,
    DEBUG_STATE = 0x02,
    DEBUG_FEEDBACK = 0x04,
    DEBUG_RUN = 0x08,
    DEBUG_ALL = 0xFF
};


#ifndef TODO
#define DO_PRAGMA(x) _Pragma (#x)
#define TODO(x) DO_PRAGMA(message ("TODO - " #x))
#endif      

/** \def TOOLS_DEPRECATED
    Macro that marks functions as deprecated -from ROS */

#ifdef __GNUC__
#define TOOLS_DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER)
#define TOOLS_DEPRECATED __declspec(deprecated)
#elif defined(__clang__)
#define TOOLS_DEPRECATED __attribute__((deprecated("Use of this method is deprecated")))
#else
#define TOOLS_DEPRECATED /* Nothing */
#endif

#ifndef Deg2Rad
#define Deg2Rad(Ang)    ( (double) ( Ang * M_PI / 180.0 ) )
#define Rad2Deg(Ang)    ( (double) ( Ang * 180.0 / M_PI ) )
#define MM2Meter(d)     ( (double) ( d / 1000.00 ) )
#define Meter2MM(d)     ( (double) ( d * 1000.00 ) )
#endif

#if defined DEBUG
#define IfDebug(arg)    arg
#else
#define IfDebug(arg)
#endif

#ifdef WIN32
#ifndef strncasecmp
#define strncasecmp(x, y, z)    _strnicmp(x, y, z)
#endif
#else
#define _strnicmp strncasecmp
#define S_OK 0
#define E_FAIL -1
#endif


// Adapter from  IKFAST
#ifndef NC_ASSERT
#include <stdexcept>
#include <sstream>
#include <iostream>
#ifndef __PRETTY_FUNCTION__
#define __PRETTY_FUNCTION__ __func__
#endif
#define NC_ASSERT(b) { if( !(b) ) { std::stringstream ss; ss << "nc exception: " << __FILE__ << ":" << __LINE__ << ": " <<__PRETTY_FUNCTION__ << ": Assertion '" << #b << "' failed"; throw std::runtime_error(ss.str()); } }
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

#define VARREF(X, Y)    \
    protected: Y &_ ## X; \
    public: Y & X( ) { return _ ## X; }

#define RVAR(X, Y)    \
    protected: Y _ ## X; \
    public: Y  X( ) { return _ ## X; }

#define RWVAR(X, Y)    \
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
 * \brief gives a random from 0 to 1
 * \return double
 */
inline double Random() {
    return ((double) rand() / (RAND_MAX));
}

inline int OneZero() {
    return ((double) rand() / (RAND_MAX));
}

/**
 * \brief gives a random between min and max
 * \param min minimum number as double
 * \param max maximum number as double
 * \return number as double between min and max
 */
inline double Random(double min, double max) {
    return min + Random() * (max - min); //gives a random from 0 to max ) +min
}

/**
 * \brief gives a random between min and max
 * \param min minimum number as integer
 * \param max maximum number as integer
 * \return number as integer between min and max
 */
inline int Random(int min, int max) {
    return min + (rand() % (max - min)); //gives a random from 0 to max ) +min
}

/**
 * \brief CGlobals is a catch-all data structure for collecting global functions, extensions, parameters, etc.
 *  Functions here usually vary between windows and linux, or
 * there is no easy mechanism in C++ to extend classes (e.g., string) like in C#
 */
class CGlobals {
public:

    enum TimeFormat {
        HUM_READ,
        GMT,
        GMT_UV_SEC,
        LOCAL
    };
    /*!
     * \brief Constructor for globals function. Functions here usually vary between windows and linux, or
     * there is no easy mechanism in C++ to extend classes (e.g., string) like in C#.
     */
    CGlobals(){
        srand((unsigned int) time(NULL)); //activates the simple randome number generator
        bQuitting=false;
        bHexdump=false;
        bQDebug=false;
        index=-1;
    }
    ~CGlobals(){}

    /*!
     * \brief StrFormat  accepts a traditional C format string and expects parameter to follow on calling stack and will
     * produce a string from it.
     * \param fmt is the C format string.
     */
    std::string StrFormat(const char *fmt, ...) {
        va_list argptr;
        va_start(argptr, fmt);
        int m;
        int n = (int) strlen(fmt) + 1028;
        std::string tmp(n, '0');
        while ((m = vsnprintf(&tmp[0], n - 1, fmt, argptr)) < 0) {
            n = n + 1028;
            tmp.resize(n, '0');
        }
        va_end(argptr);
        return tmp.substr(0, m);
    }

    /*!
     * \brief sleep milliseconds. Equivalent to Sleep in windows.
     * \param ms number of milliseconds to sleep
     */
    void Sleep(unsigned int ms) {
        //boost::this_thread::sleep(boost::posix_time::milliseconds(ms));
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }
    /*!
     * \brief Reads a file all at once into a string. Include file open, read, close. If fails, empty string is only diagnostic.
     * \param filename is the name of the file to read from
     * \param contents is a reference to a string in which to store file contents.
     */
    bool ReadFile(std::string filename, std::string & contents){
        std::ifstream     in(filename.c_str( ) );
        std::stringstream buffer;

        buffer << in.rdbuf( );
        contents = buffer.str( );
        return true;
    }

    /*!
     * \brief Writes entire string contents to a file all at once. Include file open, write, close.
     * No error messages.
     * \param filename is the name of the file to write to
     * \param contents is a reference to a string in which to write string.
     */
    void WriteFile(std::string filename, std::string & contents)
    {
        std::ofstream outFile(filename.c_str( ) );

        outFile << contents.c_str( );
    }
    /*!
     * \brief Appends entire string contents to a file all at once. Include file open, write, close.
     * No error messages.
     * \param filename is the name of the file to write to
     * \param contents is a reference to a string in which to write string.
     */
    void AppendFile(std::string filename, std::string contents)
    {
        std::ofstream outFile;

        outFile.open(filename.c_str( ), std::ofstream::out | std::ofstream::app);
        outFile << contents.c_str( );
    }
    std::string  LeftTrim (std::string  str)
    {
        size_t startpos = str.find_first_not_of(" \t\r\n");

        if ( std::string::npos != startpos )
        {
            str = str.substr(startpos);
        }
        return str;
    }
    // trim from end
    std::string  RightTrim (std::string  str, std::string trim = " \t\r\n")
    {
        size_t endpos = str.find_last_not_of(trim);

        if ( std::string::npos != endpos )
        {
            str = str.substr(0, endpos + 1);
        }
        return str;
    }
    /*!
     * \brief Trim cleans blank characters from the front and back of a string.
     * Blank chars are white space, tab, carriage return.
     * \param str is the string to trim. Will trim a copy.
     * \return a new trimmed string
     */
    std::string Trim(std::string s)
    {
        return LeftTrim(RightTrim(s) );
    }

    /*!
     * \brief GetTimeStamp returns a timestamp string depending on the input format.
     * \param  format is one of an enumeration describing how to format timestamp.
     * \return a formated timestamp string.
     */
    std::string GetTimeStamp(TimeFormat format = GMT_UV_SEC)
    {
        char            timeBuffer[50];
        struct tm *     timeinfo;
        struct timeval  tv;
        struct timezone tz;

        gettimeofday(&tv, &tz);
        timeinfo = ( format == LOCAL ) ? localtime(&tv.tv_sec) : gmtime(&tv.tv_sec);

        switch ( format )
        {
        case HUM_READ:
        {
            strftime(timeBuffer, 50, "%a, %d %b %Y %H:%M:%S %Z", timeinfo);
        }
            break;

        case GMT:
        {
            strftime(timeBuffer, 50, "%Y-%m-%dT%H:%M:%SZ", timeinfo);
        }
            break;

        case GMT_UV_SEC:
        {
            strftime(timeBuffer, 50, "%Y-%m-%dT%H:%M:%S", timeinfo);
        }
            break;

        case LOCAL:
        {
            strftime(timeBuffer, 50, "%Y-%m-%dT%H:%M:%S%z", timeinfo);
        }
            break;
        }

        //    if ( format == GMT_UV_SEC )
        //    {
        //        sprintf(timeBuffer + strlen(timeBuffer), ".%06dZ", tv.tv_usec);
        //    }

        return std::string(timeBuffer);

    }
#if 0
    bool SetEnvironmentFromMap(std::map<std::string, std::string> envmap){
        std::map<std::string, std::string>::iterator it;
        for(it=envmap.begin(); it!=envmap.end(); it++)
            setenv((*it).first.c_str(), (*it).second.c_str(), true);
        return true;
    }
#endif
    std::string ExecuteShellCommand(std::string command) {
        std::string result;
        FILE *fpipe;
        char line[512];
        if (!(fpipe = (FILE*) popen((char *) command.c_str(), "r"))) {
            // If fpipe is NULL
            std::cerr << "Problems with pipe";
            return result;
        }
        while (fgets(line, sizeof line, fpipe)) {
            result += line; // does it have line feed at end?
        }
        pclose(fpipe);
        return result;
    }
    // big endian store the most significant byte of a word at a lower byte address than the least significant byte 01020304
    // little endian store the most least byte of a word at a lower byte address than the most significant byte 04030201
    int is_big_endian(void)
    {
        union {
            uint32_t i;
            char c[4];
        } bint = {0x01020304};

        return bint.c[0] == 1;
    }
    template<typename T>
    inline std::string VectorDump(std::vector<T> v) {
        std::stringstream s;

        for (size_t i = 0; i < v.size(); i++) {
            s << v[i] << ":";
        }
        return s.str();
    }
    // -----------------------------------------
    // Application specifie parameters
    std::map< std::string, std::string> _appproperties; /**<map of application properties, e.g., ["prop"]="value" */
    std::string ExeDirectory; /**< the path to directory where exe is located  */
    std::string inifile; /**< inifile path name  */
 //   std::string SocketPort; /**< socket port to listen for Crcl clients  */
    int max_joints;
    std::vector<RobotDef> robots;
    std::string robot;
    bool bQuitting;
    int index;
    bool bHexdump;
    bool bQDebug;
    bool bDebug;
    bool bDebugMask;
 //   QString ip;
};
extern CGlobals Globals; /**< global definition of globals  */
/**< global definition of windows DebugBreak equivalent.  */
inline void DebugBreak() {
    assert(0);
} 



