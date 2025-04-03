#include <iostream>
#include <fstream>
#include <string>

void processFile(const std::string& filename) 
{
    std::ifstream inFile(filename);
    if (!inFile) 
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) 
    {
        std::cout << line << std::endl;  // Display file content
    }

    inFile.close();
}

int main() 
{
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    processFile(filename);
    return 0;
}
