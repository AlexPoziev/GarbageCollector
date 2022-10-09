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
    unsigned char marked;
    union
    {
        int value;

        struct {
            struct sObject *head;
            struct sObject *tail
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
    return vm->stack[--vm->stackSize];
}

vm* newVm(void)
{
    vm *mainVm = (vm*)(malloc(sizeof(vm)));
    mainVm->stackSize = 0;
    return mainVm;
}

Object* newObject(oType type)
{
    Object *object = (Object*)(malloc(sizeof(Object)));
    object->type = type;
    return object;
}

void pushInt(vm* vm, int intV)
{
    Object *object = newObject(INT);
    object->value = intV;
    push(vm, object);
}

Object *pushTwin(vm* vm)
{
    Object *object = newObject(TWIN);
    object->tail = pop(vm);
    object->head = pop(vm);

    push(vm, object);
    return object;
}

void mark(Object* object)
{
    if (object->marked) return;

    object->marked = 1;

    if (object->type == TWIN)
    {
        mark(object->head);
        mark(object->tail);
    }
}

void markAll(vm *vm)
{
    for (int i = 0; i < vm->stackSize; ++i)
    {
        mark(vm->stack[i]);
    }
}

int main()
{
    return 0;
}
