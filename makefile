CC = g++

futballFantasy.out: football_fantasy.o main.o league.o handling.o match.o player.o team.o user.o week.o
	${CC} football_fantasy.o main.o league.o handling.o match.o player.o team.o user.o week.o

football_fantasy.o: football_fantasy.cpp football_fantasy.hpp libs.hpp user.hpp player.hpp league.hpp
	${CC} -c football_fantasy.cpp -o football_fantasy.o

main.o: main.cpp
	${CC} -c main.cpp -o main.o

handling.o: handling.cpp handling.hpp football_fantasy.hpp match.hpp
	${CC} -c handling.cpp -o handling.o

league.o: league.cpp league.hpp libs.hpp week.hpp team.hpp
	${CC} -c league.cpp -o league.o


match.o: match.cpp match.hpp libs.hpp team.hpp
	${CC} -c match.cpp -o match.o

player.o: player.cpp player.hpp libs.hpp team.hpp
	${CC} -c player.cpp -o player.o

team.o: team.cpp team.hpp player.hpp libs.hpp
	${CC} -c team.cpp -o team.o

user.o: user.cpp user.hpp libs.hpp player.hpp
	${CC} -c user.cpp -o user.o

week.o: week.cpp week.hpp match.hpp libs.hpp
	${CC} -c week.cpp -o week.o

