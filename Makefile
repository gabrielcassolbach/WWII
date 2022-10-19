CC = g++
CFLAGS = -Wall
INCLUDE_SFML = -I SFML/include
LDFLAGS = -L SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
OBJFILES = *.cpp
TARGET = jogo

all: 
    $(CC) -c $(OBJFILES) $(INCLUDE_SFML) 
    $(CC) *.o $(CFLAGS) -o $(TARGET) $(LDFLAGS)

clean:
    rm -f $(TARGET) *~