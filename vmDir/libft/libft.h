/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:18:27 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/23 20:17:17 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <zconf.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define MAX_FD 10
# define BUFF_SIZE 10
# define ENDL '\n'
# define END '\0'

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_putchar(int c);
void				ft_putchar_fd(int c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(ssize_t n);
void				ft_putnbr_fd(int n, int fd);
int					ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(char const *s);
char				*ft_itoa(int num);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack, const char *needle,\
	size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c, int code);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_countwords(char *s, char ss);
int					ft_toupper(int c);
char				*ft_strrev(const char *str);
int					ft_wcase(int c);
char				*ft_strcapitalize(char *s);
void				ft_swap(ssize_t *a, ssize_t *b);
void				ft_printbits(unsigned long long num);
int					ft_numodgt(long long n);
int					ft_numows(char const *s, char c);
int					ft_printhex(size_t num, int base, int counter, char x);
int					ft_strpos(const char *s, int c);
int					ft_sqrt(unsigned int num);
char				*ft_margin(char *pen, char *apple);
short int			ft_pwrbase(ssize_t num, int base);
int					ft_csymb(char *s, char c);
char				*ft_multjoin(int field, ...);
int					ft_mstrcmp(int field, ...);
int					ft_strprint(char *s);
char				*ft_rfstr(char *what, char *where, char *with, int code);
int					gnl(int const fd, char **line);
char				**ft_split_wsps(const char *str, char c);
int					ft_iswsps(const char *str);
void				ft_setnum(void **arr, int len, int num);
int					ft_pmult_fd(int fd, int count, ...);
int					ft_check_iarr(int **arr, int x, int y, int num);
char				*ft_multjoinfr(int field, ...);
int					free_str_return_int(char **str, int ret);
int					are_nums(char *s);
int					lgnl(int fd, char **line, size_t length);
char				*append_char(char **s, char c);
unsigned			ft_ahtoi(const char *string);
int					raise_to_power(int num, int power);
char				get_num_in_hex(int num);
char				*get_hex_by_int_byte(size_t num, size_t len);
char				**int_to_char_hex(size_t num, size_t len);
void				free_char_matrix(char **str);
char				*ft_multcat(int field, char *dest, ...);
int					count_chars(const char *string, char letter,
												int in_row, int position);
int					check_got_num(char *string, ssize_t num, int precision);
int					are_nums(char *s);

#endif
