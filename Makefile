all: tinmusic

tinmusic: tinmusic.c
	$(CC) -o tinmusic tinmusic.c -Wall -W -pedantic -std=c99
clean:
	rm tinmusic
