NAME = exe
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -O
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(NAME)

re:
	make clean
	make all

run:

debug:
	$(MAKE) re CXXFLAGS='$(CXXFLAGS) -DDEBUG'

.PHONY: all clean re run debug