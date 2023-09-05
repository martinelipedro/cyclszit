SOURCES = ${shell find . -type f -name '*.cpp'}
HEADERS = ${shell find . -type f -name '*.hpp'}
OBJECTS = ${SOURCES:.cpp=.o}
EXE_NAME = cyclszit

CLEAN_TARGETS = ${OBJECTS} ${shell find . -type f -name '*.o'} 

LIBS = -lSDL2 -lSDL2_ttf

BIN_DIR = ./bin

.PHONY: all clean exe

all: ${OBJECTS} ${HEADERS}
	g++ $(BIN_DIR)/*.o -o $(BIN_DIR)/$(EXE_NAME) $(LIBS)

exe: all
	rm -rf ${CLEAN_TARGETS}

clean:
	rm -rf ${CLEAN_TARGETS} ${EXE_NAME}

%.o: %.cpp
	g++ -c $< -o bin/$(notdir $@)
