/*tinmusic - small music player written in C. one file at a time*/
/* sudo apt install aplay */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int playSongOnce(char *filename) {
    char command[64];
    int status;

    /* create command to execute */
    sprintf(command, "aplay -i -c 2 %s", filename);

    /* play sound */
    status = system(command);
     
    return status;
}

int appQuit() {
    char command[64];
    int status;

    sprintf(command, "killall tinmusic ; killall aplay");

    status = system(command);
    return status;
}

int main(int argc, char *argv[]) {
    int choice;

    if (argc < 2) {
        printf("Usage: tinmusic filename.wav\n");
        exit(1);
    }

    do {
    /* menu with controls*/
    system("clear");
    printf("tinmusic - a small music player made by BeanGreen247\n");
    printf("https://github.com/BeanGreen247\n\n");
    printf("Controls\n");
    printf("spacebar - pause or resume\n");
    printf("ctrl + c - terminate or kill\n\n");
    printf("menu\n");
    printf("1 - Play Once And Exit\n");
    printf("2 - Exit\n");
    scanf("%d",&choice);
    
    /*char command[1024];*/
    switch (choice) {
    case 1:
    	playSongOnce(argv[1]);
	appQuit();
	break;
    case 2:
	printf("\nGoodbye...\n");
	appQuit();
       break;
    default :
	printf("Wrong choice. Pick another.");
	break;
    }
    
    }while(choice !=2);
    appQuit();
}
