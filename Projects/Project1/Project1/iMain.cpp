/*
Original Author: S. M. Shahriar Nirjon
Last Modified by: Mohammad Saifur Rahman
last modified: October 13, 2015
Version: 2.0
*/




# include "iGraphics.h"
#include<time.h>
int mposx, mposy;
int cartoonX = 100;
int cartoonY = 50;
int bulletX;
int bulletY = 132;
int bulletmove = 150;
int levelup = 0;
char cartoonName[] = "background\\mainchararcter12.bmp.bmp";
char background[] = "background\\housebackground2.bmp.bmp";
char background1[] = "background\\background1.bmp.bmp";
char zombie[] = "background\\character Zombie1.bmp.bmp";
char bullet[] = "background\\bullet11.bmp.bmp";
char gameoverlocation[] = "background\\gameover.bmp.bmp";
char life[] = "background\\life.bmp.bmp";
char mainmenu[] = "background\\maainmenu.bmp.bmp";
char showtext[] = "level2";
bool goleft = false;
bool goright = false;
bool zombiehitcartoon = false;
bool bulletGoRight = false;
bool zombieExist = false;
bool zombieMovesleft = false;
bool bullethitszombie = false;
bool creaturehitscartoon = false;
bool level1background = false;
bool level2background = false;
bool bulletexist = false;
bool gameover = false;
bool gamestart = false;
int zombieExistforlevel2 = 0;
int cartoonMove = 75;
int imageWidth = 320;
int imageHeight = 180;
int zombiewidth = 282;
int zombieheight = 195;
int HEIGHT = 740;
int WIDTH = 1876;
int zombieX = (WIDTH - zombiewidth - 45);
int zombieY = 12;
int zombieMove = 30;
int i;
int j, k, l;
int mxx, myy;
void xstrcpy(char *to, char *from){
	int i;
	for (i = 0; (*from) != '\0'; i++){
		*to = *from;
		*to++;
		*from++;


	}

	*(to) = '\0';



}
struct imagelocation{

	char location[100];
	int positionXX = rand() % (HEIGHT - ballheight);
	int positionYY = HEIGHT;
	int ballmove = 30;
	int ballwidth = 100;
	int ballheight = 138;
	void setposition(){

		if (positionYY <= 0){
			positionXX = rand() % (HEIGHT - ballheight);
			positionYY = HEIGHT;
		}
		else
			positionYY -= ballmove;

	}
	void setlocation(){
		xstrcpy(location, "background\\batsie.bmp.bmp");

	}
	void setlocation1(){
		xstrcpy(location, "background\\batsie.bmp.bmp");

	}

}fallingcreatue1, fallingcreatue2, fallingcreatue3;


struct imagelocation1{
	bool zombieExistforlevel2 = false;
	bool bullethitszombieforlevel2 = false;
	bool zombieMovesleftforlevel2 = false;
	bool zombiehitcartoonforlevel2 = false;
	char locationn[100];
	int positionXXX = (WIDTH - zombiewidth - 45);
	int positionYYY = 12;
	int ballmovee = 95;
	int ballwidthh = 282;
	int ballheightt = 195;
	void setpositionn(){


		if (zombieMovesleftforlevel2 != true){
			positionXXX -= ballmovee;
		}

	}
	void setlocationn(){
		xstrcpy(locationn, "background\\character Zombie1.bmp.bmp");

	}
	void setlocationn1(){
		xstrcpy(locationn, "background\\creature.bmp.bmp");

	}
	void bullethittingzombie(){


		if (bulletGoRight == true && bulletX >= positionXXX){
			zombieExist = true;
			zombieExistforlevel2 = true;
			bullethitszombieforlevel2 = true;
			bullethitszombie = true;
			bulletX = cartoonX + imageWidth;
			bulletGoRight = false;
			positionXXX = WIDTH + 2000;
			positionYYY = HEIGHT + 2000;
			zombieMovesleftforlevel2 = true;
			zombieMovesleft = true;
			bulletexist = false;

		}

	}
	void zombiehittingcartoon(){
		if (positionXXX <= (cartoonX + imageWidth)){

			zombiehitcartoonforlevel2 = true;
			zombiehitcartoon = true;
			gameover = true;
		}


	}

}comingzombie[100];


