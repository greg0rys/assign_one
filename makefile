CC = g++
CPPFLAGS = -g -Wall -std=c++17
DEPS = driver.h ChickenYard.h Player.h Bone.h Game.h Field.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

app: driver.o ChickenYard.o Player.o Bone.o Game.o Field.o
	$(CC) -o app Bone.o ChickenYard.o Player.o driver.o Game.o Field.o

.PHONY: clean

clean:
	$(info -- cleaning up --)
	rm -f app
	rm -f *.o
