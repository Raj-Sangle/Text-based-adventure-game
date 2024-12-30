#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <stdlib.h>
#include <fstream.h>
#include <graphics.h>

class gameSound
{
	public:
	void dragonSound()
	{
		sound(70);
		delay(500);
		sound(100);
		delay(500);
		sound(70);
		delay(500);
		nosound();
		delay(1000);
		sound(100);
		delay(500);
		sound(70);
		delay(500);
		sound(100);
		delay(500);
		nosound();
	}
	void savedSound()
	{
		int i;
		for(i=1;i<=3;i++)
		{
			if(i==3)
			{
				sound(880);
				delay(500);
				nosound();
				delay(100);

				sound(784);
				delay(500);
				nosound();
				delay(100);

				sound(659);
				delay(500);
				nosound();
				delay(100);

				sound(587);
				delay(500);
				nosound();
				delay(100);

				sound(523);
				delay(500);
				nosound();
				delay(100);
			}
			else
			{
				sound(523);
				delay(500);
				nosound();
				delay(100);

				sound(587);
				delay(500);
				nosound();
				delay(100);

				sound(659);
				delay(500);
				nosound();
				delay(100);

				sound(784);
				delay(400);
				nosound();
				delay(150);

				sound(880);
				delay(500);
				nosound();

				delay(200);
			}
		}
}
void orangCatSound()
{
	sound(300);
	delay(500);
	sound(350);
	delay(500);
	sound(300);
	delay(500);
	nosound();
}
void deadSound() {
	int baseFreq = 300;
	int wobble = 20;
	int i;

	for (i = 0; i < 11; i++) {
		sound(baseFreq - wobble);
		delay(150);
		nosound();
		delay(50);

		sound(baseFreq + wobble);
		delay(150);
		nosound();
		delay(50);

		baseFreq -= 20;
		wobble -= 2;
	}
	nosound();
}
};

