/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 23/12/2025 by @author Tsukini

File Name:
##  @file putstr.cpp

File Description:
##  Write a string
\**************************************************************/

#include "string.hpp"
#include "error.hpp"
#include <unistd.h>

int putstr(int fd, char const *str)
{
    int len = 0;

    if (!str)
        return err_prog(PTR_ERR, KO, ERR_INFO);
    len = strlen(str);
    if (len < 0)
        return err_prog(UNDEF_ERR, KO, ERR_INFO);
    if (write(fd, str, len) != len)
        return err_prog(WRITE_ERR, KO, ERR_INFO);
    return OK;
}
