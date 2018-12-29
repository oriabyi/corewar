/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_visualization.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 11:34:34 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/29 11:34:35 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_COREWAR_VISUALIZATION_H
# define COREWAR_COREWAR_VISUALIZATION_H

# include "corewar_header.h"

# define NCUR						core->ncur

# define SHOW_CHANGED_CYCLES		50
# define SHOW_LIVE_CYCLES			10

# define SCORE_WIN_HEIGHT			66
# define SCORE_WIN_WIDTH			70
# define MEM_WIN_HEIGHT				68
# define MEM_WIN_WIDTH				195

# define COLOR_PINK					122
# define COLOR_ORANGE				123
# define COLOR_WWHITE				124
# define COLOR_GREY					125

# define CR_CL_GREEN_BLACK			2
# define CR_CL_BLUE_BLACK			3
# define CR_CL_RED_BLACK			4
# define CR_CL_CYAN_BLACK			5

# define CR_CL_BLACK_WHITE			6
# define CR_CL_BLACK_GREEN			7
# define CR_CL_BLACK_BLUE			8
# define CR_CL_BLACK_RED			9
# define CR_CL_BLACK_CYAN			10

# define CR_CL_WHITE_GREEN			12
# define CR_CL_WHITE_BLUE			13
# define CR_CL_WHITE_RED			14
# define CR_CL_WHITE_CYAN			15

# define CR_CL_ORANGE_BLACK			16
# define CR_CL_WWHITE_BLACK			17
# define CR_CL_GREY_BLACK			18
# define CR_CL_BLACK_YELLOW			19
# define CR_CL_BLACK_PINK			20
# define CR_CL_PINK_YELLOW			21
# define CR_CL_WWHITE_GREY			22
# define CR_CL_YELLOW_GREY			23
# define CR_CL_PINK_GREY			24

# define EXIT						-1
# define MAX_SPEED					100
# define MIN_SPEED					0
# define SPEED_STEP					5
# define PAUSE_BUTTON				' '
# define NEXT_CYCLE_BUTTON			's'
# define DELETE_BUTTON				127
# define ENTER_BUTTON				10
# define SPEED_PLUS_BUTTONS(x)		(x == 'e' || x == 261)
# define SPEED_MINUS_BUTTONS(x)		(x == 'q' || x == 260)
# define MENU_DOWN_BUTTON			259
# define MENU_UP_BUTTON				258
# define VISUAL_OFF					27

# define NOONE						0
# define FIRST_BOT					1
# define SECOND_BOT					2
# define THIRD_BOT					3
# define FOURTH_BOT					4
# define FOLLOW_CARRIAGE			5
# define FOLLOW_FIELD				6

void								init_colors(void);
void								init_time(t_corewar *core);
void								set_next_field(t_corewar *core);
void								set_prev_field(t_corewar *core);
void								alive_view(WINDOW *win, int id);
void								simple_print(WINDOW *win, int id);
void								altered_view(WINDOW *win, int id);
void								carriage_print(WINDOW *win, int id);
int									draw_menu(t_corewar *core, int pos_y);
int									get_button(t_corewar *core, int cycle);
int									uppend_input_field(char *field, char n);
void								fill_input_field_with_zeros(char *field);
int									del_last_letter_input_field(char *field);
void								draw_score_window(t_corewar *core,
																	int cycle);
void								draw_memory_window(t_corewar *core,
																	int cycle);
void								follow_view(WINDOW *win,
														t_ncurses ncur, int i);

#endif
