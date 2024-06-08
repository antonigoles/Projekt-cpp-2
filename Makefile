# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Flags for different architectures
WINDOWS_FLAGS = -m32
LINUX_FLAGS = -m32
MACOS_ARM_FLAGS = -arch arm64

# Compiler and flags
ifeq ($(OS),Windows_NT)
	CXX = g++
	CXXFLAGS = -std=c++20 -I$(INC_DIR) $(WINDOWS_FLAGS)
else ifeq ($(shell uname),Linux)
	CXX = g++
	CXXFLAGS = -std=c++20 -I$(INC_DIR) $(LINUX_FLAGS)
else
	CXX = g++
	CXXFLAGS = -std=c++20 -I$(INC_DIR) $(MACOS_ARM_FLAGS)
endif

# Find all .cpp files in the src directory recursively
SRCS = $(shell find $(SRC_DIR) -name '*.cpp')

# Object files in build directory, mirroring the src directory structure
OBJS = \
	build/Application/Utils/Utils.o \
	build/Application/Entity/Osoba.o \
	build/Application/Service/Lista.o \
	build/Application/Service/ServiceRepository.o \
	build/Application/IO/IO.o \
	build/Application/IO/Command.o \
	build/Application/Application.o \
	build/main.o

# Executable
EXEC = $(BUILD_DIR)/app

# Default target
all: $(BUILD_DIR) $(EXEC)

# Build executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)
	@echo "Linking complete: $(EXEC)"

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled $< to $@"

# Ensure build directory exists
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Clean up
clean:
	rm -rf $(BUILD_DIR)
	@echo "Cleaned up build artifacts"

# Run the executable
run: $(EXEC)
	$(EXEC)

# Phony targets
.PHONY: all clean run
