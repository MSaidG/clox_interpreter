#include <stdlib.h>

#include "common.h"
#include "chunk.h"
#include "memory.h"

void initChunk(Chunk *chunk)
{
    chunk->usedSize = 0;
    chunk->totalSize = 0;
    chunk->code = NULL;
    chunk->lines = NULL;
    initValueArray(&chunk->constants);
}

void writeChunk(Chunk *chunk, uint8_t byte, int line)
{
    if (chunk->totalSize < chunk->usedSize + 1)
    {
        int oldTotalSize = chunk->totalSize;
        chunk->totalSize = GROW_TOTALSIZE(oldTotalSize);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldTotalSize, chunk->totalSize); 
        chunk->lines = GROW_ARRAY(int, chunk->lines, oldTotalSize, chunk->totalSize);
    }

    chunk->code[chunk->usedSize] = byte;
    chunk->lines[chunk->usedSize] = line;
    chunk->usedSize++;
}

void freeChunk(Chunk *chunk)
{
    FREE_ARRAY(uint8_t, chunk->code, chunk->totalSize);
    FREE_ARRAY(int, chunk->lines, chunk->totalSize);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}

int addConstant(Chunk *chunk, Value value)
{
    writeValueArray(&chunk->constants, value);
    return chunk->constants.usedSize -1;
}


