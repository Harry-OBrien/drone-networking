
CSRCFLAGS= -O2 -Wall -Wextra

# Location of the files
LIS_SRC = ../src/listener
LIS_HEAD = ../include
CMD_SRC = ../src/commander
CMD_HEAD = ../include
COMMON_SRC = ../src/common
BASE_OBJ_DIR = objects
LIS_OBJ_DIR = $(BASE_OBJ_DIR)/listener
CMD_OBJ_DIR = $(BASE_OBJ_DIR)/commander
COM_OBJ_DIR = $(BASE_OBJ_DIR)/common
LISSOURCES = $(wildcard $(LIS_SRC)/*.cpp)
CMDSOURCES = $(wildcard $(CMD_SRC)/*.cpp)
COMMONSOURCES = $(wildcard $(COMMON_SRC)/*.cpp)

LISOBJ = $(patsubst $(LIS_SRC)/%.cpp, $(LIS_OBJ_DIR)/%.o, $(LISSOURCES))
LISOBJ += $(patsubst $(COMMON_SRC)/%.cpp, $(COM_OBJ_DIR)/%.o, $(COMMONSOURCES))
CMDOBJ = $(patsubst $(CMD_SRC)/%.cpp, $(CMD_OBJ_DIR)/%.o, $(CMDSOURCES))
CMDOBJ += $(patsubst $(COMMON_SRC)/%.cpp, $(COM_OBJ_DIR)/%.o, $(COMMONSOURCES))

LIS_HEADERS = $(wildcard $(LIS_HEAD)/*.hpp)
CMD_HEADERS += $(wildcard $(CMD_HEAD)/*.hpp)

LIS_NAME=listener
CMD_NAME=commander

build: $(LISOBJ) $(CMDOBJ) $(LIS_HEADERS) $(CMD_HEADERS)
	make listener
	make commander

listener: $(LISOBJ) $(LIS_HEADERS)
	g++ -o $(LIS_NAME) $(LISOBJ)

commander: $(CMDOBJ) $(CMD_HEADERS)
	g++ -o $(CMD_NAME) $(CMDOBJ)

$(LIS_OBJ_DIR)/%.o: $(LIS_SRC)/%.cpp
	mkdir -p $(@D)
	g++ -I$(LIS_SRC) -I$(LIS_HEAD) -c $< -o $@ $(CSRCFLAGS)

$(CMD_OBJ_DIR)/%.o: $(CMD_SRC)/%.cpp
	mkdir -p $(@D)
	g++ -I$(CMD_SRC) -I$(CMD_HEAD) -c $< -o $@ $(CSRCFLAGS)

$(COM_OBJ_DIR)/%.o: $(COMMON_SRC)/%.cpp
	mkdir -p $(@D)
	g++ -I$(LIS_SRC) -I$(LIS_HEAD) -c $< -o $@ $(CSRCFLAGS)

clean:
	rm -rf $(BASE_OBJ_DIR)
	rm $(LIS_NAME)
	rm $(CMD_NAME)
