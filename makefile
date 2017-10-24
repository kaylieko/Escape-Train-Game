CC=g++
SRCS = main.cpp Player.hpp Player.cpp Game.hpp Game.cpp Timer.cpp Timer.hpp Train.cpp Train.hpp TailSection.hpp TailSection.cpp GuardsArea.hpp GuardsArea.cpp Prison.hpp Prison.cpp Classroom.hpp Classroom.cpp MinisterRoom.hpp MinisterRoom.cpp Engine.hpp Engine.cpp

all: ${SRCS}
	${CC} ${CFLAGS} ${SRCS} -o final

clean:
	rm -rf *.o final
