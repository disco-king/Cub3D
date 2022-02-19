/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:39:00 by fmalphit          #+#    #+#             */
/*   Updated: 2022/02/19 12:16:06 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define MAP ".cub"
# define TEXT ".xpm"

typedef struct s_params{
	int		c_col;
	int		f_col;
	int		height;
	int		width;
	char	*no_addr;
	char	*we_addr;
	char	*so_addr;
	char	*ea_addr;
}	t_params;

int		check_name(char *name, int map);
int		check_params(t_params *params);
int		parse_color(char *color);
int		add_param(char **arr, t_params *params);
int		get_params(t_params *params, int fd);
void	init_params(t_params *params);

int		get_max_len(t_list *lst);
int		check_line(const char *line);
int		line_empty(char *line);

int		check_column(t_list *lst, int i);
int		column_empty(t_list *lst, int i);
int		check_lst(t_list *lst);

char	**lst_to_arr(t_list *lst, int *height, int *width);
char	*add_spaces(char *src, int max);

int		get_next_line(int fd, char **line);
char	**get_map(int fd, int *map_height, int *map_width);
int		get_line_lst(t_list **lines, int fd);
int		get_value(char c, int *character);

#endif