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
#**  Makefile for the compilation of the executable
#**************************************************************#

CXX := g++

TARGET := woof
TEST_TARGET := unit_tests
BUILD_DIR := .obj

W := -W -Wall -Wextra -Wpedantic -Wunused-parameter -Wshadow
W += -Wuninitialized -Wmaybe-uninitialized

DEBUG := -g -ggdb3

CPPFLAGS := -I ./include/
LDFLAGS := -L ./lib/ -lmy -lSDL2 -lGL -lGLU -ldl
CXXFLAGS := $(W)

ifeq ($(d), t)
	CXXFLAGS := $(DEBUG)
else ifeq ($(d), o)
	CXXFLAGS += -O1
endif

GLOBAL :=		main.cpp

FILES := $(GLOBAL)
SRC := $(addprefix src/, $(FILES))
OBJ := $(SRC:%.cpp=$(BUILD_DIR)/%.o)

TEST_OBJ := $(filter-out $(BUILD_DIR)/src/main.o, $(OBJ))

all: $(TARGET)

$(TARGET): $(OBJ)
	@make -C lib/my --no-print-directory d=$(d)
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) -c -o $@ $^

lib:
	@rm -f $(TARGET)
	@make -j --no-print-directory

clean:
	@rm -rf $(BUILD_DIR)
	@rm -f tests/*.o
	@rm -f *.gc*
	@rm -f vgcore.*
	@make clean -C lib/my --no-print-directory

fclean: clean
	@rm -f $(TARGET)
	@rm -f $(TEST_TARGET)
	@make fclean -C lib/my --no-print-directory

.NOTPARALLEL:
re: fclean $(TARGET)

unit_tests:
	$(CC) -o $(TEST_TARGET) $(TEST_OBJ) tests/*.c \
	$(CPPFLAGS) $(LDFLAGS) --coverage -lcriterion

tests_run:    unit_tests
	@./$(TEST_TARGET)
	@gcovr . --exclude tests/ --exclude lib/

sys_cmd: $(TARGET)
	@echo "Copying the target in \'/usr/local/bin\'..."
	@sudo cp $(TARGET) /usr/local/bin/$(TARGET)

get_unregistered_files:
	@find src/ -name "*.c" | while read file; do \
        	echo "$(SRC)" | grep -q "$$file" || \
		echo "$$file" >> new_files_detected.txt; \
        done
	@if [ -f new_files_detected.txt ]; then \
                cat new_files_detected.txt | sed "s/src\///g"; \
                rm -f new_files_detected.txt; \
        fi

get_unknow_files:
	@for file in $(SRC); do \
            if [ ! -f "$$file" ]; then \
                echo "$$file" >> missing_files.txt; \
            fi; \
        done;
	@if [ -f missing_files.txt ]; then \
                cat missing_files.txt | sed "s/src\///g"; \
                rm -f missing_files.txt; \
        fi

.PHONY: all lib clean fclean re tests_run sys_cmd \
	get_unregistered_files get_unknow_files
