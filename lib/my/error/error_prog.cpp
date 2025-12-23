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
##  @file error_prog.cpp

File Description:
##  Error print for prog version
\**************************************************************/

#include "define.hpp"
#include "error.hpp"
#include <errno.h>
#include <stdbool.h>

void err_prog_v(const error_code_t code, const err_t err)
{
    errno = KO;
    if (!PUT_ERROR)
        return;
    print_error_prog(code, err);
}

void *err_prog_n(const error_code_t code, const err_t err)
{
    errno = KO;
    if (!PUT_ERROR)
        return NULL;
    print_error_prog(code, err);
    return NULL;
}

int err_prog(const error_code_t code, const int to_return, const err_t err)
{
    errno = KO;
    if (!PUT_ERROR)
        return to_return;
    print_error_prog(code, err);
    return to_return;
}
