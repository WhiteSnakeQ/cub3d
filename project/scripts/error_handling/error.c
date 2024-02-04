#include "../../headers/errors.h"

int	error_message(char *message)
{
	return (ft_printf(2, "Error: %s", message), 1);
}
