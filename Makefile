

CC = gcc 

NAME = 2048

SRC = main.c\
	   fichier.c\
	   interaction.c\
	   jeu.c

SRCS_DIR = srcs/

SRCS = $(addprefix ${SRCS_DIR}, ${SRC})

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
