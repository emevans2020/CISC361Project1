#include "mp3.h"
#include "mp3DLL.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 128

//global variable used to keep track of current mp3
struct mp3 *current = NULL;

// creates an empty Doublylist 
DLL_t *createDLL(){
    DLL_t* list = malloc(sizeof(DLL_t));
    list->first = NULL;
	list->last = NULL;
	list->size = 0;
    return list;
} 

// prints the list of MP3s from beginning to end
void printList(DLL_t * list) {
    mp3_t * current = list->first;
    while (current != NULL) {
        printMp3(current);
        current = current->next;
    }
}

//prints display the list from last to first
void printBackward(DLL_t * list) {
   //start from the last
   mp3_t * current = list->last;
   //navigate till the start of the list
   while(current != NULL) { 
      //print data
      printMp3(current);
      //move to next item
      current = current->prev;
   }
}
//adds the MP3 to the end/tail of the list
void addMP3 (DLL_t *list){
	mp3_t* song = malloc(sizeof(struct mp3));
	char buffer[BUFFERSIZE];
	int len;

    fgets(buffer,BUFFERSIZE,stdin); //add in dummy fgets because the scanf in main leaves a character in the buffer
	printf("Enter the artist's name: ");
	if (fgets(buffer, BUFFERSIZE , stdin) != NULL){
		len = (int) strlen(buffer);
		buffer[len - 1] = '\0';          
		song->artistName = (char*) malloc(len);
		strcpy(song->artistName, buffer);
	}
	
	printf("Enter the song title: ");
	if (fgets(buffer, BUFFERSIZE , stdin) != NULL){
		len = (int) strlen(buffer);
		buffer[len - 1] = '\0';                 // why minus 1 ???
		song->title = (char*) malloc(len);
		strcpy(song->title, buffer);
	}
	
	printf ("Enter the song's release date: ");
		int date;
		scanf("%d", &date);
		song->year = date;

	printf ("Enter the duration of the song (in seconds): ");
		int rt;
		scanf("%d", &rt);
		song->runtime= rt;

	// Under this is where the list will be incremented
    if (list->size == 0){
		list->first = song;
		list->last = song;
		list->size++;
	} else {
        list->last->next = song;
        song->prev = list->last;
        list->last = song;
		song->next = NULL;
        list->size++;
    }
}

// delete one node from list and keep connected
void removeMP3(DLL_t *list, mp3_t * mp3){
	if (list->size == 1){
		list->first = NULL;
		list->last = NULL;
		list->size-=1;
	}
	else if (mp3 == list->first) {
 		list->first = mp3->next;
		list->first->prev = NULL;
		list->size-=1;
	}
    /* Change next only if node to be deleted is NOT the last node */
    else if (mp3 == list->last){
		list->last = list->last->prev;
		list->last->next = NULL;
		list->size-=1;
	}
	else {
		mp3->prev->next = mp3->next;
		mp3->next->prev = mp3->prev;
		list->size-=1;
	}
    free(mp3->artistName);
	free(mp3->title);
    free(mp3); //free up memory from mp3 deleted
}

// deletes mp3s that all have the same artist name
void deleteArtistSongs(DLL_t *list){
	char* artist;
	char buffer[BUFFERSIZE];
	int len;
	
	fgets(buffer,BUFFERSIZE,stdin);
	printf ("What artist do you want to remove from your list?");
	if (fgets(buffer, BUFFERSIZE , stdin) != NULL){
		len = (int) strlen(buffer);
		buffer[len - 1] = '\0';
		artist = (char*) malloc(len);
		strcpy(artist, buffer);
	}
	mp3_t * current = list->first;
	mp3_t * next;
	while (current != NULL){
		next = current->next;
		if (strcmp (current->artistName,artist)==0){
			removeMP3(list,current);
		}
		current = next;
	}
	free(artist);
	free(next);
	free(current);
}

// completely delete all nodes from list and list
void deleteList(DLL_t *list){
	mp3_t * current = list->first;
	while (list->size != 0){
		removeMP3 (list, current);
	}
}