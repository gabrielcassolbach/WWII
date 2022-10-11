all:
	g++ -o bin/exec codigo/*.cpp codigo/GameStuffs/*.cpp -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-system