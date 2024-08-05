SRCS = main.cpp PmergeMe.cpp

OBJS = ${SRCS:.cpp=.o}
NAME = PmergeMe
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

RESET = \033[0m
GRAS = \033[1m
ITALIQUE = \033[3m
SOULIGN = \033[4m
UP = \033[A
BLINK = \033[6m

ORANGE = \033[38;5;216m
DARKBLUE = \033[38;5;21m
RED = \033[38;5;130m
GREEN = \033[38;5;85m

all: ${NAME}

${NAME}:${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "\n ${GRAS}${RED}Exercie COMPILÉ 👏${RESET}\n"

%.o: %.cpp
	@${CC} ${CFLAGS} -c -I . $< -o $@

clean:
	@${RM} ${OBJS}
	@echo "${ORANGE}${GRAS}\tNETTOYAGE 🛁${RESET}"
	@echo "${DARKBLUE}${ITALIQUE} -les fichiers sont supprimés${RESET}"

fclean: clean
	@${RM} ${NAME}
	@echo "${DARKBLUE}${ITALIQUE} -${NAME} est supprimé${RESET}"

re: fclean all

.PHONY: all clean fclean re

