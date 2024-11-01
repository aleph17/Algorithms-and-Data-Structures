# define NMAX 10
int countingsort(int v[], int N);
int main(){
    int v[NMAX] = {5, 3, 2, 7, 4, 8, 5, 1, 0, 0}, i;
    countingsort(v,NMAX);
    for (i = 0; i < NMAX; i++){
        printf("%d ", v[i]);
    }
}

int countingsort(int v[], int N){
    int C[NMAX], i, B[NMAX];
    for (i = 0; i< NMAX; i++) C[i] = 0;
    for (i = 0; i < NMAX; i++) C[v[i]]++; //simple counting
    for (i = 1; i<NMAX; i++) C[i] += C[i-1]; // multiple counting
    for (i = N - 1; i > - 1; i--){
        B[C[v[i]] - 1] = v[i];
        C[v[i]]--;
    }
    for (i = 0; i < NMAX; i++) v[i] = B[i];
}
