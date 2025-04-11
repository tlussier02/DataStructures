/*
Full name: Trevor Lussier
Student ID: 2445730
Chapman email: tlussier@chapman.edu
Course number and section: CPSC 350 04
Assignment or exercise number: 4 (Blockchain Ledger)
*/

#include "Blockchain.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <cstdlib> 

Blockchain::Blockchain() {
    chainSize = 0;

    // Create the Genesis block
    // index=0, data="Genesis Block", prevHash="0", timestamp = current time
    Block genesis;
    genesis.setIndex(0);
    genesis.setData("Genesis Block");
    genesis.setPreviousHash("0");
    genesis.setTimestamp(getCurrentTime());
    // compute initial hash
    genesis.setCurrentHash(genesis.computeHash());

    chain[0] = genesis;
    chainSize = 1;
}

void Blockchain::addBlock(const std::string &data) {
    if (chainSize >= MAX_BLOCKS) {
        std::cerr << "Blockchain is full. Cannot add more blocks.\n";
        return;
    }
    int newIndex = chainSize;  // next block index
    std::string newTimestamp = getCurrentTime();
    std::string prevH = chain[chainSize - 1].getCurrentHash();

    Block newBlock(newIndex, newTimestamp, data, prevH);
    // newBlock already has computed its currentHash in the constructor

    chain[chainSize] = newBlock;
    chainSize++;
}

bool Blockchain::validateChain() const {
    // For each block from 1..chainSize-1, check:
    // 1) block[i]'s prevHash == chain[i-1]'s currentHash
    // 2) block[i]'s currentHash == block[i].computeHash()
    for (int i = 1; i < chainSize; ++i) {
        if (chain[i].getPreviousHash() != chain[i - 1].getCurrentHash()) {
            return false;
        }
        std::string recalculated = chain[i].computeHash();
        if (chain[i].getCurrentHash() != recalculated) {
            return false;
        }
    }
    return true;
}

void Blockchain::displayChain() const {
    for (int i = 0; i < chainSize; ++i) {
        std::cout << "Block " << i << ":\n";
        std::cout << "  Index: " << chain[i].getIndex() << "\n";
        std::cout << "  Timestamp: " << chain[i].getTimestamp() << "\n";
        std::cout << "  Data: " << chain[i].getData() << "\n";
        std::cout << "  PreviousHash: " << chain[i].getPreviousHash() << "\n";
        std::cout << "  CurrentHash: " << chain[i].getCurrentHash() << "\n";
        std::cout << "-------------------------\n";
    }
}

void Blockchain::saveToFile(const std::string &filename) const {
    std::ofstream outFile(filename.c_str());
    if (!outFile) {
        std::cerr << "Error opening file for writing: " << filename << "\n";
        return;
    }
    // Format: index|timestamp|data|prevHash|curHash
    for (int i = 0; i < chainSize; ++i) {
        outFile << chain[i].getIndex() << "|"
                << chain[i].getTimestamp() << "|"
                << chain[i].getData() << "|"
                << chain[i].getPreviousHash() << "|"
                << chain[i].getCurrentHash() << "\n";
    }
    outFile.close();
    std::cout << "Blockchain saved to file: " << filename << "\n";
}

void Blockchain::loadFromFile(const std::string &filename) {
    std::ifstream inFile(filename.c_str());
    if (!inFile) {
        std::cerr << "Error opening file for reading: " << filename << "\n";
        return;
    }
    chainSize = 0;
    std::string line;
    while (std::getline(inFile, line)) {
        char buffer[1024];
        for (int i = 0; i < 1024; ++i) {
            buffer[i] = '\0';
        }
        // copy line into buffer
        for (size_t i = 0; i < line.size() && i < 1023; ++i) {
            buffer[i] = line[i];
        }

        // expect 5 tokens
        // index(0), timestamp(1), data(2), prevHash(3), curHash(4)
        std::string tokens[5];
        int tokenCount = 0;
        int start = 0;
        for (int i = 0; buffer[i] != '\0'; ++i) {
            if (buffer[i] == '|') {
                // parse substring from start..i-1
                tokens[tokenCount] = std::string(&buffer[start], &buffer[i]);
                tokenCount++;
                start = i + 1;
            }
        }
        // last token from start..end
        tokens[tokenCount] = std::string(&buffer[start]);

        if (tokenCount < 4) {
            // not enough fields
            continue;
        }

        int idx = std::atoi(tokens[0].c_str());
        std::string timeStamp = tokens[1];
        std::string d = tokens[2];
        std::string prevH = tokens[3];
        std::string curH = tokens[4];

        Block b;
        b.setIndex(idx);
        b.setTimestamp(timeStamp);
        b.setData(d);
        b.setPreviousHash(prevH);
        b.setCurrentHash(curH);

        chain[chainSize] = b;
        chainSize++;
        if (chainSize >= MAX_BLOCKS) break; 
    }
    inFile.close();
    std::cout << "Blockchain loaded from file: " << filename << "\n";
}

std::string Blockchain::getCurrentTime() const {
    time_t now = time(0);
    // ctime returns a string with a newline at the end, can remove if needed
    char* dt = ctime(&now);
    std::string ts(dt);
    if (!ts.empty() && ts[ts.size() - 1] == '\n') {
        ts.erase(ts.size() - 1);
    }
    return ts;
}
