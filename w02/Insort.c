#include <stdio.h>


//wstawianie
//algorytm jest odporny na zduplikowane dane np 2 i 2
void insort(double v[], int n) {
    //alfa: v[0]...v[n-1] double, n >= 0
    //beta: v[0] <= v[1] <= ... <= v[n-1]
    for (int i = 1; i < n; i++) {
        double temp = v[i];
        int j = i;
        for (; j > 0 && v[j - 1] > temp; j--)
            v[j] = v[j - 1];
        v[j] = temp;
    }
}

