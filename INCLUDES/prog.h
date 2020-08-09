/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <niboute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:51:39 by jcharrou          #+#    #+#             */
/*   Updated: 2020/08/09 08:43:33 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROG_H
# define PROG_H

# include "../libft/libft.h"
# include "sdl.h"
# include <sys/types.h>
# include <sys/sysctl.h>
# include <pthread.h>
# include <math.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <inttypes.h>
# include <pthread.h>
# include "get_next_line.h"
# ifndef OPEN_MAX
# define OPEN_MAX (FOPEN_MAX)
#endif
# define IMG_Home "../RSCS/home_menu.bmp"
# define HOME "./RSCS/home/home2.bmp"
# define PLAY "./RSCS/home/PLAY.bmp"
# define MAPEDIT "./RSCS/home/mapedit.bmp"
# define SET_HOME "./RSCS/home/SETTINGS_home.bmp"
# define EXIT "./RSCS/home/EXIT.bmp"
# define SET_BACK "./RSCS/menu/settings/back_to_main_menu.bmp"
# define SET_VIDEO "./RSCS/menu/settings/video.bmp"
# define SET_AUDIO "./RSCS/menu/settings/audio.bmp"
# define SET_GAMEPLAY "./RSCS/menu/settings/gameplay.bmp"
# define VID_RES "./RSCS/menu/settings/video/Resolution.bmp"
# define VID_VSYNC "./RSCS/menu/settings/video/VSYNC.bmp"
# define VID_FS "./RSCS/menu/settings/video/Fullscreen.bmp"
# define VID_GPU "./RSCS/menu/settings/video/GPUACCELL.bmp"
# define VID_ALIAS "./RSCS/menu/settings/video/anti-aliasing.bmp"
# define VID_TEXTURE "./RSCS/menu/settings/video/texture_quality.bmp"
# define VID_RET "./RSCS/menu/settings/video/RETURN.bmp"
# define VID_APPLY "./RSCS/menu/settings/video/APPLY.bmp"
# define GAME_DIF "./RSCS/menu/settings/Gameplay/difficulty.bmp"
# define GAME_SENS "./RSCS/menu/settings/Gameplay/sensitivity.bmp"
# define GAME_CONTROL "./RSCS/menu/settings/Gameplay/controls.bmp"
# define GAME_APPLY "./RSCS/menu/settings/Gameplay/apply.bmp"
# define GAME_RETURN "./RSCS/menu/settings/Gameplay/return.bmp"
#define SHOW_CONTROLS "./RSCS/menu/settings/Gameplay/show_controls/show_controls.bmp"
# define AUDIO_VOLUME "./RSCS/menu/settings/audio/volume.bmp"
# define AUDIO_MUSIC "./RSCS/menu/settings/audio/music.bmp"
# define AUDIO_EFFEECT "./RSCS/menu/settings/audio/effect.bmp"
# define AUDIO_APPLY "./RSCS/menu/settings/audio/apply.bmp"
# define AUDIO_RETURN "./RSCS/menu/settings/audio/return.bmp"
# define PLAY_STORY "./RSCS/menu/play/story.bmp"
# define PLAY_ARCADE "./RSCS/menu/play/arcade.bmp"
# define PLAY_MULTI "./RSCS/menu/play/multi.bmp"
# define PLAY_RETURN "./RSCS/menu/play/HOME_MENU.bmp"
# define STORY_NORMAL "./RSCS/menu/play/story/normal.bmp"
# define STORY_HARD "./RSCS/menu/play/story/hard.bmp"
# define STORY_HELL "./RSCS/menu/play/story/hell.bmp"
# define STORY_RETURN "./RSCS/menu/play/story/story_home_menu.bmp"
# define ARCADE_MAP "./RSCS/menu/play/arcade/arcademap.bmp"
# define ARCADE_RETURN "./RSCS/menu/play/arcade/arcadehome.bmp"
# define MULTI_MAP "./RSCS/menu/play/multi/multimap.bmp"
# define MULTI_RETURN "./RSCS/menu/play/multi/multi_homemenu.bmp"
# define CEL_EPIC_0 "./RSCS/texture/ceiling/epic/0.bmp"
# define CEL_EPIC_1 "./RSCS/texture/ceiling/epic/1.bmp"
# define CEL_EPIC_2 "./RSCS/texture/ceiling/epic/2.bmp"
# define CEL_HIGH_0 "./RSCS/texture/ceiling/high/0.bmp"
# define CEL_HIGH_1 "./RSCS/texture/ceiling/high/1.bmp"
# define CEL_HIGH_2 "./RSCS/texture/ceiling/high/2.bmp"
# define CEL_NORMAL_0 "./RSCS/texture/ceiling/normal/0.bmp"
# define CEL_NORMAL_1 "./RSCS/texture/ceiling/normal/1.bmp"
# define CEL_NORMAL_2 "./RSCS/texture/ceiling/normal/2.bmp"
# define FLO_EPIC_0 "./RSCS/texture/floor/epic/0.bmp"
# define FLO_EPIC_1 "./RSCS/texture/floor/epic/1.bmp"
# define FLO_EPIC_2 "./RSCS/texture/floor/epic/2.bmp"
# define FLO_HIGH_0 "./RSCS/texture/floor/high/0.bmp"
# define FLO_HIGH_1 "./RSCS/texture/floor/high/1.bmp"
# define FLO_HIGH_2 "./RSCS/texture/floor/high/2.bmp"
# define FLO_NORMAL_0 "./RSCS/texture/floor/normal/0.bmp"
# define FLO_NORMAL_1 "./RSCS/texture/floor/normal/1.bmp"
# define FLO_NORMAL_2 "./RSCS/texture/floor/normal/2.bmp"
# define WAL_EPIC_0 "./RSCS/texture/wall/epic/0wallhexred.bmp"
# define WAL_EPIC_1 "./RSCS/texture/wall/epic/1wallbrick.bmp"
# define WAL_EPIC_2 "./RSCS/texture/wall/epic/2wallwood.bmp"
# define WAL_EPIC_3 "./RSCS/texture/wall/epic/3walleagleflag.bmp"
# define WAL_EPIC_4 "./RSCS/texture/wall/epic/4wallcroix.bmp"
# define WAL_EPIC_5 "./RSCS/texture/wall/epic/5wallgreenss.bmp"
# define WAL_EPIC_6 "./RSCS/texture/wall/epic/6wallgreen.bmp"
# define WAL_EPIC_7 "./RSCS/texture/wall/epic/7wallhitler.bmp"
# define WAL_EPIC_8 "./RSCS/texture/wall/epic/8walleagleflagblue.bmp"
# define WAL_EPIC_9 "./RSCS/texture/wall/epic/9wallblue.bmp"
# define WAL_HIGH_0 "./RSCS/texture/wall/high/0wallhexred.bmp"
# define WAL_HIGH_1 "./RSCS/texture/wall/high/1wallbrick.bmp"
# define WAL_HIGH_2 "./RSCS/texture/wall/high/2wallwood.bmp"
# define WAL_HIGH_3 "./RSCS/texture/wall/high/3walleagleflag.bmp"
# define WAL_HIGH_4 "./RSCS/texture/wall/high/4wallcroix.bmp"
# define WAL_HIGH_5 "./RSCS/texture/wall/high/5wallgreenss.bmp"
# define WAL_HIGH_6 "./RSCS/texture/wall/high/6wallgreen.bmp"
# define WAL_HIGH_7 "./RSCS/texture/wall/high/7wallhitler.bmp"
# define WAL_HIGH_8 "./RSCS/texture/wall/high/8walleagleflagblue.bmp"
# define WAL_HIGH_9 "./RSCS/texture/wall/high/9wallblue.bmp"
# define WAL_NORMAL_0  "./RSCS/texture/wall/normal/0wallhexred.bmp"
# define WAL_NORMAL_1 "./RSCS/texture/wall/normal/1wallbrick.bmp"
# define WAL_NORMAL_2 "./RSCS/texture/wall/normal/2wallwood.bmp"
# define WAL_NORMAL_3 "./RSCS/texture/wall/normal/3walleagleflag.bmp"
# define WAL_NORMAL_4 "./RSCS/texture/wall/normal/4wallcroix.bmp"
# define WAL_NORMAL_5 "./RSCS/texture/wall/normal/5wallgreenss.bmp"
# define WAL_NORMAL_6 "./RSCS/texture/wall/normal/6wallgreen.bmp"
# define WAL_NORMAL_7 "./RSCS/texture/wall/normal/7wallhitler.bmp"
# define WAL_NORMAL_8 "./RSCS/texture/wall/normal/8walleagleflagblue.bmp"
# define WAL_NORMAL_9 "./RSCS/texture/wall/normal/9wallblue.bmp"
# define PROG_H
# define INIT_SDL		0
# define INIT_WIN		1
# define INIT_REN		2
# define BAD_ARG  		3
# define BAD_FILE		4
# define BAD_FILENAME 	5
# define BAD_MAP		6
# define BAD_SPAWN		7
# define BAD_BLOCK		8
# define NB_THREADS 	sysconf(_SC_NPROCESSORS_CONF)
# define TEXT_W			64 * floor->texture_res
# define TEXT_H			64 * floor->texture_res
# define WALL			0
# define WALL_TEXT		1
# define SPRITE			2
# define SPRITE_TEXT	3
# define BLOCK_H		4
# define CEILING		5
# define CEILING_TXT	6
# define FLOOR_TXT		7

/*
 ** Structure pixel
 */
