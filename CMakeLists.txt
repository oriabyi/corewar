cmake_minimum_required(VERSION 3.12)
project(Corewar C)

set(CMAKE_C_STANDARD 11)
set(LIBFT ${CMAKE_SOURCE_DIR}/libft/libft.a)

include_directories(op)
include_directories(vmDir/includes)

add_executable(Corewar
        op/op.h
        vmDir/includes/corewar_header.h
        vmDir/includes/ncurses.h
        vmDir/src/add_sub_instructions.c
        vmDir/src/aff_instruct.c
        vmDir/src/alive_instruct.c
        vmDir/src/carriages_move.c
        vmDir/src/check_cycle_to_die.c
        vmDir/src/check_instruction_args.c
        vmDir/src/clean_all.c
        vmDir/src/control_work.c
        vmDir/src/create_memory_space.c
        vmDir/src/dump.c
        vmDir/src/execute_the_instruction.c
        vmDir/src/fill_memory_space.c
        vmDir/src/fork_instruct.c
        vmDir/src/getters.c
        vmDir/src/getters_args.c
        vmDir/src/jump_if_carry_instruct.c
        vmDir/src/load_index_instruct.c
        vmDir/src/load_instruct.c
        vmDir/src/logical_operations.c
        vmDir/src/main.c
        vmDir/src/math_help_for_gets.c
        vmDir/src/parse.c
        vmDir/src/store_index_instruct.c
        vmDir/src/store_instruct.c
        vmDir/src/trash.c
        vmDir/src/treatment_arguments.c
        vmDir/src/visual_draw_main_function.c
        vmDir/src/visual_draw_memory_window.c
        vmDir/src/visual_draw_score_window.c
        vmDir/src/visual_event_handler.c
        vmDir/src/visual_init.c
        vmDir/src/visual_init_colors.c
        vmDir/src/visual_init_time.c
        vmDir/src/visual_input_field_functions.c
        vmDir/src/visual_reset_event.c
        vmDir/src/visual_set_memory_print_attr.c
        vmDir/src/visual_start_end_functions.c
        vmDir/src/check_correctness.c
        vmDir/src/check_champ.c
        vmDir/src/operations_with_champs.c
        vmDir/src/get_list_arguments.c
        vmDir/src/init_instructions.c
        vmDir/src/visual_draw_menu.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lncurses")
target_link_libraries(Corewar ${LIBFT})