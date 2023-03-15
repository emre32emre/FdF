CC = gcc
NAME = fdf
LIBFT = ./lib/libft
LIBMLX = ./lib/libmlx
DIR_SRC = src
DIR_OBJ = temp
HEADERS = incl
FLAGS = -Wall -Wextra -Werror -O2
LIBMLXFLAGS = -I$(LIBMLX) -L$(LIBMLX) -lmlx -framework OpenGL -framework Appkit
LIBFTFLAGS = -L$(LIBFT) -lft

#SOURCES =	draw_and_color.c 		\
			draw_line.c				\
			draw_map_utils.c		\
			draw_map.c				\
			exit_on_error.c			\
			exit_program.c			\
			free_memory.c			\
			init_map_utils.c		\
			init_map.c				\
			main.c					\
			map_rotation.c			\
			register_hooks.c		\
			register_hooks_utils.c	\
			t_point_list.c			

SOURCES = 	main.c exit_program.c \
			 init_map.c draw_and_color.c \
			exit_program.c free_memory.c init_map_utils.c \
			t_point_list.c draw_line.c register_hooks.c \
			register_hooks_utils.c draw_map.c draw_map_utils.c \
			map_rotation.c ui.c bonus.c

SRCS = $(addprefix $(DIR_SRC)/,$(SOURCES))
OBJS = $(addprefix $(DIR_OBJ)/,$(SOURCES:.c=.o))

all: $(DIR_OBJ) $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(LIBMLX)
	$(CC) $(FLAGS) $(LIBFTFLAGS) $(LIBMATRIXFLAGS) $(LIBMLXFLAGS) -o $@ $^

$(DIR_OBJ):
	@mkdir -p temp

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(HEADERS)/$(NAME).h
	@$(CC) $(FLAGS) -I $(HEADERS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJS)
	@make -C $(LIBFT) clean
	@make -C $(LIBMLX) clean
	@/bin/rm -rf $(DIR_OBJ)
	
fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(LIBMLX) fclean

re: fclean all

.PHONY: all, $(DIR_OBJ), clean, fclean, norm

