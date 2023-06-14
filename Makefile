SRCS	=	ft_printf.c			\
			ft_utils.c			\
			ft_convert.c		\
			ft_putnbr_base.c	\

OBJS	=	${SRCS:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror

GCC	=	gcc

RM	=	rm -f

NAME	=	libftprintf.a

.c.o:		${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar rcs ${NAME} ${OBJS}
		@echo "Printf has compiled"

all:		${NAME}

clean:		
		${RM} ${OBJS}
		@echo ".o's have been cleaned"

fclean:		clean
		${RM} ${NAME}
		@echo "printf has been completely cleaned."

re:		fclean all

.PHONY:		all clean fclean re bonus
