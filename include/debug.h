#ifndef __DEBUG_MACRO_H__
#define __DEBUG_MACRO_H__
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "./colors.h"
#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) std::cerr << RED << "[Error in " << __FILE__  << " in " << __PRETTY_FUNCTION__ << " @L:" << __LINE__ << "]   " << M << std::endl << RST;
#endif
#define log_err(M, ...) std::cerr << RED << "[Error in " << __FILE__  << " in " << __PRETTY_FUNCTION__ << " @L:" << __LINE__ << "]   " << M << std::endl << RST;
#define log_warn(M, ...) std::cerr << YEL << "[WARN in " << __FILE__  << " in " << __PRETTY_FUNCTION__ << " @L:" << __LINE__ << "]   " << M << std::endl << RST;
#define log_info(M, ...) std::cerr << BLU << "[INFO in " << __FILE__  << " in " << __PRETTY_FUNCTION__ << " @L:" << __LINE__ << "]   " << M << std::endl << RST;
#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }
#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0; goto error; }
#define check_mem(A) check((A), "Out of memory. Perhaps Memory allocation failed")
#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }
#endif // __DEBUG_MACRO_H__
