# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 14:48:17 by zwalad            #+#    #+#              #
#    Updated: 2022/08/25 19:03:28 by zwalad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

CC := @gcc

FLAGS := -Wall -Wextra -Werror -I/goinfre/zwalad/homebrew/opt/readline/include

RM = @rm -f

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_Yellow = \033[1;33m
C_Purple = \033[1;35m

SRC := execut/builtins.c\
		execut/ft_utils_lib.c\
		execut/ft_echo.c\
		execut/ft_cd.c\
		execut/ft_env.c\
		execut/ft_utils1_export.c\
		execut/ft_utils11_export.c\
		execut/ft_utils2_export.c\
		execut/ft_export.c\
		execut/ft_export2.c\
		execut/ft_update_env.c\
		execut/ft_exit.c\
		execut/ft_pwd.c\
		execut/ft_unset.c\
		execut/ft_delete.c\
		execut/ft_execution.c\
		execut/ft_her_doc.c\
		execut/ft_paths.c\
		execut/ft_pipex.c\
		execut/ft_pipex2.c\
		execut/freeiat.c\
		execut/ft_redirection.c\
		execut/lib/ft_isalpha.c\
		execut/lib/ft_isalphanum.c\
		execut/lib/ft_isdigit.c\
		execut/lib/ft_split.c\
		execut/lib/ft_strchr.c\
		execut/lib/ft_strdup.c\
		execut/lib/ft_strjoin.c\
		execut/lib/ft_strlen.c\
		execut/lib/ft_strcmp.c\
		execut/lib/ft_substr.c\
		execut/lib/ft_putstrfd.c\
		execut/lib/ft_error.c\
		execut/lib/ft_atoi.c\
		execut/lib/ft_itoa.c\
		main.c\
		sub_main.c\
		utils1.c\
		utils2.c\
		command.c\
		dollar1.c\
		dollar2.c\
		files1.c\
		files2.c\
		files3.c\
		libf1.c\
		libf2.c\
		linked.c\
		quotes1.c\
		quotes2.c\
		pipex_utils.c\
		dollar_herdo1.c\
		dollar_herdo2.c\
		signals.c\

SOURCE := $(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME): $(SRC)
	@stty -echoctl
	@$(CC) $(SRC) $(FLAGS) -o $(NAME) -l readline -L/goinfre/zwalad/homebrew/opt/readline/lib
		@echo "$(C_RED)			      ___                       ___                       ___           ___           ___           ___       ___ "
		@echo "$(C_RED)			     /\__\\          ___        /\__\\          ___        /\  \         /\__\         /\  \         /\__\\     /\__\\"
		@echo "$(C_RED)			    /::||||        /\  \      /::||||        /\  \      /::\  \       /:/  /        /::\  \       /:////    /:////"
		@echo "$(C_RED)			   /:|:||||        \:\  \    /:|:||||        \:\  \    /:/\ \  \     /:/__/        /:/\:\  \     /:////    /://// "
	@echo "$(C_Purple)			  /:/|:|__|__      /::\__\  /:/|:||||__      /::\__\  _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /:////    /:////  "
	@echo "$(C_Purple)			 /:/ |::::\__\  __/:/\/__/ /:/ |:||/\__\  __/:/\/__/ /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/    /:/__/   "
	@echo "$(C_Purple)			 \/__/~~/://// /\/:/  /    \/__|:|/://// /\/:/  /    \:\ \:\ \/__/ \/__\:\/://// \:\~\:\ \/__/ \:\  \    \:\  \   "
	@echo "$(C_Purple)			       /:////  \::/__/         |:/:////  \::/__/      \:\ \:\__\        \::////   \:\ \:\__\    \:\  \    \:\  \  "
	@echo "$(C_L_BLUE)			      /:////    \:\__\         |::////    \:\__\       \:\/:/  /        /:////     \:\ \/__/     \:\  \    \:\  \ "
	@echo "$(C_L_BLUE)			     /:////      \\/__/         |:////      \\/__/        \\::/  /        /:////       \\:\\__\        \\:\\__\    \\:\\__\\"
	@echo "$(C_L_BLUE)			     \/__/                     |/__/                     \/__/         \/__/         \/__/         \/__/     \/__/"
	@echo "$(C_L_BLUE)"
	@echo " \033[0m"

clean:
	$(RM) $(SOURCE)

fclean: clean
	$(RM) $(NAME)

re: fclean all
