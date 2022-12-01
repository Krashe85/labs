#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[]){
    if (argc != 3){
        std::cout << "Failed..." << std::endl;
        return 1;
    };
    std::ifstream inp;
    std::ofstream outp;
    std::vector<int> vect;
    int i = 0;
    inp.open(argv[1]);
    outp.open(argv[2]);

    unsigned int zero = 0;
    unsigned int one = 0;

    if (inp.is_open()){
        while(!inp.eof()){
            inp >> i;

            if (i) {
                one++;
            } else {
                zero++;
            }
        }
    }


    std::cout << zero << " " << one;
    if(outp.is_open()){
        outp << zero << ' ' << one;
        outp.flush();
    }
    return 0;
}