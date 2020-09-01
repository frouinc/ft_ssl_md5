# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 15:07:13 by cyrillef          #+#    #+#              #
#    Updated: 2020/09/01 11:18:25 by cfrouin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC					=	gcc

NAME				=	ft_ssl

SRCS_DIR			=	srcs/

SRCS				=	main.c \
						params.c \
						op.c \
						md5/md5.c \
						md5/md5bis.c \
						sha256/sha256.c \
						sha256/sha256bis.c \
						sha224/sha224.c \
						sha224/sha224bis.c \
						util.c \
						error.c

SRCS_FULL			=	$(addprefix $(SRCS_DIR), $(SRCS))

OBJS				=	$(SRCS_FULL:.c=.o)

CFLAGS				=	-Wall -Wextra -I./includes/

all:				libft $(NAME)

%.o : %.c
					@gcc -g -o $@ -c $< $(CFLAGS)
					@echo "\033[K\033[34mFdf :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"

$(NAME):			$(OBJS)
					@$(GCC) $(OBJS) -o $(NAME) -L./libs/libft -lft
					@echo "\033[K\033[32m=========FT_SSL_MD5=============\033[0m"
					@echo "\033[34mCompiling\033[0m" [ $(NAME) ] "\033[K\033[32mSuccessful\033[00m"
					@echo "\033[32m================================\033[00m"

libft:
					@make -C libs/libft

clean:
					@rm -f $(OBJS)
					@rm -f good_result.log
					@rm -f my_result.log
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
