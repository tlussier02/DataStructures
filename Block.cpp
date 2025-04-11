/*
Full name: Trevor Lussier
Student ID: 2445730
Chapman email: tlussier@chapman.edu
Course number and section: CPSC 350 04
Assignment or exercise number: 4 (Blockchain Ledger)
*/

#include "Block.h"
#include <sstream>      // for stringstream
#include <iomanip>      // for std::hex
#include <stdexcept>

// Default constructor
Block::Block() {
    index = 0;
    timestamp = "";
    data = "";
    previousHash = "0";
    currentHash = "0";
}

// Overloaded constructor
Block::Block(int idx, const std::string &time, const std::string &d,
             const std::string &prevH) {
    index = idx;
    timestamp = time;
    data = d;
    previousHash = prevH;
    currentHash = computeHash(); // compute upon creation
}

// Getters
int Block::getIndex() const { return index; }
std::string Block::getTimestamp() const { return timestamp; }
std::string Block::getData() const { return data; }
std::string Block::getPreviousHash() const { return previousHash; }
std::string Block::getCurrentHash() const { return currentHash; }

// Setters
void Block::setIndex(int idx) { index = idx; }
void Block::setTimestamp(const std::string &time) { timestamp = time; }
void Block::setData(const std::string &d) { data = d; }
void Block::setPreviousHash(const std::string &prevH) { previousHash = prevH; }
void Block::setCurrentHash(const std::string &curH) { currentHash = curH; }

/*
  computeHash():
    gather (index + timestamp + data + previousHash) as a single string
    Summation of ASCII codes
    Convert sum to hex
*/
std::string Block::computeHash() const {
    // 1) build the input string
    std::stringstream input;
    input << index << timestamp << data << previousHash; 

    std::string combined = input.str();

    // 2) sum ASCII codes
    unsigned int sum = 0;
    for (size_t i = 0; i < combined.size(); ++i) {
        sum += static_cast<unsigned int>(combined[i]);
    }

    // 3) convert sum to hex
    std::stringstream ss;
    ss << std::hex << sum; 
    return ss.str();
}
