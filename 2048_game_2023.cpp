#include<iostream>  //подключаем необходимые библиотеки
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstdlib>

#pragma warning(disable:4996)//отключаем предупреждение компилятора чтобы использовать getch()


using namespace std;


int board[4][4]; //создаем матрицу для поля игры
int dirLine[] = { 1,0,-1,0 }; //ходы из строки
int dirColumn[] = { 0,1,0,-1 }; //ходы из колонны


//прописываем прототипы функций чтобы использовать их и не думать о их расположении в файле
pair<int, int>generateUnoccupiedPosition();
void addPiece();
void newGame();




//ищем рандомную свбодную позицию на поле
pair<int, int>generateUnoccupiedPosition() {
	int occupied = 1, line, column;
	while (occupied) {
		line = rand() % 4;
		column = rand() % 4;
		if (board[line][column] == 0) {
			occupied = 0;
		}
	}
	return make_pair(line, column);
}


//добавляем двоечку на рандомную свободную позицию
void addPiece() {
	pair<int, int> pos = generateUnoccupiedPosition();
	board[pos.first][pos.second] = 2;
}


//начало новой игры, то есть очищение поля и добавление одного элемента, равного 2
void newGame() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			board[i][j] = 0;
		}
	}
	addPiece();
}
