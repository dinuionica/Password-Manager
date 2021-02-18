build: main.c functions.h functions.c
	gcc main.c functions.c -o main && ./main

clean:
	rm main 
	