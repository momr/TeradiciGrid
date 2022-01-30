##########################
Teradici, HP: Grid Project
##########################

This project tries to manipulates a 16x16 square grid according to the contents of a file specified on the command line and is a part of the technical interview for a Sr. C++ Software position at Teradici and HP

On program startup, this grid is initialized to all zeroes. Subsequently, for each byte read from the file, a coordinate will be formed: the first 4 bits will refer to a row offset within this grid, and the second 4 bits will refer to a column offset within this grid.

Examining the grid at the decoded coordinate, if the grid's content at that location is zero, all entries within the grid located in the same row or column shall be set to one. Alternatively, if the content at the decoded location is non-zero (ie: one), all entries within the grid located on the associated diagonals shall be set to zero.

When the file is finished being processed, your program will print out a single decimal number indicating the number of entries in the grid that are set to zero.

For more details on how this project works with illustrations, please see the `Grid_code - 12.2020.pdf <./docs/Grid_code - 12.2020.pdf>`_ found under the `docs` directory

************
How To Build
************

::

    # Create a build directory & cd into it
    mkdir -p build && cd build

    # Build a release version
    cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build . -- -j4

**********
How To Run
**********

::

    # To generate a sample testInputfile file
    echo -n -e '\xff\x11\x12' > testInputfile.bin
    
    # Then to run the CLI tool and using the file generated in the previous step
    grid-cli-app/grid-cli -f testInputfile.bin

*************************
How To Run The Unit Tests
*************************

::

    # From inside the build directory and after a successful build
    ctest

******************************
How To Run & Test Using Docker
******************************

::

    # From inside the project root directory
    # Build the docker image
    docker build -f ./docker/Dockerfile -t grid-docker .

    # Run docker container
    docker run grid-docker

    # Run unit Tests
    docker run  -it --entrypoint ctest grid-docker

    # Run a shell inside the container, useful when debugging docker
    docker run  -it --entrypoint /bin/bash grid-docker

**********
Contact Me
**********

Medhat Omr

phone: +1 (403) 918-7512

email: medhat.omr@gmail.com