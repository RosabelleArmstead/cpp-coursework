TARGET = main
INCDIR = include
SRCDIR = src
OBJDIR = obj
BINDIR = bin

CC = g++
CFLAGS = -g -Wall -I$(INCDIR) -lm
LINKER = g++ -o
LFLAGS = -Wall -I$(INCDIR) -lm

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(INCDIR)/*.h)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)

$(OBJECTS): $(OBJDIR)%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
