/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:01:29 by nileempo          #+#    #+#             */
/*   Updated: 2024/10/12 20:45:53 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <fcntl.h>

//PARSING FUNCTIONS
int	check_if_dir(char *file);

//PROTECTED FUNCTIONS
int	protected_open(char *str);


#endif