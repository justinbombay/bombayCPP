/*
  Justin Bombay
  CS 202 - 1003
  Dr. Vasko
  Assignment 4
  sixteen.h
*/

class sixteen {
public:
//static const int SIZE = 3;
//static const int WIN = 16;
static const int SIZE = 4;
static const int WIN  = 64;
sixteen ();
void moveLeft ();
void moveRight ();
void moveUp ();
void moveDown ();
int over() const;
void output() const;

private:
int board[SIZE][SIZE];
};
