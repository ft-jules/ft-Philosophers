NAME        =   philo

CC          =   cc

LIBS        =   /inc

FLAG        =   -g3 -Wall -Wextra -Werror -pthread
#-fsanitize=thread

C_FILES     =   srcs/philo.c srcs/utils.c srcs/inits.c srcs/routine.c \
					srcs/monitor.c

OBJ_DIR     =   builds

OBJS        =   $(addprefix $(OBJ_DIR)/, $(C_FILES:.c=.o))

DEPS        =   $(OBJS:.o=.d)

all:        $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/srcs

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(FLAG) -MMD -MP -c $< -o $@

$(NAME):    $(OBJS)
	@printf "\r\033[K[philosophers] \033[0;32mBuilding : $<\033[0m"
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME) -lpthread 
#-fsanitize=thread
	@printf "\r\033[K[philosophers] \033[0;32mDone!\033[0m\n"

clean:
	@rm -rf $(OBJ_DIR) $(DEPS)
	@printf "[philosophers] \033[1;31mCleaned .o!\033[0m\n"

fclean:     clean
	@rm -rf $(NAME)
	@printf "[philosophers] \033[1;31mCleaned all!\033[0m\n"

re:         fclean all

-include $(DEPS)

.PHONY:     all clean fclean re
