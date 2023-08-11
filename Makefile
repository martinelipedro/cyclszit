SOURCES = ${shell find . -type f -name '*.cpp'}
HEADERS = ${shell find . -type f -name '*.hpp'}
OBJECTS = ${SOURCES:.cpp=.o}
EXE_NAME = cyclszit

CLEAN_TARGETS = ${OBJECTS} ${shell find . -type f -name '*.o'} 

LIBS = -lSDL2

.PHONY: all clean exe



all: ${OBJECTS} ${HEADERS}
	g++ ${OBJECTS} -o ${EXE_NAME} ${LIBS}

exe: all
	rm -rf ${CLEAN_TARGETS}

clean:
	rm -rf ${CLEAN_TARGETS} ${EXE_NAME}

%.o: %.cpp
	g++ -c $< -o $@ 