/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{

	//place your drawing codes here
	iClear();
	iShowBMP(0, 0, mainmenu);
	printf("\nmx= %d", mxx);
	printf("\nmy= %d", myy);

	if (gamestart == true){

		iSetColor(245, 245, 245);
		if (level1background != true){
			iShowBMP(0, 0, background);
		}
		if (levelup >= 3){
			level1background = true;
			level2background = true;

			zombieExist = false;//for testing only
			zombieX = 2000;//for testing only
			zombieY = 4000;//for testing only
		}

		if (level2background == true){
			iShowBMP(0, 0, background1);
		}

		if (bulletGoRight != true){
			bulletX = cartoonX + imageWidth;
		}


		fallingcreatue1.setposition();
		if (levelup >= 3){
			fallingcreatue2.setposition();
			fallingcreatue3.setposition();

		}






		if (levelup >= 3){
			for (j = 0; j < 40; j++){
				comingzombie[j].setpositionn();
				comingzombie[j].bullethittingzombie();
				comingzombie[j].zombiehittingcartoon();
			}
		}
		if (levelup >= 3){
			for (k = 0; k < 40; k++){
				if ((comingzombie[k].zombieExistforlevel2 != true)){
					iShowBMP2(comingzombie[k].positionXXX, comingzombie[k].positionYYY, comingzombie[k].locationn, 0);
				}
			}

		}
		if (creaturehitscartoon != true){
			iShowBMP2(fallingcreatue1.positionXX, fallingcreatue1.positionYY, fallingcreatue1.location, 0);
		}
		if (creaturehitscartoon != true && levelup >= 3){
			iShowBMP2(fallingcreatue2.positionXX, fallingcreatue2.positionYY, fallingcreatue2.location, 0);
			iShowBMP2(fallingcreatue3.positionXX, fallingcreatue3.positionYY, fallingcreatue3.location, 0);
		}

		if (creaturehitscartoon != true && zombiehitcartoon != true){
			iShowBMP2(cartoonX, cartoonY, cartoonName, 0);
		}
		if (creaturehitscartoon != true && zombiehitcartoon != true && bulletexist != false){
			iShowBMP2(bulletX, bulletY, bullet, 0);
		}
		if (zombieExist != true){
			iShowBMP2(zombieX, zombieY, zombie, 0);
		}





		if (bulletGoRight == true && bulletX >= (WIDTH - zombiewidth - 45)){

			zombieExist = true;
			bullethitszombie = true;
			bulletX = cartoonX + imageWidth;
			bulletGoRight = false;
			zombieX = WIDTH + 200;
			zombieY = HEIGHT + 200;
			zombieExist = false;
			zombieX = (WIDTH - zombiewidth - 45);
			zombieY = 12;
			bulletexist = false;
			levelup++;

		}
		if (fallingcreatue1.positionXX >= cartoonX && fallingcreatue1.positionXX <= (cartoonX + imageWidth) && fallingcreatue1.positionYY <= cartoonY){

			creaturehitscartoon = true;
			gameover = true;
		}
		if (fallingcreatue2.positionXX >= cartoonX && fallingcreatue2.positionXX <= (cartoonX + imageWidth) && fallingcreatue2.positionYY <= cartoonY){

			creaturehitscartoon = true;
			gameover = true;
		}
		if (fallingcreatue3.positionXX >= cartoonX && fallingcreatue3.positionXX <= (cartoonX + imageWidth) && fallingcreatue3.positionYY <= cartoonY){

			creaturehitscartoon = true;
			gameover = true;
		}
		if (cartoonY + imageHeight >= HEIGHT){
			cartoonY = HEIGHT - imageHeight;

			goleft = false;
			goright = false;

		}
		if (cartoonY <= 0){
			cartoonY = 0;

			goleft = false;
			goright = false;

		}
		if (cartoonX <= 0){
			cartoonX = 0;

			goleft = false;
			goright = false;

		}
		if (cartoonX + imageWidth >= WIDTH)
		{
			cartoonX = WIDTH - imageWidth;

			goleft = false;
			goright = false;

		}
		if (zombieMovesleft == false){

			zombieX -= zombieMove;
		}

		if (bulletGoRight == true){
			bulletX += bulletmove;

		}
		if (zombieX <= (cartoonX + imageWidth)){

			zombiehitcartoon = true;
			gameover = true;
		}
		iShowBMP(1500, (HEIGHT - 45), life);
		iShowBMP(1550, (HEIGHT - 45), life);
		iShowBMP(1600, (HEIGHT - 45), life);
		iText(27, (HEIGHT - 39), "LEVEL 1", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1400, (HEIGHT - 39), "LIFE", GLUT_BITMAP_TIMES_ROMAN_24);
		if (levelup >= 3){
			iText(27, (HEIGHT - 39), "LEVEL 2", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (gameover == true){

			level1background = true;
			level2background = false;
			creaturehitscartoon = true;
			zombieExist = true;
			zombiehitcartoon = true;
			for (l = 0; l < 40; l++){

				comingzombie[l].zombieExistforlevel2 = true;


			}
		}
		if (gameover == true){
			iShowBMP(0, 0, gameoverlocation);

		}

	}

}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	mxx = mx;
	myy = my;

	//place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (mx >= 422 && mx <= 601 && my >= 359 && my <= 418){
		gamestart = true;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx, int my)
{


	//place your code here

	mposx = mx;
	mposy = my;
	if (mx == 2){}        /*Something to do with mx*/
	else if (my == 2){}   /*Something to do with my*/

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)

{

	//place your codes for other keys here
	if (key == 's'){
		goleft = false;
		goright = false;



	}

	if (key == 'r'){

		bulletGoRight = true;
		bulletexist = true;
	}



	if (key == 'q'){


		//do something with 'q'

		//place your codes for other keys here
	}
}
/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{



	if (key == GLUT_KEY_RIGHT)
	{

		goright = true;
		goleft = false;
		cartoonX += cartoonMove;

	}
	//place your codes for other keys here
	if (key == GLUT_KEY_LEFT)
	{



		goleft = true;
		goright = false;
		cartoonX -= cartoonMove;



	}







}


//
int main()


{
	srand((unsigned)time(NULL));


	PlaySound("Music\\audioclip-1484407410000-148245.wav", NULL, SND_ASYNC);


	//place your own initialization codes here.
	fallingcreatue1.setlocation();
	fallingcreatue2.setlocation1();
	fallingcreatue3.setlocation();

	for (i = 0; i < 40; i++){
		comingzombie[i].setlocationn();
	}

	for (i = 1; i < 40; i++){
		comingzombie[i].positionXXX = comingzombie[i - 1].positionXXX + 200 + zombiewidth;

	}



	iInitialize(WIDTH, HEIGHT, "demooo");
	return 0;
}
