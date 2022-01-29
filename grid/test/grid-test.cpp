#include "../include/grid/grid.hpp"

#include <vector>
#include <gtest/gtest.h>

using namespace TeradiciGrid;

TEST(GridTest, byte2rowcol) {
    short row, col;
    std::vector<short> inputIndex = {0xff, 0x11, 0x12};
    std::vector<std::pair<short, short> > expectedResult = {{15,15}, {1,1}, {1,2}};

    int i = 0;
    for (auto const v : inputIndex){
        byte2rowcol(v, row, col);
        EXPECT_EQ(row, expectedResult[i].first) << "Error in row value of case no. i = " << i;
        EXPECT_EQ(col, expectedResult[i].second) << "Error in col value of case no. i = " << i;
        ++i;
    }
}