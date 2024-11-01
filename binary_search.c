#define N 1000
int main(){
    int i, j, p, q, id[N], sz[N];
    for (i = 0; i<N; i++) {id[i] = i; sz[i] = 1;}
    printf("bring it:");
    while(fscanf(stdin, "%d %d", &p, &q) == 2){
        for(i = p; i!= id[i]; i = id[i]);
        for(j = q; j!= id[j]; j = id[j]);
        if (i == j) printf("connected");
        else{
            printf("done");
            if (sz[i] > sz[j]){
                id[j] = id[i];
                sz[i] += sz[j];
            }
            else{
                id[i] = id[j];
                sz[j] += sz[i];
            }
        }
        printf("bring it");
    }
}
