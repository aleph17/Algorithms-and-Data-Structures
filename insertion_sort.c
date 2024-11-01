void Insert( int A[], int N){
    int i,x, j, ok = 0;
    for (i = 1; i < N; i++){
        x = A[i];
        ok = 0;
        for (j = i-1; j>=0 && !ok; j--){
            if(x < A[j]){
                A[j+1] = A[j];
                A[j] = x;
            }
            else ok = 1;
        }
    }
}