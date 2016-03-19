CXX = g++
DEL = /bin/rm

CFLAGS = -Wall -std=c++11

BIN_DIR = bin
TARGET = keno
SRC1 = drive_keno
SRC2 = kenobet
SRC_DIR = src
INCLUDE_DIR = include

all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o
	@echo "Creating compiled file"
	$(CXX) $(CFLAGS) $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o -o $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(SRC1).o: $(SRC_DIR)/$(SRC1).cpp
	@echo "Creating object file 1"
	$(CXX) $(CFLAGS) -c $(SRC_DIR)/$(SRC1).cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/$(SRC1).o

$(BIN_DIR)/$(SRC2).o: $(SRC_DIR)/$(SRC2).cpp
	@echo "Creating object file 2"
	$(CXX) $(CFLAGS) -c $(SRC_DIR)/$(SRC2).cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/$(SRC2).o

clean:
	$(DEL) $(BIN_DIR)/$(TARGET) $(BIN_DIR)/$(TARGET).o
