#ifndef BOARD_H
#define BOARD_H

class Gameboard {
 public:
    Gameboard();
    template <typename T>
    void clearMatrix(T& matrix);
    template <typename T>
    void grid(T& matrix);
    template <typename T>
    void outputMatrix(T& matrix);
};

#endif