typedef struct		s_pixel
{
	int		x;
	int		y;
	Uint8		r;
	Uint8		g;
	Uint8		b;
	Uint8		a;
	int		w_width;
	int		w_hight;
}			t_pixel;

/*
 ** Structure rect
 */
typedef struct		s_rect
{
	int		x;
	int		y;
	int		w;
	int		h;
}			t_rect;

/*
 ** Structure map
 */
typedef struct		s_elem
{
	SDL_TimerID		timercrouchdown;
	SDL_TimerID		timercrouchup;
	SDL_TimerID		timerjump;
	SDL_TimerID		timerwalk;
	SDL_TimerID		timerflyup;
	SDL_TimerID		timerflydown;
	SDL_TimerID		timer3;
	SDL_Rect 		rectfps;
	TTF_Font		*fpsfont;
	SDL_Color		fpscolor;
	SDL_Surface		*fpssurf;
	SDL_Texture		*fpstext;
	const Uint8		*keystat;
	char			**box;
	char			***map;
	char			***new;
	double			spawn_x;
	double			spawn_y;
	double			tmpx;
	double			tmpy;
	int				spawn_floor;
	int				width;
	int				hight;
	int				nh;
	int				nw;
	int				max_floor;
	int 			min;
	int 			max;
	int				j;
	int				k;
	int 			spawn;
	float 			playerwidth;
	t_rect			rect;
	t_rect			playerrect;
	SDL_Surface		*surf;
	SDL_Texture		*text;
	SDL_Surface		**walltext;
	SDL_Surface		**floortext;
	SDL_Surface		*skybox;
	SDL_Surface		**ceilingtext;
	SDL_Surface		*icon;
	SDL_Surface		**weapon;
	uint32_t			time;
	uint32_t			oldtime;
	double				frametime;
	double				speed;
	double				speedshift;
	double				angle;
	double				newangle;
	double				rotatespeed;
	int				x;
	int				y;
	int 				m;
	int 				currentstair;
	int 				txtpos;
	int 				crosshair;
	double				olddirx;
	double				rdirx;
	double				rdiry;
	int				mapx;
	int				mapy;
	double				posx;
	double				posy;
	double				rposx;
	double				rposy;
	double				deltadistx;
	double				deltadisty;
	double				sidedistx;
	double				sidedisty;
	int				dst;
	int				dend;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	double				perwalldist;
	int				linehight;
	double				oldplanex;
	double				ratio;
	t_pixel				pix0;
	t_pixel				pix1;
	t_pixel				wallcolor;
	char				*fps;
	double				mousex;
	int				mousey;
	int				lookupdown;
	int				newlookupdown;
	double 				crouchsensi;
	double				flysensi;
	int 				currenttime;
	int 				previoustime;
	int 				walk;
	int 				walkswitch;
	Uint32				red;
	Uint32				green;
	Uint32				blue;
	Uint32				grey;
	Uint32				black;
	Uint32				white;
	Uint32 				color;
	int 				texx;
	int 				texy;
	int 				txtnum;
	int 				floor_txtnum;
	int 				ceiling_txtnum;
	double				wallx;
	double				step;
	double				texpos;
	t_rect				minimap;
	t_rect				radar;
	int 				sensitivity_x;
	int 				sensitivity_y;
	double 				sensitivity_setup;
	int 				wallsize;
	int 				psy;
	int 				psyeffect;
	int 				blocksize;
	t_pixel				cmppixel0;
	t_pixel				cmppixel1;
	int 				cmpr;
	int 				cray;
	int 				texture_res;
	int 				crouch;
	int 				crouchds;
	int 				crouchde;
	int 				fly;
	int 				deltaline;
	int 				deltafly;
	int 				deltacrouch;
	double				floorwallx;
	double				floorwally;
	double				playerdist;
	double				disttowall;
	double				dist;
	double				weight;
	double				floorx;
	double				floory;
	int					ftx;
	int					fty;
	int 				stepup;
	int 				swim;
	int 				jump;
	int 				gravity;
	int					test;
}					t_elem;