class basicActions
{
	public:
	virtual void doError() = 0;
	virtual void doMove() = 0;
	virtual int getAction() = 0;
};
class Game : public gameSound, public basicActions
{
	public:
	int dela, location, haveFlowers, haveSword, petCat, dead;
	int killedSlug, killedDragon, savedPriyaMaam, coward, action;
	public:
	Game()
	{
		dela = 1000;
		location = 1;
		haveFlowers = 0;
		haveSword = 0;
		petCat = 0;
		dead = 0;
		killedSlug = 0;
		killedDragon = 0;
		savedPriyaMaam = 0;
		coward = 0;
		action;
	}
void doError() {
    cout <<"HEIN!?" << endl;
    delay(dela);
}

int getAction() {
    int actionInput;
    cin >> actionInput;
    return actionInput;
}

void doMove() {
    cout << ".";
    delay(300);
    cout << ".";
    delay(300);
    cout << ".";
    delay(300);
    cout << "\n\n";
}

void doLocation1() {
    cout << "You see the entrance to a cave to the north." << endl;
    cout << "You hear Priya ma'am yelling, \"Help me!\"" << endl;
    cout << "You also hear a loud roar." << endl;
    cout << "What do you do?" << endl;
    cout << "1) Enter cave" << endl;
    cout << "2) Run away" << endl;

    action = getAction();
    switch (action) {
	case 1:
	    location = 2;
	    break;
	case 2:
	    coward = 1;
	    break;
	default:
	    doError();
	    break;
    }
    doMove();
}

void doLocation2() {
    cout << "You are inside the cave. The smell of brimstone is overpowering." << endl;
    cout << "You see a hallway leading west, a hallway leading east," << endl;
    cout << "and a hallway leading south." << endl;
    cout << "What do you do?" << endl;
    cout << "1) Go east" << endl;
    cout << "2) Go west" << endl;
    cout << "3) Go south" << endl;
    action = getAction();
    switch (action) {
	case 1:
	    location = 4;
	    break;
	case 2:
	    location = 3;
	    break;
	case 3:
	    location = 1;
	    break;
	default:
	    doError();
	    break;
    }
    doMove();
}

void doLocation3() {
    cout << "It's really dark in here." << endl;
    cout << "You can't see a thing." << endl;
    cout << "You bumble around the room and finally find your way out." << endl;
    location = 2;
    doMove();
}

void doLocation4() {
    cout << "You are standing in a room that is empty except for spider webs all over." << endl;
    cout << "There are hallways leading west, north, and east." << endl;
    cout << "What do you do?" << endl;
    cout << "1) Go east" << endl;
    cout << "2) Go north" << endl;
    cout << "3) Go west" << endl;
    action = getAction();
    switch (action) {
	case 1:
	    location = 5;
	    break;
	case 2:
	    location = 8;
	    break;
	case 3:
	    location = 2;
	    break;
	default:
	    doError();
	    break;
    }
    doMove();
}

void doLocation5() {
    if (!petCat) {
	cout << "You are in a room. You see an orang cat." << endl;
    }
    else {
	cout << "You are in a room with a sweet cat." << endl;
    }
    cout << "There is a hallway to the west." << endl;
    cout << "What do you do?" << endl;
    cout << "1) Go west" << endl;
    if (!petCat) {
	cout << "2) Pet cat" << endl;
    }
    action = getAction();
    switch (action) {
	case 1:
	    location = 4;
	    break;
	case 2:
	    if (!petCat) {
		cout << "The mighty cat will now accompany you throughout the journey!" << endl;
		cout << "You have chances of winning now." << endl;
		orangCatSound();
		petCat = 1;
	    }
	    break;
	default:
	    doError();
	    break;
    }
    doMove();
}

void doLocation6() {
    if (!haveSword) {
	cout << "You are in a room. You see a sword lying on a large stone." << endl;
    }
    else {
	cout << "You are in a room with a large stone." << endl;
    }
    cout << "There is a hallway to the east." << endl;
    cout << "What do you do?" << endl;
    cout << "1) Go east" << endl;
    if (!haveSword) {
	cout << "2) Take sword" << endl;
    }
    action = getAction();
    switch (action) {
	case 1:
	    location = 7;
	    break;
	case 2:
	    if (!haveSword) {
		cout << "You take the sword." << endl;
		haveSword = 1;
	    }
	    break;
	default:
	    doError();
	    break;
    }
    doMove();
}

void doLocation7() {
    if (!killedSlug) {
	cout << "You are in a room. On the ground, you see a disgusting slug." << endl;
	cout << "What do you do?" << endl;
	cout << "1) Run away like a little girl" << endl;
	cout << "2) Step on slug" << endl;
	action = getAction();
	switch (action) {
	    case 1:
		cout << "You shriek and run away." << endl;
		cout << "You hear Priya ma'am yell out, \"Do I have to save myself!?\"" << endl;
		location = 8;
		break;
	    case 2:
		cout << "You get slug slime on your boots as you squish the slug." << endl;
		killedSlug = 1;
		break;
	    default:
		doError();
		break;
	}
    } else {
	cout << "You are in a room with slug guts on the floor." << endl;
	cout << "There is a hallway to the west and to the east." << endl;
	cout << "What do you do?" << endl;
	cout << "1) Go west" << endl;
	cout << "2) Go east" << endl;
	action = getAction();
	switch (action) {
	    case 1:
		location = 6;
		break;
	    case 2:
		location = 8;
		break;
	    default:
		doError();
		break;
	}
    }
    doMove();
}

void doLocation8() {
    cout << "You are in an empty room. It is very warm in here." << endl;
    cout << "There is a hallway to the west, north, east, and south." << endl;
    cout << "What do you do?" << endl;
    cout << "1) Go west" << endl;
    cout << "2) Go north" << endl;
    cout << "3) Go east" << endl;
    cout << "4) Go south" << endl;
    action = getAction();
    switch (action) {
	case 1:
	    location = 7;
	    break;
	case 2:
	    location = 10;
	    break;
	case 3:
	    location = 9;
	    break;
	case 4:
	    location = 4;
	    break;
	default:
	    doError();
	    break;
    }
    doMove();
}

void doLocation9() {
    if (!haveFlowers) {
	cout << "You are in a room. On the ground, you see some flowers growing." << endl;
    }
    else {
	cout << "You are in a room. You see a patch of dirt where flowers once grew." << endl;
    }
    cout << "There is a hallway to the west." << endl;
    cout << "What do you do?" << endl;
    cout << "1) Go west" << endl;
    if (!haveFlowers) {
	cout << "2) Pick flowers like a girl" << endl;
    }
    action = getAction();
    switch (action) {
	case 1:
	    location = 8;
	    break;
	case 2:
	    if (!haveFlowers) {
		cout << "You picked the flowers how shameful." << endl;
		haveFlowers = 1;
	    }
	    break;
	default:
	    doError();
	    break;
    }
    doMove();

}

void doLocation10() {
    cout << "You are face-to-face with a huge dragon!" << endl;
    cout << "He sees you and starts to move towards you." << endl;
    cout << "What will you do now? hahahahaha" << endl;
    dragonSound(); //function sound waala.
    cout << "1) Run away like a weakling (naruto)" << endl;
    cout << "2) Fight the dragon" << endl;
    action = getAction();
    switch (action) {
	case 1:
	    cout << "You wet your pants and run away." << endl;
	    location = 8;
	    break;
	case 2:
	    if (haveSword && petCat) {
		cout << "You swing your sword with power of orang cat and slay the dragon!" << endl;
		killedDragon = 1;
		savedPriyaMaam = 1;
	    }
	    else if(petCat && !haveSword) {
		cout << "The Cat said \"Mei hamesha takatwar logoka saath deta hu\" and killed you" << endl;
		dead = 1;
	    }
	    else{
		 cout << "You were baaye haath ka khel for the Dragon!" << endl;
		 dead = 1;
	    }
	    break;
	default:
	    doError();
	    break;
    }
    doMove();
}

};
class GameStatus {
public:
    char action[20];

