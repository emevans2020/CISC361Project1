/* Emily Evans CISC361 Project 1 
This file is for the node
*/
#include "mp3.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

mp3_t* createMp3(char *artistname, char *songtitle, int year, int rt){
     /* declares a pointer to a MP3 structure and creates new MP3 struct with pointer to it */
    mp3_t * song = malloc(sizeof(struct mp3*));
    song->artistName = artistname; /* the structure can now be used */
    song->title = songtitle;
    song->year = year;
    song->runtime = rt;
    song->next = NULL;
    song->prev = NULL;
    return song;
}

void printMp3(mp3_t *mp3){ //will print out the MP3 information
    printf ("Title: %s\t", mp3->title);
    printf ("Artist: %s\t",mp3->artistName); 
    printf ("Year: %d\t", mp3->year);
    printf ("Duration: %d\n", mp3->runtime);
}