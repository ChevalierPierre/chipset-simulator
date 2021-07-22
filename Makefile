##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .cpp .o

CC=				g++

FLAGS=			-g3 -Wall -Wextra -Werror -I./include

LFLAGS=			-L./lib

NAME=			nanotekspice

INCLUDE_DIR=	./include
INCLUDE=		$(INCLUDE_DIR)/nanotekspice.hpp \
				$(INCLUDE_DIR)/parser.hpp \
				$(INCLUDE_DIR)/pin.hpp \
				$(INCLUDE_DIR)/input.hpp \
				$(INCLUDE_DIR)/output.hpp \
				$(INCLUDE_DIR)/true.hpp \
				$(INCLUDE_DIR)/false.hpp \
				$(INCLUDE_DIR)/clock.hpp \
				$(INCLUDE_DIR)/create.hpp \
				$(INCLUDE_DIR)/IComponent.hpp \
				$(INCLUDE_DIR)/nand_gate.hpp \
				$(INCLUDE_DIR)/nor_gate.hpp \
				$(INCLUDE_DIR)/and_gate.hpp \
				$(INCLUDE_DIR)/or_gate.hpp \
				$(INCLUDE_DIR)/xor_gate.hpp \
				$(INCLUDE_DIR)/4001.hpp \
				$(INCLUDE_DIR)/4071.hpp \
				$(INCLUDE_DIR)/4081.hpp \
				$(INCLUDE_DIR)/4030.hpp \
				$(INCLUDE_DIR)/4011.hpp


SRC_DIR=		./srcs
SRC=			$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/parser.cpp \
				$(SRC_DIR)/create.cpp \
				$(SRC_DIR)/creator.cpp \
				$(SRC_DIR)/special/input.cpp \
				$(SRC_DIR)/special/output.cpp \
				$(SRC_DIR)/special/true.cpp \
				$(SRC_DIR)/special/false.cpp \
				$(SRC_DIR)/special/clock.cpp \
				$(SRC_DIR)/gates/nor_gate.cpp \
				$(SRC_DIR)/gates/or_gate.cpp \
				$(SRC_DIR)/gates/xor_gate.cpp \
				$(SRC_DIR)/gates/and_gate.cpp \
				$(SRC_DIR)/gates/nand_gate.cpp \
				$(SRC_DIR)/component/4001.cpp \
				$(SRC_DIR)/component/4071.cpp \
				$(SRC_DIR)/component/4081.cpp \
				$(SRC_DIR)/component/4030.cpp \
				$(SRC_DIR)/component/4011.cpp

OBJ=			$(SRC:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJ) $(INCLUDE)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

.cpp.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean:			clean
	@rm -rf $(NAME)
	@rm -rf lib/*.a

re: fclean all

.PHONY: clean fclean re
