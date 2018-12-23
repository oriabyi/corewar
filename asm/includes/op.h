/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2013/11/06 14:21:46 by zaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE
# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3
# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR			','
# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"
# define REG_NUMBER				16
# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA				50
# define NBR_LIVE				21
# define MAX_CHECKS				10
# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		15369203

typedef char					t_arg_type;

typedef struct					s_header
{
	unsigned int				magic;
	char						prog_name[PROG_NAME_LENGTH + 1];
	unsigned int				prog_size;
	char						comment[COMMENT_LENGTH + 1];
}								t_header;

typedef struct					s_op
{
	char						*name;
	int							n_par;
	t_arg_type					type_arg[MAX_ARGS_NUMBER];
	int							id;
	int							cycles;
	int							octal;
	int							label_size;
}								t_op;

static t_op						g_op_tab[17] =
{
	{
		.name = "live",
		.n_par = 1,
		.type_arg = {T_DIR},
		.id = 1,
		.cycles = 10,
		.octal = 0,
		.label_size = 0
	},
	{
		.name = "ld",
		.n_par = 2,
		.type_arg = {T_DIR | T_IND, T_REG},
		.id = 2,
		.cycles = 5,
		.octal = 1,
		.label_size = 0
	},
	{
		.name = "st",
		.n_par = 2,
		.type_arg = {T_REG, T_IND | T_REG},
		.id = 3,
		.cycles = 5,
		.octal = 1,
		.label_size = 0
	},
	{
		.name = "add",
		.n_par = 3,
		.type_arg = {T_REG, T_REG, T_REG},
		.id = 4,
		.cycles = 10,
		.octal = 1,
		.label_size = 0
	},
	{
		.name = "sub",
		.n_par = 3,
		.type_arg = {T_REG, T_REG, T_REG},
		.id = 5,
		.cycles = 10,
		.octal = 1,
		.label_size = 0
	},
	{
		.name = "and",
		.n_par = 3,
		.type_arg = {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		.id = 6,
		.cycles = 6,
		.octal = 1,
		.label_size = 0,
	},
	{
		.name = "or",
		.n_par = 3,
		.type_arg = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.id = 7,
		.cycles = 6,
		.octal = 1,
		.label_size = 0
	},
	{
		.name ="xor",
		.n_par = 3,
		.type_arg = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.id = 8,
		.cycles = 6,
		.octal = 1,
		.label_size = 0
	},
	{
		.name = "zjmp",
		.n_par = 1,
		.type_arg = {T_DIR},
		.id = 9,
		.cycles = 20,
		.octal = 0,
		.label_size = 1
	},
	{
		.name = "ldi",
		.n_par = 3,
		.type_arg = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.id = 10,
		.cycles = 25,
		.octal = 1,
		.label_size = 1,
	},
	{
		.name = "sti",
		.n_par = 3,
		.type_arg = {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		.id = 11,
		.cycles = 25,
		.octal = 1,
		.label_size = 1
	},
	{
		.name = "fork",
		.n_par = 1,
		.type_arg = {T_DIR},
		.id = 12,
		.cycles = 800,
		.octal = 0,
		.label_size = 1
	},
	{
		.name = "lld",
		.n_par = 2,
		.type_arg = {T_DIR | T_IND, T_REG},
		.id = 13,
		.cycles = 10,
		.octal = 1,
		.label_size = 0
	},
	{
		.name = "lldi",
		.n_par = 3,
		.type_arg = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.id = 14,
		.cycles = 40,
		.octal = 1,
		.label_size = 1
	},
	{
		.name = "lfork",
		.n_par = 1,
		.type_arg = {T_DIR},
		.id = 15,
		.cycles = 1000,
		.octal = 0,
		.label_size = 1
	},
	{
		.name = "aff",
		.n_par = 1,
		.type_arg = {T_REG},
		.id = 16,
		.cycles = 2,
		.octal = 1,
		.label_size = 0
	},
	{
		.name = 0,
		.n_par = 0,
		.type_arg = {0},
		.id = 0,
		.cycles = 0,
		.octal = 0,
		.label_size = 0
	}
};
#endif
