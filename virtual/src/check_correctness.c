#include "../includes/corewar_header.h"

char				*check_correctness_file(int check_code)
{
	char 			*message;

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
	char 			*message;

	if (check_code == WRONG_MAGIC_VALUE)
		message = "THE CHAMP HAS WRONG MAGIC VALUE!";
	else if (check_code == BAD_NAME_LENGTH)
		message = "THE CHAMP HAS WRONG NAME LENGTH!";
	else if (check_code == BAD_CHAMP_SIZE)
		message = "THE CHAMP HAS WRONG CHAMP SIZE!";
	else if (check_code == BAD_COMMENT_LENGTH)
		message = "THE CHAMP HAS WRONG COMMENT LENGTH!";
	else
		message = "ERROR!";
	return (message);
}

char 				*check_corewar_arguments(int check_code)
{
	char 			*message;

	if (check_code == BAD_ARGUMENTS)
		message = "BAD ARGUMENTS!";
	else if (check_code == BAD_FLAGS)
		message = "BAD FLAGS!";
	else if (check_code == BAD_NUMBER_FOR_DUMP)
		message = "BAD NUMBER OF CYCLES FOR DUMP!";
	else if (check_code == MISSING_CHAMP)
		message = "THERE ARE NO CHAMP";
	else if (check_code == SAME_NUM_FOR_CHAMPS)
		message = "CHAMPS CAN NOT HAVE THE SAME ID!";
	else if (check_code == TOO_BIG_NUM_FOR_CHAMP)
		message = "CHAMP CAN NOT HAVE SO BIG ID!";
	else if (check_code == REDUNDANT_ARGUMENTS)
		message = "THERE ARE REDUNDANT ARGUMENTS!";
	else
		message = "ERROR!";
	return (message);
}

void				check_correctness(t_corewar *core, int check_code)
{
	char 			*message;

	if (check_code == 0)
		return ;
	else if (check_code == MEMORY_ERROR)
	{
		message = "MEMORY ALLOCATE ERROR!";
	}
	else if (ARGUMENTS_ERROR(check_code))
	{
		message = check_corewar_arguments(check_code);
	}
	else if (FILE_ERROR(check_code))
	{
		message = check_correctness_file(check_code);
	}
	else if (CHAMP_DATA_ERROR(check_code))
	{
		message = check_champ_data(check_code);
	}
	else
		message = "ERROR!";
	exit_message(core, check_code, message);
}
