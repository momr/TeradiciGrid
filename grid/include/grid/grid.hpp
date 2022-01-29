#ifndef GRID_H
#define GRID_H

#include <array>
#include <iostream>


namespace TeradiciGrid
{
void byte2rowcol(unsigned short inputIndex, unsigned short &row, unsigned short &col);

class Grid{
public:
    // Following the Rule of five
    Grid(){
        for (auto &v: gridData){
            v = 0;
        }
    }

    Grid(const Grid&) = default;
    Grid(Grid&&) = default;
    Grid& operator=(const Grid&) = delete;
    Grid& operator=(Grid&&) = delete;
    virtual ~Grid() = default;

    void updateGrid(unsigned short inputByte);
    unsigned short getNumOfZeros() {return numOfZeros;};
    friend std::ostream& operator<<(std::ostream& os, const Grid& grid);


private:
    bool getBitValue(unsigned short row, unsigned short col);
    void updateRow(unsigned short row);
    void updateCol(unsigned short col);
    void updateDiagonal(unsigned short row, unsigned short col);
    unsigned short countZeros();
    std::array<uint8_t, 32> gridData;
    unsigned short numOfZeros = 256;
    unsigned short const NUM_OF_ROWS = 16;
    unsigned short const NUM_OF_COLS = 16;
};

}
#endif /* GRID_H */
