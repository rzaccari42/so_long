/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:42:28 by rzaccari          #+#    #+#             */
/*   Updated: 2023/01/25 21:34:59 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

/*
** LINKED LISTS STRUCTURE DEFINITION
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

/*
** FT_PRINTF STRUCTURE DEFINITION
*/
typedef struct input
{
	va_list	arguments;
	int		char_count;
}	t_input;

/*
** MANDATORY LIBFT FUNCTIONS
*/
int		ft_atoi(const char *nptr);
void	ft_bzero(void *str, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int nbr);
void	*ft_memchr(const void *str, int c, size_t len);
int		ft_memcmp(const void *str1, const void *str2, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *ptr, int val, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *str, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
char	*ft_strjoin(const char *str1, const char *str2);
size_t	ft_strlcat(char *dst, const char *src, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strndup(char *str, int start, int end);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(const char *str, const char *charset);
char	*ft_substr(const char *str, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*
** BONUS LIBFT FUNCTIONS
*/
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
** FT_PRINTF FUNCTIONS
*/
int		ft_printf(const char *input, ...);
void	format(t_input *args, char c);
void	format_c(t_input *args);
void	format_s(t_input *args);
void	format_p(t_input *args);
void	format_d(t_input *args);
void	format_i(t_input *args);
void	format_u(t_input *args);
void	format_x_lower(t_input *args);
void	format_x_upper(t_input *args);
void	format_pc(t_input *args);
int		nbrlen_dec(int nbr);
int		nbrlen_unsigned(unsigned int nbr);
int		nbrlen_hex(unsigned int nbr);
int		nbrlen_hex_p(unsigned long long nbr);
char	*ft_itoa(int nbr);
char	*itoa_unsigned(unsigned int nbr);
char	*itoa_hex_lower(unsigned int nbr);
char	*itoa_hex_upper(unsigned int nbr);
char	*itoa_hex_p(unsigned long long nbr);

/*
** GET_NEXT_LINE FUNCTIONS
*/
char	*get_next_line(int fd);
char	*get_line(char **str, int fd);
int		has_line(char *str);
char	*ft_gnl_strndup(char *str, int start, int end);
char	*ft_gnl_strjoin(char *str1, char *str2);
int		ft_gnl_strlen(char *str);

#endif
