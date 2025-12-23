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
##  @file write.hpp

File Description:
##  Header for all function who print something
\**************************************************************/

#ifndef WRITE_H
    #define WRITE_H
    
    //----------------------------------------------------------------//
    /* INCLUDE */
    
    /* type */
    #include <stddef.h>     // size_t

//----------------------------------------------------------------//
/* TYPEDEF */

/* color */
typedef enum color_e {
    BLACK = 30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
} color_t;

typedef enum back_color_e {
    B_BLACK = 40,
    B_RED,
    B_GREEN,
    B_YELLOW,
    B_BLUE,
    B_MAGENTA,
    B_CYAN,
    B_WHITE
} back_color_t;

//----------------------------------------------------------------//
/* PROTOTYPE */

/* ouput_reset */
int reset_ouput(const int fd); // Error: KO

/* ouput_style */
int strong(const int fd); // Error: KO

/* ouput_color */
int back_color(const int fd, const back_color_t back); // Error: KO
int back_color_rgb(const int fd, const unsigned char r, const unsigned char g, const unsigned char b); // Error: KO
int color(const int fd, const color_t color); // Error: KO
int color_rgb(const int fd, const unsigned char r, const unsigned char g, const unsigned char b); // Error: KO

/* string */
int putchar(const int fd, const char c); // Error: KO
int putstr(const int fd, const char * const str); // Error: KO

/* math */
int putnbr(const int fd, long long nb); // Error: KO
int putnbr_base(const int fd, const size_t nbr, const char * const str_base); // Error: KO

#endif /* WRITE_H */
