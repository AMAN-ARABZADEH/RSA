# RSA Encryption/Decryption Code
<img src="https://t.bkit.co/w_649944500f31e.gif" />
This repository contains an implementation of the RSA encryption and decryption algorithm in C++. RSA (Rivest-Shamir-Adleman) is one of the first public-key cryptosystems and is widely used for secure data transmission.

## Overview

The code in this repository demonstrates the implementation of the RSA algorithm in C++, encompassing key generation, encryption, and decryption processes. It provides a practical example of applying mathematical concepts in cryptographic operations.

### Main Components

- **Prime Number Check:** Verifies if a number is prime, which is essential for generating RSA keys.
- **Modular Exponentiation:** Efficiently computes `(base^exponent) % modulus`.
- **Modular Inverse Calculation:** Utilizes the Extended Euclidean Algorithm to find the modular inverse.
- **RSA Key Generation:** Involves selecting prime numbers `p` and `q`, computing the modulus `n` and `phi(n)`, and choosing encryption `e` and decryption `d` keys.
- **Encryption:** Encrypts a plaintext message using the RSA algorithm.
- **Decryption:** Decrypts the ciphertext back to the original plaintext.

## Usage

1. **Input Prime Numbers:** Enter two distinct prime numbers `p` and `q`.
2. **Enter Encryption Key:** Choose an encryption key `e` that is coprime with `(p-1) * (q-1)`.
3. **Automatic Calculations:** The program computes the modulus `n` and the decryption key `d`.
4. **Encryption Process:** Enter the plaintext to be encrypted. The program outputs the ciphertext.
5. **Decryption Process:** The ciphertext is automatically decrypted back to the original plaintext.

## Requirements

- C++ compiler
- Standard C++ Library

## Limitations and Future Improvements

- **Character Support:** Currently supports ASCII characters only. Future versions could handle Unicode.
- **Error Handling:** Enhanced input validation and error handling for robustness.
- **Optimization:** Potential optimizations for increased efficiency and performance.

## License

This project is under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

Contributions, suggestions, bug fixes, and improvements are welcome. Feel free to open issues or submit pull requests.

## Learn More

For more information on the RSA algorithm and its mathematical foundations, visit [RSA Cryptosystem on Wikipedia](https://en.wikipedia.org/wiki/RSA_(cryptosystem)).
