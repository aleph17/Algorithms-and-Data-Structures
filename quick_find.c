# define N 1000
int main(){
    int i,t, id[N], p, q;
    for (i = 0; i < N; i++) id[i] = i;
    while(fscanf(stdin, "%d %d\n", &p,&q) == 2){
        if(id[i]== id[q]) printf("connected");
        else {
            for (i = 0, t = id[p]; i<N; i++){
                if(id[i]==t){
                    id[i] = id[q];
                }
            }
        }
        printf("bring it");
    }
}