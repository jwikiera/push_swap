NAME				:= libft.a

SOURCES_DIRECTORY	:= ./sources/
OBJECTS_DIRECTORY	:= ./objects/

MANDATORY_DIR		:= $(SOURCES_DIRECTORY)mandatory/
SRCS_MANDATORY_LIST	:= ft_isalpha.c\
						ft_isdigit.c\
						ft_isalnum.c\
						ft_isascii.c\
						ft_isprint.c\
						ft_strlen.c\
						ft_memset.c\
						ft_bzero.c\
						ft_memcpy.c\
						ft_memmove.c\
						ft_strlcpy.c\
						ft_strlcat.c\
						ft_toupper.c\
						ft_tolower.c\
						ft_strchr.c\
						ft_strrchr.c\
						ft_strncmp.c\
						ft_memchr.c\
						ft_memcmp.c\
						ft_strnstr.c\
						ft_atoi.c\
						ft_calloc.c\
						ft_strdup.c\
						ft_substr.c\
						ft_strjoin.c\
						ft_strtrim.c\
						ft_split.c\
						ft_itoa.c\
						ft_strmapi.c\
						ft_striteri.c\
						ft_putchar_fd.c\
						ft_putstr_fd.c\
						ft_putendl_fd.c\
						ft_putnbr_fd.c
OBJS_MANDATORY_LIST	:= $(patsubst %.c, %.o, $(SOURCES_MANDATORY_LIST))
OBJS_MANDATORY		:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJS_MANDATORY_LIST))

BONUS_DIR			:= $(SOURCES_DIRECTORY)bonus/
SRCS_BONUS_LIST		:= ft_lstnew_bonus.c\
						ft_lstadd_front_bonus.c\
						ft_lstsize_bonus.c\
						ft_lstlast_bonus.c\
						ft_lstadd_back_bonus.c\
						ft_lstdelone_bonus.c\
						ft_lstclear_bonus.c\
						ft_lstiter_bonus.c\
						ft_lstmap_bonus.c
OBJS_BONUS_LIST		:= $(patsubst %.c, %.o, $(SRCS_BONUS_LIST))
OBJS_BONUS			:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJS_BONUS_LIST))

GNL_DIR				:= $(SOURCES_DIRECTORY)gnl/
SRCS_GNL_LIST		:= get_next_line.c\
               			get_next_line_utils.c
OBJS_GNL_LIST		:= $(patsubst %.c, %.o, $(SRCS_GNL_LIST))
OBJS_GNL			:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJS_GNL_LIST))

MATH_DIR				:= $(SOURCES_DIRECTORY)math/
SRCS_MATH_LIST			:= math1.c\
							math2.c\
							math3.c\
							trig.c\
							equation.c
OBJS_MATH_LIST		:= $(patsubst %.c, %.o, $(SRCS_MATH_LIST))
OBJS_MATH			:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJS_MATH_LIST))

VEC_DIR				:= $(SOURCES_DIRECTORY)vector/
SRCS_VEC_LIST			:= vector1.c\
							line.c\
							plane.c\
							intersect.c\
							matrix.c\
							vector2.c\
							vector3.c\
							matrix2.c\
							rotation_matrix.c\
							point_projection.c\
							vec2d.c
OBJS_VEC_LIST		:= $(patsubst %.c, %.o, $(SRCS_VEC_LIST))
OBJS_VEC			:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJS_VEC_LIST))

OWN_DIR				:= $(SOURCES_DIRECTORY)own/
SRCS_OWN_LIST		:= ft_str_starts_ends_with.c\
						ft_realloc.c\
						color.c\
						ft_str_is_int.c\
						ft_powertrim.c\
						ft_isspace.c\
						ft_atoi_l.c\
						ft_get_str_sign.c\
						ft_free_split.c\
						ft_index_of_int.c\
						ft_array_is_sorted.c\
						ft_intarr_bubblesort.c\
						ft_str_is_int_helper.c\
						ft_blank_trim.c\
						ft_char_cnt.c
OBJS_OWN_LIST		:= $(patsubst %.c, %.o, $(SRCS_OWN_LIST))
OBJS_OWN			:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJS_OWN_LIST))

INCLUDE_DIR			:= ./includes/

HEADER_LIST			:= get_next_line.h\
						libft.h
HEADER_FILES		:= $(addprefix $(INCLUDE_DIR), $(HEADER_LIST))

ALL_SRCS_LIST		:= $(SRCS_BONUS_LIST) $(SRCS_GNL_LIST) $(SRCS_MANDATORY_LIST) $(SRCS_MATH_LIST) $(SRCS_OWN_LIST) $(SRCS_VEC_LIST)
OBJECTS_LIST		:= $(patsubst %.c, %.o, $(ALL_SRCS_LIST))
OBJECTS				:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

GNL_BUFFER_FLAG		:= -D BUFFER_SIZE=1000

INCLUDES			:= -I$(INCLUDE_DIR)
CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror -O3 -ggdb -O0 -fstack-protector-all $(GNL_BUFFER_FLAG)
RM					:= rm -rf

LIBC				:= ar rc
LIBR				:= ranlib


.PHONY: all bonus clean fclean re


all: $(NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)
# $(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
$(OBJECTS_DIRECTORY)%.o : $(BONUS_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY)%.o : $(GNL_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY)%.o : $(MANDATORY_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY)%.o : $(MATH_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY)%.o : $(OWN_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY)%.o : $(VEC_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS) $(HEADER_FILES)
	$(LIBC) $(NAME) $(OBJECTS)
	$(LIBR) $(NAME)

bonus: $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(LIBC) $(NAME) $(OBJECTS)
	$(LIBR) $(NAME)

clean:
	$(RM) $(OBJECTS_DIRECTORY)

fclean: clean
	$(RM) $(NAME)

re: fclean all