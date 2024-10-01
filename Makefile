PHILO_NAME	=	philo

CC			=	cc
FLAG		=	-Wall -Wextra -Werror -g3

LIBFT_PATH	=	.libft
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(LIBFT_PATH)/$(LIBFT_FILE)

PHILO_SRC	=	src/
					 

PHILO_OBJ	=	$(PHILO_SRC:.c=.o)


.c.o:
	@printf "\r\033[K[philosophers] \033[0;32mBuilding : $<\033[0m"
	@$(CC) $(FLAG) -c $< -o $@

all:	$(PHILO_NAME)

# bonus:

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(PHILO_NAME): $(LIBFT_LIB) $(PHILO_OBJ) 
	@printf "\r\033[K[philosophers] \033[0;32mLinking...\033[0m"
	@$(CC) $(PHILO_OBJ) $(LIBFT_LIB) -o $(PHILO_NAME) -lm 
	@printf "\r\033[K[philosophers] \033[0;32mDone!\033[0m\n"

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(PHILO_OBJ)
	@printf "[philosophers] \033[1;31mCleaned .o!\033[0m\n"

fclean: clean
	@rm -f $(PHILO_NAME)
	@make fclean -C $(LIBFT_PATH)
	@printf "[philosophers] \033[1;31mCleaned all!\033[0m\n"

re: fclean all

.PHONY: all clean fclean re