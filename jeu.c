#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "modele.h"
#include "vue.h"


int main(int argc, char *argv[]) {
	data d;
 	if (OpenDisplay(argc, argv) ==0) {
 		fprintf(stderr,"Can’t open display\n");
		return EXIT_FAILURE;
 	}

// Creates IG and display it on screen
 	init_display(argc, argv, &d);
 	MainLoop();
	return EXIT_SUCCESS;
}
