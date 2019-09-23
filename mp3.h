/* Emily Evans CISC361 Project 1 
This file is the node header
*/
#ifndef MP3_H_
#define MP3_H_

typedef struct mp3 {
    char* artistName;
    char* title;
    int year;
    int runtime;
    struct mp3 * next;
    struct mp3 * prev;
} mp3_t;

#endif /* MP3_H_ */
mp3_t* createMp3(char *artistname, char *songtitle, int year, int rt);
void printMp3(mp3_t *mp3);