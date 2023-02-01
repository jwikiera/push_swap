/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:46:56 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/11 13:36:27 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# define PI	3.14159265358979323846264338327950288
# define HALFPI 1.57079632679489661923132169163975144

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *str, char sep);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/* lists */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *node, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* more own utils */
int			count_words(char const *str, char sep);
int			ft_str_startswith(const char *str, const char *needle);
int			ft_str_endswith(const char *str, const char *needle);
void		*ft_realloc_gnl(void *src, size_t new_len);
int			*ft_realloc_intarr(int *src, size_t arr_size, size_t new_size);
int			**ft_realloc_int2darr(int **src, size_t elem_size,
				size_t arr_size, size_t new_size);
char		*ft_realloc_chararr(char *src, size_t arr_size, size_t new_size);
int			ft_str_is_int(const char *str, int allow_double_signs);
char		*ft_powertrim(const char *str, const char *set);
int			ft_isspace(char c);
long		ft_atoi_l(const char *nptr);
int			ft_get_str_sign(const char *str);
void		ft_free_split(char **split_res, size_t size);
int			ft_index_of_int(const int *arr, int size, int target);
int			ft_array_is_sorted(const int *arr, size_t len);
int			*ft_intarr_bubblesort(const int *arr, size_t len);
char		*ft_blank_trim(const char *str);
int			str_has_multiple_signs(const char *str);
int			ft_has_syms_after_nums(const char *str);
size_t		ft_char_cnt(const char *haystack, char needle);

/* math */
int			ft_min_int(int a, int b);
int			ft_max_int(int a, int b);
int			ft_abs_int(int a);

float		ft_min_float(float a, float b);
float		ft_max_float(float a, float b);
float		ft_abs_float(float a);

double		ft_min_double(double a, double b);
double		ft_max_double(double a, double b);
double		ft_abs_double(double a);

double		cos_approx(double angle);
double		sin_approx(double angle);
double		tan_approx(double angle);
double		deg_to_rad(double angle);

/* minilibx color */
int			argb_to_int(int a, int r, int g, int b);
int			get_a(int argb);
int			get_r(int argb);
int			get_g(int argb);
int			get_b(int argb);

/* vector */
typedef struct s_vec2d
{
	int	x;
	int	y;
}	t_vec2d;

typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;
}	t_vec3d;

typedef struct s_matrix3d
{
	t_vec3d	*v1;
	t_vec3d	*v2;
	t_vec3d	*v3;
}	t_matrix3d;

typedef struct s_line3d
{
	t_vec3d	*p1;
	t_vec3d	*p2;
	t_vec3d	*v1;
}	t_line3d;

typedef struct s_plane3d
{
	t_vec3d	*p1;
	t_vec3d	*p2;
	t_vec3d	*p3;
	t_vec3d	*v1;
	t_vec3d	*v2;
}	t_plane3d;

enum e_projection {orthogonal = 0, perspective = 1};

typedef struct s_screen_info
{
	int					width;
	int					height;
	double				eye_z;
	t_matrix3d			*rotation_matrix;
	t_vec3d				*rotation_center;
	int					rotation_speed;
	int					screen_depth;
	t_plane3d			*screen_plane;
	int					background_color;
	int					pos_x;
	int					pos_y;
	int					pos_z;
	int					mov_speed;
	int					zoom_speed;
	enum e_projection	projection;
}	t_screen_info;

t_vec2d		*new_vect2d(double x, double y);

double		determinant(t_vec3d *v1, t_vec3d *v2, t_vec3d *v3);
t_vec3d		*solve_general(t_vec3d *v1, t_vec3d *v2, t_vec3d *v3,
				t_vec3d *v_sol);

enum e_rotation {axis_x = 0, axis_y = 1, axis_z = 2};
t_matrix3d	*get_rotation_matrix(double angle,
				enum e_rotation axis, int is_rad);
void		add_angle_to_rotation_matrix(t_matrix3d *matrix, double angle,
				enum e_rotation axis, int is_rad);

t_matrix3d	*new_matrix(t_vec3d *v1, t_vec3d *v2, t_vec3d *v3);
void		*free_matrix3d(t_matrix3d *m);
int			valid_matrix(t_matrix3d *m);
t_vec3d		*matrix_mult_vec(t_matrix3d *matrix, t_vec3d *vec);
t_matrix3d	*matrix_mult(t_matrix3d *m1, t_matrix3d *m2);

t_line3d	*line_from_points(t_vec3d *p1, t_vec3d *p2);
t_vec3d		*line_plane_intersect3d(t_line3d *line, t_plane3d *plane);
t_line3d	*line_from_point_and_vec(t_vec3d *p, t_vec3d *d);
void		free_line3d(t_line3d *line3d);

t_plane3d	*plane_from_points(t_vec3d *p1, t_vec3d *p2, t_vec3d *p3);
t_plane3d	*plane_from_point_and_vecs(t_vec3d *p, t_vec3d *u, t_vec3d *v);
void		free_plane3d(t_plane3d *plane3d);

t_vec3d		*new_vect3d(double x, double y, double z);
void		*free_vectors(t_vec3d *v1, t_vec3d *v2, t_vec3d *v3, t_vec3d *v4);
t_vec3d		*vec_add(t_vec3d *v1, t_vec3d *v2);
void		add_vec_inplace(t_vec3d *addee, t_vec3d *added);
void		sub_vec_inplace(t_vec3d *substractee, t_vec3d *substracted);
t_vec3d		*vec_sub(t_vec3d *v1, t_vec3d *v2);
t_vec3d		*vec_scale(t_vec3d *v, double scalar);
void		scale_vec_inplace(t_vec3d *v, double scalar);
t_vec3d		*vec_invert(t_vec3d *v);
void		invert_vec_inplace(t_vec3d *v);

t_vec3d		*cross(t_vec3d *v1, t_vec3d *v2);

t_vec3d		*apply_rotation_matrix_to_point(t_vec3d *point,
				t_screen_info *screen_info);
t_vec3d		*project_perspective(t_vec3d *point, t_plane3d *plane,
				t_screen_info *screen_info);
t_vec3d		*project_orthogonal(t_vec3d *point, t_plane3d *plane,
				t_screen_info *screen_info);

#endif
