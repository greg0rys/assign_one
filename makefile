CC = g++
CPPFLAGS = -g -Wall -std=c++17
DEPS = driver.h ChickenYard.h Player.h Bone.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

app: driver.o ChickenYard.o Player.o Bone.o
	$(CC) -o app Bone.o ChickenYard.o Player.o driver.o

.PHONY: clean

clean:
	$(info -- cleaning up --)
	rm -f app
	rm -f *.o
