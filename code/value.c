#include <stdio.h>

#include "memory.h"
#include "value.h"

void initValueArray(ValueArray *array)
{
    array->values = NULL;
    array->totalSize = 0;
    array->usedSize = 0;
}

void writeValueArray(ValueArray *array, Value value)
{
    if (array->totalSize < array->usedSize + 1)
    {
        int oldTotalSize = array->totalSize;
        array->totalSize = GROW_TOTALSIZE(oldTotalSize);
        array->values = GROW_ARRAY(Value, array->values, oldTotalSize, array->totalSize);
    }

    array->values[array->usedSize] = value;
    array->usedSize++;
}

void freeValueArray(ValueArray *array)
{
    FREE_ARRAY(Value, array->values, array->totalSize);
    initValueArray(array);
}

void printValue(Value value)
{
    printf("%g", value);    
}