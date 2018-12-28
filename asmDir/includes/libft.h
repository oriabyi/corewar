/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:56:36 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/23 17:15:06 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/syscall.h>
# include <fcntl.h>
# include <sys/param.h>
# include <stdarg.h>
# include <stddef.h>
# include <locale.h>
# include <limits.h>

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_node
{
	struct s_node		*h;
	struct s_node		*l;
	struct s_node		*r;
	struct s_node		*u;
	struct s_node		*d;
	int					size;
	char				*sign;
}						t_node;

int						g_printed;

typedef struct			s_elem
{
	char				flags[10];
	int					width;
	int					precision;
	int					length;
	int					type;
}						t_elem;

typedef union			u_data
{
	char				c;
	wchar_t				wc;
	wchar_t				*ws;
	char				*s;
	signed long long	lli;
	unsigned long long	llu;
	intmax_t			ji;
	uintmax_t			ju;
}						t_data;

int						ft_printf(const char *format, ...);
int						ft_is_flag(char c);
int						ft_is_length(char c);
int						ft_is_num(char *str);
int						ft_is_type(char c);
void					ft_init(t_elem **el);
void					ft_getflags(char **s, t_elem **el);
void					ft_getwidth(char **s, t_elem **el, va_list *args);
void					ft_getprecision(char **s, t_elem **el, va_list *args);
void					ft_getlength(char **s, t_elem **el);
void					ft_gettype(char **s, t_elem *el);
int						ft_shorten_w(t_elem *el, t_data *data, int n, int *w);
void					ft_lengthen_r(t_elem *el, t_data *data, int n);
void					ft_lengthen_l(t_elem *el, t_data *data, int n);
void					ft_prepare_int(t_elem *el, t_data *data);
void					ft_get_type_int(t_elem *el, va_list *args);
long long				ft_unlen(unsigned long long n);
long long				ft_unlen(unsigned long long n);
void					ft_lengthen_ru(t_elem *el, t_data *data, int n);
void					ft_lengthen_lu(t_elem *el, t_data *data, int n);
void					ft_prepare_uint(t_elem *el, t_data *data);
char					*ft_zero_line(void);
int						ft_fix_zero(t_elem *el);
int						ft_prepare_int_spec2(t_elem *el, t_data *data, int n,
						int size);
void					ft_prepare_int_spec(t_elem *el, t_data *data);
void					ft_get_type_int_spec(t_elem *el, va_list *args);
void					ft_prepare_chr(t_elem *el, t_data *data);
void					ft_get_type_chr(t_elem *el, va_list *args);
void					ft_get_sign(t_elem *el);
void					ft_get_undef_type(t_elem *el);
void					ft_get_type_ptr(t_elem *el, va_list *args);
void					ft_correct_bywchar(t_elem *el, t_data *data);
void					ft_print_str(t_elem *el, t_data *data);
void					ft_get_type_str(t_elem *el, va_list *args);
void					ft_correct_prec(t_elem *el, t_data *data);
void					ft_prepare_flags_int(t_elem *el, t_data *data);
long long				ft_mod(signed long long a);
void					ft_fix_old_style(t_elem *el);
void					ft_try_print(t_elem *el, va_list *args);
void					ft_getcomnd(const char *format, t_elem *el,
						va_list *args);
char					*ft_itoa_base(long long value, int base);
long long				ft_nlen(long long n);
char					*ft_putcstr(char *str, char c);
void					ft_putunbr(unsigned long long n);
int						ft_putstr_utf8(const wchar_t *str);
size_t					ft_strllen(const wchar_t *str);
void					ft_putchar(int c);
void					ft_putchar_utf8(int c);
void					ft_putchar_fd(int c, int fd);
int						ft_putstr(const char *str);
void					ft_putstr_fd(char const *s, int fd);
void					*ft_memset(void *dest, int c, size_t n);
void					ft_bzero(void *b, size_t length);
void					*ft_memcpy(void *dest, const void *src, size_t count);
void					*ft_memccpy(void *dest, const void *src, int c,
						size_t n);
void					*ft_memmove(void *dest, const void *src, size_t count);
void					*ft_memchr(const void *src, int c, size_t length);
int						ft_memcmp(const void *arr1, const void *arr2, size_t n);
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *src);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t count);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t count);
size_t					ft_strlcat(char *s1, const char *s2, size_t size);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2,
						size_t count);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strnstr(const char *s1, const char *s2, size_t len);
char					*ft_strchr(const char *s1, int c);
char					*ft_strrchr(const char *s1, int c);
int						ft_atoi(const char *s);
long long				ft_atoll(const char *s);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
						char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strjoin_del(char *s1, char *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					**ft_strsplit_spec(char const *s, char *c, char end);
char					*ft_itoa(int n);
void					ft_putendl(char const *s);
void					ft_putnbr(signed long long n);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
int						gnl(int fd, char **line);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_dlcreate_root(t_node **root,
						unsigned short grid_size, int counter);
void					ft_dlcreate_header(t_node **root, char *head_name);
t_node					*ft_dlcreate_link(t_node *last, t_node *header,
						char *link_name);
void					ft_dlcover(t_node **root, t_node *header);
void					ft_dluncover(t_node **root, t_node *header);
void					ft_dldelete_link(t_node **root, t_node *link);
void					ft_free_line(char **line);
void					ft_free_arr(char **arr);
int						ft_arrsize(char **arr);
char					**ft_arrjoin(char **arr1, char **arr2);
char					**ft_arrjoin_del(char **arr1, char **arr2);
int						ft_str_to_hex(char *c, int fd);
#endif
