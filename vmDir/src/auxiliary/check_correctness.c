/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_correctness.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:57:18 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/28 18:57:19 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

char				*check_correctness_file(int check_code)
{
	char			*message;

	if (check_code == FILE_DOESNT_EXIST)
		message = "THERE IS NO CHAMP!";
	else if (check_code == NO_RIGHT_FOR_READ)
		message = "YOU HAVE NO PERMISSION TO TAKE THIS CHAMP!";
	else if (check_code == FILE_IS_PIPE)
		message = "THIS CHAMP FILE TYPE IS PIPE, BUT IT HAS TO BE REGULAR!";
	else if (check_code == FILE_IS_SPEC_CHAR)
		message = "THIS CHAMP FILE TYPE IS CHAR, BUT IT HAS TO BE REGULAR!";
	else if (check_code == FILE_IS_DIR)
		message = "THIS CHAMP FILE TYPE IS DIR, BUT IT HAS TO BE REGULAR!";
	else if (check_code == FILE_IS_SOCKET)
		message = "THIS CHAMP FILE TYPE IS SOCKET, BUT IT HAS TO BE REGULAR!";
	else if (check_code == FILE_IS_BLOCK)
		message = "THIS CHAMP FILE TYPE IS BLOCK, BUT IT HAS TO BE REGULAR!";
	else if (check_code == WRONG_FILE_TYPE)
		message = "THIS CHAMP HAS BAD FILE TYPE, IT HAS TO BE REGULAR!";
	else if (check_code == BAD_CHAMP_EXTENSION)
		message = "THE CHAMP HAS TO HAVE EXTENSION \".cor\"!";
	else if (check_code == BAD_CHAMP)
		message = "BAD CHAMP!";
	else
		message = "ERROR!";
	return (message);
}

char				*check_champ_data(int check_code)
{
	char			*message;

	if (check_code == WRONG_MAGIC_VALUE)
		message = "THE CHAMP HAS WRONG MAGIC VALUE!";
	else if (check_code == BAD_NAME_LENGTH)
		message = "THE CHAMP HAS WRONG NAME LENGTH!";
	else if (check_code == BAD_CHAMP_SIZE)
		message = "THE CHAMP HAS WRONG CHAMP SIZE!";
	else if (check_code == BAD_COMMENT_LENGTH)
		message = "THE CHAMP HAS WRONG COMMENT LENGTH!";
	else if (check_code == BAD_EXEC_CODE_LENGTH)
		message = "THE CHAMP HAS WRONG EXEC CODE LENGTH!";
	else
		message = "ERROR!";
	return (message);
}

char				*check_corewar_arguments(int check_code)
{
	char			*message;

	message = "ERROR";
	if (check_code == BAD_ARGUMENTS)
		message = "BAD ARGUMENTS!";
	else if (check_code == BAD_FLAGS)
		message = "BAD FLAGS!";
	else if (check_code == BAD_VALUE_FOR_FLAG_N)
		message = "BAD VALUE FOR \'n\'!";
	else if (check_code == BAD_NUMBER_FOR_DUMP)
		message = "BAD NUMBER OF CYCLES FOR DUMP!";
	else if (check_code == MISSING_CHAMP)
		message = "THERE IS NO CHAMP";
	else if (check_code == SAME_NUM_FOR_CHAMPS)
		message = "CHAMPS CAN NOT HAVE THE SAME ID!";
	else if (check_code == NO_ID_AFTER_FLAG)
		message = "THERE IS NO ID AFTER FLAG \'n\'!";
	else if (check_code == TOO_BIG_NUM_FOR_CHAMP)
		message = "CHAMP CAN NOT HAVE SO BIG ID!";
	else if (check_code == REDUNDANT_ARGUMENTS)
		message = "THERE ARE REDUNDANT ARGUMENTS!";
	else if (check_code == NEED_ARGUMENTS)
		message = "Short Usage:\n\t./corewar [champ1 .. champ4]"
			"\n\t\"--help\" for detailed documentation";
	return (message);
}

char				*get_message(void)
{
	return (ft_multjoinfr(4,
		"Usage:"
		" \tExample: ./corewar -v -n -1 filename.cor\n"
		" \tGUI: ./corewar -v [Players]\n"
		" \tDefault Player Numbers: 1, 2, 3, 4...\n"
		" \tChange Player Number: -n -1 filename.cor\n"
		" \tDump: ./corewar -d 300 [Players](prints the memory"
		"after 300 cycles)\n"
		" \tGOTO: ./corewar -v -d 300 [Players](start corewar in"
		"visual mode after 300 cycles)\n"
		" \tGame on! ", ALIEN, ALIEN, ALIEN));
}

int					check_correctness(t_corewar *core, int check_code)
{
	char			*message;

	if (check_code == MEMORY_ERROR)
		message = "MEMORY ALLOCATE ERROR!";
	else if (ARGUMENTS_ERROR(check_code) || check_code == NEED_ARGUMENTS)
		message = check_corewar_arguments(check_code);
	else if (FILE_ERROR(check_code))
		message = check_correctness_file(check_code);
	else if (CHAMP_DATA_ERROR(check_code))
		message = check_champ_data(check_code);
	else if (check_code == PRINT_USAGE)
	{
		message = get_message();
		check_code = 0;
	}
	else
		message = "ERROR";
	notification_message(core, check_code, message);
	return (check_code);
}
