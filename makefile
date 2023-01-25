SRCS = so_long.c\
	   parsing.c\
	   draw.c\
	   ft_strtrim.c\
	   ft_substr.c\
	   ft_itoa.c\
	   map_checker.c\
	   player_move.c\
	   events.c\
	   put_pixels.c\
	   change_position.c

SRCSB = so_long_bonus.c\
		parsing_bonus.c\
		draw_bonus.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_itoa.c\
		map_checker_bonus.c\
		player_move_bonus.c\
		events_bonus.c\
		put_pixels_bonus.c\
		change_position_bonus.c

NAME = so_long

NAMEB = so_long_bonus

HEADER = includes.h

HEADERB = includes_bonus.h

GET_NEXT_LINE = get_next_line/get_next_line.a

PRINTF = ft_printf/libftprintf.a

OBJECT = $(SRCS:.c=.o)

OBJECTB = $(SRCSB:.c=.o)

all : $(NAME)

$(GET_NEXT_LINE) : mget_next_line

$(PRINTF) : mprintf

$(NAME) : $(GET_NEXT_LINE) $(PRINTF) $(OBJECT) $(HEADER)
			gcc $(OBJECT) $(GET_NEXT_LINE) $(PRINTF) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o  $(NAME)

bonus :	$(GET_NEXT_LINE) $(PRINTF) $(OBJECTB) $(HEADERB)
			gcc $(OBJECTB) $(GET_NEXT_LINE) $(PRINTF) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAMEB)

mget_next_line :
			make -C get_next_line/

mprintf :
			make -C ft_printf/

%.o : %.c
			gcc -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
			make clean -C get_next_line/
			make clean -C ft_printf/
			rm -rf $(OBJECT)
			rm -rf $(OBJECTB)

fclean : clean
			make fclean -C get_next_line/
			make fclean -C ft_printf/
			rm -rf $(NAME)
			rm -rf $(NAMEB)

re : fclean all
