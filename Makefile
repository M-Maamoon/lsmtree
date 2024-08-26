# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++20 -Wall

# Target executable name
TARGET = lsmtree

# Source files
SRCS = main.cpp tree/*.cpp tables/*cpp buffermanager/*cpp


# Header files
INCLUDES =  -I./tree -I./tables -I./helpers -I./buffermanager

# Object files (will be derived from the source files)
OBJS = $(SRCS:.cpp=.o)

# Default target to build the executable
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
