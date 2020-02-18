NAME	:=	ft_select

SRC		:=	main.c\
				error.c\
				term_mode.c\
				init.c\
				termcap.c\
				convert_args_to_array.c

OBJ		:=	$(SRC:.c=.o)

HEADERS	:=	ft_select.h\
				ft_limits.h\
				struct.h

DIR_SRC	:=	./src/

DIR_INCLUDE	:=	./include/

DIR_OBJ		:=	./obj/

LIBFT		:=	libft.a
DIR_LIBFT	:=	./libft/
DIR_INCLUDE_LIBFT	:=	$(DIR_LIBFT)include

MAKE_LIBFT	:=	make -C $(DIR_LIBFT)

CFLAGS		:=	-Wall -Wextra -Werror

PATH_INCLUDE	:=	$(addprefix -I , $(DIR_INCLUDE) $(DIR_INCLUDE_LIBFT))
PATH_OBJ		:=	$(addprefix $(DIR_OBJ), $(OBJ))
PATH_LIBFT		:=	$(DIR_LIBFT)$(LIBFT)

vpath	%.c	$(DIR_SRC)
vpath	%.o $(DIR_OBJ)
vpath	%.h	$(DIR_INCLUDE)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(PATH_OBJ) $(PATH_LIBFT) -o $@ -ltermcap

$(OBJ): %.o:%.c $(HEADERS) | $(DIR_OBJ)
	gcc $(CFLAGS) -c $< -o $(DIR_OBJ)$@ $(PATH_INCLUDE)

$(LIBFT):
	$(MAKE_LIBFT)

$(DIR_OBJ):
	mkdir -p $@

.SILENT: all $(NAME) $(OBJ) $(LIBFT) $(DIR_OBJ)