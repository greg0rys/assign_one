CC = g++
CPPFLAGS = -std=c++17 -g -Wall
DEPS = main.h Bone.h ChickenYard.h Game.h Player.h Field.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

app: main.o Bone.o ChickenYard.o Game.o Player.o Field.o
	$(CC) -o app main.o Bone.o ChickenYard.o Game.o Player.o Field.o

.PHONY: clean
clean:
	$(info -- cleaning up --)
	rm -f *.o
	rm -f app