/*
 ** Structure Programme
 */
typedef struct          s_map
{
	t_elem				*floor;
	char				*file;
	char				*line;
	char				*tmp;
	int					fd;
	int					i;
	int					hight;
	int					width;
	int					error;
	int					max_floor;
}                       t_map;

/*
** Structure SDL Variables
*/

typedef struct		s_env
{
	SDL_Surface		*cursorsurf;
	SDL_Texture		*cursortext;
	SDL_Rect		rectcursor;
	int				cursx;
	int				cursy;
	SDL_TimerID 	timer;
	SDL_TimerID 	timer2;
	SDL_Rect 		rectfps;
	SDL_Rect 		rect_intro;
	SDL_Rect		rect_baba;
	SDL_Texture		*fpstext;
	SDL_Rect		*rect;
	SDL_Texture		*text;
	SDL_Texture		*text2;
	SDL_Surface		*surf;
	SDL_Surface		*surf2;
	SDL_Surface		**wall_texture;
	SDL_Surface		*floor_texture;
	SDL_Surface		*ceiling_texture;
	SDL_Surface		*icon;
	SDL_Surface		**weapon;
	int				test;
    SDL_Renderer	*ren;
    SDL_Window		*win;
    SDL_Event		events;
	SDL_Texture		*bmpTex;
	SDL_Texture		*fontTex;
	SDL_Texture		*fontTex2;
	SDL_Surface		*bmpSurf;
	SDL_Surface		*texte;
	TTF_Font 		*police;
	TTF_Font 		*police2;
	SDL_Color		color;
	SDL_Color		red;
	SDL_Rect 		pos;
	SDL_Rect 		pos2;
	int				error_vid;
	int				introstep;
	int				intro;
	int				option;
	int				menu;
	int				vid_menu;
	int				gameplay_menu;
	int				res;
	int				gpu;
	int				vsync;
	int				fullscreen;
	int				aliasing;
	int				text_q;
	int				apply;
	int				ret_op;
	int 			play;
	int				mapedit;
	int				play_ready;
	int				op_menu;
	int				exit;
	int				ex_opt;
	int				audio;
	int				video;
	int				controls;
	int				gameplay;
	int				game_difficulty;
	int				game_sensitivity;
	int				game_controls;
	int				show_controls;
	int				game_apply;
	int				game_return;
	int				dif_op;
	int				sensitivity_op;
	int				sens_value;
	char			*sensitivity_value;
	int				audio_menu;
	int				audio_volume;
	int				audio_music;
	int				audio_effect;
	int				audio_apply;
	int				audio_return;
	int				effect_op;
	int				music_op;
	int				int_volume_value;
	char			*char_volume_value;
	int				play_menu;
	int				play_story;
	int				play_arcade;
	int				play_multi;
	int				play_return;
	int				story_menu;
	int				story_normal;
	int				story_hard;
	int				story_hell;
	int				story_return;
	int				arcade_menu;
	int				arcade_map;
	int				arcade_return;
	int				multi_menu;
	int				multi_map;
	int				multi_return;
	int				res_op;
	int				vsync_op;
	int				fs_op;
	int				gpu_op;
	int				aliasing_op;
	int				text_q_op;
	int				apply_video_op;
	int				p;
	double			res_width;
    double			res_hight;
}                       t_env;

