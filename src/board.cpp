#include <iostream>
using namespace std;

const int row = 12; // default battleship row & column
const int column = 12;

template <typename T>
void clearMatrix(T& matrix) {
    for(int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = "0";
        }
    }    
}

template <typename T>
void grid(T& matrix) {
    for(int i = 0; i < row; i++) {
        for(int firstrow = 0; firstrow < row; firstrow++) {
            matrix[0][i] = "—";
        }
        for (int firstcolumn = 0; firstcolumn < column; firstcolumn++) {
          if(i < row-2) {
            matrix[i+1][0] = "|";
            }   
        }
        for(int lastcolumn = 0; lastcolumn < column; lastcolumn++) {
            matrix[i][11] = "|";
        }
        for(int lastrow = 0; lastrow < row; lastrow++) {
            matrix[11][i] = "—";
        }           
    }
}

template <typename T>
void outputMatrix(T& matrix) {
    for(int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}