/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 17:10:55 by dritsema      #+#    #+#                 */
/*   Updated: 2022/08/30 17:54:46 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		len;
	char *const	env[] = {"hoi\0"};

	if (argc > 1)
	{
		len = ft_strlen(argv[1]);
		write(1, argv[1], len);
		write(1, "\n", 1);
		execve("ls", &argv[1], env);
	}
	return (0);
}
