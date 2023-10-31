typedef struct elem {
    double x;
    struct elem *next;
} elem_t, *list_t;

#include <stdio.h>
#include <stdlib.h>

list_t insert(list_t l, double x) {
    list_t n = malloc(sizeof *n);
    n->x = x;
    n->next = l;
    return n;
}

list_t append(list_t l, double x) {
    if (l == NULL) {
        list_t n = malloc(sizeof *n);
        n->x = x;
        n->next = NULL;
        return n;
    } else {
        l->next = append(l->next, x);
        return l;
    }
}

list_t append_nr(list_t l, double x) {
    if (l == NULL) {
        list_t n = malloc(sizeof *n);
        n->x = x;
        n->next = NULL;
        return n;
    } else {
        list_t it = l;
        while (it->next != NULL)
            it = it->next;
        it->next = malloc(sizeof *it->next);
        it->next->x = x;
        it->next->next = NULL;
        return l;
    }
}

list_t pop(list_t l, double *x) {
    if (l != NULL) {
        *x = l->x;
        list_t n = l->next;
        free(l);
        l = n;
    }
    return l;
}

list_t get_nr(list_t l, double *x) {
    if (l != NULL) {
        if (l->next == NULL) {
            *x = l->x;
            free(l);
            l = NULL;
        } else {
            list_t it = l;
            while (it->next->next != NULL)
                it = it->next;
            *x = it->next->x;
            free(it->next);
            it->next = NULL;
        }
    }
    return l;
}

list_t get(list_t l, double *x) {
    if (l == NULL)
        return NULL;
    else if (l->next == NULL) {
        *x = l->x;
        free(l);
        return NULL;
    } else {
        l->next = get(l->next, x);
        return l;
    }
}

list_t insort(list_t l, double x) {
    if (l == NULL || l->x > x) {
        list_t n = malloc(sizeof *n);
        n->x = x;
        n->next = l;
        return n;
    } else {
        l->next = insort(l->next, x);
        return l;
    }
}

list_t insort_nr(list_t l, double x) {
    if (l == NULL || l->x > x) {
        list_t n = malloc(sizeof *n);
        n->x = x;
        n->next = l;
        return n;
    } else {
        list_t it = l;
        while (it->next != NULL && it->nex->x <= x)
            it = it->next;
        list_t n = malloc(sizeof *n);
        n->x = x;
        n->next = it->next;
        it->next = n;
        return l;
    }
}

#include <string.h>

int main(int argc, char **argv) {

    list_t (*f)(list_t, double) = strcmp(argv[0], "./fifo") == 0 ? append : insert;
    list_t l = NULL;

    for (int i = 1; i < argc; i++)
        l = f(l, atof(argv[i]));

    while (l != NULL) {
        double x;
        l = pop(l, &x);
        printf("%g\n", x);
    }

    return 0;
}
