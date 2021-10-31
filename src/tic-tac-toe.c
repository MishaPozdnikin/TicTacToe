#ifndef tic_tac_toe_c_
#define tic_tac_toe_c_
#include "tic-tac-toe.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char empty_field[9][11] = {
    {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
    {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
    {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},
    {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
    {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
    {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},
    {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
    {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
    {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '}};

struct Game game = {
    .character = ' ',
    .field = {{' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
              {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
              {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},
              {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
              {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
              {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},
              {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
              {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
              {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '}},
    .game_mode = 1};

void game_menu() {
  char mode;
  printf("\t\t\tTIC-TAC-TOE!\n\n\n");
  printf("\t\t\tChoose game mode:\n");
  printf("\t\t\t1 - player vs computer\n");
  printf("\t\t\t2 - player vs player\n");
  printf("\t\t\t3 - computer vs computer\n");
  printf("\t\t\t4 - Exit\n");
  printf("\n- ");
  scanf("%c", &mode);
  if (mode != '1' && mode != '2' && mode != '3' && mode != '4') {
    system("cls");
    fflush(stdin);
    game_menu();
  } else {
    game.game_mode = mode - '0';
  }
}

void print_field() {
  system("cls");
  for (unsigned i = 0; i < 9; ++i) {
    for (unsigned j = 0; j < 11; ++j) {
      printf("%c", game.field[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("\n");
  printf("\n");
}

int check_field() {
  if (game.field[Y1][X1] != ' ' && game.field[Y1][X2] != ' ' &&
      game.field[Y1][X3] != ' ' && game.field[Y2][X1] != ' ' &&
      game.field[Y2][X2] != ' ' && game.field[Y2][X3] != ' ' &&
      game.field[Y3][X1] != ' ' && game.field[Y3][X2] != ' ' &&
      game.field[Y3][X3] != ' ') {
    return 1;
  }
  return 0;
}

int update_field(char character, unsigned x, unsigned y) {
  if (x == 1 && y == 1 && game.field[Y1][X1] == ' ') {
    game.field[Y1][X1] = character;
  } else if (x == 2 && y == 1 && game.field[Y1][X2] == ' ') {
    game.field[Y1][X2] = character;
  } else if (x == 3 && y == 1 && game.field[Y1][X3] == ' ') {
    game.field[Y1][X3] = character;
  } else if (x == 1 && y == 2 && game.field[Y2][X1] == ' ') {
    game.field[Y2][X1] = character;
  } else if (x == 2 && y == 2 && game.field[Y2][X2] == ' ') {
    game.field[Y2][X2] = character;
  } else if (x == 3 && y == 2 && game.field[Y2][X3] == ' ') {
    game.field[Y2][X3] = character;
  } else if (x == 1 && y == 3 && game.field[Y3][X1] == ' ') {
    game.field[Y3][X1] = character;
  } else if (x == 2 && y == 3 && game.field[Y3][X2] == ' ') {
    game.field[Y3][X2] = character;
  } else if (x == 3 && y == 3 && game.field[Y3][X3] == ' ') {
    game.field[Y3][X3] = character;
  } else {
    return -1;
  }

  return 0;
}

int is_win(char character) {
  if ((game.field[Y1][X1] == character && game.field[Y1][X2] == character &&
       game.field[Y1][X3] == character) ||
      (game.field[Y2][X1] == character && game.field[Y2][X2] == character &&
       game.field[Y2][X3] == character) ||
      (game.field[Y3][X1] == character && game.field[Y3][X2] == character &&
       game.field[Y3][X3] == character) ||
      (game.field[Y1][X1] == character && game.field[Y2][X1] == character &&
       game.field[Y3][X1] == character) ||
      (game.field[Y1][X2] == character && game.field[Y2][X2] == character &&
       game.field[Y3][X2] == character) ||
      (game.field[Y1][X3] == character && game.field[Y2][X3] == character &&
       game.field[Y3][X3] == character) ||
      (game.field[Y1][X1] == character && game.field[Y2][X2] == character &&
       game.field[Y3][X3] == character) ||
      (game.field[Y3][X1] == character && game.field[Y2][X2] == character &&
       game.field[Y1][X3] == character)) {
    return 1;
  }
  return 0;
}

int do_move(char player) {
  char x, y;
  unsigned try_counter = 0;
  print_field();
  if (check_field() != 0) {
    return -1;
  }

  if (player == 'f' ||
      (player == 'c' &&
       game.game_mode == 3)) {  // f - first player, s - second player, c -
                                // first computer, C - second computer
    game.character = 'x';
  } else {
    game.character = 'o';
  }

  if (player == 'c' || player == 'C') {
    x = rand() % 3 + 1;
    y = rand() % 3 + 1;
    while (update_field(game.character, x, y) != 0 && try_counter++ < 100) {
      x = rand() % 3 + 1;
      y = rand() % 3 + 1;
    }
    if (try_counter > 100) {
      system("cls");
      printf("\t\t\tSmth went wrong... ;(\n");
      return 1;
    }
    if (game.game_mode == 3) {
      Sleep(1000);
    }
    print_field();
  } else {
    printf("Enter coordinate x: ");
    scanf("%c", &x);
    fflush(stdin);
    while (x != '1' && x != '2' && x != '3') {
      system("cls");
      print_field();
      printf("Enter coordinate x: ");
      scanf("%c", &x);
      fflush(stdin);
    }
    printf("Enter coordinate y: ");
    scanf("%c", &y);
    fflush(stdin);
    while (y != '1' && y != '2' && y != '3') {
      system("cls");
      print_field();
      printf("Enter coordinate y: ");
      scanf("%c", &y);
      fflush(stdin);
    }
    while (update_field(game.character, x - '0', y - '0') != 0) {
      printf("Wrong move!\n");
      printf("Enter coordinate x: ");
      scanf("%c", &x);
      fflush(stdin);
      while (x != '1' && x != '2' && x != '3') {
        system("cls");
        print_field();
        printf("Enter coordinate x: ");
        scanf("%c", &x);
        fflush(stdin);
      }
      printf("Enter coordinate y: ");
      scanf("%c", &y);
      fflush(stdin);
      while (y != '1' && y != '2' && y != '3') {
        system("cls");
        print_field();
        printf("Enter coordinate y: ");
        scanf("%c", &y);
        fflush(stdin);
      }
    }
    print_field();
  }

  if (!check_field()) {
    system("cls");
    if (is_win('x')) {
      printf("Player 1 win!\n");
      return 1;
    } else if (is_win('o')) {
      printf("Player 2 win!\n");
      return 1;
    }
  } else {
    system("cls");
    printf("Draw.\n");
    return 1;
  }
  return 0;
}

void clear_field() {
  for (unsigned i = 0; i < 9; ++i) {
    for (unsigned j = 0; j < 11; ++j) {
      game.field[i][j] = empty_field[i][j];
    }
  }
}

#endif  // tic_tac_toe_c_
