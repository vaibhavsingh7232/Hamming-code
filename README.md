🔢 Hamming Code — Error Detection & Correction (C Implementation)

This repository contains a C program that generates Hamming Code and detects/corrects single-bit errors in received data.
It demonstrates concepts of Error Detection & Correction, Data Transmission Reliability, and Bit-level operations, which are widely used in computer networks, digital communication, and fault-tolerant systems.

🚀 Features

✔ Calculates required parity bits dynamically
✔ Generates Hamming Code from user-entered data bits
✔ Accepts received (possibly corrupted) Hamming Code as input
✔ Detects and corrects single-bit error, if present
✔ Shows output before and after correction
✔ Fully interactive console-based implementation

📂 Project Structure
├── hamming_code.c      # Main program — source code implementation
└── README.md           # Documentation

🧠 Concepts Covered
Concept	Description
Hamming Code	Forward error-correcting code for reliable transmission
Parity Bits	Bits added at power-of-2 positions to form redundancy
Bitwise Operations	XOR checks used to recompute parity
Error Location	Binary result pinpoints exact error bit
📌 How to Run
🔧 Requirements

GCC or any C compiler

Terminal / Command Prompt

▶️ Compilation
gcc hamming_code.c -o hamming

▶️ Execution
./hamming

🖥 Sample Interaction
Enter the number of data bits: 4
Enter the data bits (space-separated): 1 0 1 1

Number of parity bits required: 3
Hamming Code: 1 0 1 0 1 1 1

Enter the received Hamming Code (with possible errors): 1 0 0 0 1 1 1

Error detected at position: 3
Received Hamming Code (before correction): 1 0 [0] 0 1 1 1
Corrected Hamming Code: 1 0 1 0 1 1 1

🎯 Learning Outcomes

This project helped in understanding:

Reliability requirements in digital communication

Real-world implementation of theoretical ECC concepts

Efficient use of loops, arrays, bitwise operators and mathematical logic in C

How data integrity is maintained during transmission

💡 Future Enhancements

🔹 Support for multiple-bit error detection
🔹 CLI flags for automated execution without user input
🔹 Visual simulation for parity-checking process

🛠 Tech Stack
Language	Purpose
C	Core logic & execution
