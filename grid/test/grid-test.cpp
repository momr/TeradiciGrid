#include "grid/grid.hpp"

#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

using namespace TeradiciGrid;
using std::vector;
using std::cout;
using std::endl;

TEST(GridTest, byte2rowcol) {
    unsigned short row, col;
    vector<unsigned short> inputIndex = {0xff, 0x11, 0x12};
    vector<std::pair<unsigned short, unsigned short> > expectedResult = {{15,15}, {1,1}, {1,2}};

    int i = 0;
    for (auto const v : inputIndex){
        byte2rowcol(v, row, col);
        EXPECT_EQ(row, expectedResult[i].first) << "Error in row value of case no. i = " << i;
        EXPECT_EQ(col, expectedResult[i].second) << "Error in col value of case no. i = " << i;
        ++i;
    }
}

TEST(GridTest, GridClassUpdate) {
    Grid grid;
    cout << grid << endl;

    auto numOfZeros = grid.getNumOfZeros();
    EXPECT_EQ(numOfZeros, 256);

    vector<unsigned short> inputIndex = {0x00, 0xff, 0x11, 0x12};
    // vector<std::pair<unsigned short, unsigned short> > expectedResult = {{15,15}, {1,1}, {1,2}};

    int i = 0;
    for (auto const v : inputIndex){
        cout << "input byte: " << std::hex << v << endl;
        grid.updateGrid(v);
        cout << grid << endl << endl;
        ++i;
    }
}

class GridTestFixture : public ::testing::Test {
 protected:
  void SetUp() override {
    // To write bytes to a file in bash
    // echo -n -e '\xff\x11\x12' > testInputfile.bin
    std::ofstream output("testInputfile.bin", std::ios::binary);
    unsigned char buffer[3] = {0xff, 0x11, 0x12};
    output.write((char *) buffer, sizeof(buffer));
    output.close();
  }

  void TearDown() override {
    system("rm -f testInputfile.bin");
  }
};

TEST_F(GridTestFixture, GridClassCountZeros) {
    std::ifstream input("testInputfile.bin", std::ios::binary);

    std::vector<char> inputIndex(
         (std::istreambuf_iterator<char>(input)),
         (std::istreambuf_iterator<char>()));

    input.close();

    Grid grid;
    // cout << grid << endl;

    // vector<unsigned short> inputIndex = {0x00, 0xff, 0x11, 0x12};
    // // vector<std::pair<unsigned short, unsigned short> > expectedResult = {{15,15}, {1,1}, {1,2}};

    int i = 0;
    for (auto const v : inputIndex){
        cout << "input byte: " << std::hex << v << endl;
        grid.updateGrid(v);
        cout << grid << endl << endl;
        ++i;
    }

    EXPECT_EQ(grid.getNumOfZeros(), 200);
}