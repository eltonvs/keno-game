CXX = g++
DEL = /bin/rm

CFLAGS = -Wall -std=c++11

BIN_DIR = bin
TARGET = keno
SRC1 = drive_keno
SRC2 = KenoBet
SRC3 = HelperFunctions
TESTS = tests
SRC_DIR = src
INCLUDE_DIR = include

all: $(BIN_DIR)/$(TARGET)

tests: $(BIN_DIR)/$(TESTS)

$(BIN_DIR)/$(TARGET): $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o
	@echo "Creating compiled file"
	$(CXX) $(CFLAGS) $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o -o $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TESTS): $(BIN_DIR)/$(TESTS).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o
	@echo "Creating compiled file"
	$(CXX) $(CFLAGS) $(BIN_DIR)/$(TESTS).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o -o $(BIN_DIR)/$(TESTS)

$(BIN_DIR)/$(SRC1).o: $(SRC_DIR)/$(SRC1).cpp
	@echo "Creating object file 1"
	$(CXX) $(CFLAGS) -c $(SRC_DIR)/$(SRC1).cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/$(SRC1).o

$(BIN_DIR)/$(SRC2).o: $(SRC_DIR)/$(SRC2).cpp
	@echo "Creating object file 2"
	$(CXX) $(CFLAGS) -c $(SRC_DIR)/$(SRC2).cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/$(SRC2).o

$(BIN_DIR)/$(SRC3).o: $(SRC_DIR)/$(SRC3).cpp
	@echo "Creating object file 3"
	$(CXX) $(CFLAGS) -c $(SRC_DIR)/$(SRC3).cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/$(SRC3).o

$(BIN_DIR)/$(TESTS).o: $(SRC_DIR)/$(TESTS).cpp
	@echo "Creating tests object file"
	$(CXX) $(CFLAGS) -c $(SRC_DIR)/$(TESTS).cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/$(TESTS).o

clean:
	$(DEL) $(BIN_DIR)/$(TARGET) $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o $(BIN_DIR)/$(TESTS).o
