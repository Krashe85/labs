#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "No file." << std::endl;
        return 1;
    };

    std::ifstream inp;
    int i = 0;
    inp.open(argv[1]);

    unsigned int zero = 0;
    unsigned int one = 0;
    if (inp.is_open()) {
        while (!inp.eof()) {
            inp >> i;
            if (i == 1) {
                one++;
            } else {
                zero++;
            }
        }
    }


    std::cout << zero << " " << one;
    return 0;
}