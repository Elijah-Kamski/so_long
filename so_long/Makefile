NAME 				= so_long

CC					= cc
FLAGS				= -Wall -Werror -Wextra -g
MLXFLAGS			= -L ./libs/minilibx -lmlx -Ilmlx -lXext -lX11

LIBFT				= ./libs/libft/libft.a
LIBFT_DIR			= ./libs/libft
MINILIBX_PATH		= ./libs/minilibx

SRC_DIR				= ./src/
OBJ_DIR				= ./assets/obj/

SRCS 				= \
					$(SRC_DIR)checks/checks.c \
					$(SRC_DIR)checks/floodfill.c \
					$(SRC_DIR)checks/checks_map.c \
					$(SRC_DIR)free_and_exit.c \
					$(SRC_DIR)get_map_and_initialize.c \
					$(SRC_DIR)move_player.c \
					$(SRC_DIR)render.c \
					$(SRC_DIR)main.c
					
OBJS 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: $(NAME)


${NAME}: 			$(OBJS)
	@$(MAKE) --no-print-directory -C $(MINILIBX_PATH)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	$(CC) $(FLAGS) -lm $(SRCS) $(MLXFLAGS) $(LIBFT) -o $(NAME)

clean:
	@rm -rf			$(OBJS)
	@cd $(LIBFT_DIR) && $(MAKE) --no-print-directory clean

fclean: clean
	@rm -rf			$(NAME) $(OBJS)
	@cd $(LIBFT_DIR) && $(MAKE) --no-print-directory fclean


re: fclean all

.PHONY: all clean fclean
