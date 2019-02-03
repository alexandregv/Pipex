# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 13:21:32 by hben-yah          #+#    #+#              #
#    Updated: 2019/02/03 18:21:17 by hben-yah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

COMP			=	clang
FLAG			=	-Wall -Wextra -Werror -g3

# Sources paths
FILES_C			=	ft_strlen.c \
					ft_putstr.c \
					ft_strjoin.c \
					ft_strdel.c \
					ft_strnew.c \
					ft_strcpy.c \
					ft_strcat.c \
					ft_memdel.c \
					ft_memalloc.c \
					ft_bzero.c \
				    ft_realloc.c\
				    ft_strlcat.c\
				    ft_strlen.c\
				    ft_strnew.c\
				    ft_strncat.c \
				    ft_atoi.c \
				    ft_putnbr.c \
				    ft_putchar.c \
				    ft_putendl.c \
				    ft_strncpy.c \
				    ft_putstr_fd.c \
				    ft_putendl_fd.c \
				    ft_putchar_fd.c \
				    ft_strnequ.c \
				    ft_strtablen.c \
				    ft_strtabdup.c \
				    ft_strsplit.c \
				    ft_strjoin3.c \
				    ft_strdup.c \
				    ft_wrdcnt.c \
				    ft_isspace_wnt.c \
				    ft_split_chars.c \
				    ft_strtabnew.c \
				    ft_tabdel.c

FILES_O			=	$(FILES_C:.c=.o)
FILES_H			=	libft.h

# Directories
SRCS_D			=	./srcs/
OBJS_D			=   ./objs/
INCL_D 			=	./includes/

# Paths
SRCS			= 	$(addprefix $(SRCS_D), $(FILES_C))
OBJS			=	$(addprefix $(OBJS_D), $(FILES_O))
INCL			=	$(addprefix $(INCL_D), $(FILES_H))

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					@echo "\nAssemblage et création de la librairie $(NAME)"
					@ar rc $(NAME) $(OBJS)
					@ranlib $(NAME)
					@echo "Libft terminée"

$(OBJS_D)%.o	:	$(SRCS_D)%.c $(INCL)
					@echo -e "\033[2K\c"
					@echo "\rCréation de l'objet $@\c"
					@mkdir -p $(OBJS_D)
					@$(COMP) $(FLAG) -I $(INCL_D) -o $@ -c $<

clean			:
					@echo "Nettoyage des objets ./libft/objs/"
					@rm -rf $(OBJS_D)

fclean			:	clean
					@echo "Nettoyage de la librairie $(NAME)"
					@rm -f $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
