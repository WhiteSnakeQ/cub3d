#ifndef STRING_WORK_H
# define STRING_WORK_H

int		strcmp_back(char *str, char *str2, unsigned int n);

char	*ft_strchr(const char *src, int symbol);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *src, int size);
char	*ft_substr(char const *s, unsigned int start, int len);
char	*del_symbl(char *str, char *symbl);

int		ft_strslen(char **str);
int		ft_strlen(const char *str);
int		count_worlds(char *str);
int		is_digit(char symb);

void	*free_strings(char **strs);
void	free_string(char **str);

#endif