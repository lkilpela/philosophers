NAME = philo
CCFLAGS = -Wall -Wextra -Werror

HDRS = -I./include
SRCS = philo/philo.c philo/utils.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

%.o : %.c
	@$(CC) $(CCFLAGS) $(HDRS) -c $< -o $@
	@echo "$(GREEN)Compiled: $< $(RESET)"

$(NAME): $(OBJS)
	@echo "--------------------------------------------"
	@$(CC) $(OBJS) -o $(NAME)
	@echo "[$(NAME)] $(BLUE)Built target $(NAME)$(RESET)"
	@echo "--------------------------------------------"

clean:
	@rm -rf $(OBJS)
	@echo "[$(NAME)] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@echo "[$(NAME)] Everything deleted."

re: fclean all
	@echo "[$(NAME)] Everything rebuilt."

.PHONY: all clean fclean re

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
BLUE = \033[34m