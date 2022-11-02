#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void numIncreasing(std::ifstream& new_file) {
    char line[5];
    int previous = 0;
    int num_increasing = 0;
    while (new_file.getline(line, 5))
    {                     
        int number = std::stoi(line);
        if (previous != 0 && number > previous) {
            ++num_increasing;
        }
        previous = number;
    }
    new_file.close();
    std::cout << "Increasing measurements = " << num_increasing << std::endl;
}

int SumTriple(std::vector<int>& triple) {
    int sum = 0;
    for (auto it = triple.begin(); it != triple.end(); ++it) {
        sum += *it;
    }
    return sum;
}

void numIncreasingTriples(std::ifstream& new_file) {
    char line[5];
    std::vector<int> previous_triple;
    int num_increasing_triples = 0;
    while (new_file.getline(line, 5)) {     
        std::vector<int> new_triple = previous_triple;
        new_triple.push_back(std::stoi(line));

        if (previous_triple.size() == 3) {
            new_triple.erase(new_triple.begin());
            if (SumTriple(new_triple) > SumTriple(previous_triple)) {
                ++num_increasing_triples;
            }
        }
        previous_triple.swap(new_triple);
    }
    new_file.close();
    std::cout << "Increasing triple measurements = " << num_increasing_triples << std::endl;
}

int main()
{
    char ch;
    // creating the object of the data type 'istream'
    std::ifstream new_file;
    // opening the above file
    new_file.open("input.txt", std::ios::in);

    if (new_file.is_open()) { 
        numIncreasing(new_file);
    }

    new_file.open("input.txt", std::ios::in);
    if (new_file.is_open()) {
        numIncreasingTriples(new_file);
    }
    
    return 0;
}
