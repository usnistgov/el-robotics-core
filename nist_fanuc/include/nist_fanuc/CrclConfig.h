// Config.h

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

#ifdef _WIN32
#include <SDKDDKVer.h>
#define BOOST_ALL_NO_LIB
#define _CRT_SECURE_NO_WARNINGS    1

// _WINSOCKAPI_ /* Prevent inclusion of winsock.h in windows.h */
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <tchar.h>

#pragma warning ( disable : 4996 ) // 'sprintf': This function or variable may be unsafe. Consider using sprintf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
#pragma warning(disable: 4800)     // warning C4800: forcing value to bool 'true' or 'false' (performance warning)
#pragma warning(disable: 4018)     // warning C4018: '<' : signed/unsigned mismatch
#pragma warning(disable: 4244)     // warning C4244: 'argument' : conversion from 'double' to 'LPARAM', possible loss of data
#pragma warning(disable: 4267)     // warning C4244: 'argument' : conversion from 'double' to 'LPARAM', possible loss of data
#pragma warning(disable: 4312)     // warning C4244: conversion from 'OPCHANDLE' to 'OPCItem *' of greater size
#pragma warning(disable: 4800)     // warning C4800: forcing value to bool 'true' or 'false' (performance warning)
#pragma warning(disable: 4018)     // warning C4018: '<' : signed/unsigned mismatch
#pragma warning(disable: 4996)
#pragma warning(disable: 4311)
#pragma warning(disable: 4996)
#pragma warning(disable: 4541)
#pragma warning(disable: 4996)

#endif
