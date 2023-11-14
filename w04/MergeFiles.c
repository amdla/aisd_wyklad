//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct fe {
//    double x;
//    FILE *f;
//} fe_t;
//
//void heap_up(char *t, int n, size_t size, int (*f)(const void *, const void *)) {
//    //a: t[0]...t[n-1] kopiec, t[n] nowy
//    //b: t[0]...t[n]
//    char *tmp = malloc(size);
//
//
//    int i = n;
//    while (i > 0) {
//        int p = (i - 1) / 2;
//        if (f(t + i * size, t + p * size) < 0) {
//            memmove(tmp, t + i * size, size);
//            memmove(t + i * size, t + p * size, size);
//            memmove(t + p * size, tmp, size);
//            i = p;
//        } else
//            return;
//    }
//    free(tmp);
//}
//
//void heap_down(char *t, int n, size_t size, int(*f)(const void *, const void *)) {
//    //a: t[0]...t[n-1] - kopiec z ew. wyjątkiem t[0] -> dzieci
//    //b: t[0]...t[n-1] - kopiec
//    //dodac tmp
//    int i = 0;
//    int c = 1;
//    while (c < n) {
//        if (c + 1 < n && f(t + (c + 1) * size, t + c * size) < 0)
//            c++;
//        if (f(t + i * size, t + c * size) > 0) {
//            //zamiana
//            i = c;
//            c = 2 * 1 + 1;
//        } else {
//            break;
//        }
//    }
//    //free(tmp);
//
//}
//
//int fcmp(const void *a, const void *b) {
//    fe_t ea = *(fe_t *) a;
//    fe_t eb = *(fe_t *) b;
//    if (ea.x < eb.x)
//        return -1;
//    else if (ea.x == eb.x)
//        return 0;
//    else return 1;
//}
//
//void mergeFiles(FILE *in[], int n, FILE *out) {
//    fe_t *heap = malloc(n * sizeof *heap);
//    for (int i = 0; i < n; i++) {
//        heap[i].f = in[i];
//        fscanf(heap[i].f, "%lf", &(heap[i].x));
//        heap_up(heap, i, sizeof heap[0], fcmp);
//    }
//
//    while (n > 0) {
//        fprintf(out, "%g\n", heap[0].x);
//        if (fscanf(heap[0].f, "%lf", &(heap[0].x)) != 1) {
//            fclose(heap[0].f);
//            heap[0] = heap[--n];
//        }
//        //heap_down(heap, n);
//    }
//    fclose(out);
//}