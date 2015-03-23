#ifndef NIST_CORE_H_
#define NIST_CORE_H_

#ifdef WIN32

#ifdef LIBRARY_IMPORTS
#define LIBRARY_API __declspec(dllimport)
#else
#define LIBRARY_API __declspec(dllexport)
#endif

#define snprintf sprintf_s

#else

#define LIBRARY_API

#endif

/*! Returns 0 if the NIST core functions were able to be initialized,
  non-zero if not. */
extern int nist_core_init(void);

#endif	/* NIST_CORE_H_ */

