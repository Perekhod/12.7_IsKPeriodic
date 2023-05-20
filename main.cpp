#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> split(const std::string& str, int K)   //  This function divides a string into rows the size of K
{
    std::vector<std::string> subStrings;

    for (size_t i = 0; i < str.size(); i += K) 
    {
        subStrings.push_back(str.substr(i, K));
    }

    return subStrings;
}

bool IsKPeriodic(std::vector<std::string> const& v)             //  This function checks if K rows are equal
{
    return std::adjacent_find(v.begin(), v.end(), std::not_equal_to<std::string>()) == v.end();
}

int main()
{
    std::cout << "Enter base string, please:";
    std::string baseString;
    std::cin >> baseString;

    std::cout << "Enter the multiplicity value, please:";
    int K = 0;
    std::cin >> K;

    while(true)
    {
        if (K <= 0)
        {
            std::cout << "Attention! K should be > 0\n";
            std::cout << "Enter the multiplicity value, please:";
            std::cin >> K;
        }
        else
            break;
    }

    std::vector<std::string> tokens = split(baseString, K);

    for (auto& token : tokens) 
    {
        std::cout << token << std::endl;
    }

    std::cout << std::boolalpha << IsKPeriodic(tokens) << std::endl;

    return 0;
}