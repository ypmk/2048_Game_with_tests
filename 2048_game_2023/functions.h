#pragma once
#include<iostream>  //���������� ����������� ����������
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

//����������� ��������� ������� ����� ������������ �� � �� ������ � �� ������������ � �����
pair<int, int>generateUnoccupiedPosition();
void addPiece();
void newGame();
int score();
void exit_game(string s);
void rules();
void printUI_first();
void printUI_game();
bool isWin(int board[4][4]);
void applyMove(int direction);