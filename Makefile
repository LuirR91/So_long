# Standard
NAME	= so_long

# Directories
LIBFT	= ./libft/libft.a
MLX		= ./minilibx-linux/libmlx.a
INC		= inc/
SRC_DIR	= src/
OBJ_DIR = obj/

# Compiler and CFlags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -I$(INC)
MLXFLAGS	=	-Iminilibx-linux -lXext -lX11 -lm -lz
RM			= rm -f

SO_LONG_DIR			=	$(SRC_DIR)main.c \
								$(SRC_DIR)window.c \
								$(SRC_DIR)img.c \

SRCS				=	$(SO_LONG_DIR)

OBJS				=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

$(LIBFT):
					@make -s -C ./libft

$(MLX):
					@make -s -C ./minilibx-linux

$(NAME):			$(OBJS) $(LIBFT) $(MLX)
					@echo "Make .o and so_long."
					@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)
					@echo "$(NAME) has been successfully built!"

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@echo "Compiling $<..."
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

all:				$(NAME)

clean:
					$(RM) -r $(OBJ_DIR)
					@make -s clean -C ./libft
					@make -s clean -C ./minilibx-linux
					@echo "Cleaned up .o files."

fclean:				clean
					@$(RM) $(NAME)
					@make -s fclean -C ./libft
					@echo "Removed executables."

re:					fclean all
					@echo "Performing a full rebuild..."
					@$(MAKE) all

.PHONY:	all clean fclean re
