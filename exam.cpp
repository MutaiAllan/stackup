#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct Student {
    int id;
    std::vector<int> scores;
};

int main() {
    std::ifstream file("results.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line); // Read and discard the header line

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Student student;
        std::string value;

        // Read student ID
        std::getline(iss, value, ',');
        student.id = std::stoi(value);

        // Read scores for each course
        while (std::getline(iss, value, ',')) {
            student.scores.push_back(std::stoi(value));
        }

        // Print student details
        std::cout << "Student ID: " << student.id << ", Scores: ";
        for (int score : student.scores) {
            std::cout << score << " ";
        }
        std::cout << std::endl;
    }

    file.close();
    return 0;
}
