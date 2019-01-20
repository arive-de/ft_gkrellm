NAME = ft_gkrellm

SRCSFILES = main.cpp \
			GraphicalUIClass.cpp \
			IMonitorDisplayClass.cpp \
			IMonitorModuleClass.cpp \
			CpuModule.cpp \
			DatetimeModule.cpp \
			OsInfosModule.cpp \
			HostnameModule.cpp \
			ShellUIClass.cpp \
			UsernameModule.cpp

SRCPATH = srcs
OBJPATH = obj
CC = clang++
INCLUDES = -I $(SRCPATH) -I $(shell pwd)/SFML/include
# LIBS =	-L SFML/lib -lsfml-graphics -lsfml-window -lsfml-system\
# 		SFML/Frameworks/sfml-graphics.framework/sfml-graphics\
# 		SFML/Frameworks/sfml-window.framework/sfml-window\
# 		SFML/Frameworks/sfml-system.framework/sfml-system
# LIBS = -L SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

LDENV = DYLD_FRAMEWORK_PATH="$(shell pwd)/SFML/Frameworks"
# export DYLD_FRAMEWORK_PATH=`pwd`"/SFML/Frameworks"

LIBS =	-framework sfml-graphics -framework sfml-window -framework sfml-system\
		-F SFML/Frameworks -lncurses
CFLAGS = -Werror -Wall -Wextra -O2 -g
RM = rm -rf

SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.cpp=$(OBJPATH)/%.o)


all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "Compiling all"
	$(CC) -o $@ $(CFLAGS) $(OBJECTS) $(LIBS)

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

rmsfml:
	rm -rf SFML
sfml: rmsfml
	curl -O "https://www.sfml-dev.org/files/SFML-2.2-osx-clang-universal.tar.gz" 
	mkdir SFML
	tar -xzf SFML-2.2-osx-clang-universal.tar.gz -C SFML --strip-components=1
	mv SFML/extlibs/freetype.framework SFML/Frameworks/
	rm -rf "SFML-2.2-osx-clang-universal.tar.gz"

ldenv:
	@echo export $(LDENV)

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all
