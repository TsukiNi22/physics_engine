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
##  @file color_rgb.cpp

File Description:
##  Change the text color
\**************************************************************/

#include "define.hpp"
#include "write.hpp"
#include "error.hpp"

int color_rgb(const int fd, const unsigned char r, const unsigned char g, const unsigned char b)
{
    int res = OK;

    res += putchar(fd, ESC);
    res += putstr(fd, "[38;2;");
    res += putnbr(fd, r);
    res += putchar(fd, ';');
    res += putnbr(fd, g);
    res += putchar(fd, ';');
    res += putnbr(fd, b);
    res += putchar(fd, 'm');
    if (res != OK)
        return err_prog(UNDEF_ERR, KO, ERR_INFO);
    return OK;
}
