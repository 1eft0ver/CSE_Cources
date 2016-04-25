SRCS = main.c
EXT  = .c
OBJS = $(SRCS:$(EXT)=.o)
EXEC = philo
CXX  = gcc
CXXFLAGS = -std=c99 -Wall
DEP  = dep

all:$(EXEC)

$(EXEC):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS) -lpthread

%.o:%$(EXT)
	$(CXX) $(CXXFLAGS) -c $<

dep:
	$(CXX) $(CXXFLAGS) -M $(SRCS) > $(DEP)

clean:
	rm -rf $(EXEC) $(OBJS) $(DEP)
