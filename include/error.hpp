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
##  @file error.hpp

File Description:
##  Header for the error handling
\**************************************************************/

#ifndef ERROR_H
    #define ERROR_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include <stddef.h>     // size_t
    #include <stdbool.h>    // boolean

    //----------------------------------------------------------------//
    /* DEFINE */

    /* error_info */
    #define ERR_INFO (err_t{__FILE__, __func__, __LINE__})

    /* error_return_write */
    #define PUT_ERROR 0
    #define CUSTOM_PUT_ERROR 0
    #define SYSTEM_PUT_ERROR 1

    /* error_return */
    #define KO -1
    #define OK 0
    #define FATAL_ERR 255

    /* error_code */
    #define MIN_ERROR_CODE ERROR_ERR
    #define MAX_ERROR_CODE READ_DIR_ERR

//----------------------------------------------------------------//
/* TYPDEF */

/* error_info */
typedef struct err_s {
    const char *file;
    const char *func;
    const int line;
} err_t;

/* error_code */
typedef enum error_code_e {
    ERROR_ERR = -3,
    CASCADE_ERR = -2,
    UNDEF_ERR = -1,
    PTR_ERR = 0,
    MALLOC_ERR,
    WRITE_ERR,
    ARGC_ERR,
    ARGV_ERR,
    FLAG_ERR,
    OVERFLOW,
    OP_FILE_ERR,
    READ_FILE_ERR,
    OP_DIR_ERR,
    READ_DIR_ERR
} error_code_t;

/*
** For more detail in the error, look in /lib/my/error/error_dispatch.c
*/

//----------------------------------------------------------------//
/* PROTOTYPE */

/* error_handling */
void err_prog_v(const error_code_t code, const err_t err); // Error: None
void *err_prog_n(const error_code_t code, const err_t err); // Error: None
int err_prog(const error_code_t code, const int to_return, const err_t err); // Error: None

void err_custom_v(const char * const info, const err_t err); // Error: None
void *err_custom_n(const char * const info, const err_t err); // Error: None
int err_custom(const char * const info, const int to_return, const err_t err); // Error: None

void err_system_v(void * const data, const char * const info, const char * const err); // Error: None
void *err_system_n(void * const data, const char * const info, const char * const err); // Error: None
int err_system(void * const data, const int to_return, const char * const info, const char * const err); // Error: None

/* print_error_ouput */
void error_error(void); // Error: None
int dispatch(const error_code_t code); // Error: KO
void print_error_prog(const error_code_t code, const err_t err); // Error: None
void print_error_custom(const char * const info, const err_t err); // Error: None
void print_error_system(const char * const info, const char * const err); // Error: None

#endif /* ERROR_H */
