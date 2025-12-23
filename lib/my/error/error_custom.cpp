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
##  @file error_custom.cpp

File Description:
##  Error print for custom version
\**************************************************************/

#include "define.hpp"
#include "error.hpp"
#include <errno.h>
#include <stdbool.h>

void err_custom_v(const char * const info, const err_t err)
{
    errno = KO;
    if (!info)
        error_error();
    if (!CUSTOM_PUT_ERROR || !info)
        return;
    print_error_custom(info, err);
}

void *err_custom_n(const char * const info, const err_t err)
{
    errno = KO;
    if (!info)
        error_error();
    if (!CUSTOM_PUT_ERROR || !info)
        return NULL;
    print_error_custom(info, err);
    return NULL;
}

int err_custom(const char * const info, const int to_return, const err_t err)
{
    errno = KO;
    if (!info)
        error_error();
    if (!CUSTOM_PUT_ERROR || !info)
        return to_return;
    print_error_custom(info, err);
    return to_return;
}
