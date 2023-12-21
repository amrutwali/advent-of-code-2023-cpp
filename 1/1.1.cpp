#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>

std::unordered_map<std::string, int> wordToNumber = {
    {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
    {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
};

int convertWordToNumber(const std::string &word) {
    return wordToNumber[word];
}

std::vector<int> extractNumbers(const std::string &line) {
    std::vector<int> numbers;

    std::string temp;
    for (char c : line) {
        if (std::isdigit(c)) {
            numbers.push_back(c - '0');
            std::cout << c-'0' << " ";
        } else if (std::isalpha(c)) {
            temp += std::tolower(c);
            if (wordToNumber.find(temp) != wordToNumber.end()) {
                numbers.push_back(wordToNumber[temp]);
                std::cout << wordToNumber[temp] << " ";
                temp.clear();
            }
        }
    }
    std::cout << "\n";
    
    return numbers;
}

int main() {
    std::ifstream fin("input");
    unsigned int sum = 0;

    std::string currentLine;
    while (fin >> currentLine)
    {
        int extractedNumber = 0;
        std::vector<int> numbers = extractNumbers(currentLine);

        if (!numbers.empty()) {
            extractedNumber = numbers[0] * 10 + numbers[numbers.size() - 1];
            sum += extractedNumber;
        }
    }

    std::cout << sum << "\n";
    return 0;
}
