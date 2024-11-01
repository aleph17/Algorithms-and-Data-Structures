
#define N 8
int main(){
    int main[N] = {34,12,64,23,75, 91, 17,34}, adj[N];
    int i, j ,p, s,k;
    for(s = 1; s <= N/2; s *= 2){
        for(p = 0; p <= N - 2*s; p+= 2*s){
            i = p;
            j = p+s;
            for(k = p; k< p +2*s; k++){
                if ( i > p+s-1) adj[k] = main[j++];
                else if ( j > p + 2*s - 1) adj[k] = main[i++];
                else if (main[i] > main[j]) adj[k] = main[j++];
                else adj[k] = main[i++];
            }
        }
        for(k = 0; k< N; k++) main[k] = adj[k];
    }
    for(i = 0; i< N; i++) printf("%d ", main[i]);
}

