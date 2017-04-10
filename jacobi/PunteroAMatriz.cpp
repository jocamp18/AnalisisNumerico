// PunteroAPuntero.cpp
#include <iostream>

using namespace std;

int
main()
{
  const int ROWS = 5;
  const int COLS = 5;
  // Declara un puntero a un entero
  int matriz[ROWS][COLS];
  // Declara un puntero a un puntero a un entero
  int *p = &matriz[0][0];

  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      matriz[i][j] = i * ROWS + j;
    }
  }

  for (int i = 0; i < ROWS; ++i) {

    for (int j = 0; j < COLS; ++j) {
      
      cout << "matriz[" << i << "][" << j << "]=" << matriz[i][j] << endl;
      cout << "*(p + " << i << " * COLS + " << j << ")=" <<
	*(p + i*ROWS + j) << endl;
    }
  }

  return 0;
}
    
