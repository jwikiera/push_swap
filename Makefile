NAME					:= push_swap
BONUS_NAME				:= checker


UNAME_S					:= $(shell uname -s)

ifeq ($(UNAME_S),Linux)
  FSANITIZELEAK			:= -fsanitize=leak
  FRAMEWORK				:=
  LINUX_LIBS			:=
  LINUX_INCLUDES		:= -I/usr/include
  OS_FLAG				:= -D LINUX
else
  FSANITIZELEAK			:=
  FRAMEWORK				:=
  LINUX_LIBS			:=
  LINUX_INCLUDES		:=
  OS_FLAG				:= -D OSX
endif

PIVOT_PERCENTAGE_FLAG	:=
ifdef pivot
	# echo "pivot is set"
	PIVOT_PERCENTAGE_FLAG	:= -D PIVOT=$(pivot)
endif
PIVOTB1_PERCENTAGE_FLAG	:=
ifdef pivotb1
	# echo "pivot is set"
	PIVOTB1_PERCENTAGE_FLAG	:= -D PIVOTB1=$(pivotb1)
endif
PIVOTB2_PERCENTAGE_FLAG	:=
ifdef pivotb2
	# echo "pivot is set"
	PIVOTB2_PERCENTAGE_FLAG	:= -D PIVOTB2=$(pivotb2)
endif
MIN_CHUNK_FLAG			:=
ifdef minchunk
	# echo "pivot is set"
	MIN_CHUNK_FLAG		:= -D MIN_CHUNK=$(minchunk)
endif

ifndef addressoff
	FSANADDRESS			:= -fsanitize=address
else
	FSANADDRESS			:=
endif

ifndef fsanitizeoff
	FSANITIZE			:= -fno-omit-frame-pointer -fstack-protector-all $(FSANADDRESS) $(FSANITIZELEAK)
else
	FSANITIZE			:=
endif

ifdef DEBUG
	DEVFLAGS			:= -ggdb -O0 $(FSANITIZE)
else
	DEVFLAGS			:=
endif

CC						:= cc
CFLAGS					:= -Wall -Wextra -Werror -pedantic -O3 $(DEVFLAGS) $(OS_FLAG) $(PIVOT_PERCENTAGE_FLAG) $(PIVOTB1_PERCENTAGE_FLAG) $(PIVOTB2_PERCENTAGE_FLAG) $(MIN_CHUNK_FLAG)
RM						:= rm -f

LIB_DIRECTORY			:= ./libs/

LIBFT					:= $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY			:= $(LIB_DIRECTORY)libft/
LIBFT_HEADERS			:= $(LIBFT_DIRECTORY)includes/

LIBPRINTF				:= $(LIBPRINTF_DIRECTORY)libftprintf.a
LIBPRINTF_DIRECTORY		:= $(LIB_DIRECTORY)libprintf/
LIBPRINTF_HEADERS		:= $(LIBPRINTF_DIRECTORY)includes/

INCLUDE_DIR				:= ./includes/
INCLUDE_DIR_BONUS		:= ./includes_bonus/

# lm: default math lib
LIBRARIES				:= -lftprintf -lft -L. -L$(LIBFT_DIRECTORY) -L$(LIBPRINTF_DIRECTORY) $(FRAMEWORK) $(LINUX_LIBS)
INCLUDES				:= -I$(LIBFT_HEADERS) -I$(LIBPRINTF_HEADERS) -I$(INCLUDE_DIR) $(LINUX_INCLUDES)
INCLUDES_BONUS			:= -I$(INCLUDE_DIR_BONUS)

SOURCES_DIRECTORY		:= ./sources/
SOURCES_LIST			:= main.c\
							chk_args.c\
							args_to_intarray.c\
							sort_two.c\
							sort_three.c\
							sort_five.c\
							mysort.c\
							big_sort.c\
							stack_operations.c\
							stack_operations2.c\
							stack_init.c\
							array_shifts.c\
							ps_print_util.c\
							build_instruction.c\
							shorten_instructions.c\
							check_short.c\
							count_instructions.c\
							cleanup.c\
							handle_hundred_plus.c\
							del_node.c\
							stack_helpers.c\
							stack_helpers2.c\
							b_loop_one.c\
							b_loop_two.c\
							lstadd_back_wrapper.c
