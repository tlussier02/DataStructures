/*
Full name: Trevor Lussier
Student ID: 2445730
Chapman email: tlussier@chapman.edu
Course number and section: CPSC 350 04
Assignment or exercise number: 4 (Blockchain Ledger)
*/

#ifndef BLOCK_H
#define BLOCK_H

#include <string>

/*
  The Block class:
    - index (int)
    - timestamp (std::string) 
    - data (std::string)
    - previousHash (std::string)
    - currentHash (std::string)

  We'll compute currentHash by summing ASCII values from concatenated:
    (index + timestamp + data + previousHash)
  and then converting that sum to hex.
*/

class Block {
public:
    // Constructors
    Block();
    Block(int idx, const std::string &time, const std::string &d,
          const std::string &prevH);

    // Accessors
    int getIndex() const;
    std::string getTimestamp() const;
    std::string getData() const;
    std::string getPreviousHash() const;
    std::string getCurrentHash() const;

    // Mutators
    void setIndex(int idx);
    void setTimestamp(const std::string &time);
    void setData(const std::string &d);
    void setPreviousHash(const std::string &prevH);
    void setCurrentHash(const std::string &curH);

    // Utility to compute the block's hash using the assignment instructions
    std::string computeHash() const;

private:
    int index;
    std::string timestamp;
    std::string data;
    std::string previousHash;
    std::string currentHash;
};

#endif
