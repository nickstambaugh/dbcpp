CC = g++
CXXFLAGS = -std=c++11 -Wall

SRCDIR = src
OBJDIR = obj

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

EXECUTABLE = database_repl

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(wildcard $(SRCDIR)/*.h)
	@if not exist $(OBJDIR) mkdir $(OBJDIR)
	$(CC) $(CXXFLAGS) -c -o $@ $<

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CXXFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