    int restart() {
	cout << "Do you want to play again? (yes/no)" << endl;
	cin >> action;
	if (strcmp(strlwr(action), "yes") == 0) {
	    return 1;
	}
	else if (strcmp(strlwr(action), "no") == 0) {
	    cout << "Thank you for playing!" << endl;
	    getch();
	    exit(0);
	}
	else {
	    cout << "Invalid input. Exiting game." << endl;
	    getch();
	    exit(0);
	}
	return 0;
    }
};

int main() {
    gameSound so;
    Game ob;
    GameStatus status;
    fstream filo;
    int gd = DETECT, gm, i, j, k, n;
    char name[50], ans;
    clrscr();
    int playAgain = 1;
    cout << "START THE GAME?(y/n): ";
    cin >> ans;
if(ans == 'n' || ans == 'N')
{
	cout << "LOSER" << endl;
	getch();
	exit(0);
}
else if(ans == 'y' || ans == 'Y')
{
	initgraph(&gd,&gm,"C://TURBOC3/BGI");
	rectangle(150,200,500,250);
	for(i=150,j = 200, k = 151, n = 250; i<500; i=i+1,k = k+1)
	{
		delay(7);
		setfillstyle(SOLID_FILL,WHITE);
		bar3d(i,j,k,n,0,1);
		outtextxy(280,260,"LOADING");
	}
	outtextxy(285,400,"PRESS ANY KEY TO START...");
	getch();
	closegraph();
    clrscr();
    cout << "Enter your name: ";
    cin >> name;
    clrscr();
    while (playAgain) {
	ob.dead = ob.savedPriyaMaam = ob.coward = ob.haveFlowers = ob.haveSword = ob.petCat = ob.killedSlug = ob.killedDragon = ob.coward = 0;
	ob.location = 1;
	while (!ob.dead && !ob.savedPriyaMaam && !ob.coward) {
	    switch (ob.location) {
		case 1:
		    ob.doLocation1();
		    break;
		case 2:
		    ob.doLocation2();
		    break;
		case 3:
		    ob.doLocation3();
		    break;
		case 4:
		    ob.doLocation4();
		    break;
		case 5:
		    ob.doLocation5();
		    break;
		case 6:
		    ob.doLocation6();
		    break;
		case 7:
		    ob.doLocation7();
		    break;
		case 8:
		    ob.doLocation8();
		    break;
		case 9:
		    ob.doLocation9();
		    break;
		case 10:
		    ob.doLocation10();
		    break;
		default:
		    ob.doError();
		    break;
	    }
	}
	filo.open("Game_results.txt",ios::app);
	if (ob.dead) {
	    cout << "Game over. BYE BYE TATA GOODBYE" << endl;
	    filo << name << " - DEAD" << endl;
	    so.deadSound();
	}
	else if (ob.savedPriyaMaam) {
	    cout << "Congratulations! You saved Priya Ma'am! (49/50 for manual! why 49? TULA KALNAAR NAAHI)" << endl;
	    filo << name << " - WON" << endl;
	    so.savedSound();
	}
	else if (ob.coward) {
	    cout << "You didn't save Priya Ma'am! (KT! KT! KT!)" << endl;
	    filo << name << " - DARPOK" << endl;
	    so.deadSound();
	}
	filo.close();
	playAgain = status.restart();
	clrscr();
    }
}
else
{
	cout << "YOU IDIOT ILLITERATE FOOL!" << endl;
	getch();
}
    return 0;
}
