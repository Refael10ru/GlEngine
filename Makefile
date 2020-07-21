PROJECT     :=  WallPaperLogic

RELEASE		:= -O3
DEBUG		:= -ggdb3 -Og -C

STATIC		:= -Bstatic -static-libgcc -static-libstdc++
DYNAMIC		:= -static-libstdc++
UNDEF		:=

BUILD		:= $(DEBUG)
LINKTYPE	:= $(STATIC)

CXX_FLAGS 	:= -std=c++17 $(BUILD) $(LINKTYPE) -lglfw -lGL -lX11 -lpthread -lXrandr -ldl -lGLEW
CXX			:= g++

BIN			:= bin
SRC			:= src
INC			:= /usr/include
LIB			:= /usr/lib
OBJ     	:= obj
RES			:= res

INC_FLAG	:= -I$(INC) 
LIB_FLAG	:= -L$(LIB)

EXECUTABLE		:= $(PROJECT)
LIBRARIES		:= 
PLATFORM		:= linux
CLEAN_COMMAND 	:= -rm -r $(BIN)/* $(OBJ)/*/*
LINK_FLAGS		:= 

SOURCES		:= $(wildcard $(SRC)/*.cpp)
OBJECTS		:= $(patsubst $(SRC)/%,$(OBJ)/$(PLATFORM)/%,$(SOURCES:.cpp=.o))


# Compile only
$(OBJ)/$(PLATFORM)%.o : $(SRC)%.cpp $(DEPENDENCIES)
	$(CXX) $(CXX_FLAGS) $(INC_FLAG) -c -o $@ $<


# Link the object files and libraries
$(BIN)/$(EXECUTABLE) : $(OBJECTS)
	$(CXX) $^ $(CXX_FLAGS) -o $(BIN)/$(EXECUTABLE) $(LIBRARIES) $(LIB_FLAG) $(LINK_FLAGS) 

.PHONY: clean all
all:
	$(BIN)/$(EXECUTABLE)
clean:
	$(CLEAN_COMMAND)
clear:
	$(CLEAN_COMMAND)