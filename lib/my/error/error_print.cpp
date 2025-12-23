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
##  @file error_print.cpp

File Description:
##  Print the error message (information)
\**************************************************************/

#include "define.hpp"
#include "write.hpp"
#include "error.hpp"
#include <unistd.h>
#include <stdbool.h>

void error_error(void)
{
    write(STDERR, "\n", 1);
    write(STDERR, "----------------------ERROR----------------------\n", 49);
    write(STDERR, "Error: An Error have ocured in the error return.\n", 49);
    write(STDERR, "----------------------ERROR----------------------\n", 49);
    write(STDERR, "\n", 1);
}

void print_error_system(const char * const info, const char * const err)
{
    int res = OK;

    if (!err) {
        error_error();
        return;
    }
    res += reset_ouput(STDERR);
    if (info) {
        res += color_rgb(STDERR, 192, 192, 192);
        res += putstr(STDERR, info);
        res += putstr(STDERR, ": ");
    }
    res += color_rgb(STDERR, 0, 255, 255);
    res += putstr(STDERR, err);
    res += putchar(STDERR, '.');
    res += putchar(STDERR, '\n');
    res += reset_ouput(STDERR);
    if (res != OK)
        error_error();
}

static int print_error_head(void)
{
    int res = OK;

    res += reset_ouput(STDERR);
    res += strong(STDERR);
    res += putstr(STDERR, "-------------");
    res += color(STDERR, RED);
    res += putstr(STDERR, "[ERROR]");
    res += reset_ouput(STDERR);
    res += strong(STDERR);
    res += putstr(STDERR, "-------------\n");
    res += reset_ouput(STDERR);
    if (res != OK)
        return KO;
    return OK;
}

static int print_error_tail(void)
{
    int res = OK;

    res += reset_ouput(STDERR);
    res += strong(STDERR);
    res += putstr(STDERR, "\n--------------------------------\n\n");
    res += reset_ouput(STDERR);
    if (res != OK)
        return KO;
    return OK;
}

static int print_error_info(const err_t err)
{
    int res = OK;

    res += reset_ouput(STDERR);
    res += color_rgb(STDERR, 192, 192, 192);
    res += putstr(STDERR, err.file);
    res += putstr(STDERR, ", ");
    res += putstr(STDERR, err.func);
    res += putstr(STDERR, ", line ");
    res += putnbr(STDERR, err.line);
    res += putstr(STDERR, ": ");
    res += reset_ouput(STDERR);
    if (res != OK)
        return KO;
    return OK;
}

void print_error_custom(const char * const info, const err_t err)
{
    int res = OK;

    if (!info) {
        error_error();
        return;
    }
    res += print_error_head();
    res += print_error_info(err);
    res += color_rgb(STDERR, 0, 255, 255);
    res += putstr(STDERR, info);
    res += putchar(STDERR, '.');
    res += print_error_tail();
    if (res != OK)
        error_error();
}

void print_error_prog(const error_code_t code, const err_t err)
{
    int res = OK;

    res += print_error_head();
    res += print_error_info(err);
    res += color_rgb(STDERR, 0, 255, 255);
    res += dispatch(code);
    res += print_error_tail();
    if (res != OK)
        error_error();
}