/*
** Structure SDL FLAGS
*/
typedef struct          s_sdl
{
    double              res_width;
    double              res_hight;
    int                 windowed;
    int                 windowed_resize_full;
    int                 fullscreen;
    int                 fullscreen_maxres;
    int                 hard_accel;
    int                 vsync;
	int					w_max;
	int					h_max;
	int					test;
	double 				pro_hight;
	double 				pro_width;
}                       t_sdl;

int						main(int ac, char **av);
double					ft_floor(double nb);
char					*ftoa(double n, char *res);
int 					ft_ctoi(const char *str);

/*
** Related SDL INIT / RENDER Functions
*/
int						ft_set_sdl(t_sdl *sdl, t_env *env, t_elem *floor);
int						ft_init_events(t_env *env, t_sdl *sdl, t_elem *floor);
int                     ft_error(int error);
int						ft_exit_sdl(t_env *env);
int						ft_set_ttf(t_sdl *sdl, SDL_Surface *bmpSurf);

/*
** Related SDL RENDER Functions
*/

struct SDL_Renderer     *ft_init_renderer(SDL_Window *win, t_sdl *sdl);

/*
** Window events setup
*/
SDL_Window              *ft_create_window(t_sdl *sdl);
void    				get_max_res(t_sdl *sdl);

