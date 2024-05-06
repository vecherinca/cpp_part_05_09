NAME = Base
CC = c++
CFLAGS =  -g3 -Wall -Wextra -Werror -std=c++98 -I./includes
RM = rm -rf

# Adjust source file paths as needed
SRCS = src/main.cpp src/Base.cpp src/A.cpp src/B.cpp src/C.cpp
# Change to bin folder for object files
OBJS = $(SRCS:.cpp=.o)
OBJS := $(addprefix bin/,$(notdir $(OBJS)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
.SILENT:

# Create bin directory if it does not exist and compile object files into it
bin/%.o: src/%.cpp
	mkdir -p bin
	$(CC) $(CFLAGS) -c $< -o $@

bin/%.o: header/%.cpp
	mkdir -p bin
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) bin/*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all clean
	./$(NAME)

.PHONY: all clean fclean re run