#-------------------------------------->
#credit to moros1138#4147 (discord name)
#-------------------------------------->
PROJECT     :=  WallPaperLogic

RELEASE		:= -O3
DEBUG		:= -ggdb3 -Og -C

STATIC		:= -Bstatic -static-libgcc -static-libstdc++
DYNAMIC		:= -static-libstdc++
UNDEF		:=

BUILD		:= $(DEBUG)
LINKTYPE	:= $(STATIC)

CXX_FLAGS 	:= -std=c++17  $(BUILD) $(LINKTYPE) -lglfw -lGL -lX11 -lpthread -ldl -lGLEW
CXX			:= g++

BIN			:= bin
SRC			:= src
#----------------------------------------->
#"soon" going to move to the project folders
INC			:= /usr/include 
LIB			:= /usr/lib
#----------------------------------------->
OBJ     	:= obj
RES			:= res

INC_FLAG	:= -I$(INC) 
LIB_FLAG	:= -L$(LIB)

EXECUTABLE		:= $(PROJECT)
LIBRARIES		:= 
PLATFORM		:= linux
CLEAN_COMMAND 	:= -rm -r $(BIN)/* $(OBJ)/*/*
LINK_FLAGS		:= 

#------link file paths pipeline------>
tmpSRC		= 	$(wildcard $(SRC)/$(1)/*.cpp)
tmpSRC_O	=	$(tmpSRC:.cpp=.o)
AddDir		= 	$(patsubst $(SRC)/$(1)/%,$(OBJ)/$(PLATFORM)/%,$(call tmpSRC_O,$(1)))
#/-----link file paths pipeline------>
FirstSRC	:= $(wildcard $(SRC)/*.cpp)
FirstOBJ	:= $(patsubst $(SRC)/%,$(OBJ)/$(PLATFORM)/%,$(FirstSRC:.cpp=.o))

ALLOBJECTS 	:= $(FirstOBJ)
#to add folders call tmpOBJ with path to file 
#relative to make file -> $(call tmpOBJ,test)
ALLOBJECTS 	+= $(call AddDir,test)

# Compile only. (add compile rules for each dir you added)
$(OBJ)/$(PLATFORM)%.o : $(SRC)/test/%.cpp $(DEPENDENCIES)
	$(CXX) $(CXX_FLAGS) $(INC_FLAG) -c -o $@ $<

$(OBJ)/$(PLATFORM)%.o : $(SRC)%.cpp $(DEPENDENCIES)
	$(CXX) $(CXX_FLAGS) $(INC_FLAG) -c -o $@ $<



# Link the object files and libraries
$(BIN)/$(EXECUTABLE) : $(ALLOBJECTS)
	$(CXX) $^ $(CXX_FLAGS)  -o $(BIN)/$(EXECUTABLE) $(LIBRARIES) $(LIB_FLAG) $(LINK_FLAGS) 

.PHONY: clean clear all
all:
	$(BIN)/$(EXECUTABLE)
clean:
	$(CLEAN_COMMAND)
clear:
	$(CLEAN_COMMAND)