FROM gcc

# Install cmake
ARG CMAKE_VERSION=3.19.3

RUN wget https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-Linux-x86_64.sh \
    -q -O /tmp/cmake-install.sh \
    && chmod u+x /tmp/cmake-install.sh \
    && mkdir /usr/bin/cmake \
    && /tmp/cmake-install.sh --skip-license --prefix=/usr/bin/cmake \
    && rm /tmp/cmake-install.sh

ENV PATH="/usr/bin/cmake/bin:${PATH}"

WORKDIR /app
COPY . .
RUN mkdir -p build-docker

WORKDIR /app/build-docker
RUN cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build . -- -j4
COPY ./docker/testInputfile.bin .
ENTRYPOINT ["grid-cli-app/grid-cli"]
CMD ["-f", "testInputfile.bin"]
