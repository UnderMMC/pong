#include <stdio.h>

#define STR 18
#define COL 48

void frame (){
  char field[STR][COL];

  for (int i = 0; i < STR; i++){
	for (int j = 0; j < COL; j++){
		if (i == 0 || i == 2 || i == STR - 1){
			  field[i][j] = '-';
		}
		else if (j == 0 || j == COL - 1){
		    field[i][j] = '|';
		}
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

  for (int i = 0; i < STR; i++){
	for (int j = 0; j < COL; j++){
	    printf ("%c", field[i][j]);
	}
	  printf ("\n");
  }
}

int main (){
    
  frame ();

  return 0;
}
