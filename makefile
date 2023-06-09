CC = g++

a.out: football_fantasy.o main.o league.o handling.o match.o player.o team.o user.o week.o
	${CC} football_fantasy.o main.o league.o handling.o match.o player.o team.o user.o week.o

football_fantasy.o: football_fantasy.cpp football_fantasy.hpp
	${CC} -c football_fantasy.cpp -o football_fantasy.o

main.o: main.cpp
	${CC} -c main.cpp -o main.o

handling.o: handling.cpp handling.hpp
	${CC} -c handling.cpp -o handling.o

league.o: league.cpp league.hpp
	${CC} -c league.cpp -o league.o


match.o: match.cpp match.hpp
	${CC} -c match.cpp -o match.o

player.o: player.cpp player.hpp
	${CC} -c player.cpp -o player.o

team.o: team.cpp team.hpp
	${CC} -c team.cpp -o team.o

user.o: user.cpp user.hpp
	${CC} -c user.cpp -o user.o

week.o: week.cpp week.hpp
	${CC} -c week.cpp -o week.o

