#ifndef tic_tac_toe_h_
#define tic_tac_toe_h_
#define X1 1
#define X2 5
#define X3 9

#define Y1 1
#define Y2 4
#define Y3 7

struct Game {
  char character;
  char field[9][11];
  unsigned game_mode;  // 1 - player vs computer, 2 - player vs player, 3 -
                       // computer vs computer, 4 - Exit
};

extern struct Game game;

extern char empty_field[9][11];

#ifdef __cplusplus
extern "C" {
#endif
int is_win(char character);

void game_menu();

void print_field();

int check_field();

int update_field(char character, unsigned x, unsigned y);

int do_move(char player);

void clear_field();
#ifdef __cplusplus
}
#endif
#endif  // tic_tac_toe_h_
