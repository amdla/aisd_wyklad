typedef struct elenm {
    double x;
    struct elem *next;
} elem_t, *list_t;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//
//list_t insert(list_t list, double x) {
//    list_t n = malloc(sizeof *n);
//    n->x = x;
//    n->next = list;
//    return n;
//}
//
//list_t append(list_t l, double x) {
//    if (l == NULL) {
//        list_t n = malloc(sizeof *n);
//        n->x = x;
//        n->next = NULL;
//        return n;
//    } else {
//        l->next = append(l->next, x);
//        return l;
//    }
//}
//
//list_t pop(list_t l, double *x) {
//    if (l != NULL) {
//        *x = l->x;
//        list_t n = l->next;
//        free(l);
//        l = n;
//    }
//}

//int main(int argc, char **argv) {
//    list_t list = NULL;
//    list_t (*f)(list_t, double) =strcmp(argv[0], "./fifo") == 0 ? append : insert;
//
//    for (int i = 0; i < argc; i++) {
//        list = insert(list, atof(argv[i]));
//    }
//
//
//    while (list != NULL) {
//        double x;
//        printf("%g->", list->x);
//        list = list->next;
//    }
//    printf("NULL\n");
//}