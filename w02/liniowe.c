#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}

int ss(double tab[], int n, double x) {
    //alfa: v[0]... v[n-1] double, n >= 0, x double
    //beta: return i >= 0 gdy v[i] == xm -1 gdy takiego nie ma
    for (int i = 0; i < n; i++)
        if (tab[i] == x)
            return i;
    return -1;
}
