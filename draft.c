#include <stdio.h>
#include <conio.h>

#define STR 29
#define COL 99

void print(char field[STR][COL]){
	for (int i = 0; i < STR; i++){
	for (int j = 0; j < COL; j++){
	    printf ("%c", field[i][j]);
	}
	  printf ("\n");
  }
}

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

char racket(char field[STR][COL], int *right_racket, int *left_racket){
	char input = getch();

	switch(input){
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

	field[*left_racket + 1][1] = '[';
	field[*left_racket][1] = '[';
	field[*left_racket - 1][1] = '[';

	field[*right_racket + 1][COL - 2] = '[';
	field[*right_racket][COL - 2] = '[';
	field[*right_racket - 1][COL - 2] = '[';

	return input;
}

int main (){
	
	char field[STR][COL];
	int left_racket = STR / 2, right_racket = STR / 2;

	for(int i = 0; i < 50; i++){
		racket (*field, *right_racket, *left_racket);
		frame (*field, *right_racket, *left_racket);
		print(*field);
}
return 0;
}