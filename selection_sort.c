int SelectionSort(int A[], int N) {
    int i,j, temp, imin;
    for (i = 0; i< N - 1; i++){
        imin = i;
        for(j = i + 1; j < N; j ++){
            if (A[j] < A[imin]) imin = j;
        }
        temp = A[imin];
        A[imin] = A[i];
        A[i] = temp;
    }
    return -1;
}