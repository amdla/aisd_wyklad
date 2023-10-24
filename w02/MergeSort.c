#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//scalanie nie zawiera 1. rekurencji 2. algorytmu dzielącego
//scalamy każde pary w posortowane pary
//duze zapotrzebowanie na pamiec
void merge(double s[], double d[], int s_begin, int s_mid, int s_end) {
    int i = s_begin;
    int j = s_mid;
    int k = s_end;

    while (i < s_mid && j < s_end) {
        if (s[i] <= s[j])
            d[k++] = s[i++];
        else
            d[k++] = s[j++];
    }
    while (i < s_mid)
        d[k++] = s[i++];

    while (j < s_end)
        d[k++] = s[j++];
}

void msort(double t[], int n) {
    double *tmp = malloc(n * sizeof *tmp);
    double *s = t;
    double *d = tmp;

    int l = 2;
    //NP: podtablice o dlugosci 1/2 sa posortowane
    while (l / 2 < n) {
        for (int ss = 0; ss < n; ss += l)
            merge(s, d, ss, (ss + 1 / 2 > n ? n : ss + l / 2), (ss + l > n ? n : ss + l));

        tmp = s;
        s = d;
        d = tmp;
        l *= 2;
    }
    if (s != t) {
        memcpy(t, s, n * sizeof(double));
        free(s);
    }else{
        free(d);
    }
}