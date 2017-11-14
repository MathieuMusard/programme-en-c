#include "data.h"

Element *newElement(int millisecondSet, float beatPerSecondSet){
  Element *newElement = malloc(sizeof(*newElement));
  if (newElement == NULL)
    exit(EXIT_FAILURE);
  newElement->millisecond = millisecondSet;
  newElement->beatsPerSecond = beatPerSecondSet;
  newElement->next = NULL;
  return newElement;
}

List *newList(){
  List *newList = malloc(sizeof(*newList));
  if (newList == NULL)
    exit(EXIT_FAILURE);
  newList->first = NULL;
  newList->numberOfElement = 0;
  return newList;
}

void addElement(List *receivingList, Element *elementToSend){
  elementToSend->next = receivingList->first;
  receivingList->first = elementToSend;
  receivingList->numberOfElement++;
}

void printElement(Element *elementToRead){
  if (elementToRead == NULL)
    exit(EXIT_FAILURE);
  printf("%d;%f\n", elementToRead->millisecond, elementToRead->beatsPerSecond);
}

void printList(List *listToRead){
  if (listToRead == NULL)
    exit(EXIT_FAILURE);
  Element *elementToRead = listToRead->first;
  while(elementToRead != NULL){
    printElement(elementToRead);
    elementToRead = elementToRead->next;
  }
  printf("%d", listToRead->numberOfElement);
}

List *storeCSV() {
  FILE *pulseFile = NULL;
  pulseFile = fopen("pulse.csv", "r");
  List *listOfPulsesData = newList();
  char nextChar;
  if (pulseFile != NULL){
    do {
      int millisecondRead = 0;
      float beatsPerSecondRead = 0;
      fscanf(pulseFile, "%d;%f", &millisecondRead, &beatsPerSecondRead);
      addElement(listOfPulsesData, newElement(millisecondRead, beatsPerSecondRead));
      nextChar = fgetc(pulseFile);
    }while (nextChar == '\n' && nextChar != EOF);
  }
  fclose(pulseFile);
  return listOfPulsesData;
}
