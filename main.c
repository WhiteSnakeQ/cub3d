#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	void	*data = mlx_init();
	free(data);
	printf("lol");
	return (0);
}