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
##  @file define.hpp

File Description:
##  Header for all global define
\**************************************************************/

#ifndef DEFINE_H
    #define DEFINE_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* define */
    #include <unistd.h> // STDERR_FILENO, STDOUT_FILENO, STDIN_FILENO

    //----------------------------------------------------------------//
    /* DEFINE */

    /* attribute */
    #define UNUSED __attribute__((unused))

    /* ouput */
    #define STDERR STDERR_FILENO
    #define STDOUT STDOUT_FILENO
    #define STDIN STDIN_FILENO

    /* global */
    #ifndef NULL
        #define NULL ((void *) 0)
    #endif /* NULL */

    /* acii */
    #define EOF -1
    #define ESC 27

    /* base */
    #define BASE_BIN "01"
    #define BASE_OCT "01234567"
    #define BASE_DEC "0123456789"
    #define BASE_HEX "0123456789abcdef"

#endif /* DEFINE_H */
