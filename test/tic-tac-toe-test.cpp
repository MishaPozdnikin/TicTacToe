#include "tic-tac-toe.h"

#include <gtest/gtest.h>

TEST(TicTacToeTest, print_field_TEST) { ASSERT_NO_THROW(print_field()); }

TEST(TicTacToeTest, check_field_TEST_TRUE) {
  clear_field();
  game.field[Y1][X1] = 'x';
  game.field[Y1][X2] = 'x';
  game.field[Y1][X3] = 'x';
  game.field[Y2][X1] = 'x';
  game.field[Y2][X2] = 'x';
  game.field[Y2][X3] = 'x';
  game.field[Y3][X1] = 'x';
  game.field[Y3][X2] = 'x';
  game.field[Y3][X3] = 'x';
  EXPECT_TRUE(check_field());
}

TEST(TicTacToeTest, check_field_TEST_FALSE) {
  clear_field();
  game.field[Y1][X1] = ' ';
  game.field[Y1][X2] = 'x';
  game.field[Y1][X3] = 'x';
  game.field[Y2][X1] = 'x';
  game.field[Y2][X2] = 'x';
  game.field[Y2][X3] = 'x';
  game.field[Y3][X1] = 'x';
  game.field[Y3][X2] = 'x';
  game.field[Y3][X3] = 'x';
  EXPECT_FALSE(check_field());
}

TEST(TicTacToeTest, update_field_FALSE) {
  unsigned x, y = 1;
  char character = 'x';
  clear_field();
  EXPECT_EQ(update_field(character, x, y), -1);
}

TEST(TicTacToeTest, update_field_TRUE) {
  unsigned x, y = 1;
  char character = 'x';
  clear_field();
  game.field[1][1] = character;
  EXPECT_TRUE(update_field(character, x, y));
}

TEST(TicTacToeTest, is_win_TRUE) {
  char character = 'x';
  clear_field();
  game.field[Y1][X1] = character;
  game.field[Y1][X2] = character;
  game.field[Y1][X3] = character;
  EXPECT_TRUE(is_win(character));
}

TEST(TicTacToeTest, is_win_FALSE) {
  char character = 'x';
  clear_field();
  game.field[Y3][X1] = character;
  game.field[Y1][X2] = character;
  game.field[Y1][X3] = character;
  EXPECT_FALSE(is_win(character));
}

TEST(TicTacToeTest, clear_field_TEST) { ASSERT_NO_THROW(clear_field()); }
