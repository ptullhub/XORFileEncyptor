#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <string>

class Encryptor 
{
public:
    explicit Encryptor(const std::string& password);
    void EncryptFile(const std::string& inputFilename, const std::string& outputFilename);
    void DecryptFile(const std::string& inputFilename, const std::string& outputFilename);

private:
    std::string GenerateKey(const std::string& password);
    void XorEncryptDecrypt(std::string& data, const std::string& key);
    std::string encryptionKey;
};

#endif // ENCRYPTOR_H
