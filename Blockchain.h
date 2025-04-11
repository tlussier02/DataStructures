/*
Full name: Trevor Lussier
Student ID: 2445730
Chapman email: tlussier@chapman.edu
Course number and section: CPSC 350 04
Assignment or exercise number: 4 (Blockchain Ledger)
*/

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include <string>

/*
  The Blockchain class:
   - An array of Block objects (no advanced data structures).
   - A size limit (100).
   - Current number of blocks (chainSize).
   - Genesis block in the constructor.
*/

class Blockchain {
public:
    // constructor => create genesis block
    Blockchain();

    // Adds a new block with the given data, computing new block's hash,
    // linking it to the previous block
    void addBlock(const std::string &data);

    // Validate the entire chain
    bool validateChain() const;

    // Display the entire chain
    void displayChain() const;

    // Save chain to a file
    void saveToFile(const std::string &filename) const;

    // Load chain from a file, rewriting current chain
    void loadFromFile(const std::string &filename);

private:
    static const int MAX_BLOCKS = 100;
    Block chain[MAX_BLOCKS];
    int chainSize;

    // Utility for getting the current time as a string
    std::string getCurrentTime() const;
};

#endif
