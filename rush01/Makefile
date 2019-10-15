NAME = ft_gkrellm

SRC = main.cpp nk_implementation.cpp GKrellM.cpp \
		./display/TermDisplay.cpp ./display/GuiDisplay.cpp ./display/IMonitorDisplay.cpp \
		./module/IMonitorModule.cpp ./module/DateModule.cpp ./module/HostnameModule.cpp ./module/OSModule.cpp ./module/CPUModule.cpp ./module/RAMModule.cpp ./module/NetworkModule.cpp

INCL = -I ./display/ -I./module/ -I./

SDL = -I ~/Library/Frameworks/SDL2.framework/Versions/A/Headers -F ~/Library/Frameworks/ -framework SDL2

OpenGL = -framework GLUT -framework OpenGL

NCURSES = -lncurses

FLAGS = -Wall -Wextra -Werror

all:
	clang++ $(FLAGS) -o $(NAME) $(SRC) $(INCL) $(NCURSES) $(SDL) $(OpenGL)


# NAME = array

# SRC = main.cpp

# OB = $(SRC:.cpp=.o)

# FLAGS = -Wall -Werror -Wextra

# all: $(NAME)

# $(NAME): $(OB)
# 	@clang++ $(FLAGS) $(SRC) -o $(NAME)
# 	@echo "\033[92m>>>$(NAME) compiled<<<\033[0m"

# clean:
# 	@rm -f $(OB)

# fclean: clean
# 	@rm -f $(NAME)

# re: fclean all
