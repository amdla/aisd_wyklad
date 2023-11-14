#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

void cnts(int t[], int n, int w[], int m) {
    // alfa: t[0]...t[n-1] in < 0, m
    // beta: w[0]...w[n-1] - posortowane t
    int *l = calloc(m, sizeof *l);
    for (int i = 0; i < n; i++)
        l[t[i]]++;

    for (int i = 0; i < m; i++)
        l[i] += l[i - 1];

    //l[m-1] == n

    for (int i = n - 1; i >= 0; i--) {
        l[t[i]]--;
        w[l[t[i]]] = t[i];
    }

    free(l);
}
//istnieje jeszcze funkcja radix16sort, ale to by nic nie dało

void radix10sort(int t[], int n, int w[], int p) {
    //alfa: t[0]...t[n-1] int
    //beta: w[0]...w[n-1] - t posortowane wg p-tej cyfry dziesiętnej (p=0...)

    int l[10] = {0};
    int p10 = pow(10, p);
    for (int i = 0; i < n; i++)
        l[t[i] / p10 % 10]++;
    for (int i = 0; i < n; i++)
        l[i] += l[i - 1];

    int c;
    for (int i = n - 1; i >= 0; i--) {
        c = t[i] / p10 % 10;
        l[c]--;
        w[l[c]] = t[i];
    }
}

void radixsort(int t[], int n, int w[]) {
    //alfa: t[0]...t[n-1] int
    //beta: w[0]...w[n-1] - t posortowane
    int m = t[0];
    for (int i = 1; i < n; i++)
        if (t[i] > m)m = t[i];

    int p10 = 1;
    int *s = t, *d = malloc(n * sizeof *d);
    for (int p = 0; p10 <= m; p++, p10 *= 10) {
        radix10sort(s, n, d, p);
        int *tmp = s;
        s = d;
        d = tmp;
    }
    if (s != t) {
        memmove(t, s, n * sizeof *t);
        free(s);
    } else {
        free(d);
    }

}

//int main(int argc, char **argv) {
//    int n = argc > 1 ? atoi(argv[1]) : 10;
//    int m = argc > 2 ? atoi(argv[2]) : 10;
//
//    srand(time(NULL));
//    int *t = malloc(n * sizeof(t));
//    int *w = malloc(n * sizeof(t));
//
//    for (int i = 0; i < n; i++)
//        t[i] = rand() % m;
//
//    cnts(t, n, w, m);
//
//    if (n < 20) {
//        for (int i = 0; i < n; i++)
//            printf("%10d %10d\n", t[i], w[i]);
//    }
//
//    for (int i = 1; i < n; i++)
//        if (w[i - 1] > w[i])
//            fprintf(stderr, "nie sortuje");
//
//    free(t);
//    free(w);
//}