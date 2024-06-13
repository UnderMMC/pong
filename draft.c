#include <stdio.h>
#include <conio.h>

#define STR 29
#define COL 99

void frame (char field[STR][COL], int *right_racket, int *left_racket){

  for (int i = 0; i < STR; i++){
	for (int j = 0; j < COL; j++){
		if (i == 0 || i == 2 || i == STR - 1){
			  field[i][j] = '-';
		}
		else if (j == 0 || j == COL - 1){
		    field[i][j] = '|';
		}
		else if (j == (COL-1) / 2)
			field[i][j] = '.';
		else
		    field[i][j] = ' ';
	}
 }

  field[0][0] = '+';
  field[2][0] = '+';
  field[STR - 1][0] = '+';

  field[0][COL - 1] = '+';
  field[2][COL - 1] = '+';
  field[STR - 1][COL - 1] = '+';
}

int racket(char field[STR][COL], int *right_racket, int *left_racket){
	char input = getch();

	swich(input){
		case 's':
			*left_racket--;
			break;
		case 'x':
			*left_racket++;
			break;
		case 'k':
			*right_racket--;
			break;
		case 'm': 
			*right_racket++;
			break;
	}

	field[*left_racket][1] = ']';
	field[*left_racket + 1][1] = ']';
	field[*left_racket + 2][1] = ']';
	field[*left_racket - 1][1] = ']';
	field[*left_racket - 2][1] = ']';

	field[*right_racket][COL - 1] = '[';
	field[*right_racket + 1][COL - 1] = '[';
	field[*right_racket + 2][COL - 1] = '[';
	field[*right_racket - 1][COL - 1] = '[';
	field[*right_racket - 2][COL - 1] = '[';

	return input;
}

void ball(char field[STR][COL], int right_racket, int left_racket, int *dir_x, int *dir_y, int *ball_x, int *ball_y){
	if (((*ball_y) == 3) && ((*dir_x) == 1) && ((*dir_y) == -1)) 
		*dir_y *= -1;
	else if (((*ball_y) == 3) && ((*dir_x) == -1) && ((*dir_y) == -1))
		*dir_y *= -1;
	else if (((*ball_y) == (STR - 2)) && ((*dir_x) == -1) && ((*dir_y) == 1))
		*dir_y *= -1;
	else if (((*ball_y) == (STR - 2)) && ((*dir_x) == -1) && ((dir_y) == 1))
		*dir_y *= -1;
	else if ((*ball_x) == 2 && (*dir_x) == -1 && (*dir_y) == -1 &&
			  ((*ball_ y) == left_racket || (*ball_y) == left_racket + 1 || (*ball_y) == left_racket + 2 ||
			   (*ball_y) == left_racket -1 ||  (*ball_y) == left_racket -2))
		*dir_x *= -1;
	else if ((*ball_x) == 2 && (*dir_x) == -1 (*dir_y) == 1 && 
			((*ball_ y) == left_racket || (*ball_y) == left_racket + 1 || (*ball_y) == left_racket + 2 ||
			   (*ball_y) == left_racket -1 ||  (*ball_y) == left_racket -2))
		*dir_x *= -1;
	else if ((*ball_x) == COL-3 && (*dir_x) == 1 (*dir_y) == -1 && 
			((*ball_ y) == right_racket || (*ball_y) == right_racket + 1 || (*ball_y) == right_racket + 2 ||
			   (*ball_y) == right_racket -1 ||  (*ball_y) == right_racket -2))
		*dir_x *= -1;
	else if ((*ball_x) == COL-3 && (*dir_x) == 1 (*dir_y) == 1 && 
			((*ball_ y) == right_racket || (*ball_y) == right_racket + 1 || (*ball_y) == right_racket + 2 ||
			   (*ball_y) == right_racket -1 ||  (*ball_y) == right_racket -2))
		*dir_x *= -1;

	*ball_y += *dir_y;
	*ball_x += *dir_x;

	field[*ball_y][*ball_x] = 'o';
}

int main (){
	
	char field[STR][COL];
	int left_racket = STR / 2, right_racket = STR / 2;
	int dir_x = 1, dir_y = 1;
	int ball_x, ball_y;


	
	return 0;
}