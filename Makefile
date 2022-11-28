NAME = so_long

CC	= gcc

CFLAGS	=	-Wall -Wextra -Werror

SRC_DIR	=	./src/

OBJ_DIR	=	./obj/

SRCS =	checker_map.c \
		map.c \
		img.c\
		utils.c \
		movement.c \
		movement_utils.c \
		main.c \

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

LIBS		= MLX42/libmlx42.a -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/

all: lib obj $(NAME) 

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I ./includes/ -I ./42-library/ -o $@ -c $<

$(NAME): $(OBJS)
	make -C MLX42
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -L ./42-library -l ft -o $(NAME)

lib:
	make -C	./42-library

clean:
	make clean -C ./42-library
	rm -rf obj $(OBJS) 

fclean: clean
	make fclean -C ./42-library
	rm -rf obj $(NAME) 

re: fclean all

.PHONY:     all clean fclean re