/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalah <zsalah@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:52:09 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/26 17:45:42 by zsalah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	compute_wall_data(t_cast *c, t_ray *r, t_all_struct *cub)
{
	compute_wall_diff_and_distance(c, r, cub);
	c->height = (BLOCK / c->perp_dist) * (HEIGHT / 2.0f);
	c->height = fminf(fmaxf(c->height, 1.0f), HEIGHT);
	c->start_y = fmaxf(0, (HEIGHT - (int)c->height) / 2);
	c->end_y = fminf(HEIGHT, c->start_y + (int)c->height);
}

void	select_texture(t_cast *c, t_ray *r, t_all_struct *cub)
{
	if (c->side == 0 && r->dir_x > 0)
		c->tex = &cub->game.east;
	else if (c->side == 0)
		c->tex = &cub->game.west;
	else if (c->side == 1 && r->dir_y > 0)
		c->tex = &cub->game.south;
	else
		c->tex = &cub->game.north;
	if (c->side == 0)
		c->wall_x = fmodf((cub->player.y + c->distance * r->dir_y) / BLOCK,
				1.0f);
	else
		c->wall_x = fmodf((cub->player.x + c->distance * r->dir_x) / BLOCK,
				1.0f);
	if (c->wall_x < 0)
		c->wall_x += 1.0f;
	c->tex_x = (int)(c->wall_x * c->tex->width);
	if ((c->side == 0 && r->dir_x > 0) || (c->side == 1 && r->dir_y < 0))
		c->tex_x = c->tex->width - c->tex_x - 1;
	c->tex_x = fminf(fmaxf(c->tex_x, 0), c->tex->width - 1);
}

void	compute_tex_data(t_cast *c)
{
	float	wall_height;

	wall_height = (BLOCK / c->perp_dist) * (HEIGHT / 2.0f);
	c->step = (float)c->tex->height / wall_height;
	c->tex_pos = ((c->start_y - HEIGHT / 2 + wall_height / 2)) * c->step;
}

void	render_wall(t_all_struct *cub, t_cast *c, int i)
{
	int			y;
	uint32_t	color;

	y = c->start_y;
	while (y < c->end_y)
	{
		c->tex_y = (int)c->tex_pos;
		c->tex_y = fminf(fmaxf(c->tex_y, 0), c->tex->height - 1);
		color = *(uint32_t *)(c->tex->texture->pixels + (c->tex_y
					* c->tex->width + c->tex_x) * 4);
		if ((color & 0xFF) != 0)
			put_pixel(cub->game.img, i, y, color);
		c->tex_pos += c->step;
		y++;
	}
}

void	draw_line(t_all_struct *cub_map, float ray_angle, int i)
{
	t_ray	ray;
	t_cast	cast;

	init_ray(&ray, cub_map, ray_angle);
	init_deltas(&cast, &ray);
	init_steps(&cast, &ray);
	perform_dda(&cast, cub_map);
	if (!check_hit(&cast, cub_map))
		return ;
	compute_wall_data(&cast, &ray, cub_map);
	select_texture(&cast, &ray, cub_map);
	compute_tex_data(&cast);
	render_wall(cub_map, &cast, i);
}
