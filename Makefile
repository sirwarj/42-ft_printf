NAME = libftprintf.a
INCLUDE = includes
LIBFT = libft
SRC_DIR = srcs/
OBJ_DIR = objs/
CC = cc
CFLAGS =  -Wall -Werror -Wextra -I
RM = rm
AR = ar rcs

#Sources
SRC_FILES = 

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF = .cache_exists

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJF) :
	mkdir -p $(OBJ_DIR)

clean :
	$(RM) -rf $(OBJ_DIR)
	make clean -C $(LIBFT)

fclean :
	$(RM) -f $(NAME)
	$(RM) -f $(LIBFT)/libft.a

re : fclean all

.PHONY: all clean fclean re
