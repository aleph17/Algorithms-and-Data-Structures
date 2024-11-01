
# define N 10
int main(){
    int list[N] = {134,43,87,323,501,201,82,30,91,514};
    int i, D[N], max = 0, weight, mw = 1, C[N], B[N];
    for(i = 0; i < N; i++){
        if(list[i] > list[max]) max = i;
    }
    for(weight =1; list[max]/mw > 0; mw *= 10);
    mw /= 10;
    for (weight =1; weight <= mw; weight *= 10){
        for(i = 0; i < N; i++){
            D[i] = (list[i]/weight)%10;
        }
        for(i = 0; i < 10; i++) C[i] =0;
        for(i = 0; i< N; i++) C[D[i]]++;
        for(i = 1; i < N; i++) C[i] += C[i-1];
        for(i = N-1; i>=0; i--){B[C[D[i]]-1] = list[i]; C[D[i]]--;}
        for(i = 0; i < N; i++) list[i] = B[i];
    }
    for(i = 0; i < N; i++) printf("%d ", list[i]);
}