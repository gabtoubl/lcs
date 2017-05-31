NAME=		mawTest
SRCS=		main.cpp
OBJS=		$(SRCS:.cpp=.o)
CC=		g++
CXXFLAGS=	-W -Wall -Wextra -ansi -pedantic -std=c++11 -O3 -I.
LDFLAGS=	-lpthread
RM=		rm -vf

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all:		$(NAME)

clean:
		@$(RM) $(OBJS) $(NAME)

re:		clean all
