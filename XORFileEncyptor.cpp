#include <iostream>
#include "Encryptor.h"

int main() 
{
    std::string inputFilename, outputFilename, password;
    char choice;
    // Poll input from user
    std::cout << "Enter input filename: ";
    std::cin >> inputFilename;
    std::cout << "Enter output filename: ";
    std::cin >> outputFilename;
    std::cout << "Enter password: ";
    std::cin >> password;

    Encryptor encryptor(password);

    std::cout << "Choose mode: (E)ncrypt or (D)ecrypt? ";
    std::cin >> choice;

    if (choice == 'E' || choice == 'e') 
    {
        encryptor.EncryptFile(inputFilename, outputFilename);
    }
    else if (choice == 'D' || choice == 'd') 
    {
        encryptor.DecryptFile(inputFilename, outputFilename);
    }
    else 
    {
        std::cout << "Invalid option. Exiting program." << std::endl;
    }

    return 0;
}
