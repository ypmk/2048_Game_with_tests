#include "functions.h"
#pragma warning(disable:4996)//отключаем предупреждение компилятора чтобы использовать getch()


int board[4][4]; //создаем матрицу для поля игры
int dirLine[] = { 1,0,-1,0 }; //ходы из строки
int dirColumn[] = { 0,1,0,-1 }; //ходы из колонны



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


//подсчитывание суммы значений элементов, находящихся на поле, то есть получение счета за игру
int score() {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sum += board[i][j];
		}
	}
	return sum;

}


//функция выхода из игры
//выход бывает быстрый или после вопроса, уточняющего желание игрока выйти из игры
void exit_game(string s) {
	if (s == "fast") {
		system("cls"); //очищаем экран
		ifstream file_exit_fast("exit_fast.txt"); //запускаем интерфейс страницы быстрого выхода
		string str;
		while (!file_exit_fast.eof()) {
			getline(file_exit_fast, str);
			cout << str << endl;
		}
		file_exit_fast.close();
		while (1 == 1) {
			int key = getch(); //не реагируем на любые нажития клавиш, игра завершена, осталось только закрыь окно нажав на крестик
			continue;
		}
	}
	else if (s == "ask") {
		system("cls"); //очищаем экран
		ifstream file_exit_ask("exit_ask.txt"); //запускаем интерфейс выхода с уточняющим вопросом
		string str;
		while (!file_exit_ask.eof()) {
			getline(file_exit_ask, str);
			cout << str << endl;

		}
		file_exit_ask.close();

		while (1 == 1) {
			int key = getch(); //считываем нажатие клавишей пользователем
			if (key == 27) { //если пользоователь нажал esc
				exit_game("fast"); // запускаем функцию быстрого выхода из игры
				break;

			}
			else if (key == 75) { //пользователь нажал стрелочку влево, то есть он хочет вернуться к правилам
				rules(); //запсукаем страницу с правилами
				break;
			}
			else {
				continue; //другие нажатия клавиш игнорируются
			}
		}

	}

}


//функция, переводящая на новую страницу игры, на которой размещены правила игры
void rules() {
	system("cls"); //очищаем экрна
	ifstream file_rules("rules.txt"); //запускаем интерфейс с правилами(выводим текст)
	string str;
	while (!file_rules.eof()) {
		getline(file_rules, str);
		cout << str << endl;

	}
	file_rules.close();
	while (1 == 1) {
		int key = getch();  //считываем нажатие клавишей пользователем
		if (key == 75) {//пользователь нажал стрелочку влево, то есть он хочет вернуться в главное меню
			printUI_first(); //запускаем страницу с главным меню
			break;
		}
		else if (key == 27) { //если пользоователь нажал esc
			exit_game("ask"); //запускаем функцию длиного выхода, то есть выход с уточняющим вопросом
			break;
		}
		else {
			continue; //другие нажатия клавиш игнорируются
		}
	}

}


//функция, отвечающая за первую страницу, которую видит пользователь при начале игры
void printUI_first() {
	system("cls"); //очищаем экран
	ifstream file_first("first.txt"); //выводим начальную страницу
	string str;
	while (!file_first.eof()) {
		getline(file_first, str);
		cout << str << endl;

	}
	file_first.close();
	cout << "\t \t \t";
	while (1 == 1) {
		int key = getch();//считываем нажатие клавишей пользователем
		if (key == 49) { //пользователь нажал 1, то есть хочет прочитать правила
			rules(); //переходим на страницу с правилами
			break;
		}
		else if (key == 50) { //пользователь нажал 2, то есть хочет начать новую игру
			newGame(); //функция запуска новой игры
			game_all();//функция с основными действиями игры
			break;
		}
		else {
			continue;//другие нажатия клавиш игнорируются
		}
	}
}