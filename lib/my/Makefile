#**************************************************************#
#
# ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
# ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
#  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
#  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
# ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
# ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝
#
#Edition:
#**  21/12/2025 by Tsukini
#
#File Name:
#**  Makefile
#
#File Description:
#**  Makefile for the compilation of the lib
#**************************************************************#

CXX := g++

TARGET := libmy.a
BUILD_DIR := .obj

W := -W -Wall -Wextra -Wpedantic -Wunused-parameter -Wshadow
W += -Wuninitialized -Wmaybe-uninitialized

DEBUG := -g -ggdb3

CPPFLAGS := -I ../../include/
LDFLAGS := -lm
CXXFLAGS := $(W)

ifeq ($(d), t)
	CXXFLAGS := $(DEBUG)
else ifeq ($(d), o)
	CXXFLAGS += -O1
endif

ENGINE := 	engine/thread.cpp \
			engine/stack.cpp \
			engine/constructor.cpp \
			engine/destructor.cpp \
			engine/window.cpp \
			engine/update.cpp

STRING := 	string/retrive/strlen.cpp

WRITE := 	write/putchar.cpp \
			write/putstr.cpp \
        	write/putnbr.cpp \
			write/putnbr_base.cpp \
			write/edit_ouput/color/back_color.cpp \
			write/edit_ouput/color/back_color_rgb.cpp \
			write/edit_ouput/color/color_rgb.cpp \
			write/edit_ouput/color/color.cpp \
			write/edit_ouput/style/strong.cpp \
			write/edit_ouput/reset.cpp

ERROR :=	error/error_dispatch.cpp \
			error/error_print.cpp \
			error/error_prog.cpp \
			error/error_custom.cpp \
			error/error_system.cpp

SRC := $(ENGINE)
SRC += $(STRING) $(WRITE)
SRC += $(ERROR)
OBJ := $(SRC:%.cpp=$(BUILD_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	@ar rc $@ $^
	@mv $@ ../

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) -c -o $@ $^

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -f ../$(TARGET)

.NOTPARALLEL:
re: fclean $(TARGET)

get_unregistered_files:
	@find . -name "*.c" | sed "s/\.\///g" | while read file; do \
        	echo "$(SRC)" | grep -q "$$file" || \
		echo "$$file" >> new_files_detected.txt; \
        done
	@if [ -f new_files_detected.txt ]; then \
                cat new_files_detected.txt;\
                rm -f new_files_detected.txt; \
        fi

get_unknow_files:
	@for file in $(SRC); do \
            if [ ! -f "$$file" ]; then \
                echo "$$file" >> missing_files.txt; \
            fi; \
        done
	@if [ -f missing_files.txt ]; then \
                cat missing_files.txt | sed "s/src\///g"; \
                rm -f missing_files.txt; \
        fi

.PHONY: all clean fclean re get_unregistered_files get_unknow_files
