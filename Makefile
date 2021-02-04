NAME = DOOMBIRD

FLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/ -I includes/includes_SDL2/

LIB_DIR = libs/
LIBRARIES = $(LIB_DIR)libSDL2.dylib $(LIB_DIR)libSDL2_ttf.dylib

SDLX_DIR = SDLX/
INPUT_DIR = input/
SRCS_DIR = srcs/

BIN_DIR = bin/


INPUT_NAMES = 			\
	input_entry			\
	controller_in		\
	keyboard_in			\

SDLX_NAMES = 			\
	SDLX_init			\
	SDLX_render_queue	\
	SDLX_render			\

C_FILES =				\
	$(SRCS_NAMES) 		\

SRCS_NAMES =	\
	$(addprefix $(SDLX_DIR), $(SDLX_NAMES))		\
	$(addprefix $(INPUT_DIR), $(INPUT_NAMES))	\
	main 				\
	
SRCS = $(addsuffix .c, $(addprefix $(SRCS_DIR), $(C_FILES)))
OBJS = $(addprefix $(BIN_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(BIN_DIR) $(OBJS)
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBRARIES)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)%.o: %.c
	mkdir -p $(BIN_DIR)$(dir $<)
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

run: re clean
	./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all