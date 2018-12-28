# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/28 13:11:42 by ariabyi           #+#    #+#              #
#    Updated: 2018/12/28 17:20:04 by obaranni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mre

ASM := asm
VM := corewar

ASM_PATH := ./asmDir/
VM_PATH := ./vmDir/

all:
	@ make -C $(ASM_PATH)
	@ make -C $(VM_PATH)
	@ ln -fs $(ASM_PATH)$(ASM) $(ASM)
	@ ln -fs $(VM_PATH)$(VM) $(VM)
	@ chmod 744 $(ASM) $(VM)

mre:
	@ make mre -C $(ASM_PATH)
	@ make mre -C $(VM_PATH)
	@ ln -fs $(ASM_PATH)$(ASM) $(ASM)
	@ ln -fs $(VM_PATH)$(VM) $(VM)
	@ chmod 744 $(ASM) $(VM)

clean:
	make clean -C $(ASM_PATH)
	make clean -C $(VM_PATH)

fclean:
	make fclean -C $(ASM_PATH)
	make fclean -C $(VM_PATH)
	rm -f $(ASM) $(VM)

re: fclean all
