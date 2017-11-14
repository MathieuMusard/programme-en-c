#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main()
{
    List myList = *storeCSV();
    printList(&myList);
    return 0;
}
