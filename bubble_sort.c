
int bubblesort(int v[], int N){
    int i, j, temp, flag = 1;
    for (i = N-1; i> 0 && flag; i--){
        flag = 0;
        for (j = 0; j < i; j++){
            if (v[j] > v[j+1]){
                flag = 1;
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}
