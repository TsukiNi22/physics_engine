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

CC := g++

TARGET := libmy.a
BUILD_DIR := .obj

W := -W -Wall -Wextra -Wpedantic -Wunused-parameter -Wshadow
W += -Wuninitialized -Wmaybe-uninitialized

DEBUG := -g -ggdb3

CPPFLAGS := -I ../../include/
LDFLAGS := -lm
CFLAGS := $(W)

ifeq ($(d), t)
	CFLAGS := $(DEBUG)
else ifeq ($(d), o)
	CFLAGS += -O1
endif

SRC := 
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	@ar rc $@ $^
	@mv $@ ../

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c -o $@ $^

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
