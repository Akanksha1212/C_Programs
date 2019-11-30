/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:51:41 by lroux             #+#    #+#             */
/*   Updated: 2019/10/27 23:13:53 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/*
** Implementation of size-dependent types in C.
*/
typedef signed char	t_s8;
typedef unsigned char	t_u8;

typedef signed short	t_s16;
typedef unsigned short	t_u16;

typedef signed int	t_s32;
typedef unsigned int	t_u32;

typedef signed long long int	t_s64;
typedef unsigned long long int	t_u64;

typedef unsigned char	t_byte;

/*
** Implementation of boolean type in C,
** protected for inclusion of <stdbool.h>
*/
# ifdef __STDBOOL_H
#  undef false
#  undef true
# endif

typedef enum {
	false = 0,
	true = 1
}	t_bool;

typedef enum {
	success = 0,
	failure = 1
}	t_status;

#endif
