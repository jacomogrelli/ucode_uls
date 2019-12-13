NAME = uls


INC = uls.h

INCF = inc/uls.h

INC_LIB = ./libmx/libmx.a

SRC = \

SRCF = \

OBJ = \

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -g

all: install clean

install:
	@make -C libmx
	@cp $(SRCF) $(INCF) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) $(INC_LIB) $(OBJ) -o $(NAME)
	@mkdir -p ./obj
	@mv $(OBJ) ./obj
	@rm -rf $(SRC) $(INC)

uninstall:
	@rm -rf $(NAME) $(INC_LIB) ./obj

clean:
	@rm -rf ./obj
	@rm -rf $(OBJ) $(SRC) $(INC)

reinstall: uninstall install

test:
	@cp $(SRCF) $(INCF) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) $(INC_LIB) $(OBJ) -o $(NAME)
	@mkdir -p ./obj
	@mv $(OBJ) ./obj
	@rm -rf $(SRC) $(INC)
