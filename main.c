#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 256

typedef enum
{
    INT,
    TWIN
}oType;

typedef struct sObject
{
    oType type;

    union
    {
        int value;

        struct {
            struct sObject *head;
            struct sObject *title
        };
    };
}Object;

typedef struct
{
    Object *stack[MAX_STACK_SIZE];
    int stackSize;
}vm;

void push(vm *vm, Object *value)
{
    vm->stack[vm->stackSize] = value;
}

Object* pop(vm* vm)
{
    return vm->stackSize[--vm->stackSize];
}



int main()
{
    return 0;
}
