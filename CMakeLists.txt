cmake_minimum_required(VERSION 3.12)
project(corewar C)

set(CMAKE_C_STANDARD 99)
set(LIBFT ${CMAKE_SOURCE_DIR}/libft/libft.a)

add_executable(corewar
        virtual/src/main.c
        virtual/src/visual_init_time.c
        virtual/includes/corewar_header.h
        virtual/src/treatment_arguments.c
        virtual/src/parse.c
        virtual/src/parse.c
        virtual/src/getters.c
        virtual/src/math_help_for_gets.c
        virtual/src/clean_all.c
        virtual/src/control_work.c
        virtual/src/visual_draw_main_function.c
        virtual/src/execute_the_instruction.c
        virtual/src/instructions.c
        virtual/src/aff_instruct.c
        virtual/src/alive_instruct.c
        virtual/src/fork_instruct.c
        virtual/src/jump_if_carry_instruct.c
        virtual/src/load_index_instruct.c
        virtual/src/load_instruct.c
        virtual/src/long_fork_instruct.c
        virtual/src/long_load_instruct.c
        virtual/src/store_index_instruct.c
        virtual/src/store_instruct.c
        virtual/src/check_instruction_args.c
        virtual/src/trash.c
        virtual/src/getters_args.c
        virtual/src/visual_set_memory_print_attr.c
        virtual/src/logical_operations.c
        virtual/src/add_sub_instructions.c
        virtual/src/fill_memory_space.c
        virtual/src/visual_init_colors.c
        virtual/src/carriages_move.c virtual/src/visual_draw_memory_window.c virtual/src/visual_draw_score_window.c virtual/src/visual_event_handler.c virtual/src/visual_input_field_functions.c virtual/src/visual_init.c virtual/src/visual_start_end_functions.c virtual/src/visual_reset_event.c virtual/src/create_memory_space.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lncurses")
target_link_libraries(corewar ${LIBFT})