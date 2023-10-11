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

//функция, отвечающая за интерфейс страницы с полем игры
void printUI_game() {
	system("cls"); //очищаем экран
	cout << endl << endl << endl << endl;
	cout << endl << "\t \t \t " << "     Счёт: " << score() << endl; //выводим на экран счет
	for (int i = 0; i < 4; i++) {
		cout << "\t \t \t";
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0) {
				cout << setw(4) << "."; //если элемет матрицы равен нулю выводим на поле игра точку
			}
			else {
				cout << setw(4) << board[i][j]; //иначе выводим значение элемента матрицы
			}
		}
		cout << "\n";
	}
	cout << endl << endl << endl;
	cout << "\t \t \t Нажмите:" << endl << "\t \t \t esc - для выхода из игры" << endl << "\t \t \t 1 -вернуться в главное меню" << endl << "\t \t \t 2-начать новую игру" << endl;

}


//функция, узнающая можно ли совершить перемещение
bool canDoMove(int line, int column, int nextLine, int nextColumn) {
	if (nextLine < 0 || nextColumn < 0 || nextLine >= 4 || nextColumn >= 4 || board[line][column] != board[nextLine][nextColumn] && board[nextLine][nextColumn] != 0) {
		return false;
	}
	return true;
}



//функция, проверяющая, не выиграл ли пользователь
bool isWin(int board[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 2048) {
				return true;
			}
		}
	}

	return false;
}

//функция, совершающая передвижение элемента по полю
void applyMove(int direction) {
	int startLine = 0, startColumn = 0, LineStep = 1, columnStep = 1;

	if (direction == 0) {
		startLine = 3;
		LineStep = -1;
	}
	if (direction == 1) {
		startColumn = 3;
		columnStep = -1;
	}
	bool stop = false;
	int movePossible = 0, canAddPiece = 0;
	do {
		movePossible = 0;
		for (int i = startLine; i >= 0 && i < 4; i += LineStep) {
			for (int j = startColumn; j >= 0 && j < 4; j += columnStep) {
				int nextI = i + dirLine[direction];
				int nextJ = j + dirColumn[direction];
				if (board[i][j] && canDoMove(i, j, nextI, nextJ)) {
					board[nextI][nextJ] += board[i][j];
					board[i][j] = 0;
					movePossible = 1;
					canAddPiece = 1;
				}
			}
		}
		printUI_game();
	} while (movePossible);

	if (canAddPiece) {
		addPiece();
	}
}

//функция, проверяющая, есть ли в матрице нулевой элемент, то есть есть ли на поле пустое место, чтобы там появилась двойка
bool canAddPiece(int board[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0) {
				return true;
			}
		}
	}
	return false;
}


//функция, проверяющая, не проиграл ли игкрок
bool isOver() {
	string s;
	if (canAddPiece(board) == false) {
		bool over = true;
		if ((board[0][0] == board[0][1]) || (board[0][0] == board[1][0])) {
			over = false;
		}
		else if ((board[3][0] == board[2][0]) || (board[3][0] == board[3][1])) {
			over = false;
		}
		else if ((board[0][3] == board[0][2]) || (board[0][3] == board[1][3])) {
			over = false;
		}
		else if ((board[3][3] == board[3][2]) || (board[3][3] == board[2][3])) {
			over = false;
		}
		else {
			for (int i = 1; i < 3; i++) {
				for (int j = 1; j < 3; j++) {
					if ((board[i][j] == board[i][j + 1]) || (board[i][j] == board[i][j - 1]) || (board[i][j] == board[i + 1][j]) || (board[i][j] == board[i - 1][j])) {
						over = false;
					}
				}
			}
		}

		return over;
	}
	return false;
}