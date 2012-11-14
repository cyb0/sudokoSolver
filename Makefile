GCC		=	/bin/gcc

SRC		=	./src
INC		=	./include
BUILD	=	./build

all:	clean
					
				$(GCC) -Wall -Werror -I $(INC) -o $(BUILD)/sudoko.o $(SRC)/sudoko.c

clean:

				rm -rf $(BUILD)/sudoko.o 
