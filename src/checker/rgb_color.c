/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kawa <sal-kawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:06:15 by sal-kawa          #+#    #+#             */
/*   Updated: 2025/05/07 22:22:33 by sal-kawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <string.h>
// void floor_color(t_map *cub_map)
// {
//     int i;
//     int j;
//     int p;
//     char num[3];

//     p = 0;
//     j = 0;
//     i = 0;
//     while (cub_map->map_two_d[i])
//     {
//         while (cub_map->map_two_d[i][j] == 32)
//             j++;
//         if (cub_map->map_two_d[i][j] == 'F')
//         {
//             j++;
//             while (cub_map->map_two_d[i][j] == 32 || cub_map->map_two_d[i][j] == 9)
//                 j++;
//             while (cub_map->map_two_d[i][j] != 32 && cub_map->map_two_d[i][j] != ',')
//                 num[p++] = cub_map->map_two_d[i][j++];
//             cub_map->floor_color[0] = ft_atoi(num);
//             if (cub_map->floor_color[0] > 255 || cub_map->floor_color[0] < 0)
//             {
//                 printf("\033[1;31mMissed RGB:\033[0m the number [%d]
//                     of Floor not valid 😤\n", cub_map->floor_color[0]);
//                 free_two_d(cub_map->map_two_d);
//                 free(cub_map->map_one_d);
//                 exit(1);
//             }
//             p = 0;
//             while (cub_map->map_two_d[i][j] == 32 && cub_map->map_two_d[i][j] == ',')
//                 j++;
//             while (cub_map->map_two_d[i][j] != 32 && cub_map->map_two_d[i][j] != ',')
//                 num[p++] = cub_map->map_two_d[i][j++];
//             cub_map->floor_color[1] = ft_atoi(num);
//             if (cub_map->floor_color[1] > 255 || cub_map->floor_color[1] < 0)
//             {
//                 printf("\033[1;31mMissed RGB:\033[0m the number [%d]
//                     of Floor not valid 😤\n", cub_map->floor_color[1]);
//                 free_two_d(cub_map->map_two_d);
//                 free(cub_map->map_one_d);
//                 exit(1);
//             }
//             p = 0;
//             while (cub_map->map_two_d[i][j] == 32 && cub_map->map_two_d[i][j] == ',')
//             j++;
//             while (cub_map->map_two_d[i][j] != 32)
//                 num[p++] = cub_map->map_two_d[i][j++];
//             cub_map->floor_color[2] = ft_atoi(num);
//             if (cub_map->floor_color[2] > 255 || cub_map->floor_color[2] < 0)
//             {
//                 printf("\033[1;31mMissed RGB:\033[0m the number [%d]
//                     of Floor not valid 😤\n", cub_map->floor_color[2]);
//                 free_two_d(cub_map->map_two_d);
//                 free(cub_map->map_one_d);
//                 exit(1);
//             }
//             return ;
//         }
//         i++;
//     }
//     printf("\033[1;31mMissed path:\033[0m there is no Floor color 😤\n");
//     free_two_d(cub_map->map_two_d);
//     free(cub_map->map_one_d);
//     exit(1);
// }

// void ceiling_color(t_map *cub_map)
// {
//     int i;
//     int j;
//     int p;
//     char num[3];

//     p = 0;
//     i = 0;
//     while (cub_map->map_two_d[i])
//     {
//         j = 0;
//         while (cub_map->map_two_d[i][j] == 32)
//             j++;
//         if (cub_map->map_two_d[i][j] == 'C')
//         {
//             j++;
//             while (cub_map->map_two_d[i][j] == 32 || cub_map->map_two_d[i][j] == 9)
//                 j++;
//             while (cub_map->map_two_d[i][j] != 32 && cub_map->map_two_d[i][j] != ',')
//                 num[p++] = cub_map->map_two_d[i][j++];
//             cub_map->ceiling_color[0] = ft_atoi(num);
//             if (cub_map->ceiling_color[0] > 255 || cub_map->ceiling_color[0] < 0)
//             {
//                 printf("\033[1;31mMissed RGB:\033[0m the number [%d]
//                     of Ceiling not valid 😤\n", cub_map->ceiling_color[0]);
//                 free_two_d(cub_map->map_two_d);
//                 free(cub_map->map_one_d);
//                 exit(1);
//             }
//             p = 0;
//             while (cub_map->map_two_d[i][j] == 32 && cub_map->map_two_d[i][j] == ',')
//                 j++;
//             while (cub_map->map_two_d[i][j] != 32 && cub_map->map_two_d[i][j] != ',')
//                 num[p++] = cub_map->map_two_d[i][j++];
//             cub_map->ceiling_color[1] = ft_atoi(num);
//             if (cub_map->ceiling_color[1] > 255 || cub_map->ceiling_color[1] < 0)
//             {
//                 printf("\033[1;31mMissed RGB:\033[0m the number [%d]
//                     of Ceiling not valid 😤\n", cub_map->ceiling_color[1]);
//                 free_two_d(cub_map->map_two_d);
//                 free(cub_map->map_one_d);
//                 exit(1);
//             }
//             p = 0;
//             while (cub_map->map_two_d[i][j] == 32 && cub_map->map_two_d[i][j] == ',')
//                 j++;
//             while (cub_map->map_two_d[i][j] != 32)
//                 num[p++] = cub_map->map_two_d[i][j++];
//             cub_map->ceiling_color[2] = ft_atoi(num);
//             if (cub_map->ceiling_color[2] > 255 || cub_map->ceiling_color[2] < 0)
//             {
//                 printf("\033[1;31mMissed RGB:\033[0m the number [%d]
//                     of Ceiling not valid 😤\n", cub_map->ceiling_color[2]);
//                 free_two_d(cub_map->map_two_d);
//                 free(cub_map->map_one_d);
//                 exit(1);
//             }
//             return ;
//         }
//         i++;
//     }
//     printf("\033[1;31mMissed path:\033[0m there is no ceil color 😤\n");
//     free_two_d(cub_map->map_two_d);
//     free(cub_map->map_one_d);
//     exit(1);
// }

char **split_rgb(char *s)
{
    char **rgb;
    char *dup;
    char *tok;
    int i;

    if (!s || !*s) // فحص المدخلات
        return NULL;

    dup = ft_strdup(s);
    if (!dup)
        return NULL;

    rgb = malloc(sizeof(char *) * 4);
    if (!rgb)
        return (free(dup), NULL);
    
    // تهيئة جميع العناصر بـ NULL
    for (int k = 0; k < 4; k++)
        rgb[k] = NULL;

    i = 0;
    tok = strtok(dup, ",");
    while (tok && i < 3)
    {
        rgb[i] = ft_strtrim(tok, " \t");
        if (!rgb[i])
        {
            free(dup);
            free_two_d(rgb);
            return NULL;
        }
        i++;
        tok = strtok(NULL, ",");
    }
    free(dup);

    // فحص وجود 3 قيم فقط
    if (i != 3 || tok != NULL)
    {
        free_two_d(rgb);
        return NULL;
    }

    rgb[3] = NULL;
    return rgb;
}


int	is_valid_rgb(char **rgb)
{
	char	*endp;
	long	v;
	int		i;

	i = 0;
	while (i < 3)
	{
		if (!rgb[i] || !*rgb[i])
			return (0);
		v = strtol(rgb[i], &endp, 10);
		if (*endp || v < 0 || v > 255)
			return (0);
		i++;
	}
	return (1);
}

void floor_color(t_all_struct *cub_map)
{
    char *line;
    char **rgb;
    int i = -1;

    while (cub_map->map.map_two_d[++i])
    {
        line = ft_strtrim(cub_map->map.map_two_d[i], " \t");
        if (!line)
			continue;
        if (line[0] == 'F' && line[1] == ' ')
        {
            rgb = split_rgb(line + 2);
            free(line);
            
            if (!rgb || !is_valid_rgb(rgb))
            {
                free_two_d(rgb);
                printf("Invalid floor color format");
				exit (1);
			}

            for (int j = 0; j < 3; j++)
                cub_map->map.floor_color[j] = atoi(rgb[j]);
            
            free_two_d(rgb);
            return;
        }
        free(line);
    }
    printf("Missing floor color (F)");
	exit (1);
}

void	ceiling_color(t_all_struct *cub_map)
{
    char *line;
    char **rgb;
    int i = -1;

    while (cub_map->map.map_two_d[++i])
    {
        line = ft_strtrim(cub_map->map.map_two_d[i], " \t");
        if (!line)
			continue;
        if (line[0] == 'C' && line[1] == ' ')
        {
            rgb = split_rgb(line + 2);
            free(line);
            
            if (!rgb || !is_valid_rgb(rgb))
            {
                free_two_d(rgb);
                printf("Invalid ceil color format");
				exit (1);
			}

            for (int j = 0; j < 3; j++)
                cub_map->map.ceiling_color[j] = atoi(rgb[j]);
            
            free_two_d(rgb);
            return;
        }
        free(line);
    }
    printf("Missing floor color (C)");
	exit (1);
}

