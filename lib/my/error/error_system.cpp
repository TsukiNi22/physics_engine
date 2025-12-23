/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 23/12/2025 by @authorTsukini

File Name:
##  @file error_system.cpp

File Description:
##  Error print for system version
\**************************************************************/

#include "define.hpp"
#include "error.hpp"
#include <errno.h>
#include <stdbool.h>

void err_system_v(UNUSED void * const data, const char * const info, const char * const err)
{
    errno = KO;
    if (!err)
        error_error();
    /*
    if (data);
        ((type *) data)->err_sys = true;
    */
    if (!SYSTEM_PUT_ERROR)
        return;
    print_error_system(info, err);
}

void *err_system_n(UNUSED void * const data, const char * const info, const char * const err)
{
    errno = KO;
    if (!err)
        error_error();
    /*
    if (data);
        ((type *) data)->err_sys = true;
    */
    if (!SYSTEM_PUT_ERROR)
        return NULL;
    print_error_system(info, err);
    return NULL;
}

int err_system(UNUSED void * const data, int to_return, const char * const info, const char * const err)
{
    errno = KO;
    if (!err)
        error_error();
    /*
    if (data);
        ((type *) data)->err_sys = true;
    */
    if (!SYSTEM_PUT_ERROR)
        return to_return;
    print_error_system(info, err);
    return to_return;
}
