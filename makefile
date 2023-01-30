CC = g++
CPPFLAGS = -g -Wall -std=c++17
DEPS = main.h ChickenYard.h Player.h Bone.h Game.h Field.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

app: main.o ChickenYard.o Player.o Bone.o Game.o Field.o
	$(CC) -o app Bone.o ChickenYard.o Player.o main.o Game.o Field.o

.PHONY: clean

clean:
	$(info -- cleaning up --)
	rm -f app
	rm -f *.o
