NAME = ft_retro

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/

CC = clang++
CC_FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g3

NCURSES = -lncurses

SRC = main.cpp AAmunition.cpp ACharacter.cpp AWeapon.cpp Bullet.cpp Enemy.cpp Game.cpp Gun.cpp Player.cpp

OBJCTS = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJCTS)
	$(CC) $(CC_FLAGS) $(DEBUG_FLAGS) $(OBJCTS) -o $(NAME) -I$(INC_DIR) $(NCURSES)
$(OBJCTS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(CC_FLAGS) $(DEBUG_FLAGS) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

vpath %.c $(SRC_DIR)
