#define N 1000
int main(){
    int i, j, p, q, id[N];
    for(i = 0; i<N; i++) id[i] = i;
    printf("bring it:");
    while(fscanf(stdin, "%d %d", &p, &q)){
        for(i = p; i!= id[i]; i = id[i]);
        for(j = q; j!= id[j]; j = id[j]);
        if(i == j) printf("connected");
        else id[i] = id[j];
        printf("\nbring it:");
    }
}