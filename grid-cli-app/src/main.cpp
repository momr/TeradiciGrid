#include "cxxopts.hpp"
#include "grid/grid.hpp"

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>


void processInputFile(std::string &filename){
    std::ifstream input(filename, std::ios::binary);

    std::vector<char> inputIndex(
         (std::istreambuf_iterator<char>(input)),
         (std::istreambuf_iterator<char>()));

    input.close();

    TeradiciGrid::Grid grid;

    for (auto const v : inputIndex){
        grid.updateGrid(v);
    }

    std::cout << grid.getNumOfZeros() << std::endl;
}

int main(int argc, char * argv[]){
    cxxopts::Options options("grid-cli -f testInputfile.bin", "This is a driver CLI app for the Teradici Grid lib");

        options.add_options()
    ("f,file", "Input Binary File name", cxxopts::value<std::string>())
    ("h,help", "Print this help message")
    ;
    auto result = options.parse(argc, argv);

    if (result.count("help"))
    {
      std::cout << options.help() << std::endl;
      exit(0);
    }

    auto inputFileName = result["file"].as<std::string>();

    if (result.count("file"))
    {
        processInputFile(inputFileName);
    } else {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    return 0;
}