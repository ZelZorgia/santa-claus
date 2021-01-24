
NAME		=	SantaKoalaus

SANTA		=	santa

SRC		=  	main.cpp \
			Box.cpp \
			ConveyorBeltPePeNoel.cpp \
			Elf.cpp \
			GiftPaper.cpp \
			LittlePony.cpp \
			MyUnitTests.cpp \
			Object.cpp \
			TablePePeNoel.cpp \
			Teddy.cpp \
			Toy.cpp \
			Wrap.cpp

SSRC		=	santa.cpp

OBJ		=	$(SRC:.cpp=.o)

SOBJ		=	$(SSRC:.cpp=.o)

CXXFLAGS	+= 	-W -Wall -Werror -Wextra

RM		= 	rm -f

CC		= 	g++

%.o: %.cpp
		@printf "[\033[0;32mdone\033[0m] % 33s\n" $<
		@$(CC) -c -o $@ $< $(CXXFLAGS)

all:		$(NAME) $(SANTA)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) -o $(NAME)

$(SANTA):	$(SOBJ)
		@$(CC) $(SOBJ) -o $(SANTA)
		@echo -en "`cat asciiart 2>&-`"

clean:
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJ)
		@$(RM) $(OBJ) $(SOBJ)

fclean:		clean
		@$(RM) $(NAME) $(SANTA)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME)

re:		fclean all

bin:		re clean

.PHONY:		all clean fclean re bin
