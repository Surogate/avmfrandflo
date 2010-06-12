##
## Makefile for  in /u/all/chanio_f/cu/malloc
## 
## Made by Prenom Nom
## Login   <chanio_f@epitech.net>
## 
## Started on  Tue Feb  2 17:23:28 2010 Prenom Nom
## Last update Sun Feb  7 07:32:35 2010 Florian Chanioux
##

# PROJECT

NAME		=	avm_int32.so


# DIRECTORIES

DIR_SRC		=	./src/
DIR_INC		=	./inc/
DIR_LIB		=	./lib/

# BINARIES

CXX		=	g++

RM		=	rm -vf
CD		=	cd
ETAGS		=	etags
CP		=	cp

# FILES

FILES_CXX	=	avm_elem.cpp \
				main.cpp

FILES_O		=	$(FILES_CXX:.cpp=.o)

# FLAGS

LFLAGS		=	-L$(DIR_LIB)	\

IFLAGS		=	-I$(DIR_INC)
CXXFLAGS		+=	-W -Wall -ansi -pedantic $(IFLAGS)

# OPTION

.c.o		:
		$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)		:	$(FILES_O)
		$(CXX) -shared -o $(NAME) $(FILES_O) $(LFLAGS)
		mv $(NAME) ../lib

all		:	$(NAME)

clean		:
		$(RM) $(FILES_O)

fclean		:	clean
		$(RM) $(NAME)

cleanall	:	fclean
		$(RM) $(D_SRC)*~  $(D_SRC)\#*\#
		$(RM) $(D_INC)*~  $(D_INC)\#*\#
		$(RM) *~ \#*\#
		$(RM) .DS_Store
		$(RM) TAGS

re		:	fclean	all

.PHONY		:	$(NAME) all .c.o library clean fclean re
