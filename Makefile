build: main.c functions.h functions.c
	gcc main.c functions.c -o password_manager && ./password_manager

clean:
	rm main 
	
