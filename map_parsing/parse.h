#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include "./libft/libft.h"

typedef struct s_params{
	int c_col;//ceiling color
	int f_col;//floor color
	char *no_addr;
	char *we_addr;
	char *so_addr;
	char *ea_addr;
}	t_params;

int get_next_line(int fd, char **line);
int	ft_strncmp(const void *s1, const void *s2, size_t n);
void init_params(t_params *params);
int get_params(t_params *params, int fd);
int add_param(char **arr, t_params *params);
int parse_color(char *color);
int check_empty(char *line);
char **check_map(int fd);
int get_line_lst(t_list **lines, int fd);
int check_lst(t_list *lst);
int get_max_len(t_list *lst);
int check_column(t_list *lst, int i);
int check_line(const char *line);
int get_value(char c, int *character);