HEADER_LIST				:= push_swap.h
HEADER_FILES			:= $(addprefix $(INCLUDE_DIR), $(HEADER_LIST))

OBJECTS_DIRECTORY		:= objects/
OBJECTS_LIST			:= $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS					:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

SOURCES_DIRECTORY_BONUS	:= ./sources_bonus/
SOURCES_LIST_BONUS		:= main_bonus.c\
							perform_ops.c\
							helpers.c
HEADER_LIST_BONUS		:= checker.h
HEADER_FILES_BONUS		:= $(addprefix $(INCLUDE_DIR_BONUS), $(HEADER_LIST_BONUS))

OBJECTS_DIRECTORY_BONUS	:= objects_bonus/
OBJECTS_LIST_BONUS		:= $(patsubst %.c, %.o, $(SOURCES_LIST_BONUS))
OBJECTS_BONUS			:= $(addprefix $(OBJECTS_DIRECTORY_BONUS), $(OBJECTS_LIST_BONUS))

.PHONY: all clean fclean re docker_build docker_run docker_clean bonus

all: $(NAME) #$(BONUS_NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@echo "$(NAME): Creating $(LIBFT)..."
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(LIBPRINTF):
	@echo "$(NAME): Creating $(LIBPRINTF)..."
	@$(MAKE) -sC $(LIBPRINTF_DIRECTORY)

$(NAME): $(LIBFT) $(LIBPRINTF) $(OBJECTS_DIRECTORY) $(OBJECTS) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBRARIES) $(INCLUDES) -o $(NAME)


bonus: $(BONUS_NAME)

$(OBJECTS_DIRECTORY_BONUS):
	mkdir -p $(OBJECTS_DIRECTORY_BONUS)

$(OBJECTS_DIRECTORY_BONUS)%.o : $(SOURCES_DIRECTORY_BONUS)%.c $(HEADER_FILES) $(HEADER_FILES_BONUS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $(INCLUDES_BONUS) $< -o $@

$(BONUS_NAME): $(LIBFT) $(LIBPRINTF) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_DIRECTORY_BONUS) $(OBJECTS_BONUS) $(HEADER_FILES) $(HEADER_FILES_BONUS)
	$(CC) $(CFLAGS) $(filter-out objects/main.o,$(OBJECTS)) $(OBJECTS_BONUS) $(LIBRARIES) $(INCLUDES) $(INCLUDES_BONUS) -o $(BONUS_NAME)


clean:
	$(MAKE) -sC $(LIBPRINTF_DIRECTORY) clean
	$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	rm -rf $(OBJECTS_DIRECTORY)
	rm -rf $(OBJECTS_DIRECTORY_BONUS)
	rm -rf *.dSYM


clean_ps:
	rm -rf $(OBJECTS_DIRECTORY)
	rm -rf *.dSYM


fclean: clean
	$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	$(MAKE) -sC $(LIBPRINTF_DIRECTORY) clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

docker_build:
	docker build -t $(NAME) .

docker_run:
	docker run -it $(NAME)

docker_clean:
	docker system prune -a --volumes

re: fclean all

re_ps: clean_ps all

norm:
	norminette includes/ sources/ libs/libft/ libs/libprintf/ sources_bonus/ includes_bonus/

funcs: $(NAME) $(BONUS_NAME))
	@echo "Functions used in $(NAME):"
	nm -u $(NAME)
	@echo "Functions used in $(BONUS_NAME):"
	nm -u $(BONUS_NAME)

test: $(NAME)
	./tester.py -t 10 -n 1 -r
	./tester.py -t 10 -n 2 -r
	./tester.py -t 10 -n 3 -r
	./tester.py -t 10 -n 4 -r
	./tester.py -t 10 -n 5 -r
	./tester.py -t 10 -n 100 -r
	./tester.py -t 10 -n 500 -r

francinette_lft:
	cd libs/libft && cp includes/libft.h .
	cd libs/libft && ~/francinette/tester.sh
	cd libs/libft && rm libft.h