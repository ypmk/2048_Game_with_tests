#include "pch.h"
//#include "../2048_game_2023/2048_game_2023.cpp"

TEST(IsWinTest, Has2048) {
	//arrange
	int win[4][4] = { {2048, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	//act
	bool res = isWin(win);
	//assert
	EXPECT_EQ(true, res);
}
TEST(IsWinTest, DoesNotHave2048) {
	//arrange
	int win[4][4] = { {2, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	//act
	bool res = isWin(win);
	//assert
	EXPECT_EQ(false, res);
}