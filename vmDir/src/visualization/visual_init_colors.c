/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_init_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:40:44 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/27 19:40:45 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_visualization.h"

void			init_color_pairs1(void)
{
	init_pair(CR_CL_BLACK_PINK, COLOR_BLACK, COLOR_PINK);
	init_pair(CR_CL_PINK_YELLOW, COLOR_PINK, COLOR_YELLOW);
	init_pair(CR_CL_BLACK_YELLOW, COLOR_BLACK, COLOR_YELLOW);
	init_pair(CR_CL_WWHITE_BLACK, COLOR_WWHITE, COLOR_BLACK);
	init_pair(CR_CL_ORANGE_BLACK, COLOR_ORANGE, COLOR_BLACK);
	init_pair(CR_CL_GREY_BLACK, COLOR_GREY, COLOR_BLACK);
	init_pair(CR_CL_GREEN_BLACK, COLOR_GREEN, COLOR_BLACK);
	init_pair(CR_CL_BLUE_BLACK, COLOR_BLUE, COLOR_BLACK);
	init_pair(CR_CL_RED_BLACK, COLOR_RED, COLOR_BLACK);
	init_pair(CR_CL_CYAN_BLACK, COLOR_CYAN, COLOR_BLACK);
	init_pair(CR_CL_BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);
	init_pair(CR_CL_BLACK_GREEN, COLOR_BLACK, COLOR_GREEN);
	init_pair(CR_CL_BLACK_BLUE, COLOR_BLACK, COLOR_BLUE);
	init_pair(CR_CL_BLACK_RED, COLOR_BLACK, COLOR_RED);
	init_pair(CR_CL_BLACK_CYAN, COLOR_BLACK, COLOR_CYAN);
	init_pair(CR_CL_BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);
	init_pair(CR_CL_BLACK_GREEN, COLOR_BLACK, COLOR_GREEN);
	init_pair(CR_CL_BLACK_BLUE, COLOR_BLACK, COLOR_BLUE);
	init_pair(CR_CL_BLACK_RED, COLOR_BLACK, COLOR_RED);
	init_pair(CR_CL_BLACK_CYAN, COLOR_BLACK, COLOR_CYAN);
	init_pair(CR_CL_WHITE_GREEN, COLOR_WHITE, COLOR_GREEN);
	init_pair(CR_CL_WHITE_BLUE, COLOR_WHITE, COLOR_BLUE);
	init_pair(CR_CL_WHITE_RED, COLOR_WHITE, COLOR_RED);
	init_pair(CR_CL_WHITE_CYAN, COLOR_WHITE, COLOR_CYAN);
}

void			init_color_pairs2(void)
{
	init_pair(CR_CL_WWHITE_GREY, COLOR_WWHITE, COLOR_GREY);
	init_pair(CR_CL_YELLOW_GREY, COLOR_YELLOW, COLOR_GREY);
	init_pair(CR_CL_PINK_GREY, COLOR_PINK, COLOR_GREY);
}

void			init_colors(void)
{
	init_color(COLOR_GREY, 400, 400, 400);
	init_color(COLOR_PINK, 800, 200, 600);
	init_color(COLOR_ORANGE, 1000, 700, 0);
	init_color(COLOR_YELLOW, 1000, 1000, 0);
	init_color(COLOR_WWHITE, 1000, 1000, 1000);
	init_color_pairs1();
	init_color_pairs2();
}
