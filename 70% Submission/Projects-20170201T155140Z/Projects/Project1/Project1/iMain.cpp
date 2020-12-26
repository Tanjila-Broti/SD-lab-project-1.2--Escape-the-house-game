/*
Original Author: S. M. Shahriar Nirjon
Last Modified by: Mohammad Saifur Rahman
last modified: October 13, 2015
Version: 2.0
*/



#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
# include "iGraphics.h"
#include<time.h>
int mposx, mposy;
int bulletwidth = 70;
int bulletheight = 50;
int cartoonX = 100;
int cartoonY = 50;
int bulletX;
int bulletY = 121;
int bulletmove = 140;
int levelup = 0;
int Level3hitcount = 0;
char cartoonName[] = "background\\mainchararcter12.bmp.bmp";
char background[] = "background\\housebackground2.bmp.bmp";
char background1[] = "background\\background1.bmp.bmp";
char background2[] = "background\\House_of_Skulltula 22(1)2.bmp.bmp";
char background3[] = "background\\final1.bmp.bmp";
char zombie[] = "background\\new zombie.bmp.bmp";
char bullet[] = "background\\bullet1.bmp.bmp";
char gameoverlocation[] = "background\\gameover.bmp.bmp";
char life[] = "background\\life.bmp.bmp";
char mainmenu[] = "background\\main_menu.bmp.bmp";
char highscorebackground[] = "background\\rsz_high_score_backgroundd.bmp.bmp";
char showtext[] = "level2";
char highscorename[1000];
char highscorenumber[100];
int highscorearrayindex = 0;
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
bool showhighscore = false;
bool congrats = false;
bool backgroundsound = false;
bool bulletsound = false;
bool zombiescreamsound = false;
bool cartoonscream = false;
bool askforhighscore = false;
int pleasebackground = 3;
bool bossExist = false;
bool showmenu = false;
int zombiewidth = 278;
int cartoonMove = 75;
int imageWidth = 191;
int imageHeight = 180;
int bosscount = 0;
int rectangleflag = 0;
int HEIGHT = 740;
int WIDTH = 1876;
int negativemarking = 0;
int totalmarking = 0;


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
char tempImage1[100] = "Character\\stand.bmp.bmp";


int zombieImageIndex = 0;
char ZombieGoingLeftImages[4][100] = {
	"Zombie\\01.bmp.bmp",
	"Zombie\\02.bmp.bmp",
	"Zombie\\03.bmp.bmp",
	"Zombie\\04.bmp.bmp",
};

char tempImageZombie[100] = "";


int i;
int j, k, l, m, n, z, c;
int mxx, myy;
int lifecount = 0;
FILE *fp;
void xstrcpy(char *to, char *from){
	int i;
	for (i = 0; (*from) != '\0'; i++){
		*to = *from;
		*to++;
		*from++;


	}

	*(to) = '\0';



}

