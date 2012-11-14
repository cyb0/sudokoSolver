GCC		=	/bin/gcc

SRC		=	./src
INC		=	./include
BUILD	=	./build

all:	clean
					
				touch $(BUILD)/grid.txt
				$(GCC) -Wall -Werror -I $(INC) -o $(BUILD)/sudoko.o $(SRC)/sudoko.c

clean:

				rm -rf $(BUILD)/* 
