SRCS = mytar.cpp
EXT  = .cpp
OBJS = $(SRCS:$(EXT)=.o)
EXEC = mytar
CXX  = g++
CXXFLAGS = -Wall
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
