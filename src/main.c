/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 17:10:55 by dritsema      #+#    #+#                 */
/*   Updated: 2022/09/03 14:49:18 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		len;
	pid_t	id;
	char *const	env[] = {NULL};

	if (argc > 1)
	{
		len = ft_strlen(argv[1]);
		write(1, argv[1], len);
		write(1, "\n", 1);
		id = fork();
		if (id == 0)
		{
			ft_printf("I am child\n");
		}
		execve("/bin/bash", argv, env);
	}
	return (0);
}
