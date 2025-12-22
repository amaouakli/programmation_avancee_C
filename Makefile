
CC = gcc 

NAME = 2048

NAME_REPLAY = replay_mode

SRC = main.c\
	   fichier.c\
	   interaction.c\
	   jeu.c\
	   ft_itoa.c\
	   ft_strmanip.c\
	   affichage.c

REPLAY_SRC = replay_main.c\
			 fichier.c\
			 interaction.c\
			 jeu.c\
			 ft_itoa.c\
			 ft_strmanip.c\
			 affichage.c

SRCS_DIR = srcs/

SRCS = $(addprefix ${SRCS_DIR}, ${SRC})

REPLAY_SRCS = $(addprefix ${SRCS_DIR}, ${REPLAY_SRC})

OBJS = ${SRCS:.c=.o}

REPLAY_OBJS = ${REPLAY_SRCS:.c=.o}



### COLORS ###
NOC		= \033[0m
BLACK	= \033[1;30m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
PURPLE	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m


all: ${NAME}

${NAME}: ${OBJS}
	@echo "${GREEN}project compiled${NOC}"
	@${CC} ${OBJS} -o ${NAME}

run: ${NAME}
	./${NAME}

${NAME_REPLAY}: ${REPLAY_OBJS}
	@echo "${BLUE}replay mode compiled${NOC}"
	@${CC} ${REPLAY_OBJS} -o ${NAME_REPLAY}

replay: ${NAME_REPLAY}

resetsavefiles:
	@echo "${RED}removing all savefiles${NOC}"
	rm -f savefiles/*

clean:
	@echo "${YELLOW}removing all .o and precompiled headers${NOC}"
	rm -f ${OBJS}
	rm -f ${SRCS_DIR}*.h.gch

fclean: clean
	@echo "${YELLOW}removing output${NOC}"
	rm -f ${NAME}
	rm -f ${NAME_REPLAY}

re: fclean all

.PHONY: all clean fclean re
