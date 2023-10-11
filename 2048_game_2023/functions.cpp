#include "functions.h"
#pragma warning(disable:4996)//��������� �������������� ����������� ����� ������������ getch()


int board[4][4]; //������� ������� ��� ���� ����
int dirLine[] = { 1,0,-1,0 }; //���� �� ������
int dirColumn[] = { 0,1,0,-1 }; //���� �� �������



//���� ��������� �������� ������� �� ����
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


//��������� ������� �� ��������� ��������� �������
void addPiece() {
	pair<int, int> pos = generateUnoccupiedPosition();
	board[pos.first][pos.second] = 2;
}


//������ ����� ����, �� ���� �������� ���� � ���������� ������ ��������, ������� 2
void newGame() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			board[i][j] = 0;
		}
	}
	addPiece();
}


//������������� ����� �������� ���������, ����������� �� ����, �� ���� ��������� ����� �� ����
int score() {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sum += board[i][j];
		}
	}
	return sum;

}


//������� ������ �� ����
//����� ������ ������� ��� ����� �������, ����������� ������� ������ ����� �� ����
void exit_game(string s) {
	if (s == "fast") {
		system("cls"); //������� �����
		ifstream file_exit_fast("exit_fast.txt"); //��������� ��������� �������� �������� ������
		string str;
		while (!file_exit_fast.eof()) {
			getline(file_exit_fast, str);
			cout << str << endl;
		}
		file_exit_fast.close();
		while (1 == 1) {
			int key = getch(); //�� ��������� �� ����� ������� ������, ���� ���������, �������� ������ ������ ���� ����� �� �������
			continue;
		}
	}
	else if (s == "ask") {
		system("cls"); //������� �����
		ifstream file_exit_ask("exit_ask.txt"); //��������� ��������� ������ � ���������� ��������
		string str;
		while (!file_exit_ask.eof()) {
			getline(file_exit_ask, str);
			cout << str << endl;

		}
		file_exit_ask.close();

		while (1 == 1) {
			int key = getch(); //��������� ������� �������� �������������
			if (key == 27) { //���� ������������� ����� esc
				exit_game("fast"); // ��������� ������� �������� ������ �� ����
				break;

			}
			else if (key == 75) { //������������ ����� ��������� �����, �� ���� �� ����� ��������� � ��������
				rules(); //��������� �������� � ���������
				break;
			}
			else {
				continue; //������ ������� ������ ������������
			}
		}

	}

}


//�������, ����������� �� ����� �������� ����, �� ������� ��������� ������� ����
void rules() {
	system("cls"); //������� �����
	ifstream file_rules("rules.txt"); //��������� ��������� � ���������(������� �����)
	string str;
	while (!file_rules.eof()) {
		getline(file_rules, str);
		cout << str << endl;

	}
	file_rules.close();
	while (1 == 1) {
		int key = getch();  //��������� ������� �������� �������������
		if (key == 75) {//������������ ����� ��������� �����, �� ���� �� ����� ��������� � ������� ����
			printUI_first(); //��������� �������� � ������� ����
			break;
		}
		else if (key == 27) { //���� ������������� ����� esc
			exit_game("ask"); //��������� ������� ������� ������, �� ���� ����� � ���������� ��������
			break;
		}
		else {
			continue; //������ ������� ������ ������������
		}
	}

}


//�������, ���������� �� ������ ��������, ������� ����� ������������ ��� ������ ����
void printUI_first() {
	system("cls"); //������� �����
	ifstream file_first("first.txt"); //������� ��������� ��������
	string str;
	while (!file_first.eof()) {
		getline(file_first, str);
		cout << str << endl;

	}
	file_first.close();
	cout << "\t \t \t";
	while (1 == 1) {
		int key = getch();//��������� ������� �������� �������������
		if (key == 49) { //������������ ����� 1, �� ���� ����� ��������� �������
			rules(); //��������� �� �������� � ���������
			break;
		}
		else if (key == 50) { //������������ ����� 2, �� ���� ����� ������ ����� ����
			newGame(); //������� ������� ����� ����
			game_all();//������� � ��������� ���������� ����
			break;
		}
		else {
			continue;//������ ������� ������ ������������
		}
	}
}