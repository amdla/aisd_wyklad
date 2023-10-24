void heap_up(double t[], int n) {
    //alfa: t[0]...t[n-1] jest kopcem, t[n] - double
    //beta: t[0]...t[n-1] jest kopcem
    int i = n;
    while (i > 0) {
        int parent = (i - 1 / 2);
        if (t[parent] >= t[i]) return;
        else {
            double tmp = t[i];
            t[i] = t[parent];
            t[parent] = tmp;
            i = parent;
        }
    }
}

void heap_down(double t[], int n) {
    //alfa: t[0]..t[n-1] jest kopcem z ew. wyjątkiem relacji t[i] z dziećmi
    //beta: t[0]...t[n-1] jest kopcem
    int i = 0;
    int child = 2 * i + 1;
    while (child < n) {
        if (child + 1 < n && t[child + 1] > t[child])
            child++;
        if (t[i] >= t[child])
            return;
        else {
            double tmp = t[i];
            t[i] = t[child];
            t[child] = tmp;
            i = child;
            child = 2 * i + 1;
        }
    }
}

void heap_sort(double t[], int n) {
    for (int i = 1; i < n; i++)
        heap_up(t, i);
    for (int i = n - 1; i > 0; i--) {
        double tmp = t[0];
        t[0] = t[i];
        t[i] = tmp;
        heap_down(t, i);
    }
}