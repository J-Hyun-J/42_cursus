/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:31:16 by hyjeong           #+#    #+#             */
/*   Updated: 2021/06/21 13:51:24 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
size_t	ft_strcpy(char *dst, const char *src, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t len);
char	*ft_strchr(const char *str, int character);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
void	*ft_memset(void *ptr, int value, size_t num);
void	*ft_memcpy(void *dst, const void *src, size_t num);
void	*ft_memccpy(void *dst, const void *src, int c, size_t num);
void	*ft_memmove(void *dst, const void *src, size_t num);
void	*ft_memchr(const void *ptr, int c, size_t num);
void	ft_bzero(void *ptr, size_t num);
int		ft_memcmp(const void *s1, const void *s2, size_t num);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
int		ft_lstsize(t_list *lst);

#endif
