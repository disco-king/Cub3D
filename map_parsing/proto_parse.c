#include "parse.h"



int main(int argc, char const *argv[])
{
	t_params params;
	char **map;

	if(argc == 1)
		return(1);
	init_params(&params);
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		printf("Fd error!\n");
		return(1);
	}
	if(get_params(&params, fd))
	{
		printf("Params invalid!\n");
		return(1);
	}

	printf("north path %s\nwest path %s\nsouth path %s\neast path %s\n",
		params.no_addr, params.we_addr, params.so_addr, params.ea_addr);
	printf("floor %d\nceiling %d\n", params.f_col, params.c_col);

	map = check_map(fd, &(params.height), &(params.width));
	if(!map)
	{
		printf("Map invalid!\n");
		exit(1);
	}
	printf("height %d width %d\n", params.height, params.width);
	char **buff = map;
	while (*buff)
	{
		printf("%s$\n", *buff);
		buff++;
	}
	
	exit(0);
}