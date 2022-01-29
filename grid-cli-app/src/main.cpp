#include <iostream>
#include <csignal>
#include <thread>


bool shutDown = false;

void OnSigInt(int) {
    shutDown = true;
}

int someFunc(){
    while (!shutDown) {
        std::cout << "Hello World!" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return EXIT_SUCCESS;
}
int main(){
    auto const previousInteruptHandler = signal(SIGINT, OnSigInt);
    auto const returnValue = someFunc();
    (void)signal(SIGINT, previousInteruptHandler);
    std::cout << "Good Bye!" << std::endl;
}