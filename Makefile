CC		=	gcc
NAME	=	libftprintf.a
CFLAGS	=	-Wall -Wextra -Werror

SRCFILES	=	atoi.c				\
				printf.c			\
				printf1.c			\
				printf2.c			\
				printf3.c			\
				printf4.c			\
				printf5.c			\
				utils.c


OBJFILES	=	$(strip $(patsubst %.c, %.o, ${SRCFILES}))

OBJ4TEST	=	$(strip $(patsubst %.c, %.o, ${TSTFILES}))
LIB4NAME	=	$(subst lib,,${NAME:.a=})
EXE4TEST	=	${CURDIR}/ft_printf_test
TSTFILES	=	test.c

all: ${NAME}

# francinette: has bug
FSOARESFLAGS	=	-c

${NAME}: ${OBJFILES}
	$(AR) ${ARFLAGS} ${FSOARESFLAGS} ${@} ${?}

test: ${NAME} ${OBJ4TEST}
	$(CC) ${CFLAGS} ${OBJ4TEST} -o ${EXE4TEST} -L${CURDIR} -l${LIB4NAME} && ${EXE4TEST}
	$(RM) ${EXE4TEST}

re: fclean all

clean:
	$(RM) ${OBJFILES} ${OBJ4TEST}

fclean: clean
	$(RM) ${NAME}

.PHONY: all clean fclean re
