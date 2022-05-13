##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	sources/main/main.c	\
		sources/my/my_putstr.c	\
		sources/my/my_strcpy.c	\
		sources/my/my_compute_power_rec.c \
		sources/my/my_strcat_path.c \
		sources/my/my_strcmp_bool.c \
		sources/my/my_strcmp_header.c \
		sources/window/set_window.c	\
		sources/menus/main_menu.c	\
		sources/buttons/create_btn.c	\
		sources/buttons/btn_action.c	\
		sources/menus/play_menu.c	\
		sources/menus/settings_menu.c	\
		sources/menus/reso_menu.c	\
		sources/menus/key_config_menu.c	\
		sources/buttons/resolutions/choose.c	\
		sources/buttons/resolutions/creation.c	\
		sources/sounds/sounds.c	\
		sources/menus/lang.c	\
		sources/save//set_up_saves.c	\
		sources/game/game.c	\
		sources/buttons/resolutions/delete.c	\
		sources/buttons/fonctions.c	\
		sources/buttons/fonctions2.c	\
		sources/buttons/fonctions3.c	\
		sources/buttons/functs.c	\
		sources/menus/change_lang.c	\
		sources/menus/change_lang_other.c \
		sources/inventory/inventory.c	\
		sources/skilltree/skilltree.c	\
		sources/inventory/adding.c	\
		sources/inventory/delete.c	\
		sources/inventory/mooving.c	\
		sources/inventory/update.c	\
		sources/inventory/modifier.c	\
		sources/buttons/binding/bind.c	\
		sources/buttons/binding/bind2.c	\
		sources/buttons/binding/configs.c	\
		sources/quests/quests.c	\
		sources/collisions/check_collisions_auxiliaries.c \
		sources/collisions/check_collisions_function.c \
		sources/collisions/check_collisions.c \
		sources/collisions/events_collisions.c \
		sources/collisions/init_collisions.c \
		sources/collisions/init_movements.c \
		sources/collisions/init_view.c \
		sources/collisions/move_back.c \
		sources/collisions/view_follow.c \
		sources/collisions/init_vertex_arrays.c \
		sources/collisions/init_transitions_positions.c \
		sources/json/fetch_object_header.c \
		sources/json/init_parser.c \
		sources/json/parse_array.c \
		sources/json/parse_number.c \
		sources/json/parse_objects.c \
		sources/json/parse_string.c \
		sources/json/parse_value.c \
		sources/json/parse_whitespace.c \
		sources/json/json_parser.c	\
		sources/menus/keys.c	\
		sources/window/window.c \
		sources/collisions/update_view.c	\
		sources/skilltree/buy.c	\
		sources/skilltree/sell.c	\
		sources/skilltree/desc.c	\
		sources/menus/pause_menu.c	\
		sources/save/create_save.c	\
		sources/save/open.c	\
		sources/save/apply.c	\
		sources/particles/particles.c	\
		sources/particles/create_fog.c	\
		sources/particles/create_rain.c	\
		sources/window/free/free_all.c	\
		sources/window/free/free_button.c	\
		sources/window/free/free_params.c	\
		sources/window/free/free_menus.c	\
		sources/particles/free_particles.c	\
		sources/animations/do_animation.c	\
		sources/animations/do_transition.c	\
		sources/inventory/status.c	\
		sources/menus/hud.c	\
		sources/menus/hud2.c	\
		sources/menus/hud3.c	\
		sources/buttons/funct2.c	\
		sources/debug_room/do_htp.c	\
		sources/save/bounds.c	\
		sources/save/save.c	\
		sources/joystick/joystick.c	\
		sources/interactions/add_cell.c \
		sources/interactions/check_interactions.c \
		sources/interactions/do_text_loop.c \
		sources/interactions/init_interact_structure.c \
		sources/interactions/init_interactions.c \
		sources/battle_engine/ui/init_battle.c \
		sources/battle_engine/ui/do_battle.c \
		sources/battle_engine/attack/choose_arrow_definitions.c \
		sources/battle_engine/attack/do_attack.c \
		sources/battle_engine/attack/init_attack.c \
		sources/battle_engine/defense/check_collisions.c \
		sources/battle_engine/defense/choose_position.c \
		sources/battle_engine/defense/do_defense_loop.c \
		sources/battle_engine/defense/do_math_pattern.c \
		sources/battle_engine/defense/events_defense.c \
		sources/battle_engine/defense/fetch_patterns.c \
		sources/battle_engine/defense/generate_pattern.c \
		sources/battle_engine/defense/init_defense.c \
		sources/collisions/init_collisions_structure.c	\
		sources/animations/do_cutscene.c	\

SRC_TESTS	=	tests/tests.c	\
			tests/my_putstr.c	\
			tests/my_getnbr.c	\
			tests/my_itoa.c	\
			tests/usage.c	\

OBJ	=	$(SRC:.c=.o)

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

CFLAGS	=	-Iincludes -lcsfml-system -lcsfml-audio -lm \
			-Wall -Wextra -g3 -lcsfml-graphics -lcsfml-window

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

NAME	=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f includes/*.gch

fclean: clean
	rm -f *~
	rm -f *'#'
	rm -f $(NAME)
	rm -f *vgcore.*
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_tests
	rm -f tests/tests.o

tests_run:	fclean
			gcc -o unit_tests $(SRC_TESTS) -Iincludes --coverage -lcriterion
			./unit_tests
			gcovr --exclude test.c

re:	fclean all