/*
** Setup struct
*/
void					ft_set_sdlstruct(t_sdl *sdl, t_env *env);
void					ft_set_envstruct(t_env *env);
void					ft_setuppixels(uint_fast32_t pixels[2880][5120]);

/*
** Set Menu
*/
void					interface_menu(t_env *env);
void					option_menu(t_env *env);
void					set_events_struct(t_env *env);
void					open_options(t_env *env);
int						exit_from_menu(t_env *env);
void 					videos_menu(t_env *env, t_sdl *sdl);
void					switch_menu(t_env *env);
void					switch_menu_1(t_env *env);
void					switch_menu_2(t_env *env);
void					switch_menu_3(t_env *env);
void					switch_option(t_env *env);
void					switch_option_1(t_env *env);
void					switch_option_2(t_env *env);
void					switch_option_3(t_env *env);
void					open_video(t_env *env);
void 					video_menu(t_sdl *sdl, t_env *env);
void					exit_from_option(t_env *env);
void					switch_video_op(t_env *env);
void					switch_video_op_1(t_env *env);
void					switch_video_op_2(t_env *env);
void					switch_video_op_3(t_env *env);
void					switch_video_op_4(t_env *env);
void					switch_video_op_5(t_env *env);
void					switch_video_op_6(t_env *env);
void					switch_video_op_7(t_env *env);
void					switch_video_op_8(t_env *env);
void					switch_video_op_9(t_env *env);
void					switch_video_op_10(t_env *env);
void					switch_video_op_11(t_env *env);
void					switch_video_op_12(t_env *env);
void					switch_video_op_13(t_env *env);
void					choose_res(t_sdl *sdl, t_env *env);
void					choose_vsync(t_sdl *sdl, t_env *env);
void					choose_fs(t_sdl *sdl, t_env *env);
void					choose_gpu(t_sdl *sdl, t_env *env);
void					choose_aliasing(t_sdl *sdl,t_env *env);
void					choose_texture(t_sdl *sdl, t_env *env);
void					back_to_option(t_env *env);
void					change_video_option1(t_env *env);
void					change_video_option2(t_env *env);
void					change_video_option3(t_env *env);
void					change_video_option4(t_env *env);
void					apply_video_option(t_env *env);
void					apply_video_option2(t_sdl *sdl, t_env *env, t_elem *floor);
void					play_option(t_env *env);
void					menu_events_list(t_env *env, t_sdl *sdl, t_elem *floor);
void					set_ttf(t_env *env);
void					set_ttf_rect(t_env *env, double x, double y, double w, double h);
void					error_option(t_sdl *sdl, t_env *env);
void					open_gameplay(t_env *env);
void					gameplay_menu(t_sdl *sdl, t_env *env);
void					switch_gameplay_op(t_env *env, t_elem *floor);
void					switch_gameplay_1(t_env *env);
void					switch_gameplay_2(t_env *env);
void					switch_gameplay_3(t_env *env);
void					switch_gameplay_4(t_env *env);
void					switch_gameplay_5(t_env *env);
void					switch_gameplay_6(t_env *env);
void					switch_gameplay_7(t_env *env);
void					switch_gameplay_8(t_env *env);
void					change_difficulty(t_env *env);
void					change_sensitivity(t_env *env);
void					open_controls(t_env *env);
void					exit_from_gameplay(t_env *env);
void					apply_gameplay(t_env *env, t_elem *floor);
void					choose_sensitivity(t_sdl *sdl, t_env *env);
void					choose_difficulty(t_sdl *sdl, t_env *env);
void					open_audio(t_env *env);
void					audio_menu(t_sdl *sdl, t_env *env);
void					switch_audio_op(t_env *env);
void					open_play_content(t_env *env);
void					switch_play_op(t_env *env);
void					switch_play_1(t_env *env);
void					switch_play_2(t_env *env);
void					switch_play_3(t_env *env);
void					switch_play_4(t_env *env);
void					switch_play_5(t_env *env);
void					switch_play_6(t_env *env);
void					play_menu(t_env *env);
void					open_story(t_env *env);
void					story_menu(t_env *env);
void					switch_story_op(t_env *env);
void					switch_story_1(t_env *env);
void					switch_story_2(t_env *env);
void					switch_story_3(t_env *env);
void					switch_story_4(t_env *env);
void					switch_story_5(t_env *env);
void					switch_story_6(t_env *env);
void					arcade_menu(t_env *env);
void					open_arcade(t_env *env);
void					open_multi(t_env *env);
void					switch_arcade_op(t_env *env);
void					exit_from_arcade(t_env *env);
void					multi_menu(t_env *env);
void					exit_from_multi(t_env *env);
void					exit_from_story(t_env *env);
void					open_normal(t_env *env);
void					open_hard(t_env *env);
void					open_hell(t_env *env);
void					switch_multi_op(t_env *env);
void					control_menu(t_env *env);
void					exit_from_control(t_env *env);
void    				ft_cursor(t_env *env);
void					change_effect(t_env *env);
void					change_music(t_env *env);
void					exit_from_play_menu(t_env *env);
void					change_volume(t_env *env);
void					switch_audio_op(t_env *env);
void					switch_audio_1(t_env *env);
void					switch_audio_2(t_env *env);
void					switch_audio_3(t_env *env);
void					switch_audio_4(t_env *env);
void					switch_audio_5(t_env *env);
void					switch_audio_6(t_env *env);
void					switch_audio_7(t_env *env);
void					switch_audio_8(t_env *env);
void					switch_audio_9(t_env *env);
void					audio_menu(t_sdl *sdl, t_env *env);
void					choose_effect(t_sdl *sdl, t_env *env);
void					choose_music(t_sdl *sdl, t_env *env);
void					choose_volume(t_sdl *sdl, t_env *env);
void					exit_from_audio(t_env *env);