void Myreverse(char str[], int len)
{
	int start, end;
	char temp;
	for (start = 0, end = len - 1; start < end; start++, end--) {
		temp = *(str + start);
		*(str + start) = *(str + end);
		*(str + end) = temp;
	}
}
// Implementation of itoa()
char* Myitoa(int num, char* str, int base)
{
	int i = 0;
	bool isNegative = false;

	/* Handle 0 explicitely, otherwise empty string is printed for 0 */
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	// In standard itoa(), negative numbers are handled only with 
	// base 10. Otherwise numbers are considered unsigned.
	if (num < 0 && base == 10)
	{
		isNegative = true;
		num = -num;
	}

	// Process individual digits
	while (num != 0)
	{
		int rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	// If number is negative, append '-'
	if (isNegative)
		str[i++] = '-';

	str[i] = '\0'; // Append string terminator

	// Reverse the string
	Myreverse(str, i);

	return str;
}

struct highscores{

	char name[100];
	int point;


}topscore[3], tempo, tempo1, topscore1[3];

void change() {
	cartoonImageIndex++;
	if (cartoonImageIndex >= 8) {
		cartoonImageIndex = 0;
	}
}

struct imagelocation{

	char location[100];
	int positionXX = rand() % 1650;
	int positionYY = HEIGHT;
	int ballmove = 14;
	int ballwidth = 96;
	int ballheight = 64;
	void setposition(){

		if (positionYY <= (200)){
			positionXX = rand() % 1650;
			positionYY = HEIGHT;
		}
		else
			positionYY -= ballmove;

	}
	void collision(){

		if (positionXX >= cartoonX && positionXX <= (cartoonX + imageWidth) && positionYY <= cartoonY){

			creaturehitscartoon = true;
			positionXX = rand() % 1500;
			positionYY = 740;

			negativemarking++;
			lifecount++;
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

}fallingcreatue1, fallingcreatue2, fallingcreatue3, fallingcreatue4, fallingcreatue5, fallingcreatue6, fallingcreatue7, fallingcreatue8, fallingcreatue9;


struct imagelocation1{
	bool zombieExistforlevel2 = false;
	bool bullethitszombieforlevel2 = false;
	bool zombieMovesleftforlevel2 = false;
	bool zombiehitcartoonforlevel2 = false;
	char locationn[100];
	int positionXXX = (WIDTH - zombiewidth - 45);
	int positionYYY = 12;
	int ballmovee = 60;
	int ballwidthh = 282;
	int ballheightt = 195;
	int hittest = 0;

	void setpositionn(){

		if (level2background == true){
			ballmovee = 68;
		}
		if (level3background == true){

			ballmovee = 63;
		}
		if (zombieMovesleftforlevel2 != true && zombieExistforlevel2 == false){
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
			iKeyboard('k');
			zombieExistforlevel2 = true;
			bullethitszombieforlevel2 = true;
			bulletX = cartoonX + imageWidth;
			bulletGoRight = false;
			for (i = 0; i < 3; i++){
				positionXXX = WIDTH + 20;
				positionXXX = positionXXX + 490;
			}
			positionYYY = HEIGHT + 2000;
			zombieMovesleftforlevel2 = true;
			bulletexist = false;
			levelup++;

		}




	}
	void Level3bullethittingzombie(){


		if (bulletGoRight == true && bulletX >= positionXXX && level3background == true){
			bulletX = cartoonX + imageWidth;
			bulletGoRight = false;
			++hittest;
			bulletexist = false;
			printf("\n %d", hittest);

			if (hittest >= 2){
				zombieExistforlevel2 = true;
				bullethitszombieforlevel2 = true;
				bulletX = cartoonX + imageWidth;
				bulletGoRight = false;
				for (i = 0; i < 3; i++){
					positionXXX = WIDTH + 20;
					positionXXX = positionXXX + 490;
				}
				positionYYY = HEIGHT + 2000;
				zombieMovesleftforlevel2 = true;
				bulletexist = false;
				levelup++;

			}
		}


	}
	void zombiehittingcartoon(){
		//iKeyboard('l');
		if (positionXXX <= (cartoonX + imageWidth)){

			zombiehitcartoonforlevel2 = true;
			for (i = 0; i < 3; i++){
				positionXXX = WIDTH + 20;
				positionXXX = positionXXX + 500;
			}
			positionYYY = HEIGHT + 2000;
			lifecount++;
			negativemarking++;
			printf("\nhit no \t %d", lifecount);
		}



	}

}comingzombie[100];


struct boss{

	char locationn[100];
	int bossgoup = 0;
	int bossgodown = 0;
	int ballwidthh = 300;
	int ballheighth = 391;
	int bosswidth = 326;
	int bossheight = 200;
	int positionYYY = (HEIGHT - ballheighth);
	int positionXXX = (WIDTH - ballwidthh - 310 + 100);
	int ballmoveeX = 30;
	int ballmoveeY = 20;
	int bossmove = 30;
	int fireballX = 949;
	int fireballY = 414;
	int ballmovecopyX = 20;
	int ballmovecopyY = 13;

	void setpositionn(){

		if (positionYYY <= 0){
			ballmoveeX = rand() % 50;
			ballmoveeY = rand() % 30;
			positionYYY = 1;
			bossgodown = 1;
			bossgoup = 1;
			if (ballmoveeX >= 25 && ballmoveeX <= 50){

				ballmovecopyX = ballmoveeX;
			}
			if (ballmoveeY >= 10 && ballmoveeY <= 30){

				ballmovecopyY = ballmoveeY;
			}

		}

		if ((positionYYY + bossheight) >= HEIGHT){
			bossgodown = 4;
			printf("\n bingo");
		}
		if ((positionYYY + bossheight) >= HEIGHT){
			ballmoveeX = rand() % 50;
			ballmoveeY = rand() % 30;
			bossgoup = 0;
			fireballX = positionXXX - 120;
			fireballY = positionYYY - 100;
			if (ballmoveeX >= 25 && ballmoveeX <= 50){

				ballmovecopyX = ballmoveeX;
			}
			if (ballmoveeY >= 10 && ballmoveeY <= 30){

				ballmovecopyY = ballmoveeY;
			}
		}
		if (bossgodown == 0 || bossgodown == 4)
		{
			positionYYY = positionYYY - bossmove;

		}
		if (bossgoup == 1){

			positionYYY += bossmove;

		}

	}

	void setlocationn(){
		xstrcpy(locationn, "background\\newdragon.bmp.bmp");

	}
	void bullethittingboss(){
		if (bulletX >= positionXXX && bulletY >= positionYYY){

			bosscount++;
			levelup = levelup + 30;

			bulletX = cartoonX + imageWidth;
			bulletGoRight = false;
			bulletexist = false;
		}
	}

	void bosshittingcartoon(){
		if (positionXXX <= (cartoonX + imageWidth)){

			lifecount++;
			negativemarking = negativemarking + 5;
		}


	}
	void fireballsetposition(){


		fireballX = fireballX - ballmovecopyX;
		fireballY = fireballY - ballmovecopyY;
		if (fireballX <= 0){

			fireballX = positionXXX - 120;
			fireballY = positionYYY - 100;

		}
		if (fireballY <= 0){

			fireballX = positionXXX - 140;
			fireballY = positionYYY - 100;

		}
		if (fireballX <= (cartoonX + imageWidth) && fireballY <= (cartoonY + imageHeight)){


			lifecount++;
			fireballX = positionXXX - 140;
			fireballY = positionYYY - 100;


		}
		if (fireballX <= (bulletX + bulletwidth) && fireballY <= (bulletY + bulletheight)){

			bulletX = cartoonX + imageWidth;
			bulletGoRight = false;
			bulletexist = false;

		}
	}




} boss1;

void InitializeEverythingWhenGameIsOver(){
	mposx, mposy;
	bulletwidth = 70;
	zombieImageIndex = 0;
	bulletheight = 50;
	cartoonX = 100;
	cartoonY = 50;
	bulletX;
	bulletY = 121;
	bulletmove = 10;
	levelup = 0;
	Level3hitcount = 0;



	highscorearrayindex = 0;
	goleft = false;
	goright = false;
	stand = true;
	bulletGoRight = false;
	creaturehitscartoon = false;
	level1background = false;
	level2background = false;
	bulletexist = false;
	gameover = false;
	gamestart = false;
	level3background = false;
	showhighscore = false;
	congrats = false;
	backgroundsound = false;
	bulletsound = false;
	zombiescreamsound = false;
	cartoonscream = false;
	askforhighscore = false;
	pleasebackground = 3;
	bossExist = false;
	showmenu = false;
	zombiewidth = 278;
	cartoonMove = 75;
	imageWidth = 191;
	imageHeight = 180;
	bosscount = 0;
	rectangleflag = 0;
	HEIGHT = 740;
	WIDTH = 1876;
	negativemarking = 0;
	totalmarking = 0;

	cartoonImageIndex = 0;



	lifecount = 0;
	boss1.bossgodown = 0;
	boss1.ballwidthh = 300;
	boss1.ballheighth = 391;
	boss1.bosswidth = 326;
	boss1.bossheight = 200;
	boss1.positionYYY = (HEIGHT - boss1.ballheighth);
	boss1.positionXXX = (WIDTH - boss1.ballwidthh - 310 + 100);
	boss1.ballmoveeX = 30;
	boss1.ballmoveeY = 20;
	boss1.bossmove = 30;
	boss1.fireballX = 949;
	boss1.fireballY = 414;
	boss1.ballmovecopyX = 20;
	boss1.ballmovecopyY = 13;
	fallingcreatue1.ballheight = 64;
	fallingcreatue1.positionXX = rand() % 1650;
	fallingcreatue1.positionYY = HEIGHT;
	fallingcreatue1.ballmove = 14;
	fallingcreatue1.ballwidth = 96;
	fallingcreatue2.ballheight = 64;
	fallingcreatue2.positionXX = rand() % 1650;
	fallingcreatue2.positionYY = HEIGHT;
	fallingcreatue2.ballmove = 14;
	fallingcreatue2.ballwidth = 96;
	fallingcreatue3.ballheight = 64;
	fallingcreatue3.positionXX = rand() % 1650;
	fallingcreatue3.positionYY = HEIGHT;
	fallingcreatue3.ballmove = 14;
	fallingcreatue3.ballwidth = 96;
	fallingcreatue4.ballheight = 64;
	fallingcreatue4.positionXX = rand() % 1650;
	fallingcreatue4.positionYY = HEIGHT;
	fallingcreatue4.ballmove = 15;
	fallingcreatue4.ballwidth = 96;
	fallingcreatue5.ballheight = 64;
	fallingcreatue5.positionXX = rand() % 1650;
	fallingcreatue5.positionYY = HEIGHT;
	fallingcreatue5.ballmove = 15;
	fallingcreatue5.ballwidth = 96;
	fallingcreatue6.ballheight = 64;
	fallingcreatue6.positionXX = rand() % 1650;
	fallingcreatue6.positionYY = HEIGHT;
	fallingcreatue6.ballmove = 15;
	fallingcreatue6.ballwidth = 96;
	fallingcreatue7.ballheight = 64;
	fallingcreatue7.positionXX = rand() % 1650;
	fallingcreatue7.positionYY = HEIGHT;
	fallingcreatue7.ballmove = 16;
	fallingcreatue7.ballwidth = 96;

	fallingcreatue8.ballheight = 64;
	fallingcreatue8.positionXX = rand() % 1650;
	fallingcreatue8.positionYY = HEIGHT;
	fallingcreatue8.ballmove = 16;
	fallingcreatue8.ballwidth = 96;

	fallingcreatue9.ballheight = 64;
	fallingcreatue9.positionXX = rand() % 1650;
	fallingcreatue9.positionYY = HEIGHT;
	fallingcreatue9.ballmove = 16;
	fallingcreatue9.ballwidth = 96;

	for (i = 0; i < 100; i++){
		comingzombie[i].zombieExistforlevel2 = false;
		comingzombie[i].bullethitszombieforlevel2 = false;
		comingzombie[i].zombieMovesleftforlevel2 = false;
		comingzombie[i].zombiehitcartoonforlevel2 = false;
		comingzombie[i].positionXXX = (WIDTH - zombiewidth - 45);
		comingzombie[i].positionYYY = 12;
		comingzombie[i].ballmovee = 95;
		comingzombie[i].ballwidthh = 282;
		comingzombie[i].ballheightt = 195;
		comingzombie[i].hittest = 0;


	}

	fallingcreatue1.setlocation();
	fallingcreatue2.setlocation1();
	fallingcreatue3.setlocation();
	fallingcreatue4.setlocation1();
	fallingcreatue5.setlocation1();
	fallingcreatue6.setlocation1();
	fallingcreatue7.setlocation1();
	fallingcreatue8.setlocation1();
	fallingcreatue9.setlocation1();
	boss1.setlocationn();

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

}
void Rectangle(){
	if (rectangleflag == 0){
		iRectangle((WIDTH / 2), ((HEIGHT / 2) - 240), 500, 50);
		iText(1000, 150, highscorename);
	}
	if (rectangleflag == 1){
		iSetColor(255, 0, 0);
		iRectangle((WIDTH / 2), ((HEIGHT / 2) - 240), 500, 50);
		iText(1000, 150, highscorename);
		iSetColor(245, 245, 245);
	}
}
/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{

	//place your drawing codes here
	iClear();

	if (gameover != true){
		iShowBMP(0, 0, mainmenu);
	}
	//printf("\n mxx \t%d", mxx);

	//printf("\n myy \t%d", myy);
	//printf("\n Level 3 hitcount= %d", Level3hitcount);
	printf("\n char index= %d", cartoonImageIndex);
	if (gamestart == true){

		iSetColor(245, 245, 245);

		if (level1background != true){
			iShowBMP(0, 0, background);
		}
		if (levelup >= 10){
			level1background = true;
			level2background = true;
			//PlaySound("Maid_with_the_Flaxen_Hair_converted.wav", NULL, SND_ASYNC);
			//PlaySoundW();

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

		if (levelup < 51){
			fallingcreatue1.setposition();
			fallingcreatue2.setposition();
			fallingcreatue3.setposition();
		}
		//fallingcreatue1.collision();
		if (levelup >= 10 && levelup<51){
			fallingcreatue4.setposition();
			fallingcreatue5.setposition();
			fallingcreatue6.setposition();

			//fallingcreatue2.collision();
			//fallingcreatue3.collision();
		}
		if (levelup >= 28 && levelup<51){

			fallingcreatue7.setposition();
			fallingcreatue8.setposition();
			fallingcreatue9.setposition();
			//fallingcreatue4.collision();
		}
		/*
		if (levelup >= 51){

		fallingcreatue5.setposition();
		fallingcreatue6.setposition();
		//fallingcreatue5.collision();
		//fallingcreatue6.collision();
		}

		*/





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
				comingzombie[m].Level3bullethittingzombie();
				comingzombie[m].zombiehittingcartoon();
			}

		}

		if (levelup < 10){
			for (k = 0; k < 13; k++){
				if ((comingzombie[k].zombieExistforlevel2 != true)){
					iShowBMP2(comingzombie[k].positionXXX, comingzombie[k].positionYYY, ZombieGoingLeftImages
						[zombieImageIndex], 0);
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
					iShowBMP2(comingzombie[n].positionXXX, comingzombie[n].positionYYY, ZombieGoingLeftImages
						[zombieImageIndex], 0);
				}
			}
		}
		if (levelup >= 28){

			for (n = 0; n < 60; n++){
				if ((comingzombie[n].zombieExistforlevel2 != true)){
					iShowBMP2(comingzombie[n].positionXXX, comingzombie[n].positionYYY, ZombieGoingLeftImages
						[zombieImageIndex], 0);
				}
			}
		}



		if (levelup < 51){
			iShowBMP2(fallingcreatue1.positionXX, fallingcreatue1.positionYY, fallingcreatue1.location, 0);
			iShowBMP2(fallingcreatue2.positionXX, fallingcreatue2.positionYY, fallingcreatue2.location, 0);
			iShowBMP2(fallingcreatue3.positionXX, fallingcreatue3.positionYY, fallingcreatue3.location, 0);
		}
		if (levelup >= 10 && levelup<51){
			iShowBMP2(fallingcreatue4.positionXX, fallingcreatue4.positionYY, fallingcreatue4.location, 0);
			iShowBMP2(fallingcreatue5.positionXX, fallingcreatue5.positionYY, fallingcreatue5.location, 0);
			iShowBMP2(fallingcreatue6.positionXX, fallingcreatue6.positionYY, fallingcreatue6.location, 0);
		}
		if (levelup >= 28 && levelup<51){
			iShowBMP2(fallingcreatue7.positionXX, fallingcreatue7.positionYY, fallingcreatue7.location, 0);
			iShowBMP2(fallingcreatue8.positionXX, fallingcreatue8.positionYY, fallingcreatue8.location, 0);
			iShowBMP2(fallingcreatue9.positionXX, fallingcreatue9.positionYY, fallingcreatue9.location, 0);

		}
		/*
		if (levelup >= 51){
		iShowBMP2(fallingcreatue5.positionXX, fallingcreatue5.positionYY, fallingcreatue5.location, 0);
		iShowBMP2(fallingcreatue6.positionXX, fallingcreatue6.positionYY, fallingcreatue6.location, 0);

		}*/

		/*
		if (gameover != true){
		iShowBMP2(cartoonX, cartoonY, cartoonName, 0);
		}*/

		if (gameover != true) {
			if (goright) {
				iShowBMP2(cartoonX, cartoonY - 30, cartoonGoingRightImages[cartoonImageIndex], 0);
				xstrcpy(tempImage, cartoonGoingRightImages[cartoonImageIndex]);
			}
			if (goleft) {
				iShowBMP2(cartoonX, cartoonY - 30, cartoonGoingLeftImages[cartoonImageIndex], 0);
				xstrcpy(tempImage, cartoonGoingLeftImages[cartoonImageIndex]);
			}
			if (stand) {

				iShowBMP2(cartoonX, cartoonY - 30, tempImage1, 0);
			}
		{
			goright = false;
			goleft = false;
			stand = true;
		}
		}
		/*if (gameover != true && pleasebackground != 4) {

		{
		iShowBMP2((WIDTH - zombiewidth - 45), 12, ZombieGoingLeftImages
		[zombieImageIndex], 0);
		xstrcpy(tempImageZombie, ZombieGoingLeftImages[zombieImageIndex]);
		}
		} */

		if (bulletexist != false){
			iShowBMP2(bulletX, bulletY, bullet, 0);
		}


		if (levelup >= 51){

			boss1.setpositionn();
			boss1.bullethittingboss();
			boss1.fireballsetposition();

			if (bosscount >= 8){
				bossExist = true;
				gameover = true;
				pleasebackground = 3;
				congrats = true;
			}



			if (bossExist != true){
				iShowBMP2(boss1.positionXXX, boss1.positionYYY, boss1.locationn, 0);
			}
			if (bossExist != true){
				iShowBMP2(boss1.fireballX, boss1.fireballY, "background\\fireball.bmp.bmp", 0);
			}
		}


		if (fallingcreatue1.positionXX >= cartoonX && fallingcreatue1.positionXX <= (cartoonX + imageWidth) && fallingcreatue1.positionYY <= (cartoonY + imageHeight)){

			creaturehitscartoon = true;
			fallingcreatue1.positionYY = HEIGHT;

			negativemarking++;
			lifecount++;
		}
		if (fallingcreatue2.positionXX >= cartoonX && fallingcreatue2.positionXX <= (cartoonX + imageWidth) && fallingcreatue2.positionYY <= (cartoonY + imageHeight)){

			creaturehitscartoon = true;
			fallingcreatue2.positionYY = HEIGHT;

			negativemarking++;
			lifecount++;
		}
		if (fallingcreatue3.positionXX >= cartoonX && fallingcreatue3.positionXX <= (cartoonX + imageWidth) && fallingcreatue3.positionYY <= (cartoonY + imageHeight)){

			creaturehitscartoon = true;
			fallingcreatue3.positionYY = HEIGHT;

			negativemarking++;
			lifecount++;
		}
		if (fallingcreatue4.positionXX >= cartoonX && fallingcreatue4.positionXX <= (cartoonX + imageWidth) && fallingcreatue4.positionYY <= (cartoonY + imageHeight)){

			creaturehitscartoon = true;
			fallingcreatue4.positionYY = HEIGHT;
			negativemarking = negativemarking + 2;

			lifecount++;
		}
		if (fallingcreatue5.positionXX >= cartoonX && fallingcreatue5.positionXX <= (cartoonX + imageWidth) && fallingcreatue5.positionYY <= (cartoonY + imageHeight)){

			creaturehitscartoon = true;
			fallingcreatue5.positionYY = HEIGHT;

			negativemarking++;
			lifecount++;
		}
		if (fallingcreatue6.positionXX >= cartoonX && fallingcreatue6.positionXX <= (cartoonX + imageWidth) && fallingcreatue6.positionYY <= (cartoonY + imageHeight)){
			creaturehitscartoon = true;
			fallingcreatue6.positionYY = HEIGHT;

			negativemarking++;
			lifecount++;
		}


		if (fallingcreatue7.positionXX >= cartoonX && fallingcreatue7.positionXX <= (cartoonX + imageWidth) && fallingcreatue7.positionYY <= (cartoonY + imageHeight)){
			creaturehitscartoon = true;
			fallingcreatue7.positionYY = HEIGHT;

			negativemarking++;
			lifecount++;
		}


		if (fallingcreatue8.positionXX >= cartoonX && fallingcreatue8.positionXX <= (cartoonX + imageWidth) && fallingcreatue8.positionYY <= (cartoonY + imageHeight)){
			creaturehitscartoon = true;
			fallingcreatue8.positionYY = HEIGHT;

			negativemarking++;
			lifecount++;
		}


		if (fallingcreatue9.positionXX >= cartoonX && fallingcreatue9.positionXX <= (cartoonX + imageWidth) && fallingcreatue9.positionYY <= (cartoonY + imageHeight)){
			creaturehitscartoon = true;
			fallingcreatue9.positionYY = HEIGHT;

			negativemarking++;
			lifecount++;
		}
		/*
		for (i = 0; i < 60; i++){

		if(fallingcreatue6.positionXX >= comingzombie[i].positionXXX && fallingcreatue6.positionXX <= (comingzombie[i].positionXXX + comingzombie[i].ballwidthh) && fallingcreatue6.positionYY <= comingzombie[i].positionYYY){

		fallingcreatue6.positionYY = HEIGHT;
		}

		if (fallingcreatue5.positionXX >= comingzombie[i].positionXXX && fallingcreatue5.positionXX <= (comingzombie[i].positionXXX + comingzombie[i].ballwidthh) && fallingcreatue5.positionYY <= comingzombie[i].positionYYY){

		fallingcreatue5.positionYY = HEIGHT;
		}

		if (fallingcreatue4.positionXX >= comingzombie[i].positionXXX && fallingcreatue4.positionXX <= (comingzombie[i].positionXXX + comingzombie[i].ballwidthh) && fallingcreatue4.positionYY <= comingzombie[i].positionYYY){

		fallingcreatue4.positionYY = HEIGHT;
		}

		if (fallingcreatue3.positionXX >= comingzombie[i].positionXXX && fallingcreatue3.positionXX <= (comingzombie[i].positionXXX + comingzombie[i].ballwidthh) && fallingcreatue3.positionYY <= comingzombie[i].positionYYY){

		fallingcreatue3.positionYY = HEIGHT;
		}

		if (fallingcreatue2.positionXX >= comingzombie[i].positionXXX && fallingcreatue2.positionXX <= (comingzombie[i].positionXXX + comingzombie[i].ballwidthh) && fallingcreatue2.positionYY <= comingzombie[i].positionYYY){

		fallingcreatue2.positionYY = HEIGHT;
		}

		if (fallingcreatue1.positionXX >= comingzombie[i].positionXXX && fallingcreatue1.positionXX <= (comingzombie[i].positionXXX + comingzombie[i].ballwidthh) && fallingcreatue1.positionYY <= comingzombie[i].positionYYY){

		fallingcreatue1.positionYY = HEIGHT;
		}





		}
		*/

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
			cartoonX = 5;

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



		if (lifecount < 4){
			iShowBMP(1500, (HEIGHT - 45), life);
		}
		if (lifecount < 2){
			iShowBMP(1550, (HEIGHT - 45), life);
		}
		if (lifecount < 1){
			iShowBMP(1600, (HEIGHT - 45), life);
		}
		if (levelup < 10){
			iText(27, (HEIGHT - 39), "LEVEL 1", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		iText(1400, (HEIGHT - 39), "LIFE", GLUT_BITMAP_TIMES_ROMAN_24);
		if (levelup >= 10 && levelup < 28){
			iText(27, (HEIGHT - 39), "LEVEL 2", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (levelup >= 28 && levelup < 51){
			iText(27, (HEIGHT - 39), "LEVEL 3", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (levelup >= 51){
			iText(27, (HEIGHT - 39), "FINAL LEVEL", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (lifecount >= 30){

			gameover = true;
		}
		if (gameover == true){

			level1background = true;
			level2background = false;
			creaturehitscartoon = true;
			bossExist = true;
			gamestart = false;

			for (l = 0; l < 60; l++){

				comingzombie[l].zombieExistforlevel2 = true;


			}
		}


	}
	if (gameover == true){
		iShowBMP(0, 0, gameoverlocation);

	}
	if (gameover == true && askforhighscore == true){

		Rectangle();
		iText((740), (210), "TYPE YOUR NAME BELOW:", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (gameover == true){
		iText(((WIDTH / 2)), (HEIGHT - 100), "'CLICK HERE' TO GO TO MAIN MENU", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (gameover == true && congrats == true){

		iText(((WIDTH / 2) - 200), (HEIGHT - 50), "CONGRATULATIONS!YOU ESCAPED SUCCESFULLY", GLUT_BITMAP_TIMES_ROMAN_24);


	}
	totalmarking = levelup - negativemarking;
	if (gameover == true){
		totalmarking = levelup - negativemarking;
		iText(1340, 210, "YOUR SCORE : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1650, 210, Myitoa(totalmarking, highscorenumber, 10), GLUT_BITMAP_TIMES_ROMAN_24);

		//iText((740), (210), "TYPE YOUR NAME BELOW:", GLUT_BITMAP_TIMES_ROMAN_24);
	}



	/*fopen_s(&fp, "Highscore3.txt", "r");
	for (;;)
	{



	z = fgetc(fp);
	if (z == EOF){
	fclose(fp);
	break;
	}
	fscanf(fp, "%d %[^\n]", &tempo.point, tempo.name);
	if (tempo.point > topscore[0].point){
	topscore[0] = tempo;

	}
	l = ftell(fp);
	l = l + 1;
	fseek(fp, l, SEEK_SET);
	}
	fclose(fp);


	*/


	//fclose(fp);
	/*
	printf("\n");
	printf("here we go");
	printf("\n");
	printf(topscore[0].name);
	printf("\n");
	printf("his score %d", topscore[0].point);

	*/

	/*	fopen_s(&fp, "Highscore3.txt", "r");
	for (;;)
	{



	z = fgetc(fp);
	if (z == EOF){
	fclose(fp);
	break;
	}
	fscanf(fp, "%d %[^\n]", &tempo.point, tempo.name);
	if (tempo.point > topscore[1].point && tempo.point != topscore[0].point){
	topscore[1] = tempo;

	}
	l = ftell(fp);
	l = l + 1;
	fseek(fp, l, SEEK_SET);
	}
	fclose(fp);

	*/



	//fclose(fp);
	/*
	printf("\n");
	printf("here we go");
	printf("\n");
	printf(topscore[1].name);
	printf("\n");
	printf("his score %d", topscore[1].point);
	*/

	/*	fopen_s(&fp, "Highscore3.txt", "r");

	for (;;)
	{



	z = fgetc(fp);
	if (z == EOF){
	fclose(fp);
	break;
	}
	fscanf(fp, "%d %[^\n]", &tempo.point, tempo.name);
	if (tempo.point > topscore[2].point && tempo.point != topscore[0].point && tempo.point != topscore[1].point){
	topscore[2] = tempo;

	}
	l = ftell(fp);
	l = l + 1;
	fseek(fp, l, SEEK_SET);
	}
	fclose(fp);*/

	fopen_s(&fp, "Highscore6.txt", "r");
	for (;;)

	{
		fscanf(fp, "%d %[^\n]", &topscore1[0].point, topscore1[0].name);


		/*z = fgetc(fp);
		if (z == EOF){
		fclose(fp);
		break;
		}*/



		//	fscanf(fp, "%d %[^\n]",&topscore1[0].point,topscore1[0].name);



		l = ftell(fp);
		l = l + 1;
		fseek(fp, l, SEEK_SET);
		fscanf(fp, "%d %[^\n]", &topscore1[1].point, topscore1[1].name);
		l = ftell(fp);
		l = l + 1;
		fseek(fp, l, SEEK_SET);
		fscanf(fp, "%d %[^\n]", &topscore1[2].point, topscore1[2].name);
		z = fgetc(fp);
		if (z == EOF){
			fclose(fp);
			break;
		}
	}
	fclose(fp);


	//printf(topscore1[2].name);
	//bubblesoting below:
	for (i = 2; i >= 1; i--)
		for (j = 0; j < i; j++)
			if (topscore1[j].point >= topscore1[j + 1].point)
			{

				tempo.point = topscore1[j + 1].point;
				xstrcpy(tempo.name, topscore1[j + 1].name);
				topscore1[j + 1].point = topscore1[j].point;
				xstrcpy(topscore1[j + 1].name, topscore1[j].name);
				topscore1[j].point = tempo.point;
				xstrcpy(topscore1[j].name, tempo.name);

			}
	printf("\n");
	printf(topscore1[2].name);

	for (i = 0; i < 3; i++){

		if (totalmarking >= topscore1[i].point){
			askforhighscore = true;
			topscore1[i].point = totalmarking;
			xstrcpy(topscore1[i].name, highscorename);
			break;
		}
		else
		{
			askforhighscore = false;
		}

	}

	printf("\nafter comparing");
	printf(topscore1[2].name);
	printf("\n");
	printf("%d", topscore1[2].point);
	/*for (i = 2; i >= 1; i--)
	for (j = 0; j < i; j++)
	if (topscore1[j].point > topscore1[j + 1].point)
	{

	tempo.point = topscore1[j + 1].point;
	xstrcpy(tempo.name, topscore1[j + 1].name);
	topscore1[j + 1].point = topscore1[j].point;
	xstrcpy(topscore1[j + 1].name, topscore1[j].name);
	topscore1[j].point = tempo.point;
	xstrcpy(topscore1[j].name, tempo.name);

	}
	*/
	//fclose(fp);
	/*printf("\n");
	printf("here we go");
	printf("\n");
	printf(topscore[2].name);
	printf("\n");
	printf("his score %d", topscore[2].point);
	*/
	if (showhighscore == true){

		iShowBMP(0, 0, highscorebackground);
		iText(((WIDTH)-1740), (HEIGHT - 100), "'CLICK HERE' TO GO TO MAIN MENU", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(466, 380, "1", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(506, 380, topscore1[2].name, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 380, Myitoa(topscore1[2].point, highscorenumber, 10), GLUT_BITMAP_TIMES_ROMAN_24);
		iText(466, 340, "2", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(506, 340, topscore1[1].name, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 340, Myitoa(topscore1[1].point, highscorenumber, 10), GLUT_BITMAP_TIMES_ROMAN_24);
		iText(466, 300, "3", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(506, 300, topscore1[0].name, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 300, Myitoa(topscore1[0].point, highscorenumber, 10), GLUT_BITMAP_TIMES_ROMAN_24);

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
	if (mx >= 662 && mx <= 858 && my >= 331 && my <= 414){
		gamestart = true;
	}
	if (mx >= 662 && mx <= 858 && my >= 331 && my <= 414 && gameover == true){
		InitializeEverythingWhenGameIsOver();
		gamestart = true;
	}
	if (mx >= 716 && mx <= 864 && my >= 640 && my <= 663){
		gameover = false;
		gamestart = false;
		InitializeEverythingWhenGameIsOver();
	}
	if (mx >= 664 && mx <= 883 && my >= 110 && my <= 172 && gameover != true){
		exit(0);

	}
	if (mx >= 409 && mx <= 1103 && my >= 223 && my <= 287){
		showhighscore = true;

	}
	if (mx >= 98 && mx <= 254 && my >= 642 && my <= 661){
		showhighscore = false;

	}
	if (mx >= 707 && mx <= 1093 && my >= 130 && my <= 177){
		rectangleflag = 1;
	}
	else
	{
		rectangleflag = 0;
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
	if (rectangleflag == 1){
		highscorename[highscorearrayindex] = key;
		highscorearrayindex++;
	}
	if (key == '\r'){
		for (i = 0; i < 3; i++){

			if (totalmarking >= topscore1[i].point){

				topscore1[i].point = totalmarking;
				xstrcpy(topscore1[i].name, highscorename);

				break;
			}

		}
		fopen_s(&fp, "Highscore6.txt", "w");
		for (j = 0; j< 3; j++){

			fprintf(fp, "%d", topscore1[j].point);
			fprintf(fp, " ");
			fprintf(fp, topscore1[j].name);
			fprintf(fp, "\n");

		}
		fclose(fp);


		/*if (totalmarking > -4){
		fopen_s(&fp, "Highscore4.txt", "r");

		l = ftell(fp);
		for (;;)
		{


		fseek(fp, l, SEEK_SET);

		z = fgetc(fp);
		if (z == EOF){
		fclose(fp);
		break;
		}
		fscanf(fp, "%d %[^\n]", &tempo.point, tempo.name);

		if (totalmarking > tempo.point){
		fopen_s(&fp, "Highscore4.txt", "r");
		fseek(fp, l, SEEK_SET);
		xstrcpy(tempo.name, highscorename);
		fprintf(fp, "%d", tempo.point);
		fprintf(fp, " ");
		fprintf(fp, tempo.name);
		fclose(fp);
		break;
		}
		l = ftell(fp);
		l = l + 1;


		}
		fclose(fp);
		}
		*/
		//ma nigga code below
		/*
		fopen_s(&fp, "Highscore3.txt", "r");
		for( ; ;)
		{



		z = fgetc(fp);
		if (z == EOF){
		fclose(fp);
		break;
		}
		fscanf(fp, "%d %[^\n]", &tempo.point, tempo.name);
		if (tempo.point > topscore[0].point){
		topscore[0] = tempo;

		}
		l = ftell(fp);
		l = l + 1;
		fseek(fp, l, SEEK_SET);
		}
		fclose(fp);





		//fclose(fp);
		printf("\n");
		printf("here we go");
		printf("\n");
		printf(topscore[0].name);
		printf("\n");
		printf("his score %d", topscore[0].point);
		*/


		/*
		fopen_s(&fp, "Highscore1.txt", "r");
		fscanf_s(fp,"%s %d%[^\n]",topscore[0].name,100,topscore[0].point,10);
		l = ftell(fp);
		fseek(fp, l + 1, SEEK_SET);
		fscanf_s(fp, "%s %d%[^\n]", topscore[0].name, 100, topscore[0].point, 10);
		fclose(fp);

		printf(topscore[0].name);
		printf("\n");
		printf(" %d",topscore[0].point);
		printf("\n");
		printf("ftell  %d", l);
		*/

		for (i = 0; i < highscorearrayindex; i++)
		{
			highscorename[i] = 0;
		}
		totalmarking = 0;
	}

	if (key == 's'){
		goleft = false;
		goright = false;



	}

	if (key == 'r'){

		bulletGoRight = true;
		bulletexist = true;
		bulletsound = true;
		backgroundsound = true;
		zombiescreamsound = false;
		cartoonscream = false;
		if (bulletsound == true){
			PlaySound("Music\\9_mm_gunshot-mike-koenig-123.wav", NULL, SND_ASYNC);

		}

	}
	if (key == 'k'){
		zombiescreamsound = true;
		bulletsound = false;
		//cartoonscream = false;
		backgroundsound = true;
		if (zombiescreamsound == true){
			PlaySound("Music\\dragonzd.wav", NULL, SND_ASYNC);
		}

	}

	/*if (key == 'l'); {

	//cartoonscream = true;
	bulletsound = false;
	backgroundsound = true;
	zombiescreamsound = false;
	if (cartoonscream == true){
	PlaySound("Music\\ah.wav", NULL, SND_ASYNC);

	}

	}
	*/
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
		change();
		goright = true;
		goleft = false;
		cartoonX += cartoonMove;
		stand = false;

	}
	//place your codes for other keys here
	if (key == GLUT_KEY_LEFT)
	{

		change();

		goleft = true;
		goright = false;
		cartoonX -= cartoonMove;

		stand = false;

	}


	else {

	}




}
/*
void change() {
cartoonImageIndex++;
if (cartoonImageIndex >= 8) {
cartoonImageIndex = 0;
}
}*/
void change01() {
	if (pleasebackground != 4){
		zombieImageIndex++;
		if (zombieImageIndex >= 4) {
			zombieImageIndex = 0;
		}
	}
}
//
int main()


{


	srand((unsigned)time(NULL));

	//iSetTimer(200, change);
	iSetTimer(18, change01);

	if (backgroundsound != true){
		bulletsound = false;
		zombiescreamsound = false;
		//cartoonscream = false;
		PlaySound("Music\\audioclip-1484407410000-148245.wav", NULL, SND_LOOP | SND_ASYNC);
	}


	//place your own initialization codes here.
	fallingcreatue1.setlocation();
	fallingcreatue2.setlocation1();
	fallingcreatue3.setlocation();
	fallingcreatue4.setlocation1();
	fallingcreatue5.setlocation1();
	fallingcreatue6.setlocation1();
	fallingcreatue7.setlocation1();
	fallingcreatue8.setlocation1();
	fallingcreatue9.setlocation1();
	boss1.setlocationn();

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

	iInitialize(WIDTH, HEIGHT, "demooo");
	return 0;
}

