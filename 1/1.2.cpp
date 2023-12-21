// Advent of Code 2023
// https://adventofcode.com/2023/day/1

#include <array>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int wordToNumber(const std::string& word) {
    // Create an unordered_map to map words to their numeric values
    std::unordered_map<std::string, int> wordMap = {
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}
    };

    // Check if the word exists in the map
    auto it = wordMap.find(word);
    if (it != wordMap.end()) {
        return it->second; // Return the corresponding numeric value if found
    }

    return -1; // Return -1 if word not found (handle error or indicate missing conversion)
}

int calculateNumber(const std::string line)
{
    // array to hold the occured numbers;
    std::vector<unsigned int> numbers;
    // iterate through the string to find occurences and add it to array
    for (size_t i = 0; i < line.length(); i++)
    {
        // add number to array if in numeric form
        if (isdigit(line[i]))
        {
            numbers.push_back(line[i] - '0');
            continue;
        }
        //  iterate over the remaining text to check if the substring [i,j] exists as one of the lettered format of the numbers for eg. nine.
        // if the number exists in the string, add the number to the numbers array
        for (size_t j = i; j < line.length(); j++)
        {
            std::string substring = line.substr(i, j - i + 1);
            int convertedNumber = wordToNumber(substring);
            if (convertedNumber != -1) {
                numbers.push_back(convertedNumber);
            }
        }
        
    }
    // return the number in the required format
    return numbers.front() * 10 + numbers.back();
}

int main(int argc, char *argv[])
{
    std::string temp;

    std::ifstream fin("input");

    unsigned int sum = 0;

    while (fin >> temp)
    {
        sum += calculateNumber(temp);
    }

    std::cout << "The sum of all the numbers: " << sum << "\n";
}