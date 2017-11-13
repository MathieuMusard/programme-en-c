#ifndef GENERATIONCODE_H_INCLUDED
#define GENERATIONCODE_H_INCLUDED

typedef struct BPM BPM {
    Int pulse ;
    double time;
}BPM;

typedef struct Element {
    int nombre;
    Element *suivant
}Element;

typedef struct Liste {
    Element *premier;
}Liste;

Liste *initialisation()
void insertion (Liste *liste, int nvNombre)
void suppression (Liste *liste)
void ajoutBPM
#endif // GENERATIONCODE_H_INCLUDED
