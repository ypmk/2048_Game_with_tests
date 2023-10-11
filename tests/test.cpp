#include "pch.h"
#include "../2048_game_2023/functions.h"
#include "gtestbdd.h"

//Модульные тесты для функции isWin

//Пользователь выиграл
TEST(IsWinTest, Has2048) {
	//arrange
	int win[4][4] = { {2048, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	//act
	bool res = isWin(win);
	//assert
	EXPECT_EQ(true, res);
}

//Пользователь не выиграл
TEST(IsWinTest, DoesNotHave2048) {
	//arrange
	int win[4][4] = { {2, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	//act
	bool res = isWin(win);
	//assert
	EXPECT_EQ(false, res);
}

//Сценарии для функции canAddPiece
FEATURE("Pieces can be added on an empty space") {
	//AS_A developer
	//I_WANT to determine if a piece can be added
	//SO_THAT the game could stop if there aren't any moves left
}
SCENARIO("New piece can be added on a board")
{
	GIVEN("A board with an empty space")
		int board[4][4] = { {2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 0, 2}, {2, 2, 2, 2} };
	WHEN("a player made a move")
		bool res = canAddPiece(board);
	THEN("The result should be true")
		ASSERT_EQ(true, res);
}
SCENARIO("New piece cannot be added on a board")
{
	GIVEN("A board without an empty space")
		int board[4][4] = { {2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2} };
	WHEN("a player made a move")
		bool res = canAddPiece(board);
	THEN("The result should be false")
		ASSERT_EQ(false, res);
}