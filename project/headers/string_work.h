#ifndef STRING_WORK_H
# define STRING_WORK_H

#include "unistd.h"

int		strcmp_back(char *str, char *str2, unsigned int n);

char	*ft_strchr(const char *src, int symbol);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *src, int size);
char	*ft_substr(char const *s, unsigned int start, int len);
char	*del_symbl(char *str, char *symbl);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_strjoin(const char *s1, const char *s2);

int		ft_strslen(char **str);
int		ft_strlen(const char *str);
int		count_worlds(char *str);
int		is_digit(char symb);
int		ft_strcmp(const char *s1, const char *s2);
int		count_symb(char *str, char c);
int		ft_atoi(char *str);
int		str_is_digit(char *str);

void	*free_strings(char **strs);
void	free_string(char **str);
void	*ft_bzero(void *b, size_t len);

#endif