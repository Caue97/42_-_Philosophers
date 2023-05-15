# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 18:07:38 by felcaue-          #+#    #+#              #
#    Updated: 2023/05/14 22:33:02 by felcaue-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

#compilation
CC 				= cc
CF 				= -g -Wall -Wextra -Werror
CFI 			= -I $(INCLUDE)
CLPT 			= -pthread

SRC_PATH 		= ./src/
OBJ_PATH		= ./objs_philo/
INCLUDE 		= ./include/

SRC				= main.c\
				init_clock.c\
				init_mutex.c\
				init_philo.c\
				init_tabletop.c\
				get.c\
				set.c\
				start.c\
				philo_activity.c\
				utils_01.c\
				utils_02.c
				

VPATH 			:= $(SRC_PATH)\

OBJ				= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))

#common commands
RM 				= rm -rf

#rules
$(OBJ_PATH)%.o: %.c
				@printf "\n$(CY)Generating object...$(RC)\n"
				mkdir -p $(OBJ_PATH)
				$(CC) $(CF) $(CLPT) $(CFI) -c $< -o $@
				@printf "$(GR)Object ready!$(RC)"

$(NAME):		$(OBJ)
				@printf "\n$(CY)Generating philosophers executable...$(RC)\n"
				$(CC) -g $(CF) $(CLPT) -I $(INCLUDE) -o $(NAME) $(OBJ)
				@printf "$(GR)Done!$(RC)\n\n"

all:			$(NAME)

re:				fclean all

clean:
				$(RM) $(OBJ) $(OBJDIR)
				@printf "$(RE)philosophers objects removed!$(RC)\n\n"

fclean:			clean
				$(RM) $(NAME)
				@printf "$(RE)Executables removed!$(RC)\n\n"


.PHONY:			all clean fclean re bonus rebonus

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m