#ifndef COREWAR_COREWAR_HEADER_H
#define COREWAR_COREWAR_HEADER_H

#include "../../libft/libft.h"
#include "../../op/op.h"
#include "ncurses.h"
#include "stdio.h"
#include <time.h>

/* 0-4		simple colors
 * 5-9		carriages
 * 10-14	alive
 * 15-19	new moves
*/


/* select defines */
# define ENTER	0xA
# define ESC	0x1B
# define SPC	0x20
# define BKS	0x7F
# define UP		0x415B1B
# define DOWN	0x425B1B
# define LEFT	0x445B1B
# define RIGHT	0x435B1B
# define DEL	0x7E335B1B

/////////////////////////////////////

/*
**	Obaranni bonus multi bots
*/

# define O_BOTS					4


# define NONE_ARG				0

# define T_DIR_TWO_BYTES		2
# define T_DIR_FOUR_BYTES		4

# define SHOW_CHANGED_CYCLES		50

#define NOT_EXPOSED 				0
#define COUNTING_FROM_ONE 			1
#define DIF_ID_BOT__CARRIAGE		4


#define ONE_BYTE		1
#define TWO_BYTES		2
#define THREE_BYTES		3
#define FOUR_BYTES		4

#define EXIT_COMMAND	0

# define ARGUMENT_OF_PROCESS(x) (x + 1)

#define ignat(x, y, z) if (y == 1 && z == 1) return

/*
** Get arguments // check defines
*/

# define GET_FIRST_ARGUMENT(x)		(x >> 6)
# define GET_SECOND_ARGUMENT(x)		((x >> 4) & 3)
# define GET_THIRD_ARGUMENT(x)		((x >> 2) & 3)

# define GET_T_IND_ARG(x) (x ^ 7)
/*
** Bool
*/
# define TRUE	1
# define FALSE	0


#define DIF_BTW_CAR_NOT_CAR		5





# define ERROR	1




# define IDX_MOD_ON		1
# define IDX_MOD_OFF	0


// colors for delete


# define RESET			"\x1b[0m"
# define BLUE			"\x1b[34m"
# define RED			"\x1b[31m"
# define CYAN			"\x1b[36m"
# define GREEN			"\x1b[32m"
# define BLACK			"\x1b[30m"

# define L_GREEN		"\x1b[92m"
# define L_BLUE			"\x1b[94m"
# define L_RED			"\x1b[91m"
# define L_CYAN			"\x1b[96m"

# define BACK_GREEN			"\x1b[42m"

/*
**	Define colors
*/

# define CR_CL_WHITE_BLACK			1
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

# define PAUSE						' '
# define SPEED_PLUS					'e'
# define SPEED_MINUS				'q'
# define VISUAL_OFF					27


# define CR_IS_VIEW_SANE(x)			(x >= 0 && x <= 4)
# define CR_IS_VIEW_CARRIAGE(x)		(x >= 5 && x <= 9)
# define CR_IS_VIEW_ALTERED(x)		(x >= 10 && x <= 14)
# define CR_IS_VIEW_ALIVE(x)		(x >= 15 && x <= 19)

# define DENOTE_CARRIAGE			5
# define DENOTE_ALTERED				10
# define DENOTE_ALIVE				15

/*
**	Define errors
*/

# define MEMORY_ERROR				17
# define BAD_ARGUMENTS				24
# define WRONG_ARGUMENTS			25
# define WRONG_MAGIC_VALUE			26
# define WRONG_PLACE_FOR_FLAGS		27


# define NO_INSTRUCTION				0

# define NOONE						0
# define FIRST_BOT					1
# define SECOND_BOT					2
# define THIRD_BOT					3
# define FOURTH_BOT					4

# define NOONE_CARRIAGE				5
# define FIRST_BOT_CARRIAGE			6
# define SECOND_BOT_CARRIAGE		7
# define THIRD_BOT_CARRIAGE			8
# define FOURTH_BOT_CARRIAGE		9

# define FIRST_BOT_REVERSE			11
# define SECOND_BOT_REVERSE			12
# define THIRD_BOT_REVERSE			13
# define FOURTH_BOT_REVERSE			14

# define FIRST_BOT_BOLD				16
# define SECOND_BOT_BOLD			17
# define THIRD_BOT_BOLD				18
# define FOURTH_BOT_BOLD			19






/*
**	Instructions
*/

# define CW_LIVE					1
# define CW_LD						2
# define CW_ST						3
# define CW_ADD						4
# define CW_SUB						5
# define CW_AND						6
# define CW_OR						7
# define CW_XOR						8
# define CW_ZJMP					9
# define CW_LDI						10
# define CW_STI						11
# define CW_FORK					12
# define CW_LLD						13
# define CW_LLDI					14
# define CW_LFORK					15
# define CW_AFF						16

/*
**	Define cycles
*/

# define CW_LIVE_CYCLES				10
# define CW_LD_CYCLES				5
# define CW_ST_CYCLES				5
# define CW_ADD_CYCLES				10
# define CW_SUB_CYCLES				10
# define CW_AND_CYCLES				6
# define CW_OR_CYCLES				6
# define CW_XOR_CYCLES				6
# define CW_ZJMP_CYCLES				20
# define CW_LDI_CYCLES				25
# define CW_STI_CYCLES				25
# define CW_FORK_CYCLES				800
# define CW_LLD_CYCLES				10
# define CW_LLDI_CYCLES				50
# define CW_LFORK_CYCLES			1000
# define CW_AFF_CYCLES				2

int 				bigmother;
typedef	struct			s_flags
{
	unsigned			visual:1;
	unsigned			h_visual:1;// Рыба
	unsigned			a_visual:5;// Рыба
	unsigned			o_visual:1;// Рыба
	unsigned			s_visual:1;// Рыба
}						t_flags;


