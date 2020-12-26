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
char background2[] = "background\\House_of_Skulltula 22(1)2.bmp.bmp";
char background3[] = "background\\final1.bmp.bmp";
char zombie[] = "background\\new zombie.bmp.bmp";
char bullet[] = "background\\bullet2.bmp.bmp";
char gameoverlocation[] = "background\\gameover.bmp.bmp";
//char life[] = "background\\life.bmp.bmp";
/*char life01[] = "Lifebar\\lifebar01.bmp";
char life02[] = "Lifebar\\lifebar02.bmp";
char life03[] = "Lifebar\\lifebar03.bmp";
char life04[] = "Lifebar\\lifebar04.bmp"; */
char mainmenu[] = "background\\Haunted House2.bmp.bmp";
char showtext[] = "level2";
bool goleft = false;
bool goright = false;
bool stand = true;
bool bulletGoRight = false;
bool creaturehitscartoon = false;
bool level1background = false;
bool level2background = false;
bool bulletexist = false;
bool gameover = false;
bool gamestart = false;
bool level3background = false;
int pleasebackground = 3;
bool bossExist = false;
bool showmenu = false;
int zombiewidth = 278;
int cartoonMove = 75;
int imageWidth = 191;
int imageHeight = 180;
int bosscount = 0;
bool music = false;

int HEIGHT = 740;
int WIDTH = 1876;

int cartoonImageIndex = 0;
char cartoonGoingRightImages[8][100] = {
	"Character\\cartoon (1).bmp",
	"Character\\cartoon (2).bmp",
	"Character\\cartoon (3).bmp",
	"Character\\cartoon (4).bmp",
	"Character\\cartoon (5).bmp",
	"Character\\cartoon (6).bmp",
	"Character\\cartoon (7).bmp",
	"Character\\cartoon (8).bmp",
};

char cartoonGoingLeftImages[8][100] = {
	"Character\\cartoon (1).bmp",
	"Character\\cartoon (2).bmp",
	"Character\\cartoon (3).bmp",
	"Character\\cartoon (4).bmp",
	"Character\\cartoon (5).bmp",
	"Character\\cartoon (6).bmp",
	"Character\\cartoon (7).bmp",
	"Character\\cartoon (8).bmp",
};
char tempImage[100] = "Character\\cartoon (1).bmp";

int lifebarIndex = 0;
char lifebarImage[4][100] = {
	"Lifebar\\lifebar01.bmp",
	"Lifebar\\lifebar02.bmp",
	"Lifebar\\lifebar03.bmp",
	"Lifebar\\lifebar04.bmp",

};
char temp[100] = "Lifebar\\lifebar01.bmp";





int i;
int j, k, l, m, n;
int mxx, myy;
int lifecount = 0;
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
	int ballmove = 8;
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

}fallingcreatue1, fallingcreatue2, fallingcreatue3, fallingcreatue4, fallingcreatue5, fallingcreatue6;
//int temp;

struct imagelocation1{
	bool zombieExistforlevel2 = false;
	bool bullethitszombieforlevel2 = false;
	bool zombieMovesleftforlevel2 = false;
	bool zombiehitcartoonforlevel2 = false;
	char locationn[100];
	int positionXXX = (WIDTH - zombiewidth - 45);
	int positionYYY = 12;
	int ballmovee = 45;
	int ballwidthh = 282;
	int ballheightt = 195;
	void setpositionn(){

		if (level2background == true){
			ballmovee = 100;
		}
		if (zombieMovesleftforlevel2 != true){
			positionXXX -= ballmovee;
		}

	}
	void setlocationn(){
		xstrcpy(locationn, "background\\new zombie.bmp.bmp");

	}
	void setlocationn1(){
		xstrcpy(locationn, "background\\creature.bmp.bmp");

	}
	void bullethittingzombie(){


		if (bulletGoRight == true && bulletX >= positionXXX){
			zombieExistforlevel2 = true;
			bullethitszombieforlevel2 = true;
			bulletX = cartoonX + imageWidth;
			bulletGoRight = false;
			positionXXX = WIDTH + 2000;
			positionYYY = HEIGHT + 2000;
			zombieMovesleftforlevel2 = true;
			bulletexist = false;
			levelup++;

		}

	}
	void zombiehittingcartoon(){
		if (positionXXX <= (cartoonX + imageWidth)){

			zombiehitcartoonforlevel2 = true;
			positionXXX = WIDTH + 2000;
			positionXXX = positionXXX - 2000;
			positionYYY = HEIGHT + 2000;
			lifecount++;
			//printf("HIT %d\n", temp++);
		}


	}

}comingzombie[100];
struct boss{

