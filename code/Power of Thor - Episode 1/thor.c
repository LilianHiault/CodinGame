#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{
    // the X position of the light of power
    int light_x;
    // the Y position of the light of power
    int light_y;
    // Thor's starting X position
    int initial_tx;
    // Thor's starting Y position
    int initial_ty;
    scanf("%d%d%d%d", &light_x, &light_y, &initial_tx, &initial_ty);

    int x = initial_tx;
    int y = initial_ty;


    while (1) {
        // The remaining amount of turns Thor can move. Do not remove this line.
        int remaining_turns;
        scanf("%d", &remaining_turns);

	while ((x != light_x) || (y != light_y)) {
	  if (light_y < y && y > 0) {
	    printf("N");
	    y = y - 1;
	  }
	  if (light_y > y && y < 17) {
	    printf("S");
	    y++;
	  }
	  if (light_x < x && x > 0) {
	    printf("W");
	    x = x - 1;
	  }
	  if (light_x > x && x < 39) {
	    printf("E");
	    x++;
	  }
	  printf("\n");
	}

	// Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");


        // A single line providing the move to be made: N NE E SE S SW W or NW
    }

    return 0;
}
