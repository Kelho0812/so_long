NAME = so_long

LIBFT = ./include/libft/libft.a

PRINTF = ./include/ft_printf/libftprintf.a

MINILIBX = ./include/minilibx-linux/libmlx_Linux.a

CC = cc

CFLAGS = -Werror -Wall -Wextra -g

MINIFLAGS =  -L./include/minilibx-linux/ -lmlx -lXext -lX11 -lm -lz

RM = rm -rf

SDIR := src
ODIR := obj

SOURCES := $(wildcard $(SDIR)/*.c)
OBJECTS := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SOURCES))

all : ${NAME}

${NAME} : ${OBJECTS} $(LIBFT) $(PRINTF)  $(MINILIBX)
	@${CC} ${CFLAGS} ${OBJECTS} -o ${NAME} $(LIBFT) $(PRINTF) $(MINILIBX)  ${MINIFLAGS}
	@echo "so_long created"

$(ODIR)/%.o: $(SDIR)/%.c | $(ODIR)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "so_long objects created"

$(ODIR):
	@mkdir -p $@	

$(LIBFT) :
	@cd ./include/libft/ && make bonus -s
	@echo "libft.a created"

$(PRINTF) :
	@cd ./include/ft_printf/ && make -s
	@echo "prinft.a created"

$(MINILIBX) :
	@cd ./include/minilibx-linux/ && make -s
	@echo "libmlx.a created"

clean :
	@${RM} ${OBJECTS}
	@${RM} ${ODIR}
	@echo "so_long objects deleted"
	@cd ./include/libft/ && make clean -s
	@echo "libft objects deleted"
	@cd ./include/ft_printf/ && make clean -s
	@echo "ft_printf objects deleted"
	@cd ./include/minilibx-linux/ && make clean -s
	@echo "libmlx.a created"

fclean : clean
	@${RM} ${NAME}
	@echo "so_long deleted"
	@cd ./include/libft/ && make fclean -s
	@echo "libft.a deleted"
	@cd ./include/ft_printf/ && make fclean -s
	@echo "ft_printf.a deleted"

re : fclean all