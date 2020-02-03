# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celva <celva@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 10:55:19 by celva             #+#    #+#              #
#    Updated: 2020/01/27 10:03:01 by celva            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCDIR = srcs/
OBJDIR = objs/
INCDIR = includes/

SRCS =	fdf.c fdf1.c \
		transform.c \
		parsing_file.c \
		drawing_gpu.c \
		init_cl.c color.c \
		key_press.c \
		init_fdf.c

OBJECTS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

MLXDIR = mlx/
MLXLIB = $(addprefix $(MLXDIR), mlx.a)
MLXINC = -I $(MLXDIR)
MLXLNK = -L $(MLXDIR) -l mlx -framework OpenGL -framework AppKit

FTDIR = ft_printf/
FTLIB = $(addprefix $(FTDIR), libftprintf.a)
FTINC = -I $(FTDIR)/includes -I $(FTDIR)/libft/includes/
FTLNK = -L $(FTDIR)

all: obj $(FTLIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	gcc -g $(MLXINC) $(FTINC) -I $(INCDIR) -o $@ -c $<

$(FTLIB):
	make -C $(FTDIR)

$(MLXLIB):
	make -sC $(MLXDIR)

$(NAME): $(OBJECTS)
	gcc -g $(OBJECTS) $(MLXLNK) $(FTLNK) $(FTLIB) -lm -o $(NAME) -framework OpenCL

linux:
	gcc -g -o new $(addprefix $(SRCDIR), $(SRCS)) $(FTLIB) -I $(INCDIR) $(MLXINC) $(FTINC) mlx_linux/libmlx_Linux.a -lm -lXext -lX11 -framework OpenCL

clean: 
	@/bin/rm -rf $(OBJDIR)
	@make -C $(FTDIR) clean
	@make -C $(MLXDIR) clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C $(FTDIR) fclean

re: fclean all

.PHONY: all obj linux clean fclean re
