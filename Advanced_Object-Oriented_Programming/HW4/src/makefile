SRCS = Main.cpp Lexer.cpp Num.cpp Real.cpp Tag.cpp Token.cpp Type.cpp Word.cpp
EXT  = .cpp
OBJS = $(SRCS:$(EXT)=.o)
EXEC = scanner
CXX  = g++
CXXFLAGS = -std=c++11 -Wall
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
