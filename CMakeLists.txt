cmake_minimum_required(VERSION 3.12)
project(Corewar C)

set(CMAKE_C_STANDARD 11)
set(LIBFT ${CMAKE_SOURCE_DIR}/vmDir/libft/libft.a)

include_directories(op)
include_directories(vmDir/includes)

add_executable(Corewar
        op/op.h
        vmDir/includes/corewar_header.h
        vmDir/includes/ncurses.h

        vmDir/src/instructions/add_sub_instructions.c
        vmDir/src/instructions/aff_instruct.c
        vmDir/src/instructions/alive_instruct.c
        vmDir/src/war/carriages_move.c
        vmDir/src/war/check_cycle_to_die.c
        vmDir/src/war/check_instruction_args.c
        vmDir/src/auxiliary/clean_all.c
        vmDir/src/auxiliary/control_work.c
        vmDir/src/initialization/create_memory_space.c
        vmDir/src/dump.c
        vmDir/src/war/execute_the_instruction.c
        vmDir/src/initialization/fill_memory_space.c
        vmDir/src/instructions/fork_instruct.c
        vmDir/src/parsing/getters.c
        vmDir/src/war/getters_args.c
        vmDir/src/instructions/jump_if_carry_instruct.c
        vmDir/src/instructions/load_index_instruct.c
        vmDir/src/instructions/load_instruct.c
        vmDir/src/instructions/logical_operations.c
        vmDir/src/main.c
        vmDir/src/parsing/math_help_for_gets.c
        vmDir/src/parsing/parse.c
        vmDir/src/instructions/store_index_instruct.c
        vmDir/src/instructions/store_instruct.c
        vmDir/src/war/trash.c
        vmDir/src/parsing/treatment_arguments.c
        vmDir/src/visualization/visual_draw_main_function.c
        vmDir/src/visualization/visual_draw_memory_window.c
        vmDir/src/visualization/visual_draw_score_window.c
        vmDir/src/visualization/visual_event_handler.c
        vmDir/src/visualization/visual_init.c
        vmDir/src/visualization/visual_init_colors.c
        vmDir/src/visualization/visual_init_time.c
        vmDir/src/visualization/visual_input_field_functions.c
        vmDir/src/visualization/visual_reset_event.c
        vmDir/src/visualization/visual_set_memory_print_attr.c
        vmDir/src/visualization/visual_start_end_functions.c
        vmDir/src/auxiliary/check_correctness.c
        vmDir/src/parsing/check_champ.c
        vmDir/src/parsing/operations_with_champs.c
        vmDir/src/war/get_list_arguments.c
        vmDir/src/initialization/init_instructions.c
        vmDir/src/visualization/visual_draw_menu.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lncurses")
target_link_libraries(Corewar ${LIBFT})