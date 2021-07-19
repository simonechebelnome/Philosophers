#Name
NAME =			philosophers

#Compiler
CC = 			gcc
CFLAGS = 		-Wall -Wextra -Werror -lpthread

#Norm
NORM =			norminette

#Shell
MKDIR =			mkdir -p
RM =			rm -rf

#Directories
SRCDIR = 		./srcs/*
OBJDIR =  		./objs/*
INCDIR = 		./includes

FILES =			main.c \
				parser.c \
				utils.c \
				routine.c \
				actions.c \
				sleep.c 

#Srcs
SRCS = 			$(foreach FILE, $(FILES), $(shell find $(SRCDIR) -name $(FILE)))

#Objs
OBJS = 			$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRCS:.c=.o))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) -I $(INCDIR) -c -o $@ $<

all: $(NAME) run

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

norminette:
	@$(NORM)

clean:
	@$(RM) $(OBJDIR) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all norminette libft clean fclean run re