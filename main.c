#include "mp3DLL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (){
    int option; 
    DLL_t *list = createDLL(); //instantiate a new doubly linked list
    // there is a problem doubly linked list that keeps program from compiling

    while(1){
		printf ("Choose an option from the menu below (choose number 1-5):\n \
		(1) add an MP3 to the list\n (2) delete MP3(s) from the list\n \
		(3) print the list from beginning to end\n \(4) print the list from end to beginning\n \
		(5) exit the program.\n");
		scanf("%d", &option);

		if (option == 1){ // The case if you want to add a MP3 to the list
            addMP3 (list);
		} 
		else if(option == 2){ 	// The case if you want to delete MP3(s) from the list
			deleteArtistSongs(list);
		}
		else if(option == 3){ // Here should print the whole list
			printList(list);
		}
        else if(option == 4){ // This will print out the list from back to front
			printBackward(list);
		}
        else if(option  == 5){
			printf ("Exiting the program now!\n");
			deleteList(list);
			free(list);
			exit(0); // exit the program
		}        
        else{
            printf ("Please enter a valid number (1-5) \n");
		}
    }
}