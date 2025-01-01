#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

struct Block {
  int id = -1;
  ll startPos;
  ll endPos;
  Block* nextBlock = nullptr;
  Block* prevBlock = nullptr;
  bool moveAttempt = false;
};

Block* rightMostFileBlock(Block* finalBlock) {
  Block* final = finalBlock->prevBlock;
  while (final->id == -1) final = final->prevBlock;
  return final;
}

int main() {
  int size; char c;
  int currPos = 0;
  Block diskMap;
  Block* currBlock = &diskMap;
  Block* finalBlock;
  bool file = true;
  int id = 0;
  int spaceCount = 0;
  while (f >> c) {
    size = c - '0';
    if (size > 0) {
      currBlock->startPos = currPos;
      currBlock->endPos = currPos + size - 1;
      currBlock->nextBlock = new Block();
      currBlock->nextBlock->prevBlock = currBlock;
      if (file) {
        currBlock->id = id;
        id++;
      } else currBlock->id = -1;
      currPos += size;
      currBlock = currBlock->nextBlock;
    }
    file = !file;
  }
  spaceCount = currPos;
  finalBlock = currBlock->prevBlock;
  delete finalBlock->nextBlock;
  currBlock = &diskMap;
  currPos = currBlock->startPos;
  while (finalBlock->startPos != 0) {
    currBlock = &diskMap;
    currPos = currBlock->startPos;
    int finalBlockSize = finalBlock->endPos - finalBlock->startPos + 1;
    while (currBlock->id != finalBlock->id) {
      if (currBlock->id == -1) {
        int currBlockSize = currBlock->endPos - currBlock->startPos + 1;
        if (finalBlockSize == currBlockSize) {
          currBlock->id = finalBlock->id;
          currBlock->moveAttempt = true;
          finalBlock->id = -1;
          break;
        }
        else if (finalBlockSize < currBlockSize) {
          currBlock->id = finalBlock->id;
          currBlock->moveAttempt = true;
          currBlock->endPos -= (currBlockSize - finalBlockSize);
          currBlock->nextBlock->prevBlock = new Block();
          currBlock->nextBlock->prevBlock->startPos = currBlock->endPos+1;
          currBlock->nextBlock->prevBlock->endPos = currBlock->nextBlock->startPos-1;
          currBlock->nextBlock->prevBlock->prevBlock = currBlock;
          currBlock->nextBlock->prevBlock->nextBlock = currBlock->nextBlock;
          currBlock->nextBlock = currBlock->nextBlock->prevBlock;
          finalBlock->id = -1;
          break;
        }
      }
      currBlock = currBlock->nextBlock;
      currPos = currBlock->startPos;
    }
    finalBlock->moveAttempt = true;
    finalBlock = rightMostFileBlock(finalBlock);
  }
  currBlock = &diskMap;
  ll checkSum = 0;
  for (int i=0; i<spaceCount; i++) {
    if (currBlock->id != -1) checkSum += i * currBlock->id;
    if (i == currBlock->endPos) currBlock = currBlock->nextBlock;
  }
  std::cout << checkSum;
}
