CSRCS =
EX1_SRCS = mapread.cpp
EX2_SRCS = mapwrite.cpp
EXT = .c
COBJS = $(CSRCS:$(EXT)=.o)
EX1_OBJS = $(EX1_SRCS:$(EXT)=.o)
EX2_OBJS = $(EX2_SRCS:$(EXT)=.o)
EXEC1 = read
EXEC2 = write
CXX = g++
CXXFLAGS = -D_XOPEN_SOURCE=500 -Wall
DEP = dep

all: ${EXEC1} ${EXEC2}

$(EXEC1): $(COBJS) $(EX1_OBJS)
		$(CXX) $(CXXFLAGS) -o $@ $(COBJS) $(EX1_OBJS)

$(EXEC2): $(COBJS) $(EX2_OBJS)
		$(CXX) $(CXXFLAGS) -o $@ $(COBJS) $(EX2_OBJS)

%.o:%$(EXT)
		$(CXX) $(CXXFLAGS) -c $<

dep:
		$(CXX) $(CXXFLAGS) -M ${CSRCS} ${EX1_SRCS} ${EX2_SRCS} > ${DEP}

clean:
		rm -rf *.o output ${EXEC1} ${EXEC2} ${DEP}
