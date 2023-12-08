#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>

typedef long long large_int;

// Function to check if a number is prime
bool isPrime(large_int num) {
    if (num <= 1) return false;
    for (large_int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function for modular exponentiation
large_int modExp(large_int base, large_int exponent, large_int modulus) {
    large_int result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

// Function to calculate the modular inverse using Extended Euclidean Algorithm
large_int modInverse(large_int a, large_int m) {
    large_int m0 = m, t, q;
    large_int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;

        // m is remainder now, process same as Euclid's algo
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to read a file into a string
std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Cannot open file: " + filename);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// Function to write a string to a file
void writeFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Cannot open file: " + filename);
    }
    file << content;
}
void encryptFunction(large_int e, large_int n) {
    std::string plaintextFilename, ciphertextFilename;

    std::cout << "Enter the plaintext filename (e.g., message.txt): ";
    std::cin >> plaintextFilename;
    plaintextFilename = "C:/Users/amana/CLionProjects/RSA/" + plaintextFilename + ".txt";

    std::string ciphertext = "";
    try {
        std::string plaintext = readFile(plaintextFilename);

        std::cout << "\nEncrypting...\n";
        for (char c : plaintext) {
            large_int encryptedValue = modExp(static_cast<large_int>(c), e, n);
            ciphertext += std::to_string(encryptedValue) + " ";
        }

        std::cout << "Enter the filename to save encrypted data (e.g., encrypted.txt): ";
        std::cin >> ciphertextFilename;
        ciphertextFilename = "C:/Users/amana/CLionProjects/RSA/" + ciphertextFilename + ".txt";

        writeFile(ciphertextFilename, ciphertext);
        std::cout << "Encryption complete. Encrypted data written to: " << ciphertextFilename << "\n";
    } catch (const std::exception& ex) {
        std::cerr << "Encryption Error: " << ex.what() << "\n";
    }
}

void decryptFunction(large_int d, large_int n) {
    std::string ciphertextFilename;

    std::cout << "Enter the filename of the encrypted data (e.g., encrypted.txt): ";
    std::cin >> ciphertextFilename;
    ciphertextFilename = "C:/Users/amana/CLionProjects/RSA/" + ciphertextFilename + ".txt";

    try {
        std::string ciphertext = readFile(ciphertextFilename);
        std::string decryptedText = "";
        std::istringstream iss(ciphertext);
        std::string token;

        std::cout << "\nDecrypting...\n";
        while (iss >> token) {
            large_int decryptedValue = modExp(std::stoll(token), d, n);
            decryptedText += static_cast<char>(decryptedValue);
        }

        std::cout << "Decrypted Message:\n" << decryptedText << "\n";
    } catch (const std::exception& ex) {
        std::cerr << "Decryption Error: " << ex.what() << "\n";
    }
}


int main() {
    large_int p, q, e;

    // Input for p and q
    std::cout << "Enter two distinct prime numbers (p and q): ";
    std::cin >> p >> q;

    if (!isPrime(p) || !isPrime(q)) {
        std::cout << "Both numbers must be prime." << std::endl;
        return 1;
    }

    large_int n = p * q;
    large_int phiN = (p - 1) * (q - 1);

    // Input for e
    std::cout << "Enter the encryption key e (1 < e < " << phiN << "): ";
    std::cin >> e;

    if (e <= 1 || e >= phiN || std::__gcd(e, phiN) != 1) {
        std::cout << "Invalid encryption key." << std::endl;
        return 1;
    }

    large_int d = modInverse(e, phiN);

    std::cout << "Public Key: (e = " << e << ", n = " << n << ")" << std::endl;
    std::cout << "Private Key: (d = " << d << ", n = " << n << ")" << std::endl;

    std::string plaintextFilename, ciphertextFilename;

    // Reading plaintext from file
    std::cout << "Enter the plaintext filename: ";
    std::cin >> plaintextFilename;
    plaintextFilename = "C:/Users/amana/CLionProjects/RSA/" + plaintextFilename +  ".txt";


    std::string ciphertext = "";
    try {
        std::string plaintext = readFile(plaintextFilename);

        for (char c : plaintext) {
            large_int encryptedValue = modExp(static_cast<large_int>(c), e, n);
            ciphertext += std::to_string(encryptedValue) + " ";
        }

        std::cout << "Enter the filename to save encrypted data: ";
        std::cin >> ciphertextFilename;
        ciphertextFilename = "C:/Users/amana/CLionProjects/RSA/" + ciphertextFilename + ".txt";

        writeFile(ciphertextFilename, ciphertext);
        std::cout << "Encryption complete. Data written to " << ciphertextFilename << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }


    // Decrypting text
    std::string decryptedText = "";
    std::istringstream iss(ciphertext);
    std::string token;

    while (iss >> token) {
        large_int decryptedValue = modExp(std::stoll(token), d, n);
        decryptedText += static_cast<char>(decryptedValue);
    }

    std::cout << "Decrypted Message: " << decryptedText << std::endl;

    int choice;
    std::cout << "RSA Encryption/Decryption Program\n";
    std::cout << "1. Encrypt\n";
    std::cout << "2. Decrypt\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;

    if (choice != 1 && choice != 2) {
        std::cerr << "Invalid choice. Exiting program.\n";
        return 1;
    }
//  Public Key: (e = 17, n = 3233)
// Private Key: (d = 2753, n = 3233)
    if (choice == 1) {
        encryptFunction(e, n);
    } else {
        decryptFunction(d, n);
    }

    return 0;
}