/*
**Setup map
*/
int     				ft_checkfilename(char *file);
int						ft_parse_map_param(t_map *map);
int						get_next_line(const int fd, char **line);
int        				ft_filwidth(t_elem *floor);
int						ft_checkspawn(t_elem *floor);
int     				ft_checkfloors(t_elem *floor);
char					*join_free(char *s1, char *s2);
void					ft_printmap(t_elem *floor);
void					ft_newmap(t_elem *floor);
void					ft_filmap(t_elem *floor);
int						ft_wolfcheck(t_elem *floor);
int						ft_checkvalue(t_elem *floor);
int						ft_checkstairs(t_elem *floor);
int						ft_checkmap(t_elem *floor);

/*
**Display Game
*/
int						ft_display_game(t_env *env, t_elem *floor);
void					ft_set_pixels(t_env *env, t_elem *floor);
void					ft_crosshair(t_env *env);
void					ft_minimap(t_env *env, t_elem *floor);
void					ft_radar(t_env *env, t_elem *floor);
void					ft_drawcompass(int x, int y, t_env *env, t_elem *floor);
Uint32					ft_printfps(Uint32 intervalle, void *parametre);
void					ft_countfps(t_elem *floor);
char					*ftoa(double n, char *res);
void					ft_initfps(t_elem *floor, t_env *env);
void					ft_intro(t_env *env);
void					ft_init_intro(t_env *env);
Uint32					ft_speak(Uint32 intervalle, void *param);
void					ft_render_intro(t_env *env);
void					ft_baba(t_env *env);
void    				ft_intro_content_p1(t_env *env);
void    				ft_intro_content_p2(t_env *env);
void    				ft_intro_content_p3(t_env *env);
void    				ft_intro_content_p4(t_env *env);
void    				ft_intro_content_p5(t_env *env);

