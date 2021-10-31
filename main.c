#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "tic-tac-toe.h"

int main() {
  char player;
  unsigned moves_counter = 1;
  char keep_playing = 'y';

  srand(time(NULL));

  while (keep_playing == 'y') {
    system("cls");
    clear_field();
    game_menu();
    if (game.game_mode == 1) {
      player = 'f';
      while (do_move(player) == 0) {
        moves_counter++;
        if (moves_counter % 2 == 0) {
          player = 'c';
        } else {
          player = 'f';
        }
      }
    } else if (game.game_mode == 2) {
      player = 'f';
      while (do_move(player) == 0) {
        moves_counter++;
        if (moves_counter % 2 == 0) {
          player = 's';
        } else {
          player = 'f';
        }
      }
    } else if (game.game_mode == 3) {
      player = 'c';
      while (do_move(player) == 0) {
        moves_counter++;
        if (moves_counter % 2 == 0) {
          player = 'C';
        } else {
          player = 'c';
        }
      }
    } else if (game.game_mode == 4) {
      system("cls");
      return 0;
    }

    printf("Great! would you like to play again? (y to continue)\n");
    fflush(stdin);
    scanf("%c", &keep_playing);
    fflush(stdin);
  }
  return 0;
}
