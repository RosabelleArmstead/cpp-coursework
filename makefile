TARGET = main
INCDIR = include
SRCDIR = src
OBJDIR = obj
BINDIR = bin

CC = g++ -std=c++11
CFLAGS = -g -Wall -I$(INCDIR) -lm
LINKER = g++ -std=c++11 -o
LFLAGS = -Wall -I$(INCDIR) -lm

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(INCDIR)/*.h)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)

$(OBJECTS): $(OBJDIR)%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
