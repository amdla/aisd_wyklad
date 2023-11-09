#ifndef AISD_WYKLAD_BST_H
#define AISD_WYKLAD_BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    double x;
    struct node *left, *right;
    struct node *parent;
} *btree_t;

//BST: left < this < right

btree_t add(btree_t t, double x) {
    if (t == NULL) {
        btree_t n = malloc(sizeof *n);
        n->x = x;
        n->left = n->right = NULL;
        return n;
    }
    if (x < t->x) {
        t->left = add(t->left, x);
    } else if (x > t->x) {
        t->right = add(t->right, x);
    }
    return t;
}

void print_tree(btree_t t, int level) {
    if (t != NULL) {
        print_tree(t->left, level + 1);
        for (int i = 0; i < level; i++)
            printf("   ");
        printf("%g\n", t->x);
        printf(t->right, level + 1);
    }


}

int main(int argc, char **argv) {
    btree_t t = NULL;
    for (int i = 1; i < argc; i++) {
        t = add(t, atof(argv[i]));
    }

    print_tree(t, 0);
    return 0;
}


#endif