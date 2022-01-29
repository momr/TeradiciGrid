#ifndef GRID_H
#define GRID_H

#include <array>


namespace TeradiciGrid
{

void byte2rowcol(short inputIndex, short &row, short &col){
    const short NUM_OF_BITS = 4;
    row = ((1 << NUM_OF_BITS) - 1) & (inputIndex >> NUM_OF_BITS);
    col = ((1 << NUM_OF_BITS) - 1) & inputIndex;
}

class Grid{
public:
    short getNumOfZeros() {return numOfZeros;};

private:
    std::array<unsigned char, 32> gridData;  // zero-initialized
    short numOfZeros = 256;
};

}
#endif /* GRID_H */
