# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyrillefrouin <cyrillefrouin@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 15:07:13 by cyrillef          #+#    #+#              #
#    Updated: 2019/12/11 12:13:21 by cyrillefrou      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC					=	gcc

NAME				=	ft_ssl_md5

SRCS_DIR			=	srcs/

SRCS				=	main.c

SRCS_FULL			=	$(addprefix $(SRCS_DIR), $(SRCS))

OBJS				=	$(SRCS_FULL:.c=.o)

CFLAGS				=	-Wall -Wextra -I./includes/

all:				libft $(NAME)

%.o : %.c
					@gcc -g -o $@ -c $< $(CFLAGS)
					@echo "\033[K\033[34mFdf :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"

$(NAME):			$(OBJS)
					@$(GCC) $(OBJS) -o $(NAME) -L./libs/libft -lft -fsanitize=address
					@echo "\033[K\033[32m=========FT_SSL_MD5=============\033[0m"
					@echo "\033[34mCompiling\033[0m" [ $(NAME) ] "\033[K\033[32mSuccessful\033[00m"
					@echo "\033[32m================================\033[00m"

libft:
					@make -C libs/libft

clean:
					@rm -f $(OBJS)
					@echo "\033[K\033[31m=========FT_SSL_MD5=============\033[0m"
					@echo "\033[31mCleaning\033[00m  " [ "*.o" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"
					@make -C libs/libft clean

rclean:
					@rm -f $(OBJS)
					@echo "\033[K\033[31m=========FT_SSL_MD5=============\033[0m"
					@echo "\033[31mCleaning\033[00m  " [ "*.o" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"

fclean:				clean
					@rm -f $(NAME)
					@echo "\033[K\033[31m=========FT_SSL_MD5=============\033[0m"
					@echo "\033[31mRemoving\033[00m  " [ "fractol" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"
					@make -C libs/libft fclean

rfclean:			rclean
					@rm -f $(NAME)
					@echo "\033[K\033[31m=========FT_SSL_MD5=============\033[0m"
					@echo "\033[31mRemoving\033[00m  " [ "fractol" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"

re:					fclean all

ren:				rfclean all

.PHONY:				all clean fclean re ren