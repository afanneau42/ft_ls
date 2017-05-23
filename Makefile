# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afanneau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 15:10:35 by afanneau          #+#    #+#              #
#    Updated: 2017/05/17 17:18:36 by afanneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SOURCES =  sources/main.c \
		   sources/check.c \
		   sources/init.c \
		   sources/do_dir.c \
		   sources/error.c \
		   sources/sort_files.c \
		   sources/l_flag_info.c \
		   sources/create_dir_struct.c \

OBJECTS =  main.o \
		   check.o \
		   init.o \
		   do_dir.o \
		   error.o \
		   sort_files.o \
		   l_flag_info.o \
		   create_dir_struct.o \

all : $(NAME)

$(NAME) :
	make -C libft/ && make -C libft/ clean
	gcc -Wall -Wextra -Werror -I libft/includes -c $(SOURCES) -Iincludes
	gcc -o $(NAME) $(OBJECTS) -L libft/ -lft

clean :
	rm -f  $(OBJECTS)
	make -C libft/ clean

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all
