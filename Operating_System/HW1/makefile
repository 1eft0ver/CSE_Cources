SRCS = main.c shell.c
EXT  = .c
OBJS = $(SRCS:$(EXT)=.o)
EXEC = myshell
CXX  = gcc
CXXFLAGS = -std=c99 -D_POSIX_SOURCE -Wall
DEP  = dep

all:$(EXEC) 

$(EXEC):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o:%$(EXT)
	$(CXX) $(CXXFLAGS) -c $<

dep:
	$(CXX) $(CXXFLAGS) -M $(SRCS) > $(DEP)

clean:
	rm -rf $(EXEC) $(OBJS) $(DEP)