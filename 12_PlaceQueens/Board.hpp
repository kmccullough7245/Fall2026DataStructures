#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>

class Board {
public:
    Board(int size = 8);

    void printBoard() const;
    void placeQueens();
    int countPlaceQueens();
    
private:
    bool checkPlace(const int row, const int col) const;
    void printRow(int row) const;
    bool placeQueens(int row);

    std::vector<std::string> board;
    unsigned board_size;
};

#endif