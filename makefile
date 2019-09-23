mp3: main.o mp3DLL.o mp3.o
	gcc main.o mp3DLL.o mp3.o -o mp3
main.o: main.c mp3DLL.h 
	gcc -c main.c
mp3DLl.o:mp3DLL.c mp3DLL.h mp3.h
	gcc -c mp3DLL.c
mp3.o: mp3.c mp3.h
	gcc -c mp3.c
clean:
	rm *.o mp3