SRCS            =	main.c\
					tools.c\
					make_stack.c\
					operations_f.c\
					operations_s.c\
					operations_t.c\
					sort_median.c\
					sort_stack.c\

OBJS            =    $(SRCS:.c=.o)

CC              =   gcc
RM              =   rm -f
CFLAGS          =   -Wall -Wextra -Werror

NAME            =    push_swap

LIBRARIES        =    -L libftprintfgnl -lftprintfgnl
INCLUDES        =    -Ilibftprintfgnl

all:            $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror $(INCLUDES) -g3 -I/usr/include -O3 -c $< -o $@

$(NAME):		$(OBJS)
				make -C libftprintfgnl
				$(CC) $(CFLAGS) $(OBJS)  -o $(NAME) $(LIBRARIES)

norme :
				norminette $(SRCS) push_swap.h libftprintfgnl

clean:
				make -C libftprintfgnl clean
				$(RM) $(OBJS)


fclean:			clean
				make -C libftprintfgnl fclean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus norme
