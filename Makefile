RM = rm -rvf 
CC = clang #g++ -g

CXXFLAGS = -Wall -std=c++17

IDIR =../include
INCLUDES = -I$(IDIR)     
LDIR =../lib
LFLAGS = -L$(LDIR)  

# Place to store all generated files
# The build_DIR target  
BUILD_DIR:= ./build
APP_DIR  = $(BUILD_DIR)/apps


OBJ_DIR=obj
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

SRC_DIR=src
SRCS = $(wildcard $(SRC_DIR)/*.cpp)   # All source files.

LIBS = -lpthread  -lstdc++ -lm #-fopenmp 
TARGET = $(APP_DIR)/main

all:$(TARGET)
	@echo Executing 'all' complete!
	@echo  Simple compiler named $(TARGET) has been compiled
	@echo "=============\n\n"
	sleep 3
	clear
	@echo "======================================="

$(TARGET): $(OBJS)    
	@echo "Call $(CC) to generate $@ from $<"
	$(CC) -o $@ $^ $(CXXFLAGS) $(LIBS) $(INCLUDES) $(LFLAGS)    

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Hello from $@"
	$(CC) -c $< -o $@ $(CXXFLAGS)

info:
	@echo "[*] Application dir: ${APP_DIR}     "
	@echo "[*] Application file: ${TARGET}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRCS}         "
	@echo "[*] Objects:         ${OBJS}     "

run:
	$(TARGET)

clean: 
	$(RM) $(TARGET) $(APP_DIR) $(OUTPUT_DIR) $(OBJ_DIR)/*.o $(OBJ_DIR) $(BUILD_DIR)
	@echo Cleanup complete!
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

dirs:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(IDIR)