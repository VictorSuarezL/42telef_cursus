# Define a custom color for output
CYAN = \033[0;96m

# Specify the shell to be used for executing commands
SHELL=/bin/bash

# Use the uname command to determine the OS and store it in the UNAME variable
UNAME = $(shell uname -s)

# Set the default PRINTF command to echo
PRINTF = echo

# Check if the detected OS is Linux
ifeq ($(UNAME), Linux)
# If it's Linux, set PRINTF to echo -e to enable escape sequences
	PRINTF = echo -e
endif

# Name and location of the library
BIN_DIR = bin
BIN = libft.a
NAME = $(BIN_DIR)/$(BIN)

# Source directory for source files (.c)
SRC_DIR = src
TEST_DIR = test

# Destination directory for object files (.o)
OBJ_DIR = obj

# List of source files
SRC = ft_isalpha.c\
		# ft_isdigit.c \



# Generate a list of object files from the list of source files
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Compiler options
FLAGS = -Wall -Wextra -Werror

# Additional commands and variables
AR = ar rcs
CC = gcc -MD
HEADER = libft.h
PRINTF = printf
RM = rm -f
MKDIR = mkdir -p

# Default target: Build the library
all: $(NAME)

# Rule to build the library from object files
$(NAME): $(OBJ) | $(BIN_DIR)
	@$(AR) $(NAME) $^

# Rule to compile a source file into an object file in the OBJ_DIR directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

# Create the OBJ_DIR directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Create the BIN_DIR directory if it doesn't exist
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Clean: Remove object files
clean:
	$(RM) -r $(OBJ_DIR)

# Full Clean: Remove object files and the library
fclean: clean
	$(RM) -r $(BIN_DIR)
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

# Rebuild everything from scratch
re: fclean all

# Rule to build an executable from a test source file
TEST_DIR = test
TESTS = test_isalpha.c \
		# test_isdigit.c \

TEST_SRCS   = $(addprefix $(TEST_DIR)/,$(TESTS))
TEST_BINS   = $(patsubst $(TEST_DIR)/%.c,$(TEST_DIR)/%,$(TEST_SRCS))


# Regla para compilar y ejecutar los tests
test: 
	@$(PRINTF) "$(CYAN)Running tests$(DEFAULT)\n"
	gcc ./test/test_isalpha.c ./bin/libft.a -o ./bin/test_isalpha && ./bin/test_isalpha
	rm -f ./bin/test_isalpha

# Define phony targets (targets that don't represent files)
.PHONY: all clean fclean re test
