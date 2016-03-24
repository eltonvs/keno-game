CXX = g++
DEL = /bin/rm

CFLAGS = -Wall -std=c++11
DFLAGS = -g -O0

BIN_DIR = bin
TARGET = keno
SRC1 = drive_keno
SRC2 = KenoBet
SRC3 = HelperFunctions
TESTS = tests
DEBUG = debug
SRC_DIR = src
INCLUDE_DIR = include

all: $(BIN_DIR)/$(TARGET)

tests: $(BIN_DIR)/$(TESTS)

debug: $(BIN_DIR)/$(DEBUG)

$(BIN_DIR)/$(TARGET): $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o
	@echo "Creating compiled file"
	$(CXX) $(CFLAGS) $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o -o $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TESTS): $(BIN_DIR)/$(TESTS).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o
	@echo "Creating compiled [tests] file"
	$(CXX) $(CFLAGS) $(BIN_DIR)/$(TESTS).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o -o $(BIN_DIR)/$(TESTS)

$(BIN_DIR)/$(DEBUG): $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o
	@echo "Creating compiled [ready to debug] file"
	$(CXX) $(CFLAGS) $(DFLAGS) $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o -o $(BIN_DIR)/$(DEBUG)

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
	$(DEL) $(BIN_DIR)/$(TARGET) $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o $(BIN_DIR)/$(SRC3).o
	$(DEL) $(BIN_DIR)/$(TESTS) $(BIN_DIR)/$(TESTS).o
	$(DEL) $(BIN_DIR)/$(DEBUG)
