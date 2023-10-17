#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}

int podziel(double t[], int p, int k) {
    int i, j;
    for (i = p, j = p; i <= k; i++) {
        if (t[i] < t[p]) {
            double tmp = t[j + 1];
            t[j] = t[i];
            t[i] = tmp;
            j++;
        }
    }
    double tmp = t[p];
    t[p]=t[j];
    t[j]=tmp;
    return j;
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