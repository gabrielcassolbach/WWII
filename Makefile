CC = g++
CFLAGS = -Wall
INCLUDE_SFML = -I SFML/include
LDFLAGS = -L SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
OBJFILES = *.cpp Entities/*.cpp  Entities/Characters/*.cpp Managers/*.cpp Entities/Obstacles/*.cpp Levels/*.cpp Lists/*.cpp
TARGET = z_jogo

all: 
	$(CC) -c $(OBJFILES) $(INCLUDE_SFML)    
	$(CC) *.o $(CFLAGS) -o $(TARGET) $(LDFLAGS)
	rm  -f *.o
clean:
	rm -f $(TARGET) *~
