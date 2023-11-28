NAME = libftprintf.a

CC = cc

AR = ar

SRC = ft_printf.c\
	ft_put_x_lower.c\
	ft_put_x_upper.c\
	ft_put_unsigned_int.c\
	ft_putchar.c\
	ft_put_int.c\
	ft_putptr.c\
	ft_putstr.c\

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = rcs

all : $(NAME)
	@echo Creating $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
	
re : fclean all