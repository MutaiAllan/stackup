#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("names.txt");
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();

    return 0;
}
