#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

// Function to calculate grade based on score
char calculateGrade(double score) {
    if (score >= 80) {
        return 'A';
    } else if (score >= 70) {
        return 'B';
    } else if (score >= 60) {
        return 'C';
    } else if (score >= 50) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    std::ifstream inputFile("results.txt");
    std::ofstream outputFile("analysis.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files" << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::string> courses;
    std::vector<double> totalScores;
    double classTotal = 0;
    int studentCount = 0;

    while (std::getline(inputFile, line)) {
        std::string course;
        double score;

        std::istringstream iss(line);
        iss >> course >> score;

        // Store course name
        courses.push_back(course);
        
        // Calculate grade for each course and store total score
        char grade = calculateGrade(score);
        totalScores.push_back(score);

        // Print result for each student
        std::cout << "Course: " << course << ", Score: " << score << ", Grade: " << grade << std::endl;

        // Write result to output file
        outputFile << "Course: " << course << ", Score: " << score << ", Grade: " << grade << std::endl;

        // Calculate class total score
        classTotal += score;
        studentCount++;
    }

    // Calculate class average
    double classAverage = classTotal / studentCount;

    // Calculate overall grade for the course taken
    char overallGrade = calculateGrade(classAverage);

    // Calculate average mark per course
    std::cout << std::fixed << std::setprecision(2);
    for (size_t i = 0; i < courses.size(); ++i) {
        double average = totalScores[i] / studentCount;
        std::cout << "Average score for " << courses[i] << ": " << average << std::endl;
    }

    // Print class average score and grade
    std::cout << "Class average score: " << classAverage << std::endl;
    std::cout << "Class grade: " << overallGrade << std::endl;

    // Write class average score and grade to output file
    outputFile << "Class average score: " << classAverage << std::endl;
    outputFile << "Class grade: " << overallGrade << std::endl;

    // Close files
    inputFile.close();
    outputFile.close();

    return 0;
}
