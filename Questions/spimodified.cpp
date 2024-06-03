#include <iostream>
#include <string>
#include <map>
#include <algorithm> // For std::tolower

int main() {
    std::map<std::string, int> gradePoints = {
        {"AA", 10}, {"AB", 9}, {"BB", 8}, {"BC", 7}, {"CC", 6},
        {"CD", 5}, {"DD", 4}
    };

    std::map<std::string, std::string> subjects = {
        {"open", "Subject"}, {"PTSP", "Subject"}, {"Analog", "Subject"},
        {"Embedded", "Subject"}, {"EMP", "Subject"},
        {"anal lab", "Lab"}, {"emb lab", "Lab"}
    };

    std::map<std::string, int> credits = {
        {"Subject", 3}, {"Lab", 1}
    };

    float totalGradePoints = 0;
    int totalCredits = 0;

    for (const auto& subject : subjects) {
        std::string name = subject.first;
        std::string type = subject.second;

        std::cout << "Enter your grade for " << name << ": ";
        std::string grade;
        std::cin >> grade;

        // Convert grade to uppercase
        std::transform(grade.begin(), grade.end(), grade.begin(), ::toupper);

        if (gradePoints.find(grade) != gradePoints.end()) {
            totalGradePoints = totalGradePoints + gradePoints[grade] * credits[type];
            totalCredits = totalCredits +  credits[type];
        } else {
            std::cout << "Invalid grade entered for " << name << std::endl;
        }
    }

    float spi = totalGradePoints / totalCredits;
    std::cout << "Your SPI for this semester: " << spi << std::endl;

    float previousCPI;
    std::cout << "Enter your previous CPI: ";
    std::cin >> previousCPI;

    float newCPI = (previousCPI * 77 + spi * 21) / 98;
    std::cout << "Your new CPI: " << newCPI << std::endl;

    return 0;
}
