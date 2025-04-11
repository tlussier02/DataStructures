# DataStructures
Projects on common data structures.
Full Name: Trevor Lussier Student ID: 2445730 Chapman Email: tlussier@chapman.edu Course Number and Section: CPSC 350 04 Assignment or Exercise Number: 4 – Blockchain Ledger

A. List of All Source Files Block.h

Block.cpp

Blockchain.h

Blockchain.cpp

main.cpp

B. Known Issues, Errors, or Deviations Compile/Runtime Errors: Currently, there are no known compile-time or runtime errors.

Limitations:

The maximum number of blocks is set to 100 (stored in a simple array).

Deviations: None beyond the assignment’s instructions. All specifications for hashing, file I/O, block creation, and validation are met.

C++ time and date: W3Schools C++ date/time reference

Integer to hexadecimal conversion: Standard library approach with and as discussed in the assignment.

Author: Trevor Lussier.

Execution bash g++ -std=c++11 Block.cpp Blockchain.cpp main.cpp -o A4.exe ./A4.exe You will be presented with a console-based menu:

Add a New Block

Display the Blockchain

Validate the Blockchain

Save Blockchain to File

Load Blockchain from File

Exit

File I/O

Save: You’ll be prompted for an output filename. The blockchain is saved line by line with the format index|timestamp|data|prevHash|currHash.

Load: Provide a previously saved file to reconstruct the chain.

Hash Function Each block’s hash is computed by summing the ASCII values of (index + timestamp + data + previousHash) and then converting the result to a hexadecimal string.
