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
##  @file error_dispatch.cpp

File Description:
##  Dispatch error message (type)
\**************************************************************/

#include "define.hpp"
#include "write.hpp"
#include "error.hpp"

static const char * const error_message[] = {
    "An Error have ocured in the error return.",        // ERROR_ERR
    "Cascade Error.",                                   // CASCADE_ERR
    "Undefinied Error.",                                // UNDEF_ERR
    "The given pointer is NULL.",                       // PTR_ERR
    "The allocation attempt with malloc have fail.",    // MALLOC_ERR
    "The write function have failed.",                  // WRITE_ERR
    "Incorrect number of argument given to main.",      // ARGC_ERR
    "Incorrect input in the given argument.",           // ARGV_ERR
    "Unknow flag given for execution.",                 // FLAG_ERR
    "Overflow on a variable.",                          // OVERFLOW
    "'Invalid Permision' or 'No Existant File'.",       // OP_FILE_ERR
    "'Can't' or 'Fail' to read the file.",              // READ_FILE_ERR
    "'Invalid Permision' or 'No Existant Directory.'",  // OP_DIR_ERR
    "'Can't' or 'Fail' to read the directory.",         // READ_DIR_ERR
    NULL
};

int dispatch(const error_code_t code)
{
    int res = OK;

    if (code < MIN_ERROR_CODE || code > MAX_ERROR_CODE) {
        res += putnbr(STDERR, code);
        res += putstr(STDERR, ", Unknow error code.");
    } else {
        res += putstr(STDERR, error_message[code + MIN_ERROR_CODE * -1]);
    }
    if (res != OK)
        return KO;
    return OK;
}
