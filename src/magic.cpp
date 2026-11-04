#include <iostream>

#include "mylib.h"
using namespace std;
int main() {
  int size, row, col;
  cout << "Enter the size of the magic square: ";
  cin >> size;
  row = 1;
  col = (size + 1) / 2;
  display((col * 4) + 5, (row * 3) + 5, " 1 ");
  system("sleep 0.3");
  for (int i = 2; i <= size * size; i++) {
    if ((i - 1) % size != 0) {
      row--;
      col--;
      if (row < 1) {
        row = size;
      }
      if (col < 1) {
        col = size;
      }
    } else {
      row++;
    }
    display((col * 4) + 5, (row * 3) + 5, " " + to_string(i) + " ");
    system("sleep 0.3");
  }
  display(1, 50, "Press any key to exit...");
  return 0;
}