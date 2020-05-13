GPP = g++
NAME = cpa
LINKER_FLAGS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
OBJ_DIR = obj
SRC_DIR = src
OBJ = $(OBJ_DIR)/main.o \
	$(OBJ_DIR)/Keyboard.o \
	$(OBJ_DIR)/Key.o \
	$(OBJ_DIR)/ActiveNote.o \
	$(OBJ_DIR)/ControlPanel.o \
	$(OBJ_DIR)/Scale.o \
	$(OBJ_DIR)/CheckBox.o \
	$(OBJ_DIR)/Chord.o \
	$(OBJ_DIR)/VolumeControl.o \
	$(OBJ_DIR)/Progression.o
OBJ_PATH = ./$(OBJ_DIR)/
SRC_PATH = ./$(SRC_DIR)/

#SFML library is required to compile
#On ubuntu you can get it by:
#$ sudo apt-get install libsfml-dev
#compile with:
#$ make
#run with:
#$ ./cpa
#enjoy

$(NAME): $(OBJ_DIR) $(OBJ)
	$(GPP) $(OBJ_PATH)*.o $(LINKER_FLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_PATH)main.o: $(SRC_PATH)main.cpp
	$(GPP) -c -o $@ $<

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp $(SRC_PATH)%.hpp
	$(GPP) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)
	rm $(NAME)