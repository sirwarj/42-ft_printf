NAME = libft.a
INCLUDE = ../includes
CC = cc
CFLAGS = -Wall -Wextra -Werror -I
SRC_DIR = srcs/
OBJ_DIR = objs/
RM = rm
AR = ar rcs
# Source
SRC_FILES = \
		  ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
		  ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove \
		  ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr \
		  ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr \
		  ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin \
		  ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri \
		  ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
	      ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
		  ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF = .cache_exists

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $^
	ranlib $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

$(OBJF):
	mkdir -p $(OBJ_DIR)

clean :
	$(RM) -rf $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
