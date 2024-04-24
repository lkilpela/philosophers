NAME = philo
CCFLAGS = -Wall -Wextra -Werror

LIBFT = lib/libft

HDRS = -I./include -I$(LIBFT)/include/
LIBS = $(LIBFT)/build/libft.a
SRCS = philo/philo.c
OBJS = $(SRCS:%.c=%.o)

all: libft $(NAME)

libft:
	@echo "--------------------------------------------"
	@make -C $(LIBFT)
	@echo "--------------------------------------------"
%.o : %.c
	@$(CC) $(CCFLAGS) -o $@ -c $< $(HDRS)
	@echo "$(GREEN)Compiled: $< $(RESET)"

$(NAME): $(OBJS)
	@echo "--------------------------------------------"
	@$(CC) $(OBJS) $(LIBS) $(HDRS) -o $(NAME)
	@echo "[$(NAME)] $(BLUE)Built target $(NAME)$(RESET)"
	@echo "--------------------------------------------"

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)
	@echo "[$(NAME)] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/build
	@echo "[$(NAME)] Everything deleted."

re: fclean all
	@echo "[$(NAME)] Everything rebuilt."

.PHONY: all clean fclean re libft

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
BLUE = \033[34m