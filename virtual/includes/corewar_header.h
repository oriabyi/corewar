#ifndef COREWAR_COREWAR_HEADER_H
#define COREWAR_COREWAR_HEADER_H

#include "../../libft/libft.h"
#include "../../op/op.h"
#include "ncurses.h"
#include "stdio.h"
#include <time.h>
# include <sys/stat.h>
# include <sys/types.h>


# define ALIEN "\xF0\x9F\x91\xBD"

#define F_VISUAL		core->flags.visual
#define F_DUMP			core->flags.dump

#define CUR_COORD		carriage->cur_coord

#define REG				carriage->registers

#define COMMAND		 	carriage->command

#define CARRY			carriage->carry
#define CYCLES			carriage->cycles

#define ALIVE			carriage->alive

# define IS_VALID_COMMAND(x) (x >= 1 && x <= 16)


# define O_BOTS						4


# define NONE_ARG					0


# define ALTERED_FIELD				-1
# define SHOW_CHANGED_CYCLES		50

#define NOT_EXPOSED 				0
#define COUNTING_FROM_ONE 			1


#define ONE_BYTE					1
#define TWO_BYTES					2
#define FOUR_BYTES					4



#define CHAMP_IS_DEAD				3




# define CHECK_REG(x) (x >= 0 && x <= 15)

/*
** Get arguments // check defines
*/

# define GET_FIRST_ARG(x)		(x >> 6)
# define GET_SECOND_ARG(x)		((x >> 4) & 3)
# define GET_THIRD_ARG(x)		((x >> 2) & 3)

# define GET_T_IND_ARG(x) (x ^ 7)


# define ERROR	1


# define LINE_SIZE 188

/*
**	Visual colors
*/


# define SCORE_WIN_HEIGHT			66
# define SCORE_WIN_WIDTH			70
# define MEM_WIN_HEIGHT				66
# define MEM_WIN_WIDTH				195


# define COLOR_ORANGE				123
# define COLOR_WWHITE				124
# define COLOR_GREY					125

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

# define CR_CL_ORANGE_BLACK			16
# define CR_CL_WWHITE_BLACK			17
# define CR_CL_GREY_BLACK			18


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

# define DENOTE_CARRIAGE			5 //TODO: remove
# define DENOTE_ALTERED				10
# define DENOTE_ALIVE				15

# define FILE_IS_REG				0


/*
**	Define errors
*/

# define MEMORY_ERROR				33

# define ARGUMENTS_ERROR(arg)		(arg >= BAD_ARGUMENTS && \
									arg <= REDUNDANT_ARGUMENTS)
# define BAD_ARGUMENTS				34
# define BAD_FLAGS					35
# define BAD_VALUE_FOR_FLAG_N		36
# define BAD_NUMBER_FOR_DUMP		37
# define MISSING_CHAMP				38
# define SAME_NUM_FOR_CHAMPS		39
# define NO_ID_AFTER_FLAG			40
# define TOO_BIG_NUM_FOR_CHAMP		41
# define REDUNDANT_ARGUMENTS		42

# define FILE_ERROR(arg)			(arg >= FILE_DOESNT_EXIST && \
									arg <= BAD_CHAMP)
# define FILE_DOESNT_EXIST			43
# define NO_RIGHT_FOR_READ			44
# define FILE_IS_PIPE				45
# define FILE_IS_SPEC_CHAR			46
# define FILE_IS_DIR				47
# define FILE_IS_SOCKET				48
# define FILE_IS_BLOCK				49
# define WRONG_FILE_TYPE			50

# define CHAMP_DATA_ERROR(arg)		(arg >= WRONG_MAGIC_VALUE && \
									arg <= BAD_COMMENT_LENGTH)
# define BAD_CHAMP_EXTENSION		51
# define BAD_CHAMP					52
# define WRONG_MAGIC_VALUE			53
# define BAD_NAME_LENGTH			54
# define BAD_CHAMP_SIZE				55
# define BAD_COMMENT_LENGTH			56

# define PRINT_USAGE				60


# define NO_INSTRUCTION				0

# define NOONE						0
# define FIRST_BOT					1
# define SECOND_BOT					2
# define THIRD_BOT					3
# define FOURTH_BOT					4

# define NUMBER_OF_REGISTERS		16

#define FIRST_ARG	0
#define SECOND_ARG	1
#define THIRD_ARG	2

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
	unsigned			dump;
}						t_flags;


typedef struct			s_carriage
{
	int 				cur_coord;
	unsigned 			carry:1;
	unsigned			flag:1;
	unsigned 			alive:1;
	unsigned 			registers[16];
	unsigned 			command:8;
	int 				cycles;
	int 				id;

	struct s_carriage	*next;
}						t_carriage;

typedef struct			s_champion
{

	char 				*name;
	char 				*comment;
	unsigned char		*exec_code;
	unsigned			id;
	unsigned			size;
	unsigned 			quant_carriages;
	unsigned			alive:2;

	t_carriage			*carriage;
}						t_champ;

typedef struct			s_ncurses
{
	int 				i;
	struct timespec 	tstart;
	struct timespec		tend;
	int		 			draw_speed;
	int 				pressed_button;
	int 				where_pause;
	unsigned 			pause:1;

	char				cycle_to_go[7];
	char				champ_id[7];
	char				carriage_id[7];
	char 				*current_field;

	WINDOW				*memory_window;
	WINDOW				*score_window;
}						t_ncurses;

