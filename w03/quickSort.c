#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}

int podziel(double t[], int p, int k) {
    int i, j;
    for (i = p + 1, j = p; i <= k; i++) {
        if (t[i] < t[p]) {
            double tmp = t[j + 1];
            t[j] = t[i];
            t[i] = tmp;
            j++;
        }
    }
    double tmp = t[p];
    t[p] = t[j];
    t[j] = tmp;
    return j;
}

int xpodziel(double t[], int p, int k) {
    int i = p + 1;
    int j = k;
    while (i < j) {
        while (i < j && t[i] < t[p])
            i++;
        while (i < j && t[j] >= t[p])
            j--;
        if (i < j) {
            double tmp = t[i];
            t[i] = t[j];
            t[j] = tmp;
        }
    }
    if (t[i] >= t[p])
        i--;
    double tmp = t[i];
    t[i] = t[p];
    t[p] = tmp;
    return i;
}

void qsort_r(double t[], int p, int k) {
    if (p < k) {
        int s = podziel(t, p, k);
        qsort_r(t, p, s - 1);
        qsort_r(t, s + 1, k);
    }
}

void myqsort(double t[], int n) {
    qsort_r(t, 0, n - 1);
}

//void qsortbr(double t[], int n) {
//    stack_t stos;
//    push(stos, 0);
//    push(stos, n - 1);
//    while (not_empty(stos)) {
//        int k = pop(stos);
//        int p = pop(stos);
//        int s = xpodziel(t, p, k);
//        if (s - p > 1) {
//            push(stos, p);
//            push(stos, s - 1);
//        }
//        if (k - s > 1) {
//            push(stos, s + 1);
//            push(stos, k);
//        }
//    }
//}