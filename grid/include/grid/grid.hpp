#ifndef GRID_H
#define GRID_H

#include <array>
#include <iostream>


namespace TeradiciGrid
{
/**
 * @brief Extract both row and col indicies out of an input byte
 * 
 * @param inputIndex input byte
 * @param row output index
 * @param col output index
 */
void byte2rowcol(unsigned short inputIndex, unsigned short &row, unsigned short &col);

class Grid{
public:
    // Object Life cycle

    /**
     * @brief Construct a new Grid object
     * 
     */
    Grid(){
        for (auto &v: gridData){
            v = 0;
        }
    }

    // Following the Rule of zero/three/five
    Grid(const Grid&) = default;
    Grid(Grid&&) = default;
    Grid& operator=(const Grid&) = delete;
    Grid& operator=(Grid&&) = delete;
    virtual ~Grid() = default;

    /**
     * @brief Update grid state
     * 
     * @param inputByte first 4 bits refers to the row offset within the grid,
     *                  and the second 4 bits refers to the column offset 
     */
    void updateGrid(unsigned short inputByte);

    /**
     * @brief Get the Num Of Zeros in the grid
     * 
     * @return unsigned short 
     */
    unsigned short getNumOfZeros() {return countZeros();};

    /**
     * @brief Output stream operator<< overload, so that the Grid state 
     *        can be output to the console for example during debugging
     * 
     * @param os std::ostream&
     * @param grid the self Grid object
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os, const Grid& grid);


private:
    /**
     * @brief Get the Bit Value of a cell of the grid at a given row and col
     * 
     * @param row input index
     * @param col input index
     * @return true if cell value is One
     * @return false if cell value is Zero
     */
    bool getBitValue(unsigned short row, unsigned short col) const;

    /**
     * @brief Update all values of a given row and set it to Ones
     * 
     * @param row input index
     */
    void updateRow(unsigned short row);

    /**
     * @brief Update all values of a given col and set it to Ones
     * 
     * @param col input index
     */
    void updateCol(unsigned short col);

    /**
     * @brief Update all values of both diagonals and set it to Zeros
     * 
     * @param row input index
     * @param col input index
     */
    void updateDiagonal(unsigned short row, unsigned short col);

    /**
     * @brief Counts the number of zeros in the grid
     * 
     * @return unsigned short 
     */
    unsigned short countZeros();

    /**
     * @brief The internal state of a Grid object
     * 
     */
    std::array<unsigned char, 32> gridData;

    // Useful constants
    unsigned short const MAX_NUM_ZEROS = 256;
    unsigned short const NUM_OF_ROWS = 16;
    unsigned short const NUM_OF_COLS = 16;
};

}
#endif /* GRID_H */
