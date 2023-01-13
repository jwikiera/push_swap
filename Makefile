NAME					:= push_swap

UNAME_S					:= $(shell uname -s)

ifeq ($(UNAME_S),Linux)
  FSANITIZE				:= -fsanitize=address -fsanitize=leak
  FRAMEWORK				:=
  LINUX_LIBS			:=
  LINUX_INCLUDES		:= -I/usr/include
  OS_FLAG				:= -D LINUX
else
  FSANITIZE				:=
  FRAMEWORK				:=
  LINUX_LIBS			:=
  LINUX_INCLUDES		:=
  OS_FLAG				:= -D OSX
endif

CC						:= cc
CFLAGS					:= -Wall -Wextra -Werror -pedantic -O3 -fno-omit-frame-pointer -ggdb -O0 -fstack-protector-all $(FSANITIZE) $(OS_FLAG)
RM						:= rm -f

LIB_DIRECTORY			:= ./libs/

LIBFT					:= $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY			:= $(LIB_DIRECTORY)libft/
LIBFT_HEADERS			:= $(LIBFT_DIRECTORY)includes/

LIBPRINTF				:= $(LIBPRINTF_DIRECTORY)libftprintf.a
LIBPRINTF_DIRECTORY		:= $(LIB_DIRECTORY)libprintf/
LIBPRINTF_HEADERS		:= $(LIBPRINTF_DIRECTORY)includes/

INCLUDE_DIR				:= ./includes/

# lm: default math lib
LIBRARIES				:= -lftprintf -lft -L. -L$(LIBFT_DIRECTORY) -L$(LIBPRINTF_DIRECTORY) $(FRAMEWORK) $(LINUX_LIBS)
INCLUDES				:= -I$(LIBFT_HEADERS) -I$(LIBPRINTF_HEADERS) -I$(INCLUDE_DIR) $(LINUX_INCLUDES)

SOURCES_DIRECTORY		:= ./sources/
SOURCES_LIST			:= main.c\
							chk_args.c\
							args_to_intarray.c\
							sort_two.c\
							sort_three.c\
							sort_five.c\
							sort_hundred.c\
							sort_fivehundred.c\
							mysort.c\
							intarr_bubblesort.c\
							stack_operations.c\
							stack_operations2.c\
							stack_init.c\
							array_shifts.c\
							ps_print_util.c
SOURCES					:= $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
HEADER_LIST				:= push_swap.h
HEADER_FILES			:= $(addprefix $(INCLUDE_DIR), $(HEADER_LIST))

OBJECTS_DIRECTORY		:= objects/
OBJECTS_LIST			:= $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS					:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

.PHONY: all clean fclean re docker_build docker_run docker_clean

all: $(NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)
	#@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
	#@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): Creating $(LIBFT)..."
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(LIBPRINTF):
	@echo "$(NAME): Creating $(LIBPRINTF)..."
	@$(MAKE) -sC $(LIBPRINTF_DIRECTORY)

$(NAME): $(LIBFT) $(LIBPRINTF) $(OBJECTS_DIRECTORY) $(OBJECTS) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBRARIES) $(INCLUDES) -o $(NAME)

clean:
	@$(MAKE) -sC $(LIBPRINTF_DIRECTORY) clean
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@rm -rf *.dSYM
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(LIBPRINTF_DIRECTORY) clean
	@rm -f $(NAME)
	@echo "$(NAME): $(NAME) was deleted"

docker_build:
	docker build -t $(NAME) .

docker_run:
	docker run -it $(NAME)

docker_clean:
	docker system prune -a --volumes

re: fclean all

norm:
	norminette includes/ sources/ libs/libft/ libs/libprintf/

funcs: $(NAME)
	nm -u $(NAME)

test: $(NAME)
	./$(NAME)

francinette_lft:
	cd libs/libft && cp includes/libft.h .
	cd libs/libft && ~/francinette/tester.sh
	cd libs/libft && rm libft.h