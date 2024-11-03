/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:38:48 by nileempo          #+#    #+#             */
/*   Updated: 2024/11/03 05:59:38 by nileempo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# ifdef __APPLE__
#  define ESC_KEY	53
#  define W_KEY		13
#  define A_KEY		0
#  define S_KEY		1
#  define D_KEY		2
# elif defined(__LINUX__)
#  define ESC_ESC   65307
#  define W_KEY		119
#  define A_KEY		97
#  define S_KEY		115
#  define D_KEY		100

# endif

#endif