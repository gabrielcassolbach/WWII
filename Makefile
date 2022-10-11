CC = g++
CFLAGS = -Wall
INCLUDE_SFML = -i /SFML/include
LDFLAGS = -L ~/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
OBJFILES = *.cpp
TARGET = jogo

all: $(TARGET)

$(TARGET): $(OBJFILES) 
	$(CC) -c $(OBJFILES) $(INCLUDE_SFML) 
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(TARGET) *~
