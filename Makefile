# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niboute <niboute@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/30 11:39:58 by dlartigu          #+#    #+#              #
#    Updated: 2020/08/09 09:59:35 by niboute          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############## COLORS ##################

NAME = Wolf3D
LIB = libft/libft.a
SRCS_PATH = SRCS/
PWD := $(shell pwd)

SRCS_NAME = main_utils/main.c \
			main_utils/ft_exit.c \
			main_utils/ft_set_ttf.c \
			gnl/get_next_line.c \
			gnl/join_free.c \
			gnl/ft_helpers.c \
			setsdl/ft_set_sdl.c\
			setsdl/ft_window.c \
			setsdl/ft_render_set.c \
			setsdl/ft_setstruct.c \
			setsdl/get_max_res.c \
			parsing/ft_parse_map.c\
			parsing/ft_error.c \
			parsing/ft_fillinfos.c \
			parsing/ft_printtab.c \
			parsing/ft_checkfloor.c \
			parsing/ft_wolfcheck.c \
			parsing/ft_checkspawn.c \
			free/ft_freetab.c \
			free/ft_freestruct.c \
			menu/menu_content.c \
			menu/events_menu.c \
			menu/events_option.c \
			menu/switch_menu.c \
			menu/switch_arcade.c \
			menu/switch_option.c \
			menu/switch_audio.c \
			menu/switch_audio_2.c \
			menu/events_audio.c \
			menu/events_video_options.c \
			menu/events_video_op_2.c \
			menu/switch_video_op.c \
			menu/switch_video_op_2.c \
			menu/switch_video_op_3.c \
			menu/video_content.c \
			menu/video_content_2.c \
			menu/gameplay_content.c \
			menu/switch_gameplay.c \
			menu/switch_gameplay_2.c \
			menu/events_gameplay.c \
			menu/audio_content.c \
			menu/play_menu_content.c \
			menu/story_content.c \
			menu/arcade_content.c \
			menu/multi_content.c \
			menu/switch_multi.c \
			menu/control_contents.c \
			menu/switch_menu_content.c \
			menu/switch_menu_content_2.c \
			menu/events_play_menu.c \
			menu/switch_story.c \
			menu/switch_story_2.c \
			menu/events_story.c \
			menu/ft_cursor.c \
			raycasting/ft_initray.c \
			raycasting/ft_raycasting.c \
			loadtextures/ft_walltexture.c \
			loadtextures/ft_ceilingtexture.c \
			loadtextures/ft_floortexture.c \
			loadtextures/ft_textnum.c \
			loadtextures/ft_loadtextures.c \
			draw/ft_crosshair.c \
			draw/ft_minimap.c \
			draw/ft_putpixel.c \
			draw/ft_fps.c \
			draw/ft_drawrenderer.c \
			draw/ft_drawcompass.c \
			draw/ft_draw_walltextured.c \
			draw/ft_drawfloorceiling.c \
			move/ft_moves.c \
			move/ft_mousemotion.c \
			move/ft_speedshift.c \
			move/ft_movements.c \
			move/ft_crouch.c \
			move/ft_walk.c \
			move/ft_fly.c \
			move/ft_jump.c \
			move/ft_flydive.c \
			play_content/play_content.c \
			play_content/ft_intro.c \
			play_content/ft_intro_content.c \

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))

OBJ= $(SRCS:.c=.o)

HEADER=	prog.h \
		get_next_line.h

INC=./INCLUDES/

HEADERS= $(addprefix $(INC), $(HEADER))

SDL2= SDL2/

SDL2_TTF= SDL2_TTF/

LIBSDL2_TTF= SDL2_TTF/lib/libSDL2_ttf.a

INC_LIBFT= libft/libft.h

LD_LIBFT= -L ./libft -lft

UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
		SDL_DEPENDENCIES = $(shell  ./SDL2/bin/sdl2-config --libs) \
			-L ./SDL2_TTF/lib -lSDL2_ttf
        SDL_DEPENDENCIES += -lfreetype
		INC_SDL2= SDL2/include/SDL2/
		INC_SDL2_TTF= SDL2_TTF/include/SDL2/
		MAKE_DEPLOY = deploy_linux
		FREETYPE_INSTALLED=$(shell dpkg -l | grep libfreetype6-dev)
		FREEGLUT_INSTALLED=$(shell dpkg -l | grep freeglut3-dev)
    endif
    ifeq ($(UNAME_S),Darwin)
		SDL_DEPENDENCIES = $(shell sdl2-config --libs) \
			-L ~/.brew/lib/ -lSDL2_ttf
        SDL_DEPENDENCIES += -L ~/.brew/lib -lfreetype
		INC_SDL2 = -I ~/.brew/include/SDL2/
		MAKE_DEPLOY = deploy_mac
		FREETYPE_INSTALLED=$(shell brew list | grep freetype)
		FREEGLUT_INSTALLED=$(shell brew list | grep freeglut)
	endif

CC= clang
CFLAGS += -Wall -Wextra -Werror -O2
CFLAGS += -I $(INC)
CFLAGS += -I $(INC_SDL2)
CFLAGS += -I $(INC_SDL2_TTF)
LDFLAGS += $(SDL_DEPENDENCIES)
LDFLAGS += $(LD_LIBFT)
LDFLAGS += -L ./libft -lft

all: buildft check_deploy $(NAME)

buildft:
	@make --no-print-directory -C libft/

check_deploy:
	@(test -s ./SDL2 -a FREETYPE_INSTALLED)|| make $(MAKE_DEPLOY)

$(NAME): $(LIB) $(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) -I $(INC_SDL2) \
				-I $(INC_SDL2_TTF) -I $(INC) -I $(INC_LIBFT)
			@echo "\\n[OK] Compilation de $(NAME)"

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c -o $@ $< && printf "[OK] Generation de %-50s\r" "$@"

clean:
		@rm -f $(OBJ)
		@make -C libft clean
		@echo "[OK] Supression de tous les objets"
fclean: clean
		@rm -rf $(NAME)
		@make -C libft fclean
		@echo "[OK] Supression de tous les fichiers"

clean_sdl:
        ifeq ($(UNAME_S),Linux)
			rm -rf ./SDL2
			rm -rf ./SDL2-2.0.12
			rm -rf ./SDL2-2.0.12.tar.gz
			rm -rf ./SDL2_TTF
			rm -rf ./SDL2_ttf-2.0.15
			rm -rf ./SDL2_ttf-2.0.15.tar.gz
        endif

deploy:
		make $(MAKE_DEPLOY)

deploy_linux:
		cp ./.linux/sdl.h INCLUDES/sdl.h
        ifeq ($(strip $(FREETYPE_INSTALLED)), )
			sudo apt-get install libfreetype6-dev
        endif
        ifeq ($(strip $(FREEGLUT_INSTALLED)), )
			sudo apt-get install freeglut3-dev
        endif
		$(MAKE) clean_sdl
		wget https://www.libsdl.org/release/SDL2-2.0.12.tar.gz -O SDL2-2.0.12.tar.gz \
		&& tar -xf SDL2-2.0.12.tar.gz \
		&& (cd SDL2-2.0.12 \
		&& ./configure --prefix=$(shell pwd)/SDL2 --enable-static --disable-shared \
		&& make \
		&& make install)
		@wget https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.15.tar.gz -O SDL2_ttf-2.0.15.tar.gz \
		&& tar -xf SDL2_ttf-2.0.15.tar.gz \
		&& (cd SDL2_ttf-2.0.15 \
		&& ./configure --prefix=$(shell pwd)/SDL2_TTF \
		--with-sdl-prefix=$(shell pwd)/SDL2 \
		--with-sdl-exec-prefix=$(shell pwd)/SDL2 --disable-shared \
		--enable-static \
		&& make \
		&& make install)
		@rm -rf ./SDL2-2.0.12
		@rm -rf ./SDL2-2.0.12.tar.gz
		@rm -rf ./SDL2_ttf-2.0.15
		@rm -rf ./SDL2_ttf-2.0.15.tar.gz

deploy_mac:
		cp ./.macos/sdl.h INCLUDES/sdl.h
        ifeq ($(strip $(FREETYPE_INSTALLED)), )
			brew install freetype
        endif
        ifeq ($(strip $(FREEGLUT_INSTALLED)), )
			brew install freeglut
        endif
		ifeq ($(shell brew list | grep sdl2))
			brew install sdl2
			brew install sdl_ttf
		endif

re: fclean all

redeploy: clean_sdl deploy

.PHONY: all clean fclean re buildft clean_sdl deploy redeploy check_deploy
