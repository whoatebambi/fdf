/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:33:43 by fcouserg          #+#    #+#             */
/*   Updated: 2023/11/16 11:18:50 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// COLOR
// parameter has an integer type. The displayed color needs to be encoded
// in this integer, following a defined scheme. All displayable colors
// can be split in 3 basic colors: red, green and blue. Three associated
// values, in the 0-255 range, represent how much of each color is mixed up
// to create the original color. Theses three values must be set inside the
// integer to display the right color. The three least significant bytes of
// this integer are filled as shown in the picture below:

//         | 0 | R | G | B |   color integer
//         +---+---+---+---+

// While filling the integer, make sure you avoid endian problems. Remember
// that the "blue" byte should always be the least significant one.
