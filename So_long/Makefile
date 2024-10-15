# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 15:55:00 by luiribei          #+#    #+#              #
#    Updated: 2024/10/11 15:55:02 by luiribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME	= so_long

# Directories
INC		= inc/
SRC_DIR	= src/
OBJ_DIR = obj/

# Compiler and CFlags
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -O3 -g -I$(INC)
RM		= rm -f

# Source Files
COMMANDS_DIR		=	$(SRC_DIR)commands/push.c \
						$(SRC_DIR)commands/reverse_rotate.c \
						$(SRC_DIR)commands/rotate.c \
						$(SRC_DIR)commands/swap.c

SORTING_DIR			=	$(SRC_DIR)sorting/sort_stacks.c \
						$(SRC_DIR)sorting/sort_three.c

UTILS_DIR			=	$(SRC_DIR)utils/a_to_b.c \
						$(SRC_DIR)utils/b_to_a.c \
						$(SRC_DIR)utils/errors.c \
						$(SRC_DIR)utils/stack_initiation_a.c \
						$(SRC_DIR)utils/stack_utils.c

# Main Source File
MAIN_SRC            =   $(SRC_DIR)push_swap.c

# Concatenate all source files
SRCS				=	$(COMMANDS_DIR) $(SORTING_DIR) $(UTILS_DIR) $(MAIN_SRC)

# Apply the pattern substitution to each source file in SRC and produce
# a corresponding list of object files in the OBJ_DIR
OBJ					=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# Build rules
all:				$(NAME)

$(NAME):			$(OBJ)
					@echo "Linking object files to create $(NAME)..."
					@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
					@echo "$(NAME) has been successfully built!"

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@echo "Compiling $<..."
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					$(RM) -r $(OBJ_DIR)
					@echo "Cleaned up object files."

fclean:				clean
					@$(RM) $(NAME)
					@echo "Removed executable $(NAME)."

re:					fclean all
					@echo "Performing a full rebuild..."
					@$(MAKE) all

# Phony targets represent actions/commands not files
.PHONY:	all clean fclean re