typedef struct			s_carriage
{
	int 				cur_pos;
	unsigned 			carry:1;
	unsigned			flag:1;
	unsigned 			alive:1;
	unsigned 			registers[16];
	unsigned 			command:5;
	int 				cycles;

	struct s_carriage	*next;
}						t_carriage;

typedef struct			s_bot
{
	char 				*name;
	char 				*comment;
	unsigned char		*exec_code;
	unsigned			id;
	unsigned			size;
	unsigned 			quant_carriages;
	int 				fd;

	t_carriage			*carriage;
}						t_bot;

typedef struct 		s_carriage_cell t_carriage_cell;

typedef struct			s_ncurses
{
	int 				i;
	int		 			draw_speed;
	int 				pressed_button;
	unsigned 			pause:1;
	WINDOW				*memory_window;
	WINDOW				*score_window;
}						t_ncurses;

struct 			s_carriage_cell
{
	unsigned			bot_id;
	t_carriage_cell		*next;
};

typedef struct			s_cell
{
	char 				val;
	unsigned char		hex[3];
	unsigned			bot_id:5;
	unsigned			sum_acts:5;
	unsigned			time;
}						t_cell;

typedef struct			s_corewar
{
	t_cell				*cell;
	t_ncurses			ncur;
	t_bot				*bots;
	t_flags				flags;
	short 				qua_bots;
}						t_corewar;


/*
** Treatment arguments
*/

int 	check_arguments(t_flags *flags, int ac, char **av);

/*
** Parse
*/

int 	parse(t_corewar *core, char **av);


/*
** Getters
*/

char 	*get_name(int fd);

void	get_exec_code(int fd, unsigned len, unsigned char **exec_code);
char 	*get_comment(int fd);
int 	get_size(int fd);

/*
** Math help for getters
*/

int 	get_num_by_octet_bytes(int fd);
int 	get_old_young_numbers(int num, int base, int *power);
int 				ft_module(int i);

/*
** Clean all
*/

void 	clean_all(t_corewar *core);

/*
** Control work
*/

void 	exit_message(t_corewar *core, int error_code, char *error_message);
void 	check_correctness(t_corewar *core, int check_code);
/*
** Visualization
*/

int 	vs_init(t_corewar *core);
//int 	vs_refresh(t_corewar *core);
int 	vs_end(t_corewar *core);

//my visio
int				draw(t_corewar *core, int cycle);
int 			create_memory_space(t_corewar *core);
void			fill_memory_space(t_bot *bots, t_cell *cell, int qua_bots);


/*
** Math
*/

/*
** Instructions
*/

int 	alive_instruct(t_cell *cell, t_bot *bot);
int 	load_instruct(t_cell *cell, t_bot *bot);
int 	store_instruct(t_cell *cell, t_bot *bot);

// add and sub operations here
int 	add_sub_instructs(t_cell *cell, t_bot *bot);

// all logical operations here
int 	logical_operations(t_cell *cell, t_bot *bot);

int 	jump_if_carry_instruct(t_cell *cell, t_bot *bot);

//	LLDI in LDI
int 	load_index_instruct(t_cell *cell, t_bot *bot);

int 	store_index_instruct(t_cell *cell, t_bot *bot);

//  long fork in fork
int 	fork_instruct(t_cell *cell, t_bot *bot);

int 	long_load_instruct(t_cell *cell, t_bot *bot);
int 	aff_instruct(t_cell *cell, t_bot *bot);

/*
** Check carry
*/

void 	change_carry_if_need(t_bot *bot, int position);

/*
**	Move Carriage
*/

void 	move_carriage(t_cell *cell, t_bot *bot, int step);

/*
** Check args of instruction
*/

int 	check_instruction_args(int argument, int first, int second, int third);

/*
** Get_T_DiRS
*/

unsigned char 		get_t_dir_one(t_cell *cell, t_bot *bot);
short 				get_t_dir_two(t_cell *cell, t_bot *bot);
unsigned int 		get_t_dir_four(t_cell *cell, t_bot *bot);


// some trash
int 			do_process(t_corewar *core, int qua_bots);
void 			vs_start(t_corewar *core);
void 			dog_nail_vs(t_corewar *core);
int 			t_load_instr(t_cell *cell, t_bot *bot, int t_reg, int handicap); // swap this with get_t_dir_four

ssize_t 		correction_coordinates(ssize_t coordinate);

unsigned 			get_id_of_bot(unsigned num);
int 	get_argument(t_cell *cell, t_bot *bot, int num_of_argument);

// carriage
t_carriage 				*create_carriage(int id);


//cycles
int 			get_cycles(t_bot *bot);

//print
void		simple_print(WINDOW *win, int id);
void 		carriage_print(WINDOW *win, int id);
void 		alive_view(WINDOW *win, int id);
void 		altered_view(WINDOW *win, int id);

//
ssize_t 		get_dir(t_cell *cell, t_bot *bot, int handicap, int bytes);

//getters args
ssize_t		get_arg_reg(t_cell *cell, t_bot *bot, int *step);
ssize_t		get_arg_dir(t_cell *cell, t_bot *bot, int *step, int bytes);
ssize_t		get_arg_ind(t_cell *cell, t_bot *bot, int *step, int code);


//write in cell
int 	write_in_cell(t_cell *cell, int position, t_bot *bot, int t_reg);

//add sub
ssize_t 	which_operation_needs(ssize_t a, ssize_t b, int command);
#endif

// 4 magic value
// 128 bytes - name
// 4 null
// 4 bot size
// 2048 comment
// 4 null
