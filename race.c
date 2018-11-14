/*
	RACE!

	(1) Kompiliere das Spiel und führe es aus.

	(2) Was macht rand(), srand() und time()? Lese dir je den ersten Absatz der DESCRIPTION in den dazugehörigen manpages durch.

	(3) Räume den Code auf:
		- versuche den Code überblicksmäßig zu verstehen
		- verwende all dein Wissen dazu den Code verständlicher zu machen
		- formatiere den Code
			- ein Befehl pro Zeile
			- eine Deklaration pro Zeile
			- rücke den Code richtig ein
			- ...
		- schreibe Codestellen um;
			- verwende passende Schleifenarten, Variablentypen, ...
			- verwende Konstanten, Enums, ...
			- keine globalen Variablen (außerhalb von main)
			- ...
		- entferne unnötigen Code
		- kommentiere Stellen
		- ...

	(4) Die Straße kann links aus dem Bildschirm verschwinden. Behebe dieses Problem.

	(5) Wenn man bspw. immer 'd' eingibt, kann man über den Straßenrand fahren. Finde den Fehler und behebe ihn.

	(6) Lass den Spieler sein Fahrzeugzeichen eingeben.

	(7) Wenn der Spieler nach einer Bewegung direkt neben der linken oder rechten Straßenbegrenzung steht, soll er einen Punkt zusätzlich bekommen. Gib zusätzlich "ACHTUNG!" aus.

	(8) Die Straßenbreite soll sich im Laufe des Spiels ändern. Zu Beginn soll die Straße 8 Zeichen breit sein. Nach jeder vierten Bewegung soll die Straßenbreite eins schmäler werden, bis sie nur noch 3 Zeichen breit ist.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){

    enum directions {RIGHT = 1, LEFT};
    enum directions direction;
    char car;

    short player=10,left=7, right=13;
    int points=0;

    //now = current time
	unsigned int now = time(NULL);

	// initialisiere den Zufallsgenerator mit der aktuellen Zeit
	srand(now);

    //title page
	printf("           \n");
	printf("   _____     \n");
	printf("  /_..._\\    \n");
	printf(" (0[###]0)  RACE! \n");
	printf("  `'   `'    \n");
	printf("           \n");
	printf("    [a] left \n");
	printf("    [s] straight ahead \n");
	printf("    [d] right\n");
	printf("\n");

    //input car character
    printf("\nEnter the sign that will be your car: ");
    scanf("%c", &car);
    printf("\n");

	while(1){

        //Input
		char c;
        scanf(" %c",&c);

        int random_number = rand() % 100; // Zahl zwischen 0 und 99

        //no moving left if the road is at the left edge
        if(left > 0){
        //determine direction of road movement
            if(random_number <=49){
                direction = RIGHT;}
            else direction = LEFT;
        }
        else{
            direction = RIGHT;
            }

        //check input and move player
        if(c == 'a'){
            player--;
            }
        if(c == 'd'){
            player++;
            }

        //check movement direction
		switch(direction){

            //moving right
            case RIGHT: left++; right++; break;

            //moving right
            case LEFT: left--; right--;
		}


		//draw symbols
		for(int i = 0; i< 40; i++){

            if(i == left){
                printf(")");
                }

            else if(i==right){
                printf("(");
            }

            else if(i==player) {
                printf("%c",car);
            }

            else printf(" ");
        }

		printf("\n");

        //game ends
		if(player <= left || player >= right){
            break;
            }
		else {
        //game continues
		points++;
        }

        if(player - left == 1 || right - player == 1){
            points++;
            printf("\nACHTUNG!\n");
            }
	}

	printf("GAME OVER.          \nPOINTS: %d\n", points);
    return EXIT_SUCCESS;
}
