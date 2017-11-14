#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main()
{
    List myList = *storeCSV();
    //tribulle(myList);
    printList(&myList);
    return 0;
}
