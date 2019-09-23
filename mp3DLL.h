#include "mp3.h"

#ifndef MP3DLL_H_
#define MP3DLL_H_


typedef struct DLL {
	mp3_t *first;
	mp3_t *last;
	int size;
}DLL_t;

// Doubly linked functions below
	DLL_t *createDLL();
	void printList(DLL_t * list);
	void printBackward(DLL_t * list);
	void addMP3 (DLL_t *list);
	void deleteArtistSongs(DLL_t *list);
	void removeMP3(DLL_t *list, mp3_t * mp3);
	void deleteList(DLL_t *list);

#endif /* MP3DLL_H_ */