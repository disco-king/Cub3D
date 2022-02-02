#include "parse.h"

int line_empty(char *line)
{
	if(!line)
		return(1);
	while(*line)
	{
		if(*line != ' ')
			return(0);
		line++;
	}
	return(1);
}

int get_value(char c, int *character)
{
	if(c == ' ' || c == 0)
		return(2);
	if(c == '1')
		return(1);
	if(c == '0')
		return(0);
	if(c == 'N' || c == 'S'
		|| c == 'W' || c == 'E')
		if(!character || *character == 0)
		{
			if(character)
				*character = 1;
			return(0);
		}
	return(-1);
}

int check_line(const char *line)
{
	static int character;
	int flag;
	int buff;

	flag = 2;
	while(*line)
	{
		buff = get_value(*line, &character);
		if(buff < 0 || flag - buff < -1
			|| flag - buff > 1)
			return(1);
		flag = buff;
		line++;
	}
	if(flag <= 0)
		return(1);
	return(0);
}

int check_column(t_list *lst, int i)
{
	int flag;
	int buff;

	flag = 2;
	while(lst)
	{
		if(i > ft_strlen(lst->content))
			buff = 2;
		else
			buff = get_value(lst->content[i], NULL);
		if(buff < 0 || flag - buff < -1
			|| flag - buff > 1)
			return(1);
		flag = buff;
		lst = lst->next;
	}
	if(flag <= 0)
		return(1);
	return(0);
}

int column_empty(t_list *lst, int i)
{
	while(lst)
	{
		if(i < ft_strlen(lst->content)
			&& lst->content[i] != ' ')
			return(0);
		lst = lst->next;
	}
	return(1);
}

int get_max_len(t_list *lst)
{
	int max;
	int buff;

	max = 0;
	while(lst)
	{
		buff = ft_strlen(lst->content);
		if(buff > max)
			max = buff;
		lst = lst->next;
	}
	return(max);
}

int check_lst(t_list *lst)
{
	int max_len;
	int empty;
	int i;

	i = 0;
	empty = 0;
	max_len = get_max_len(lst);
	while(i < max_len)
	{
		if(!column_empty(lst, i))
		{
			if(check_column(lst, i) || empty == 2)
				return(1);
			empty = 1;
		}
		else if (empty)
			empty++;
		i++;
	}
	return(0);
}

int get_line_lst(t_list **lines, int fd)
{
	int res;
	int empty = 0;
	char *line;

	res = get_next_line(fd, &line);
	while (res || line)
	{
		if(!line_empty(line))
		{
			if(check_line(line) || empty == 2)
				break ;
			empty = 1;
			ft_lstadd_back(lines, ft_lstnew(ft_strdup(line)));
		}
		else if(empty)
			empty++;
		free(line);
		res = get_next_line(fd, &line);
	}
	if(!res && !line)
		return(0);
	free(line);
	return(1);
}

char *add_spaces(char *src, int max)
{
	int len = ft_strlen(src);
	char *ret = malloc((sizeof(char)) * max + 1);
	ft_memcpy(ret, src, len);
	ft_memset(&(ret[len]), 32, max - len);
	ret[max] = 0;
	return(ret);
}

char **lst_to_arr(t_list *lst, int *height, int *width)
{
	int i = 0;
	*width = get_max_len(lst);
	*height = ft_lstsize(lst);

	char **ret = malloc(sizeof(char *) * (*height + 1));
	while(lst)
	{
		if(ft_strlen(lst->content) < *width)
			ret[i] = add_spaces(lst->content, *width);
		else
			ret[i] = ft_strdup(lst->content);
		if(!ret[i])
			return(free_all(ret));
		i++;
		lst = lst->next;
	}
	ret[i] = NULL;
	return(ret);
}

char **check_map(int fd, int *map_height, int *map_width)
{
	char **map;
	t_list *map_lines;

	map_lines = NULL;
	if(get_line_lst(&map_lines, fd)
		|| check_lst(map_lines))
	{
		ft_lstfree(map_lines);
		return(NULL);
	}
	map = lst_to_arr(map_lines, map_height, map_width);
	ft_lstfree(map_lines);
	return(map);
}