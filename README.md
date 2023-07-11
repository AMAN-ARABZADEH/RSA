# RSA Encryption/Decryption Code
<img src="https://t.bkit.co/w_649944500f31e.gif" />
This repository contains an implementation of the RSA encryption and decryption algorithm in C++.
RSA (Rivest-Shamir-Adleman) is a widely used public-key cryptographic algorithm that allows secure communication between two parties over an insecure channel.

## Overview

The code in this repository demonstrates the steps involved in generating RSA keys,
encrypting a plaintext message,
and decrypting the ciphertext back to the original plaintext. 


The main components of the code include:

- Checking if a number is prime.
- Computing modular exponentiation.
- Calculating the modular inverse using the Extended Euclidean Algorithm.
- Generating RSA keys: choosing prime numbers, computing the modulus and phi(n), and selecting the encryption and decryption keys.
- Encrypting a plaintext message using the RSA algorithm.
- Decrypting a ciphertext message back to plaintext.

## Usage

To use the code, follow these steps:

1. Enter two distinct prime numbers `p` and `q` when prompted. These primes are used for key generation.
2. Enter an encryption key `e` when prompted. This key should be coprime with `(p-1) * (q-1)`.
3. The program will compute the necessary values, including the modulus `n` and the decryption key `d`, based on the inputs.
4. Enter a plaintext message when prompted.
5. The program will encrypt the plaintext using RSA encryption and display the ciphertext.
6. The program will then decrypt the ciphertext back to the original plaintext and display it.

## Requirements

- C++ compiler
- Standard Library

## Limitations and Future Improvements

- The current implementation only supports ASCII characters for encryption and decryption. It could be enhanced to handle Unicode characters.
- Error handling and input validation can be improved to handle unexpected user inputs gracefully.
- The code can be optimized further for efficiency and performance.
## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions to this repository are welcome. If you have any suggestions, bug fixes, or improvements, please feel free to open an issue or submit a pull request.

## Source:  https://en.wikipedia.org/wiki/RSA_(cryptosystem)

