# Cryptography-and-Network-Security-Assignment
Cryptography and Network Security - 231

- Members:
  - Dinh Trong Phuc - 2014156
  - Nguyen Thi My Linh - 2012968
  - Bui Nguyen Gia Huy - 2011253
  - Le Viet Hung - 1911302

## Abstract:

In this assignment, we will implement a simple RSA encryption/decryption by C++.

# Cryptography-and-Network-Security-Assignment
A simple RSA encryption/decryption by C++.

## Getting Started

In "NTL Testing" commit, I had pushed a testing NTL library program by C++.

- First, we need install NTL. Docs: https://libntl.org/doc/tour-win.html
- After setting up the env then compile the main.cpp file:
  ![Testing program](/img/testing.png "testing in terminal")

## Compile these files
Compile file in __src/__ and export binary file to __debug/__
```bash
g++ -g -O2 -std=c++11 -pthread -march=native src/main.cpp -o debug/main -lntl -lgmp -lm
```

## Update 

### Update 1:
* Adding NTL library and Miller-Rabin algorithm.

### Update 2:
* Adding "Euclide", "Extended Euclide" and "Square and Multiply" algorithms.

### Update 3:
* Adding "Stein's GCD" & "Binary GCD" algorithms.