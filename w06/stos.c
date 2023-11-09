//#include "stos.h"
//#include <stdlib.h>
//#include <math.h>
//
//stos_t init_stos() {
//    stos_t s = malloc(sizeof *s);
//    s->head = NULL;
//    s->n = 0;
//    return s;
//}
//
//void push(stos_t s, double x) {
//    elem_t nowy = malloc(sizeof *nowy);
//    nowy->x = x;
//    nowy->next = s->head;
//    s->head = nowy;
//    s->n++;
//}
//double pop(stos_t s, double *x) {
//    if (s == NULL) {
//        *x = NAN;
//        return s;
//    }
//    double x = s->head->x;
//    stos_t stary = s->head;
//    s->head = s->head->next;
//    free(stary);
//    s->n--;
//    return x;
//}
//
//int is_empty(stos_t s) {
//    return s->n != 0;
//}
//
//void free_stos(stos_t s){
//    while(s->head!=NULL){
//        elem_t stary = s->head;
//        s->head = s->;
//
//    }
//}