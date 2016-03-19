CXX = g++
DEL = /bin/rm

CFLAGS = -Wall -std=c++11

BIN_DIR = bin
TARGET = keno
TARGET1 = drive_keno
TARGET2 = kenobet
SRC_DIR = src
INCLUDE_DIR = include

all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(BIN_DIR)/$(TARGET1).o $(BIN_DIR)/$(TARGET2).o
	@echo "Creating compiled file"
	$(CXX) $(CFLAGS) $(BIN_DIR)/$(TARGET1).o $(BIN_DIR)/$(TARGET2).o -o $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET1).o: $(SRC_DIR)/$(TARGET1).cpp
	@echo "Creating object file 1"
	$(CXX) $(CFLAGS) -c $(SRC_DIR)/$(TARGET1).cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/$(TARGET1).o

$(BIN_DIR)/$(TARGET2).o: $(SRC_DIR)/$(TARGET2).cpp
	@echo "Creating object file 2"
	$(CXX) $(CFLAGS) -c $(SRC_DIR)/$(TARGET2).cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/$(TARGET2).o

clean:
	$(DEL) $(BIN_DIR)/$(TARGET) $(BIN_DIR)/$(TARGET).o
