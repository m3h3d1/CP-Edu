#include<windows.h> //  header file for gotoxy
#include <stdio.h>     //header file for standard input output

COORD coord = {0, 0};  // sets coordinates to (0,0) as global variables
void gotoxy (int x, int y) {
    coord.X = x; coord.Y = y; // X and Y are the coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
  	//calling these function
	gotoxy(20,20);printf("This is demo of gotoxy function");
	return 0;
}