	char locationnn1[100];
	int ballwidthhh1 = 300;
	int ballheighthh1 = 391;
	int positionYYYY1 = (HEIGHT - ballheighthh1);
	int positionXXXX1 = (WIDTH - ballwidthhh1 - 310);
	int ballmoveee1 = 34;
	int fireballX = 949;
	int fireballY = 414;



	void setpositionnn1(){

		if (positionYYYY1 <= 0){

			positionYYYY1 = HEIGHT;
		}
		else
			positionYYYY1 -= ballmoveee1;

	}
	void setlocationnn1(){
		xstrcpy(locationnn1, "background\\Boss3.bmp.bmp");

	}
	void bullethittingboss(){
		if (bulletX >= positionXXXX1 && bulletY >= positionYYYY1){
			bosscount++;
		}

	}

	void fireballsetposition(){


		fireballX = fireballX - 30;
		fireballY = fireballY - 40;
		if (fireballX <= 0){

			fireballX = positionXXXX1 - 3;
			fireballY = positionYYYY1 - 1;

		}
		if (fireballY <= 0){

			fireballX = positionXXXX1 - 3;
			fireballY = positionYYYY1 - 1;

		}
		if (fireballX <= (cartoonX + imageWidth) && fireballY <= (cartoonY + imageHeight)){

			gameover = true;



		}
	}




} boss1;