/*
 ** PIXELS
 */
void					ft_putpixel(SDL_Surface *surf, int x, int y, int color);
Uint32					ft_readpixel(SDL_Surface *surf, int x, int y);
void					ft_bresenham(SDL_Surface *surf, t_pixel pixel0, t_pixel pixel1, Uint32 color);
void					ft_drawrect(SDL_Surface *surf, Uint32 color, t_rect rect);

/*
 ** RENDERER
 */
void					ft_initcolors(t_env *env, t_elem *floor);
void					ft_initraycasting(t_elem *floor);
void					ft_raycasting(t_env *env, t_elem *floor);
void					ft_drawrenderer(t_env *env, t_elem *floor);
void					ft_video_op_error(t_sdl *sdl, t_env *env);

/*
 ** TEXTURE
 */
SDL_Surface				*ft_load_texture(char *file);
void					ft_init_texture(t_elem *floor);
void					ft_texnum(t_elem *floor);
void					ft_walltexture(t_elem *floor);
void					ft_ceilingtexture(t_elem *floor);
void					ft_floortexture(t_elem *floor);
void					ft_draw_walltextured(t_env *env, t_elem *floor);
void					ft_drawfloorceiling(t_env *env, t_elem *floor);

/*
 ** MOVES
 */
void					ft_inputs(t_env *env, t_elem *floor);
void					ft_mousemotion(t_env *env, t_elem *floor);
void					ft_dispminimap(t_env *env, t_elem *floor);
void					ft_speedshift(t_env *env, t_elem *floor);
void					ft_movements(t_env *env, t_elem *floor);
void					ft_walk(t_env *env, t_elem *floor);
void					ft_dive(t_elem *floor);
void					ft_crouch(t_env *env, t_elem *floor);
void					ft_jump(t_env *env, t_elem *floor);
void					ft_fly(t_env *env, t_elem *floor);

/*
 ** Free Structs
 */

void					ft_free_tab_telem(t_elem *floor);
void	    			ft_freetab(char ***tab);
void					ft_freebigtab(char ****tab);

void					ft_free_surface(SDL_Surface **surface);
void					ft_free_texture(SDL_Texture **texture);
void					ft_free_structs(t_env *env, t_map *map, t_elem *floor);
void					ft_sdl_error(char *str);
void					ft_ttf_error(char *str);
void					ft_fct_error(char *str);
void					ft_free_surface_tab(SDL_Surface ***surfaces);


#endif
