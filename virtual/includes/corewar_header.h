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

#define NCUR			core->ncur
#define F_VISUAL		core->flags.visual
#define F_DUMP			core->flags.dump
#define CUR_COORD		carriage->cur_coord
#define REG				carriage->registers
#define CARRY			carriage->carry
#define ALIVE			carriage->alive


# define I_COMMAND		carriage->instruction->command
# define I_CODAGE		carriage->instruction->codage
# define I_QUA_ARGS		carriage->instruction->qua_args
# define I_LABEL_SIZE	carriage->instruction->label_size
# define I_INSTRUCT		carriage->instruction
# define I_DESIRED		instruction->desired



#define LIST_ARGUMENTS	arguments->list_arguments
#define ARG_FIRST	arguments->first_arg
#define ARG_SECOND	arguments->second_arg
#define ARG_THIRD	arguments->third_arg


# define O_BOTS						4
# define NONE_ARG					0
# define SHOW_CHANGED_CYCLES		50
# define NOT_EXPOSED 				0


#define ONE_BYTE					1
#define TWO_BYTES					2
#define FOUR_BYTES					4


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


# define QUA_INSTRUCTIONS 			16

/*
**	Visual colors
*/


# define SCORE_WIN_HEIGHT			66
# define SCORE_WIN_WIDTH			70
# define MEM_WIN_HEIGHT				68 // 66
# define MEM_WIN_WIDTH				195


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
# define CR_CL_YELLOW_BLACK			19

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



# define BAD_EXEC_CODE_LENGTH			57

# define PRINT_USAGE				60
# define NEED_ARGUMENTS				61

# define NOONE						0
# define FIRST_BOT					1
# define SECOND_BOT					2
# define THIRD_BOT					3
# define FOURTH_BOT					4
# define FOLLOW_CARRIAGE			5

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

# define CW_ZJMP_CYCLES				20
# define CW_FORK_CYCLES				800
# define CW_LLDI_CYCLES				50
# define CW_LFORK_CYCLES			1000
# define CW_AFF_CYCLES				2


int 				bigmother;

typedef	struct			s_flags
{
	unsigned			visual:1;
	unsigned			dump;
}						t_flags;

typedef struct 			s_arguments
{
	unsigned char		list_arguments;
	ssize_t 			first_arg;
	ssize_t 			second_arg;
	ssize_t 			third_arg;
}						t_args;


typedef struct 			s_instructions
{
	unsigned			command:5;
	unsigned 			codage:1;
	unsigned 			label_size:3;
	unsigned 			cycles:10;
	unsigned			desired[3];
	unsigned			qua_args:3;
}						t_instructions;

typedef struct			s_carriage
{
	unsigned			id;
	int 				cur_coord;
	unsigned 			carry:1;
	unsigned			flag:1;
	unsigned 			alive:1;
	unsigned 			registers[16];
	int 				cycles;
	t_instructions		*instruction;

	struct s_carriage	*next;
}						t_carriage;


typedef struct			s_champion
{

	char 				*name;
	char 				*comment;
	unsigned char		*exec_code;
	unsigned			id;
	unsigned			size;
	unsigned			alive:2;
}						t_champ;

typedef struct			s_ncurses
{
	struct timespec 	tstart;
	struct timespec		tend;
	int		 			draw_speed;
	int 				where_pause;
	unsigned 			pause:1;
	int 				pressed_button;
	char				cycle_to_go[7];
	char				carriage_id[7];
	int					carriage_pos;
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
	t_args				arguments;
	t_instructions		instructions[QUA_INSTRUCTIONS];
	unsigned 			cycles;
	int 				cycle_to_die;
	int 				max_checks;
	unsigned 			qua_champs;
	unsigned 			qua_lives;
	unsigned 			quant_carriages;
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
void 				fill_champs(t_corewar *core, t_champ **champ, int qua_champs); // refactor me;


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
int				draw(t_corewar *core, int cycle, unsigned *cycles_limit);
int 			create_memory_space(t_corewar *core);
void			fill_memory_space(t_champ *champs, t_field *field, int qua_champs);
int 			draw_menu(t_corewar *core, int pos_y);


//operations

unsigned 			find_free_space(t_champ *champs);
int 				get_champ_by_id(t_champ *champ, unsigned id);
int 				create_champs(t_champ **champs);
void 				sort_champs(t_champ **champ, int qua_champs);

/*
** Check Champ
*/

int 				check_champ_file(char *champfilename);
int 				check_champ_info(t_champ *champ);
/*
** Instructions
*/

void 	alive_instruct(t_field *field, t_carriage *carriage, t_corewar *core, t_args *arguments);
void 	load_instruct(t_carriage *carriage, t_args *arguments);
void 	store_instruct(t_field *field, t_carriage *carriage, t_args *arguments,
					   unsigned cycles);

// add and sub operations here
void 	add_sub_instructs(t_carriage *carriage, t_args *arguments);

// all logical operations here
void 	logical_operations(t_carriage *carriage, t_args *arguments);

int 	jump_if_carry_instruct(t_field *field, t_carriage *carriage, t_args *arguments);

//	LLDI in LDI
void 	load_index_instruct(t_field *field, t_carriage *carriage, t_args *arguments);

void 	store_index_instruct(t_field *field, t_carriage *carriage, t_args *arguments,
							 unsigned cycles);

//  long fork in fork
void					fork_instruct(t_field *field, t_carriage *carriage,
									  t_corewar *core, t_args *arguments);

void 	aff_instruct(t_carriage *carriage, t_args *arguments);

/*
** Check carry
*/

void 	change_carry_if_need(unsigned char coord, t_carriage *carriage);

/*
**	Move Carriage
*/

void 	move_carriage(t_field *field, int step, t_carriage *carriage);


/*
** Check args of instruction
*/

  int 	get_indent_size(int argument, int bytes);
int 	check_instruction_arg(int argument, int byte);

// some trash
void 			do_process(t_corewar *core);
int 			check_reg(int reg);

ssize_t 		correction_coordinates(ssize_t coordinate);

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
void 		follow_view(WINDOW *win);

//
ssize_t 		get_dir(t_field *field, int handicap, int bytes, t_carriage *carriage);

//getters args


//write in field
int 	write_in_field(t_field *field, int position, unsigned t_reg);
int  write_in_field1(t_field *field, int coord, unsigned t_reg, t_carriage *carriage);//delete

//add sub
unsigned				which_operation_needs(ssize_t a, ssize_t b, unsigned command);

int 	get_indent(int argument, int count_arguments, int bytes);

//dump
void 			print_memory(t_corewar *core);

//check cycle_to_die
int 			check_cycle_to_die(t_corewar *core);

//
int 					check_type_arguments(t_args *args, int type, int num, ...);
int 					get_part_argument(int argument, int position);
// new way
ssize_t			get_arguments(t_field *field, int argument, int number, t_carriage *carriage);

void 					 denote_field(t_field *field, int coord);


int 					get_regs_value(int argument, t_carriage *carriage, int type, int num, ...);


int 					get_t_args(t_field *field, t_carriage *carriage, t_args *arguments);


void 			init_instructions(t_instructions *instructions);
t_instructions	*get_instruction_by_id(t_instructions *instructions, unsigned id);

void 			fill_first_positions(t_field *field, unsigned  quant_carriages, t_carriage *carriage);

void 				reverse_list(t_carriage **begin_list);

void 	add_champ_id(int coord, t_field *field, t_carriage *carriage, unsigned cycles);

#endif

// 4 magic value
// 128 bytes - name
// 4 null
// 4 champ size
// 2048 comment
// 4 null