/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{

	//place your drawing codes here
	iClear();
	//printf("\nlevel up= %d", levelup);
	//
	//printf("\nlifecount= %d", lifecount);

	iShowBMP(0, 0, mainmenu);

	//printf("\nmx= %d", mxx);
	//printf("\nmy= %d", myy);

	if (gamestart == true){

		iSetColor(245, 245, 245);
		if (lifecount >= 4){
			gameover == true;
		}
		if (level1background != true){
			iShowBMP(0, 0, background);
		}
		if (levelup >= 10){
			level1background = true;
			level2background = true;


		}
		if (levelup >= 28){
			level1background = true;
			level2background = false;
			level3background = true;


		}
		if (levelup >= 51){
			level1background = true;
			level2background = false;
			level3background = false;
			pleasebackground = 4;


		}

		if (level3background == true){

			iShowBMP(0, 0, background2);

		}

		if (pleasebackground == 4){

			iShowBMP(0, 0, background3);
		}


		if (level2background == true){
			iShowBMP(0, 0, background1);
		}

		if (bulletGoRight != true){
			bulletX = cartoonX + imageWidth;
		}


		fallingcreatue1.setposition();
		if (levelup >= 10){
			fallingcreatue2.setposition();
			fallingcreatue3.setposition();

		}
		if (levelup >= 28){

			fallingcreatue4.setposition();

		}
		if (levelup >= 51){

			fallingcreatue5.setposition();
			fallingcreatue6.setposition();

		}







		if (levelup < 10){
			for (j = 0; j < 13; j++){
				comingzombie[j].setpositionn();
				comingzombie[j].bullethittingzombie();
				comingzombie[j].zombiehittingcartoon();
			}
		}
		if (levelup >= 10){
			for (m = 0; m < 34; m++){
				comingzombie[m].setpositionn();
				comingzombie[m].bullethittingzombie();
				comingzombie[m].zombiehittingcartoon();
			}

		}
		if (levelup >= 28){
			for (m = 0; m < 60; m++){
				comingzombie[m].setpositionn();
				comingzombie[m].bullethittingzombie();
				comingzombie[m].zombiehittingcartoon();
			}

		}

		if (levelup < 10){
			for (k = 0; k < 13; k++){
				if ((comingzombie[k].zombieExistforlevel2 != true)){
					iShowBMP2(comingzombie[k].positionXXX, comingzombie[k].positionYYY, comingzombie[k].locationn, 0);
				}
			}
		}
		if (levelup >= 10){

			comingzombie[10].zombiehitcartoonforlevel2 == true;
			comingzombie[11].zombiehitcartoonforlevel2 == true;
			comingzombie[12].zombiehitcartoonforlevel2 == true;
			comingzombie[10].positionXXX = 50000; 
			comingzombie[11].positionXXX = 50000;
			comingzombie[12].positionXXX = 50000;
			comingzombie[10].zombieMovesleftforlevel2 = 0;
			comingzombie[11].zombieMovesleftforlevel2 = 0;
			comingzombie[12].zombieMovesleftforlevel2 = 0;





		}
		if (levelup >= 28){

			comingzombie[31].zombiehitcartoonforlevel2 == true;
			comingzombie[32].zombiehitcartoonforlevel2 == true;
			comingzombie[33].zombiehitcartoonforlevel2 == true;
			comingzombie[31].positionXXX = 50000;
			comingzombie[32].positionXXX = 50000;
			comingzombie[33].positionXXX = 50000;
			comingzombie[31].zombieMovesleftforlevel2 = 0;
			comingzombie[32].zombieMovesleftforlevel2 = 0;
			comingzombie[33].zombieMovesleftforlevel2 = 0;





		}
		if (levelup >= 51){

			comingzombie[57].zombiehitcartoonforlevel2 == true;
			comingzombie[58].zombiehitcartoonforlevel2 == true;
			comingzombie[59].zombiehitcartoonforlevel2 == true;
			comingzombie[57].positionXXX = 50000;
			comingzombie[58].positionXXX = 50000;
			comingzombie[59].positionXXX = 50000;
			comingzombie[57].zombieMovesleftforlevel2 = 0;
			comingzombie[58].zombieMovesleftforlevel2 = 0;
			comingzombie[59].zombieMovesleftforlevel2 = 0;

		}
		if (levelup >= 10){

			for (n = 0; n < 34; n++){
				if ((comingzombie[n].zombieExistforlevel2 != true)){
					iShowBMP2(comingzombie[n].positionXXX, comingzombie[n].positionYYY, comingzombie[n].locationn, 0);
				}
			}
		}
		if (levelup >= 28){

			for (n = 0; n < 60; n++){
				if ((comingzombie[n].zombieExistforlevel2 != true)){
					iShowBMP2(comingzombie[n].positionXXX, comingzombie[n].positionYYY, comingzombie[n].locationn, 0);
				}
			}
		}




		iShowBMP2(fallingcreatue1.positionXX, fallingcreatue1.positionYY, fallingcreatue1.location, 0);

		if (levelup >= 10){
			iShowBMP2(fallingcreatue2.positionXX, fallingcreatue2.positionYY, fallingcreatue2.location, 0);
			iShowBMP2(fallingcreatue3.positionXX, fallingcreatue3.positionYY, fallingcreatue3.location, 0);
		}
		if (levelup >= 28){
			iShowBMP2(fallingcreatue4.positionXX, fallingcreatue4.positionYY, fallingcreatue4.location, 0);

		}
		if (levelup >= 51){
			iShowBMP2(fallingcreatue5.positionXX, fallingcreatue5.positionYY, fallingcreatue5.location, 0);
			iShowBMP2(fallingcreatue6.positionXX, fallingcreatue6.positionYY, fallingcreatue6.location, 0);

		}

		/*
		if (gameover != true){
			iShowBMP2(cartoonX, cartoonY, cartoonName, 0);
		}
		*/
		if (gameover !=true) {
			if (goright) {
				iShowBMP2(cartoonX, cartoonY - 30, cartoonGoingRightImages[cartoonImageIndex], 0);
				xstrcpy(tempImage, cartoonGoingRightImages[cartoonImageIndex]);
			}
			if (goleft) {
				iShowBMP2(cartoonX, cartoonY - 30, cartoonGoingLeftImages[cartoonImageIndex], 0);
				xstrcpy(tempImage, cartoonGoingLeftImages[cartoonImageIndex]);
			}
			if (stand) {
				iShowBMP2(cartoonX, cartoonY - 30, tempImage, 0);
			}
		{
			goright = false;
			goleft = false;
			stand = true;
		}
		}
		if (bulletexist != false){
			iShowBMP2(bulletX, bulletY, bullet, 0);
		}


		if (levelup >= 51){

			boss1.setpositionnn1();
			boss1.bullethittingboss();
			boss1.fireballsetposition();

			if (bosscount >= 3){
				bossExist = true;
			}

			if (bossExist != true){
				iShowBMP2(boss1.positionXXXX1, boss1.positionYYYY1, boss1.locationnn1,0);
			}
			iShowBMP2(boss1.fireballX, boss1.fireballY, "background\\fireball.bmp.bmp", 0);

		}


		if (fallingcreatue1.positionXX >= cartoonX && fallingcreatue1.positionXX <= (cartoonX + imageWidth) && fallingcreatue1.positionYY <= cartoonY){

			creaturehitscartoon = true;
			fallingcreatue1.positionYY = HEIGHT;


			lifecount++;
		}
		if (fallingcreatue2.positionXX >= cartoonX && fallingcreatue2.positionXX <= (cartoonX + imageWidth) && fallingcreatue2.positionYY <= cartoonY){

			creaturehitscartoon = true;
			fallingcreatue2.positionYY = HEIGHT;


			lifecount++;
		}
		if (fallingcreatue3.positionXX >= cartoonX && fallingcreatue3.positionXX <= (cartoonX + imageWidth) && fallingcreatue3.positionYY <= cartoonY){

			creaturehitscartoon = true;
			fallingcreatue3.positionYY = HEIGHT;


			lifecount++;
		}
		if (fallingcreatue4.positionXX >= cartoonX && fallingcreatue4.positionXX <= (cartoonX + imageWidth) && fallingcreatue4.positionYY <= cartoonY){

			creaturehitscartoon = true;
			fallingcreatue4.positionYY = HEIGHT;


			lifecount++;
		}
		if (fallingcreatue5.positionXX >= cartoonX && fallingcreatue5.positionXX <= (cartoonX + imageWidth) && fallingcreatue5.positionYY <= cartoonY){

			creaturehitscartoon = true;
			fallingcreatue5.positionYY = HEIGHT;


			lifecount++;
		}
		if (fallingcreatue6.positionXX >= cartoonX && fallingcreatue6.positionXX <= (cartoonX + imageWidth) && fallingcreatue6.positionYY <= cartoonY){

			creaturehitscartoon = true;
			fallingcreatue6.positionYY = HEIGHT;


			lifecount++;
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


		if (bulletGoRight == true){
			bulletX += bulletmove;

		}



		/*if (lifecount < 4){
			iShowBMP(1500, (HEIGHT - 45), life);
		}
		if (lifecount < 2){
			iShowBMP(1550, (HEIGHT - 45), life);
		}
		//if (lifecount < 1){
			iShowBMP(1600, (HEIGHT - 45), life);
		} */
		if (lifecount < 4){
			iShowBMP2(1500, (HEIGHT - 45), lifebarImage[lifebarIndex], 0);
			xstrcpy(temp, lifebarImage[lifebarIndex]);
			}
		/*if (lifecount < 3){
			iShowBMP(1500, (HEIGHT - 45), life02);
		}
		if (lifecount < 2){
			iShowBMP(1550, (HEIGHT - 45), life03);
		}
		if (lifecount < 1){
			iShowBMP(1600, (HEIGHT - 45), life04);
		}
		*/
		
		if (levelup < 10){
			iText(27, (HEIGHT - 39), "LEVEL 1", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		iText(1400, (HEIGHT - 39), "LIFE", GLUT_BITMAP_TIMES_ROMAN_24);
		if (levelup >= 10 && levelup<28){
			iText(27, (HEIGHT - 39), "LEVEL 2", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (levelup >= 28 && levelup<51){
			iText(27, (HEIGHT - 39), "LEVEL 3", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (levelup >= 51){
			iText(27, (HEIGHT - 39), "FINAL LEVEL", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (lifecount >= 4){
		
			gameover = true;
		}
		if (gameover == true){

			level1background = true;
			level2background = false;
			creaturehitscartoon = true;
			bossExist = true;

			for (l = 0; l < 60; l++){

				comingzombie[l].zombieExistforlevel2 = true;


			}
		}
		if (gameover == true){
			iShowBMP(0, 0, gameoverlocation);

		} 
		
		if (gameover == true){

			iText((WIDTH / 2), (HEIGHT - 100), "'CLICK HERE' TO GO TO MAIN MENU", GLUT_BITMAP_TIMES_ROMAN_24);
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
	if (mx >= 564 && mx <= 916 && my >= 367 && my <= 535){
		gamestart = true;
	}
	if (mx >= 716 && mx <= 864 && my >= 640 && my <= 663){
		gamestart = false;

	}
	if (mx >= 550 && mx <= 905 && my >= 89 && my <= 235){
		exit(0);

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
		music = true;
		PlaySound("Music\\9_mm_gunshot-mike-koenig-123.wav", NULL, SND_ASYNC);
		
		PlaySound("Music\\audioclip-1484407410000-148245.wav", NULL, SND_LOOP | SND_ASYNC);
	
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
	else {
		
	}






}

void change() {
	cartoonImageIndex++;
	if (cartoonImageIndex >= 8) {
		cartoonImageIndex = 0;
	}
}

void change01() {
	lifebarIndex++;
	if (lifebarIndex >= 4) {
		lifebarIndex = 0;
	}
}

int main()


{
	srand((unsigned)time(NULL));
	iSetTimer(200, change);

	PlaySound("Music\\audioclip-1484407410000-148245.wav", NULL, SND_LOOP | SND_ASYNC);
	



	//place your own initialization codes here.
	fallingcreatue1.setlocation();
	fallingcreatue2.setlocation1();
	fallingcreatue3.setlocation();
	fallingcreatue4.setlocation1();
	fallingcreatue5.setlocation1();
	fallingcreatue6.setlocation1();
	boss1.setlocationnn1();

	for (i = 0; i < 34; i++){
		comingzombie[i].setlocationn();
	}

	for (i = 1; i < 13; i++){
		comingzombie[i].positionXXX = comingzombie[i - 1].positionXXX + 200 + zombiewidth;

	}
	comingzombie[13].positionXXX = (WIDTH - zombiewidth - 45);


	for (i = 14; i < 34; i++){

		comingzombie[i].positionXXX = comingzombie[i - 1].positionXXX + 200 + zombiewidth;


	}
	for (i = 34; i < 60; i++){
		comingzombie[i].setlocationn1();
	}
	comingzombie[34].positionXXX = (WIDTH - zombiewidth - 45);

	for (i = 35; i < 60; i++){

		comingzombie[i].positionXXX = comingzombie[i - 1].positionXXX + 200 + zombiewidth;


	}

	iInitialize(WIDTH, HEIGHT, "Escape The House");
	return 0;
}
