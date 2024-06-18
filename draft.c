#include <stdio.h>
#include <conio.h>
//#include <ncurses/ncurses.h>
//#include <unistd>

#define STR 29
#define COL 99

void frame (char field[STR][COL]){

  for (int i = 0; i < STR; i++){
	for (int j = 0; j < COL; j++){
		if (i == 0 || i == 2 || i == STR - 1){
			  field[i][j] = '-';
		}
		else if (j == 0 || j == COL - 1){
		    field[i][j] = '|';
		}
		else if (j == (COL + 1) / 2)
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
	//scanf("%c", &input);

	switch(input){
		case 's':
			(*left_racket)--;
			break;
		case 'x':
			(*left_racket)++;
			break;
		case 'k':
			(*right_racket)--;
			break;
		case 'm': 
			(*right_racket)++;
			break;
	}

	field[*left_racket][1] = ']';
	field[*left_racket + 1][1] = ']';
	field[*left_racket + 2][1] = ']';
	field[*left_racket - 1][1] = ']';
	field[*left_racket - 2][1] = ']';

	field[*right_racket][COL - 2] = '[';
	field[*right_racket + 1][COL - 2] = '[';
	field[*right_racket + 2][COL - 2] = '[';
	field[*right_racket - 1][COL - 2] = '[';
	field[*right_racket - 2][COL - 2] = '[';

	return input;
}

void ball(char field[STR][COL], int right_racket, int left_racket, int *dir_x, int *dir_y, int *ball_x, int *ball_y){
	if((*ball_y == STR - 2) && (*dir_x == 1) && (*dir_y == 1))
	  *dir_y *= -1;
	else if((*ball_y == STR - 2) && (*dir_x == -1) && (*dir_y == 1))
	  *dir_y *= -1;
	else if((*ball_y == 3) && (*dir_x == 1) && (*dir_y == -1))
	  *dir_y *= -1;
	else if((*ball_y == 3) && (*dir_x == -1) && (*dir_y == -1))
	  *dir_y *= -1;
	else if((*ball_x == COL - 3) && (*dir_x == 1) && (*dir_y == 1) &&
	  	   ((*ball_y == right_racket) || (*ball_y == right_racket + 1) || (*ball_y == right_racket + 2) ||
	   		(*ball_y == right_racket - 1) || (*ball_y == right_racket - 2)))
				*dir_x *= -1;
	else if((*ball_x == COL - 3) && (*dir_x == 1) && (*dir_y == -1) &&
	  	   ((*ball_y == right_racket) || (*ball_y == right_racket + 1) || (*ball_y == right_racket + 2) ||
	   	 	(*ball_y == right_racket - 1) || (*ball_y == right_racket - 2)))	
	   			*dir_x *= -1;
	else if((*ball_x == 2) && (*dir_x == -1) && (*dir_y == 1) &&
	  	   ((*ball_y == left_racket) || (*ball_y == left_racket + 1) || (*ball_y == left_racket + 2) ||
	   		(*ball_y == left_racket - 1) || (*ball_y == left_racket - 2)))
	   			*dir_x *= -1;
	else if((*ball_x == 2) && (*dir_x == -1) && (*dir_y == -1) &&
	  	   ((*ball_y == left_racket) || (*ball_y == left_racket + 1) || (*ball_y == left_racket + 2) ||
	   		(*ball_y == left_racket - 1) || (*ball_y == left_racket - 2)))
	   			*dir_x *= -1;

	*ball_y += *dir_y;
	*ball_x += *dir_x;

	field[*ball_y][*ball_x] = 'o';
}

void goal(int *score, int *left_racket, int *right_racket, int *dir_x, int *dir_y, int *ball_x, int *ball_y){
	(*score)++;

	*left_racket = STR / 2;
	*right_racket = STR / 2;

	*ball_x = COL / 2;
	*ball_y = STR / 2;
	(*dir_x) *= -1;
	(*dir_y) *= -1;
}

void draw_field(char field[STR][COL]){
	for(int i = 0; i < STR; i++){
		for(int j = 0; j < COL; j++){
			printf("%c", field[i][j]);
		}
		printf("\n");
	}
}

int main (){
	
	char field[STR][COL];
	int left_racket = STR / 2, right_racket = STR / 2;
	int dir_x = 1, dir_y = 1;
	int ball_x = COL / 2, ball_y = STR / 2;
	int left_score = 0, right_score = 0;
	char winner = 'n';
	char input = 'f';

	do{
		//nodelay(stdscr, true);

		frame(field);
		input = racket(field, &right_racket, &left_racket);
		ball(field, right_racket, left_racket, &dir_x, &dir_y, &ball_x, &ball_y);

		if(ball_x == 1)
			goal(&left_score, &left_racket, &right_racket, &dir_x, &dir_y, &ball_x, &ball_y);
		else if (ball_x == COL - 2)
			goal(&right_score, &left_racket, &right_racket, &dir_x, &dir_y, &ball_x, &ball_y);
		
		//clear();
		//clearScreen();
		
		if(left_score == 11){
			winner = 'l';
			break;
		}
		else if (right_score == 11){
			winner = 'r';
			break;
		}

		//usleep(30 * 0000);
		printf("Left player scoer: %d\n", left_score);
		printf("Right player scoer: %d\n", right_score);

		draw_field(field);
	} while(input != 'q');

	//endwin();

	if(winner == 'l'){
		printf("Left player WIN!");
	} else if (winner == 'r'){
		printf("Right player WIN!");
	}
	
	return 0;
}