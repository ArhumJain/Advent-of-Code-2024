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
};

Block* rightMostFileBlock(Block* finalBlock) {
  Block* final = finalBlock->prevBlock;
  delete final->nextBlock;
  while (final->id == -1) {
    final = final->prevBlock;
    delete final->nextBlock;
  }
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
  int fileCount = 0;
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
        fileCount += size;
      } else currBlock->id = -1;
      currPos += size;
      currBlock = currBlock->nextBlock;
    }
    file = !file;
  }
  finalBlock = currBlock->prevBlock;
  delete finalBlock->nextBlock;
  currBlock = &diskMap;
  currPos = currBlock->startPos;
  while (currPos <= fileCount-1) {
    if (currBlock->id == -1) {
      int finalBlockSize = finalBlock->endPos - finalBlock->startPos + 1;
      int currBlockSize = currBlock->endPos - currBlock->startPos + 1;
      currBlock->id = finalBlock->id;
      if (finalBlockSize > currBlockSize) {
        finalBlock->endPos -= currBlockSize;
      }
      else if (finalBlockSize == currBlockSize) {
        finalBlock = rightMostFileBlock(finalBlock);
      }
      else if (finalBlockSize < currBlockSize) {
        currBlock->endPos -= (currBlockSize - finalBlockSize);
        currBlock->nextBlock->prevBlock = new Block();
        currBlock->nextBlock->prevBlock->startPos = currBlock->endPos+1;
        currBlock->nextBlock->prevBlock->endPos = currBlock->nextBlock->startPos-1;
        currBlock->nextBlock->prevBlock->prevBlock = currBlock;
        currBlock->nextBlock->prevBlock->nextBlock = currBlock->nextBlock;
        currBlock->nextBlock = currBlock->nextBlock->prevBlock;
        finalBlock = rightMostFileBlock(finalBlock);
      }
    }
    currBlock = currBlock->nextBlock;
    currPos = currBlock->startPos;
  }
  currBlock = &diskMap;
  ll checkSum = 0;
  for (int i=0; i<fileCount; i++) {
    checkSum += i * currBlock->id;
    if (i == currBlock->endPos) currBlock = currBlock->nextBlock;
  }
  std::cout << checkSum;
}
