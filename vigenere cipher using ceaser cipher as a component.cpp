#include <iostream>
#include <string>

std::string encryptVigenere(const std::string &plaintext, const std::string &keyword)
{
    std::string ciphertext;
    int keywordLength = keyword.length();

    for (size_t i = 0; i < plaintext.length(); ++i)
    {
        char plainChar = plaintext[i];
        char keywordChar = keyword[i % keywordLength];

        // Convert plaintext character to uppercase
        if (islower(plainChar))
        {
            plainChar = toupper(plainChar);
        }

        // Convert keyword character to uppercase
        if (islower(keywordChar))
        {
            keywordChar = toupper(keywordChar);
        }

        if (isalpha(plainChar))
        {
            // Apply Caesar cipher shift
            char encryptedChar = 'A' + ((plainChar - 'A' + (keywordChar - 'A')) % 26);

            // Convert encrypted character to lowercase if the original plaintext character was lowercase
            if (islower(plaintext[i]))
            {
                encryptedChar = tolower(encryptedChar);
            }

            ciphertext += encryptedChar;
        }
        else
        {
            ciphertext += plainChar; // Keep non-alphabetic characters unchanged
        }
    }

    return ciphertext;
}

int main()
{
    std::string plaintext = "HELLO WORLD!";
    std::string keyword = "KEY";

    std::string ciphertext = encryptVigenere(plaintext, keyword);

    std::cout << "Plaintext: " << plaintext << std::endl;
    std::cout << "Ciphertext: " << ciphertext << std::endl;

    return 0;
}
