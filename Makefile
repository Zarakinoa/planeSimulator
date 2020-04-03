## Variables ..........................................................................:
CXX= g++ -Wno-narrowing
CXXFLAGS= -Wall -g
LDFLAGS= -lraylib

## File directory .....................................................................:
SRCDIR= src
HEADDIR= include
OBJDIR= object
BINDIR= bin

## Project structure ..................................................................:
EXEC= planeSimulator
SRC= $(wildcard $(SRCDIR)/*.cpp)
OBJ= $(SRC:$(SRCDIR)/*.cpp=$(OBJDIR)/*.o)

## Launching ..........................................................................:
run: all
	@$(BINDIR)/./$(EXEC)

## Compilation ........................................................................:
all: $(EXEC)

$(EXEC): $(OBJ)
	@$(CXX) -g -o $(BINDIR)/$@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADDIR)/%.h
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

## Object cleaning ....................................................................:
clean:
	@rm $(OBJDIR)/*.o

## Executable cleaning ................................................................:
Clean:clean
	@rm $(BINDIR)/*

## Archiving ..........................................................................:
tar:
	tar -zcvf ../planeSimulator.tar.gz *