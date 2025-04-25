#include "Encryptor.h"
#include <iostream>
#include <fstream>

Encryptor::Encryptor(const std::string& password) 
{
    encryptionKey = GenerateKey(password);
}

// Generate a key by repeating the password until it’s long enough
std::string Encryptor::GenerateKey(const std::string& password) 
{
    if (password.empty()) 
    {
        std::cerr << "Error: Password cannot be empty!" << std::endl;
        exit(1);
    }
    return password;  // Store original password as the base key
}


// XOR each character with the generated key
void Encryptor::XorEncryptDecrypt(std::string& data, const std::string& key) 
{
    size_t keyLength = key.length();
    if (keyLength == 0) return;

    for (size_t i = 0; i < data.length(); ++i) 
    {
        data[i] ^= key[i % keyLength];  // Repeat the key dynamically
    }
}


void Encryptor::EncryptFile(const std::string& inputFilename, const std::string& outputFilename) 
{
    std::ifstream inFile(inputFilename, std::ios::binary);
    // File not found handle
    if (!inFile) 
    {
        std::cerr << "Error opening input file: " << inputFilename << std::endl;
        return;
    }

    // Read entire file into a string
    std::string data((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    inFile.close();

    XorEncryptDecrypt(data, encryptionKey);

    std::ofstream outFile(outputFilename, std::ios::binary);
    if (!outFile) 
    {
        std::cerr << "Error opening output file: " << outputFilename << std::endl;
        return;
    }

    outFile.write(data.data(), data.size());
    outFile.close();

    std::cout << "Processing complete! Output saved to: " << outputFilename << std::endl;
}

void Encryptor::DecryptFile(const std::string& inputFilename, const std::string& outputFilename) 
{
    EncryptFile(inputFilename, outputFilename); // Symmetric
}

