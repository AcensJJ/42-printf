# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/18 15:41:28 by jacens       #+#   ##    ##    #+#        #
#    Updated: 2019/11/15 14:08:13 by jacens      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME    =   printflibft.a

CC      =   gcc 
CFLAGS  =   -Wall -Wextra -Werror
DIR_LIB =	./libft/
HEADER  =   ft_printf.h

LFLAGS  =   -I $(HEADER)

SRCS    =	ft_printf.c

OBJ     =   $(SRCS:.c=.o)

all: lib $(NAME)

lib:
	make bonus -C $(DIR_LIB)
	cp $(DIR_LIB)/libft.a $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(DIR_LIB)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(DIR_LIB)

re : fclean all

.PHONY : all clean fclean re