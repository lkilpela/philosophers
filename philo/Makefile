NAME 		= philo

CC			=	cc
M_SRC_DIR	=	.
CCFLAGS		=	-Wall -Wextra -Werror -lpthread 
CC_DEBUG	=	#-g #-fsanitize=leak
HDRS		=	-I./include
SRCS		=	src/init.c src/monitor.c src/philo.c src/routine.c src/time.c src/utils.c
OBJS		=	$(SRCS:%.c=%.o)

vpath %.c $(M_SRC_DIR)

all: $(NAME)

%.o : %.c
	@$(CC) $(CCFLAGS) -o $@ -c $< $(HDRS)
	@echo "$(GREEN)Compiled: $< $(RESET)"

$(NAME): $(OBJS)
	@echo "--------------------------------------------"
	@$(CC) $(OBJS) $(HDRS) -o $(NAME)
	@echo "[$(NAME)] $(BLUE)Built target $(NAME)$(RESET)"make
	@echo "--------------------------------------------"

clean:
	@rm -rf $(OBJS)
	@echo "[$(NAME)] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@echo "[$(NAME)] Everything deleted."

re: fclean all
	@echo "[$(NAME)] Everything rebuilt."

################################################################################
# NORM
################################################################################
norm:
	norminette -R CheckForbiddenSourceHeader $(M_SRC_DIR) | grep -v "OK!" || true

norm2:
	norminette -R CheckForbiddenSourceHeader $(M_SRC_DIR)


.PHONY: all clean fclean re

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
BLUE = \033[34m