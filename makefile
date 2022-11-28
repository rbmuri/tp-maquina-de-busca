# CC and flags
CC = g++
CXXFLAGS = -std=c++17 -g -Wall

# folders
INCLUDE_FOLDER = ./include/
BIN_FOLDER = ./
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/

# main files
MAIN_NORMAL = main
MAIN_TEST = Testes_de_unidade

# all sources, objs, and header files
MAIN = main
TARGET = run.out
SRC = $(wildcard $(SRC_FOLDER)*.cpp)
OBJ = $(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))

# compile
$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

all: $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLDER)$(TARGET) $(subst $(OBJ_FOLDER)$(MAIN_TEST).o, , $(OBJ))

test: $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLDER)$(TARGET) $(subst $(OBJ_FOLDER)$(MAIN_NORMAL).o, , $(OBJ))

run:
	@$(BIN_FOLDER)$(TARGET)
