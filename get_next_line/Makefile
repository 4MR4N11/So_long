# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 13:14:25 by kel-amra          #+#    #+#              #
#    Updated: 2022/03/13 14:59:32 by kel-amra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	get_next_line.c\
		get_next_line_utils.c

HEADER = get_next_line.h

NAME = get_next_line.a

OBJECT = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(OBJECT) $(HEADER)
			ar rcs $(NAME) $(OBJECT)

%.o : %.c
			gcc $(FLAGS) -c $<

clean :
			rm -rf $(OBJECT)

fclean : clean
			rm -rf $(NAME)

re : fclean all
