INCLUDES_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs
UTILS_DIR = utils

SRCS_FILES =	server.c \
				client.c
UTILS_FILES =	ft_atoi.c \
				ft_error.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES)) $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.c=.o)) $(addprefix $(OBJS_DIR)/, $(UTILS_FILES:.c=.o))

CLIENT_OBJS = $(filter-out $(OBJS_DIR)/server.o, $(OBJS))
SERVER_OBJS = $(filter-out $(OBJS_DIR)/client.o, $(OBJS))

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = minitalk
CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS)
	@echo "Client compilation done !"

$(SERVER): $(SERVER_OBJS)
	@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS)
	@echo "Server compilation done !"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES_DIR)/$(NAME).h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

$(OBJS_DIR)/%.o: $(UTILS_DIR)/%.c $(INCLUDES_DIR)/$(NAME).h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "Objects deleted !"
	@rmdir $(OBJS_DIR) 2> /dev/null || true

fclean: clean
	@$(RM) $(CLIENT) $(SERVER)
	@echo "Programs deleted !"

re: fclean all

.PHONY: all clean fclean re