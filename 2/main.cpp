#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cout << "No File..." << std::endl;
        return 1;
    };
    std::ifstream inp;
    std::vector<int> vector;
    int i = 0;
    inp.open(argv[1]);
    unsigned int zero = 0;
    unsigned int one = 0;
    if (inp.is_open()){
        while(!inp.eof()){
            inp >> i;
            vector.push_back(i);
        }
    }

    auto ufree = std::unique(vector.begin(), vector.end());
    vector.erase(ufree, vector.end());
    for(i = 0; i < vector.size(); i++){
        if (vector[i]){
            one++;
        }else{
            zero++;
        }

    }

    std::cout << zero << " " << one;
    return 0;
}