typedef struct			s_battlefield
{
	unsigned char		hex[3];
	unsigned			champ_id:5;
	unsigned			is_alive:1;
	unsigned			carriages_on;
	int					altered_cycles;
	unsigned			old_owner;
}						t_field;

typedef struct			s_corewar
{
	t_field				*field;
	t_ncurses			ncur;
	t_champ				*champs;
	t_flags				flags;
	int 				cycle_to_die;
	int 				max_checks;
	unsigned 			qua_champs;
	unsigned 			qua_lives;
	unsigned 			qua_carrs;
	unsigned 			last_live:3;

	t_carriage			*carriage;
}						t_corewar;


/*
** Treatment arguments
*/

int 	check_availability_flags(t_flags *flags, int ac, char **av);

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
unsigned 	get_size(int fd);

/*
** Math help for getters
*/

unsigned 	get_num_by_octet_bytes(int fd, int size);
int 	get_old_young_numbers(unsigned char num, int base, int *power);
int 				ft_module(int i);

/*
** Clean functions
*/

void	clean_carriages(t_carriage *carriage);
void 	clean_all(t_corewar *core);

/*
** Control work
*/

int 	notification_message(t_corewar *core, int error_code, char *error_message);
int 	check_correctness(t_corewar *core, int check_code);
/*
** Visualization
*/

void 			reset_game(t_corewar *core);
void			fill_input_field_with_zeros(char *field);
int 			uppend_input_field(char *field, char n);
int 			delete_last_letter_from_iput_field(char *field);
void 			set_next_field(t_corewar *core);
void 			set_prev_field(t_corewar *core);
int 			get_button(t_corewar *core, int cycle);
void 			draw_score_window(t_corewar *core, int cycle);
void 			draw_memory_window(t_corewar *core, int cycle);
void 			init_time(t_corewar *core);
void 			init_colors(void);
int 			visual_init(t_corewar *core);
void 			visual_start(t_corewar *core);
int 			visual_end(t_corewar *core);
int 			display_windows(t_corewar *core, int cycle);
int				draw(t_corewar *core, int cycle);
int 			create_memory_space(t_corewar *core);
void			fill_memory_space(t_champ *champs, t_field *field, int qua_champs);


/*
** Math
*/

/*
** Instructions
*/

void 	alive_instruct(t_field *field, t_carriage *carriage, t_corewar *core);
void 	load_instruct(t_field *field, t_carriage *carriage, unsigned  char argument);
void 	store_instruct(t_field *field, t_carriage *carriage, unsigned  char argument, unsigned id);

// add and sub operations here
void 	add_sub_instructs(t_field *field, t_carriage *carriage, unsigned  char argument);

// all logical operations here
void 	logical_operations(t_field *field, t_carriage *carriage, unsigned  char argument);

int 	jump_if_carry_instruct(t_field *field, t_carriage *carriage);

//	LLDI in LDI
void 	load_index_instruct(t_field *field, t_carriage *carriage, unsigned  char argument);

void 	store_index_instruct(t_field *field, t_carriage *carriage, unsigned  char argument, unsigned id);

//  long fork in fork
void					fork_instruct(t_field *field, t_carriage *carriage,
									  unsigned *quant_carriages);

void 	aff_instruct(t_field *field, t_carriage *carriage, unsigned id);

/*
** Check carry
*/

void 	change_carry_if_need(int coord, t_carriage *carriage);

/*
**	Move Carriage
*/

void 	move_carriage(t_field *field, int step, t_carriage *carriage);


/*
** Check args of instruction
*/

int 	check_instruction_args(int argument, int first, int second, int third);
int 	help_fishka(int argument, int bytes);
int 	check_instruction_arg(int argument, int byte);
int 			get_dir_bytes(unsigned command);
int			get_codage(unsigned command);

// some trash
void 			do_process(t_corewar *core);
int 			check_reg(int reg);

ssize_t 		correction_coordinates(ssize_t coordinate);

unsigned 			get_id_of_champ(unsigned num);
unsigned char 	get_argument(t_field *field, int coord);

// carriage
t_carriage 				*create_carriage(int id);


//cycles
int 			check_cycle_to_die(t_corewar *core);
int 			get_cycles(t_carriage *carriage);

//print
void		simple_print(WINDOW *win, int id);
void 		carriage_print(WINDOW *win, int id);
void 		alive_view(WINDOW *win, int id);
void 		altered_view(WINDOW *win, int id);

//
ssize_t 		get_dir(t_field *field, int handicap, int bytes, t_carriage *carriage);

//getters args
ssize_t		get_arg_reg(t_field *field, t_champ *champ, int *step, ssize_t *get);


//write in field
int 	write_in_field(t_field *field, int position, int t_reg, t_carriage *carriage, unsigned id);

//add sub
unsigned				which_operation_needs(unsigned a, unsigned b, unsigned command);

int 	fishka(int argument, int count_arguments, int bytes);

//dump
void 			print_memory(t_corewar *core);

//check cycle_to_die
int 			check_cycle_to_die(t_corewar *core);

//
int 		check_mult_regs(int field, ...);
int 					check_type_arguments(int argument, int type, int num, ...);
int 					get_part_argument(int argument, int position);
// new way
ssize_t			get_arguments(t_field *field, int argument, int number, t_carriage *carriage);

void					fill_old_owner(t_field *field, int coord);
void 					 denote_field(t_field *field, int coord);


int 					get_regs_value(int argument, t_carriage *carriage, int type, int num, ...);

void					get_old_owner(t_field *field, int coord);

#endif

// 4 magic value
// 128 bytes - name
// 4 null
// 4 champ size
// 2048 comment
// 4 null
