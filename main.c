/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:59:13 by nileempo          #+#    #+#             */
/*   Updated: 2024/10/12 20:34:02 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3D.h"

int	main(int argc, char **argv)
{
	printf("START main\n");
	printf("argc = %d\n", argc);

	check_if_dir(argv[1]);
	printf("argv = %s", argv[1]);
	return (0);
}
