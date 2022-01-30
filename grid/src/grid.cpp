#include "grid/grid.hpp"

namespace TeradiciGrid{

void byte2rowcol(unsigned short inputIndex, unsigned short &row, unsigned short &col){
    const unsigned short NUM_OF_BITS = 4;
    row = ((1 << NUM_OF_BITS) - 1) & (inputIndex >> NUM_OF_BITS);
    col = ((1 << NUM_OF_BITS) - 1) & inputIndex;
}

bool Grid::getBitValue(unsigned short row, unsigned short col){
    if(col < 8){ // low
        return gridData[row*2] & (1 << col);
    } else { // high
        return gridData[(row*2)+1] & (1 << (col - 8));
    }
}

void Grid::updateGrid(unsigned short inputByte){
    unsigned short row, col;
    byte2rowcol(inputByte, row, col);

    auto bitValue = getBitValue(row, col);
    if(bitValue){
        updateDiagonal(row, col);
    } else {
        updateRow(row);
        updateCol(col);
    }
};

void Grid::updateRow(unsigned short row) {
    unsigned short low = (row*2), high = (row*2+1);
    gridData[low] = 0xff;
    gridData[high] = 0xff;
}

void Grid::updateCol(unsigned short col) {
    for (int i = 0; i < NUM_OF_ROWS; ++i){
        if(col < 8){ // low
            gridData[i*2] |= 1 << col;
        } else { // high
            gridData[(i*2)+1] |= 1 << (col - 8);
        }
    }
}

void Grid::updateDiagonal(unsigned short row, unsigned short col) {
    unsigned short c1 = col - row, c2 = col + row;
    for (int i = 0; i < NUM_OF_ROWS; ++i){
        if(c1 < 8 && c1 >= 0){
            gridData[i*2] &= ~(1 << c1);
        } else if (c1 >= 8 && c1 < NUM_OF_COLS) {
            gridData[(i*2)+1] &= ~(1 << (c1 - 8));
        } 
        
        if(c2 < 8 && c2 >= 0){
            gridData[i*2] &= ~(1 << c2);
        } else if (c2 >= 8 && c2 < NUM_OF_COLS) {
            gridData[(i*2)+1] &= ~(1 << (c2 - 8));
        }

        ++c1;
        --c2;
    }
}

unsigned short Grid::countZeros(){
    int count=0;
    for (auto const v : gridData){
        auto tmp=v;
        while(tmp){
            tmp=tmp&(tmp-1);  // jump to first bit == 1
            ++count;
        }
    }
    return MAX_NUM_ZEROS - count;
}

std::ostream& operator<<(std::ostream& os, const Grid& grid)
{
    uint16_t high, low;
    uint16_t whole_row;
    for (int i = 0; i < grid.NUM_OF_ROWS; ++i){
        low = grid.gridData[i*2];
        high = grid.gridData[i*2+1];
        whole_row = (high << 8) | low;
        for (int j = grid.NUM_OF_COLS-1; j >= 0; --j)
        {
            os << ((whole_row >> (grid.NUM_OF_COLS-1-j)) & 0x1);
        }
        os << std::endl;
    }
    os << std::endl;
    return os;
}

}