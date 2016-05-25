SRCS = main.c mm.c
EXT  = .c
OBJS = $(SRCS:$(EXT)=.o)
EXEC = memory_manager
CXX  = gcc
CXXFLAGS = -std=c99 -Wall
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
