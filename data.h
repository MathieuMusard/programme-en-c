#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
  int millisecond;
  float beatsPerSecond;
  struct Element *next;
}Element;

typedef struct List{
  Element *first;
  int numberOfElement;
}List;

Element *newElement(int millisecondSet, float beatPerSecondSet);
List *newList();
void addElement(List *receivingList, Element *elementToSend);
void printElement(Element *elementToRead);
void printList(List *listToRead);
List *storeCSV();

#endif // DATA_H_INCLUDED
