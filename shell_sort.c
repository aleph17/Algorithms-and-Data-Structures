
int shellsort(int v[], int N){
    int i, j,x, h = 1;
    while(h <= N/3){
        h = 3*h + 1;
    }
    while(h > 1) {
        for (i = h; i < N; i++) {
            j = i;
            x = v[i];
            while(j-h >= 0 && x < v[j-h]){
                v[j] = v[j-h];
                j -= h;
            }
            v[j] = x;
        }
        h = h/3;
    }
    return 0;
}
