# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ███████ <███████@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 12:33:02 by ███████           #+#    #+#              #
#    Updated: 2022/10/17 01:42:19 by ███████          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# minimal color codes
END=$'\x1b[0m
BOLD=$'\x1b[1m
UNDER=$'\x1b[4m
REV=$'\x1b[7m
GREY=$'\x1b[30m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m

OBJS_MS = $(SRCS_MS:.c=.o)
SRCS_MS = $(addprefix $(SRC_DIR)/, \
core/main.c \
	core/init.c core/prompting.c core/error.c \
debug/dbg_show.c \
exec/execution.c exec/redirect_dup.c \
lexing/lexing.c lexing/analyze_arg_oredirect_file.c lexing/analyze_cmd.c \
	lexing/analyze_heredoc_iredirect_file1.c \
	lexing/analyze_heredoc_iredirect_file2.c \
	lexing/analyze_pipe.c lexing/cmd_path.c \
	lexing/node.c \
parsing/parsing.c \
	parsing/check_valid_input1.c parsing/check_valid_input2.c \
	parsing/deglueing.c parsing/quote.c \
builtin/builtin.c builtin/builtin_exit.c builtin/builtin_echo.c \
	builtin/builtin_cd.c builtin/builtin_env.c builtin/builtin_unset.c \
	builtin/builtin_pwd.c \
signal/signal.c \
)

OBJS_MST = $(SRCS_MST:.c=.o)
SRCS_MST = $(addprefix $(SRC_DIR)/, \
core/env.c core/clear.c \
parsing/dequoting1.c parsing/dequoting2.c parsing/expand1.c parsing/expand2.c \
	parsing/input_parsing.c \
builtin/builtin_export1.c builtin/builtin_export2.c \
)

OBJS_UTEST = $(UTEST_SRC:.c=.o)
UTEST_SRC = $(addprefix ./.utests/, \
main.c error.c test_input_parsing.c test_expand_dequoting1.c \
test_expand_dequoting2.c test_expand_parsed_input.c \
)

SRC_DIR	= ./sources
INC_DIR	= ./includes/
CC = gcc
MF = Makefile
LDFLAGS = -L /usr/include -lreadline -L $(shell brew --prefix readline)/lib
CPPFLAGS = -I $(shell brew --prefix readline)/include

ifeq ($(DEBUG), 1)
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
else
FLAGS = -Wall -Wextra -Werror
endif

LIBFT_PATH = ./libft/libft.a
LIBTEST_PATH = ./libft/libtest.a
NAME = minishell
MS_HEADER_FILE = $(INC_DIR)/minishell.h
UTEST_NAME = utest
UTEST_HEADER_FILE = $(INC_DIR)/utest.h

all : _libft $(NAME)

$(NAME) : $(MF) $(OBJS_MS) $(OBJS_MST) $(LIBFT_PATH)
	@$(CC) $(FLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS_MS) $(OBJS_MST) $(LIBFT_PATH) -o $(NAME)
	@echo "\n${GREEN}> Compilation of minishell is success 🎉${END}"

./.utests/%.o : ./.utests/%.c $(UTEST_HEADER_FILE) $(MF)
	@/bin/echo -n .
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR) 

%.o : %.c $(MS_HEADER_FILE) $(MF)
	@/bin/echo -n .
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)

clean :
	@make clean -C ./libft
	@rm -f $(OBJS_MS)
	@rm -f $(OBJS_MST)
	@rm -f $(OBJS_UTEST)
	@echo "${YELLOW}> All objects files of minishell have been deleted ❌${END}"

fclean : clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@rm -f $(UTEST_NAME)
	@echo "${YELLOW}> Cleaning of minishell has been done ❌${END}"

re: fclean all

_libft :
	@make -C ./libft DEBUG=$(DEBUG)

_test :
	@make test -C ./libft DEBUG=$(DEBUG)

test: _libft _test $(UTEST_NAME)

$(UTEST_NAME) : $(MF) $(OBJS_MST) $(OBJS_UTEST) $(LIBTEST_PATH) $(LIBFT_PATH)
	@$(CC) $(FLAGS) $(OBJS_MST) $(OBJS_UTEST) $(LIBTEST_PATH) $(LIBFT_PATH) -o $(UTEST_NAME)
	@echo "\n${GREEN}> Compilation of unit tests is success 🎉${END}"

.PHONY:	all clean fclean re lib