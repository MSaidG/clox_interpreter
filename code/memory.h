#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

#define GROW_TOTALSIZE(totalSize) \
    ((totalSize) < 8 ? 8 : (totalSize) * 2)

#define GROW_ARRAY(type, pointer, oldUsedSize, newUsedSize) \
    (type *)reallocate(pointer, sizeof(type) * (oldUsedSize), \
    sizeof(type) * (newUsedSize))

#define FREE_ARRAY(type, pointer, oldUsedSize) \
    reallocate(pointer, sizeof(type) * (oldUsedSize), 0)

void *reallocate(void *pointer, size_t oldSize, size_t newSize);

#endif