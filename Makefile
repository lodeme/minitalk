NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus
LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c
OBJ_SERVER = $(SRC_SERVER:%.c=./obj/%.o)
OBJ_CLIENT = $(SRC_CLIENT:%.c=./obj/%.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:%.c=./obj/%.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:%.c=./obj/%.o)
HEADERS = minitalk.h \
          libft/libft.h

GREY=\033[1;33m
CHECK=\033[0;32m✔\033[0m

COMPILATION_FLAG_FILE=.compilation_started

all: $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	@echo "${GREY}====> Compiling libft..."
	@make bonus -s -C libft > /dev/null
	@echo "${CHECK} Compiled libft"

$(NAME_SERVER): $(LIBFT) $(OBJ_SERVER) $(HEADERS)
	@echo "${GREY}====> Creating program $(NAME_SERVER)..."
	@$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER) -Llibft -lft
	@echo "${CHECK} Created $(NAME_SERVER) program"
	@$(RM) $(COMPILATION_FLAG_FILE)

$(NAME_CLIENT): $(LIBFT) $(OBJ_CLIENT) $(HEADERS)
	@echo "${GREY}====> Creating program $(NAME_CLIENT)..."
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT) -Llibft -lft
	@echo "${CHECK} Created $(NAME_CLIENT) program"
	@$(RM) $(COMPILATION_FLAG_FILE)

$(NAME_SERVER_BONUS): $(LIBFT) $(OBJ_SERVER_BONUS) $(HEADERS)
	@echo "${GREY}====> Creating program $(NAME_SERVER_BONUS)..."
	@$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) -o $(NAME_SERVER_BONUS) -Llibft -lft
	@echo "${CHECK} Created $(NAME_SERVER_BONUS) program"
	@$(RM) $(COMPILATION_FLAG_FILE)

$(NAME_CLIENT_BONUS): $(LIBFT) $(OBJ_CLIENT_BONUS) $(HEADERS)
	@echo "${GREY}====> Creating program $(NAME_CLIENT_BONUS)..."
	@$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) -o $(NAME_CLIENT_BONUS) -Llibft -lft
	@echo "${CHECK} Created $(NAME_CLIENT_BONUS) program"
	@$(RM) $(COMPILATION_FLAG_FILE)

./obj/%.o: %.c
	@if [ ! -f $(COMPILATION_FLAG_FILE) ]; then \
		echo "${GREY}====> Compiling $(NAME_SERVER) and $(NAME_CLIENT)"; \
		touch $(COMPILATION_FLAG_FILE); \
	fi
	@mkdir -p ./obj
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null
	@echo "${CHECK} Compiled $<"

clean:
	@echo "${GREY}====> Cleaning up object files..."
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) \
					$(OBJ_CLIENT_BONUS) $(COMPILATION_FLAG_FILE) > /dev/null
	@make clean -C libft > /dev/null
	@echo "${CHECK} Cleanup complete"

fclean: clean
	@echo "${GREY}====> Full clean - Removing libraries and programs"
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT) \
				$(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)> /dev/null
	@make fclean -C libft > /dev/null
	@echo "${CHECK} Full cleanup complete"

re: fclean all

bonus: all $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

.PHONY: all clean fclean re
