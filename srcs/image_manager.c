/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:30:23 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 15:09:56 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.data
			+ (y * img.size_line) + (x * img.bpp / 8))));
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int) 0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.width && y < img.height)
	{
		dst = img.data + (y * img.size_line + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

void	put_img_to_img(t_img dst, t_img src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src.width)
	{
		j = 0;
		while (j < src.height)
		{
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}
