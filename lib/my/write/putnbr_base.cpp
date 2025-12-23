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
##  @file putnbr_base.cpp

File Description:
##  Convert the given number in the given base
\**************************************************************/

#include "string.hpp"
#include "write.hpp"
#include "error.hpp"
#include <stddef.h>

int putnbr_base(int fd, size_t nbr, char const *str_base)
{
    int base = 0;
    int res = OK;

    if (!str_base)
        return err_prog(PTR_ERR, KO, ERR_INFO);
    base = strlen(str_base);
    if (base < 0)
        return err_prog(UNDEF_ERR, KO, ERR_INFO);
    if (base <= 1)
        return err_prog(ARGV_ERR, KO, ERR_INFO);
    for (int i = 0; nbr >= 1; i++) {
        res += putchar(fd, str_base[nbr % base]);
        nbr /= base;
    }
    if (res != OK)
        return err_prog(UNDEF_ERR, KO, ERR_INFO);
    return OK;
}
