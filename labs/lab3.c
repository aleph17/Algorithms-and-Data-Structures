####################### INSERTION SORT  ####################

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

void Insert( int A[], int N){
    int i,x, j;
    for (i = 1; i < N; i++){     // 2N
        x = A[i];                // N-1
        j = i-1;                 // N-1
        while(j>=0 && x < A[j]){ // 2*sum(2...N) j = -1 is also considered
                A[j+1] = A[j];   // sum(1, N-1)
                j--;             // sum(1,N-1)
        }
        A[j + 1] = x;            // N-1
    }
}                                // O(N^2)

#####################  BUBBLE  #####################

void Bubble( int A[], int N){
    int i,x, j, sorted = 0;
    for (i = N -1; i > 0 && !sorted; i--){
        sorted = 1;
        for (j= 0; j<i-1; j++){
            if(A[j]>A[j+1]){
                sorted = 0;
                x = A[j+1];
                A[j+1] = A[j];
                A[j] = x;
            }
        }
    }
}

################## SHELL  #######################

void Shell( int A[], int N,int h){
    int i,x, j;
    for (i = h; i < N; i++){
        x = A[i];
        for (j= i - h; j >= 0; j -= h){
            if(x < A[j]){
                A[j + h] = A[j];
                A[j] = x;
            }
        }
    }
}
void KnuthShell( int A[], int N){
    int i,x, j, l =0,h = 1;
    while (h < N/3) h = 3*h +1;
    while (h>=1) {
        for (i = h; i < N; i++) {
            x = A[i];
            j = i;
            while (j >= l + h && x < A[j - h]) {
                A[j] = A[j - h];
                j -= h;
            }
            A[j] = x;
        }
        h = (h-1)/3;
    }
}

##################### IMP/EXP  ########################

#define NMAX 30
#define MAX 100
typedef struct{
    int num;
    char name[NMAX];
} table;
typedef struct{
    int sim, sex;
    char name[NMAX];
} state;

int main(){
    FILE *f0 = fopen("input.txt","r"), *f1 = fopen("output.txt", "w");
    int nstat, ncom, i, x, si,se, exmax = 0, immax = 0;
    table comps[MAX], trans[MAX];
    char nom[NMAX+1];
    fscanf(f0,"%d %d", &nstat,&ncom);
    state statewise[nstat];
    for (i = 0; i < nstat; i++) {
        fscanf(f0,"%d %s",&x,nom);
        strcpy(statewise[x].name, nom);
    }
    for (i = 0; i < ncom; i++) {
        fscanf(f0,"%d %s",&x,nom);
        comps[i].num = x;
        strcpy(comps[i].name, nom);
    }
    for (i = 0; i<nstat; i++){
        strcpy(statewise[i].name,comps[i].name);
        statewise[i].sex = 0; statewise[i].sim = 0;
    }
    while(fscanf(f1,"%s %d  %*s",nom, &x) == 2){
        trans[i].num = x;
        strcpy(trans[i].name, nom);
        if (x<0) si += x;
        else se += x;
        for (i = 0; i<ncom; i++){
            if (comps[i].name == nom){
                if (x<0) statewise[comps[i].num].sim += x;
                else statewise[comps[i].num].sex += x;
            }
        }
    }
    printf("overall import = %d, overal export  = %d", si, se);
    for (i = 0; i < ncom; i++){
        if (statewise[i].sex > exmax){
            exmax  = i;
        }
        if (statewise[i].sim > immax){
            immax  = i;
        }
    }
    printf("with highest import rate %s (%d); with highest export rate %s (%d)", );
    fclose(f0);fclose(f1);
    return 0;
}

#####################  PIXEL   #########################

typedef struct{
    int r[2];
    int c[2];
    int level;
    int color;
};
int main(int argc,  char *argv[]){
    FILE *fpin = fopen("input.txt","r"), *fpout = fopen("output.txt", "w");
    fclose(fpin);fclose(fpout);
    return 0;
}
################  EXTRA COMMANDS  ######################
//int strlen1(char *s){
//    int cnt = 0;
//    while (*s++ != '\0') cnt ++;
//    return cnt;
//}
//int strlen3(char *s){
//    char *p = s;
//    while(*p++ != '\0');
//    return p - s;
//}
//int sort(int A[]){
//    int N, k, i, C[k], B[k];
//    for (i = 0; i < k; i++) C[i] = 0;
//    for (i = 0; i < N; i++) C[A[i]]++;
//    for (i = 1; i < k; i++) C[i]+= C[i-1];
//    for (i = N-1; i>=0; i--){
//        B[C[A[i]] - 1] = A[i];
//        C[A[i]]--;
//    }
//    for (i = 0; i < N; i++) A[i] = B[i];
//}

############## BOTTOM-UP SEARCH  ###############

void BottomUp(int A[],  int B[], int N){
    int i, q, m;
    i = 0;
    for (m = 1; m <= N; m += m){
        for (i = 0; i < N; i += 2*m){
                q = i + m -1;
                void merge(A[], B[], i, q, min(i+ 2*m -1,N- 1));
        }
    }
}
void merge(int A[], int B[], int l, int q, int r){
    int i, j, k;
    j = q + 1;
    for (k = l; k <= l + 2*(q-l); k++){
        if (l > q) B[k] = A[j++];
        else if (r < q) B[k] = A[i++];
        else if (A[i]> A[j]|| A[i] == A[j]) B[k] = A[i++];
        else B[k] = A[j++];
    }
    for (k = l; k <= r; k++){
        A[k] = B[k];
    }
}
###############  ELIMINATE CHARS IN STRINGS BY MOVING  ############

int main(){
    char str[16] = {"ThisIsAString"};
    int pos[10] = {2,4,6,8,9, -1}, i, j,k, n;
    n = strlen(str);
    for (i = 0; pos[i]!= -1; i++){
        for(j = pos[i]; j< strlen(str); j++)
            str[j] = str[j+1];
        for(k = i + 1; pos[k] != -1; k++){
            if (pos[k] > pos[i]){
                pos[k]--;
            }
        }
    }
    return(n - strlen(str));
}

############  ROTATING VECTORS  ############

int main (){
    int i,dir = -1, p = 4, N = 10, v[10] = {1,3,4,0,4,0, 9,4,2,0}, res[N];
    for (i = 0; i < N; i++){
        if((i + dir*p) > 9) res[(i+dir*p)%10] = v[i];
        else if ((i+dir*p) < 0) res[N + (i +dir*p)%10] = v[i];
        else res[i+dir*p] = v[i];
    }
    for (i= 0; i < N; i++) printf("%d ",res[i]);
    printf("\n");
}

##############  SUBMATRIX  ##############

#define MAX 20
int main(){
    FILE *fpin = fopen("input.txt", "r");
    int m[MAX][MAX], i,j, r, c, run = 1, num, px, py, sum = 0, max = 0, nx, ny;
    fscanf(fpin,"%d %d", &r, &c);
    for (i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            fscanf(fpin,"%d",&m[i][j]);
        }
    }
//    while(run){
        num = 2;
        if (num>0 && num <= r && num <= c){
            for (py = 0; py <= r- num; py++){
                for (px = 0; px <= c - num; px ++){
                    sum = 0;
                    for (i = 0; i < num; i++){
                        for(j = 0; j < num; j++){
                            printf("%d ",m[py + i][px + j]);
                            sum += m[py + i][px + j];
                        }
                        printf("\n");
                    }
                    if (sum > max) { max = sum; ny = py; nx = px;}
                    printf("\n");
                }
            }
            printf("%d - sum   %d - x   %d - y", max, nx, ny);
        }
        else printf("get off");
 //   }
}

####################### SUBSEQUENCE  ####################

# define N 30
void ssequence(int v[], int n);
int main(){
    int i, v[N], n, ok = 1, c =0;
    for (i = 0; i < N && ok; i++){
        scanf( "%d", &n);
        if (n != -1) {v[i] = n;c++;}
        else ok = 0;
    }
    ssequence(v, c);
    return 0;
}
void ssequence(int v[], int n){
    int i,j, smax = 0, cur = 0, position[N], npos = 0;
    for (i = 0; i < n; i++){
        if (v[i] != 0) cur += 1;
        if (v[i] == 0 || i == n -1) {
            if (i == n - 1 && v[i] != 0) i++;
            if (cur == smax) {
                npos += 1;
                position[npos] = i - smax;
            }
            else if (cur > smax) {
                smax = cur;
                npos = 0;
                position[npos] = i - smax;
            }
            cur = 0;
        }
    }
    for (i = 0; i <= npos; i++){
        fprintf(stdout, "{ ");
        for ( j = 0; j < smax; j ++){
            fprintf(stdout, "%d ", v[position[i] +j]);
        }
        fprintf(stdout, "}\n");
    }
}

################   CHESS WINNER  ###################

#define NMAX 20
int main(){
    FILE *fpin = fopen("input.txt","r");
    int mat[NMAX][NMAX],r,c, row, col, best, brow;
    //reading the matrix;
    fscanf(fpin, "%d %d", &row,&col);
    for (r = 0; r < row; r++){
        for (c = 0; c < col; c++){
            fscanf(fpin,"%d", &mat[r][c]);
        }
    }
    // having the sum matrix
    for (c = 1; c < col; c++){
        for (r = 0; r < row; r++){
            mat[r][c] += mat[r][c-1];
        }
    }
    // deciding for each column the best
    for (c = 0; c < col; c++) {
        best = 0;
        brow = 0;
        for (r = 0; r < row; r++) {
            if (mat[r][c] > best) (best = mat[r][c], brow = r);
        }
        fprintf(stdout, "on day %d the best player is number %d \n", c + 1, brow +1);
    }
    fclose(fpin);
    return 0;
}

###################  encoding   ########################

# define NMAX 20
int main(){
    FILE *fpin = fopen("input.txt","r"), *fpout = fopen("output.txt", "w"), *fpdict = fopen("dictionary.txt","r");
    char c, *codes[NMAX], *words[NMAX], word1[NMAX], word2[NMAX], extra[NMAX];
    int i, n, j;
    boolean found;
    //creating the coding
    fscanf(fpdict,"%d", &n);
    for (i = 0; i < n; i++){
        fscanf(fpdict, "%s %s\n", word1,word2);
        codes[i] = strdup( word1);
        words[i] = strdup(word2);
    }
    //reading from the inputfile
    while(fscanf(fpin,"%s%c",word1,&c) == 2){
        found = False;
        for (i = 0; i< n && !found; i++) {
            if (strlen(word1) >= strlen(words[i])){
                for (j = 0; j <= strlen(word1) - strlen(words[i]) && !found; j++){
                    strcpy(word2, (word1 + j)); word2[strlen(words[i])] = '\0';
                    if (strcmp(word2, words[i]) == 0) found = True;
                }
            }
        }
        if (found) {
            if (strlen(word2)+ (j - 1) < strlen(word1)){
                strcpy(extra ,word1 + (j-1) + strlen(word2));
                strcpy((word1 + j-1), codes[i - 1]);
                strcpy(word1 + (j-1) + strlen(word2) +2, extra);
            }
            else strcpy((word1 + j-1), codes[i - 1]);
        }

        fprintf(fpout, "%s%c",word1,c);
    }
    return 0;
}

###############   MATRIX TURNER   ######################

void mover(int mat[][NMAX], int nr, int nc, int index, int adrow, int adcol);
int main (){
    FILE *fpin = fopen("input.txt", "r");
    int c, r, nr, nc, mat[NMAX][NMAX], index, locat, ndir, dub[NMAX][NMAX];
    char sel[NMAX], dir[NMAX];
    fscanf(fpin, "%d %d", &nr, &nc);
    for (r = 0; r < nr; r++){
        for (c = 0; c< nc; c++){
            fscanf(fpin,"%d", &mat[r][c]);
        }
    }
    fscanf(stdin, "%s %d %s %d", sel,&index,dir,&locat);
    if (strcmp(dir,"down")== 0 || strcmp(dir,"right") == 0)
        ndir = 1;
    else if (strcmp(dir,"up")== 0 || strcmp(dir,"left") == 0)
        ndir = -1;
    else fprintf(stderr, "wrong input");
    if (strcmp(sel,"column")== 0){
        mover(mat, nr, nc, index, 0, ndir*locat);
    }
    else if (strcmp(sel,"row")== 0)
        mover(mat, nr, nc, index, ndir*locat, 0);
    else fprintf(stderr, "wrong input");
    return 0;
}

void mover(int mat[][NMAX], int nr, int nc, int index, int adrow, int adcol){
    int dub[NMAX][NMAX],r, c;
    //transforming into dub
        for (r = 0; r < nr; r ++){
            for (c = 0; c < nc; c++){
                if ( (c == index && adrow == 0) || (r == index && adcol == 0))
                    dub[(nr + r+ adcol%nr )%nr][(nc + c+ adrow%nc )%nc] = mat[r][c];
                else
                    dub[r][c] = mat[r][c];
            }
        }
    //printing the dub
    for (r = 0; r < nr; r ++){
        for (c = 0; c < nc; c++){
            fprintf(stdout, "%d ", dub[r][c]);
        }
        fprintf(stdout,"\n");
    }
}


#####################   DESTINATIZIONE MARE  ####################

#define LEN 30
#define CHECKER 1
#define EXTRA 0
typedef struct {
    char code[LEN];
    char dep[LEN];
    char dest[LEN];
    int day;
    int delay;
} trip;
void interval(trip routes[], int n);
void depart(trip routes[], int n);
void destination(trip routes[], int n);
void laters(trip routes[],int n);
void delays(trip routes[], int n);
int main() {
#if CHECKER
    FILE *fpin = fopen("input.txt", "r");
    int n, i, month, day;
    typedef enum {
        Interval, Depart, Destination, Laters, AllDelays, End
    } command;
    command action;
    fscanf(fpin, "%d", &n);
    trip routes[n];
    for (i = 0; i < n; i++) {
        fscanf(fpin, "%s %s %s %*d/%d/%d %*s %*s %d", routes[i].code, routes[i].dep, routes[i].dest, &month, &day,
               &(routes[i].delay));
        routes[i].day = month * 30 + day;
    }
    while(fscanf(stdin, "%d", &action) == 1){
        if (action < 0 || action > 6) return -1;
        switch (action){
            case 0: interval(routes, n); break;
            case 1: depart(routes, n); break;
            case 2: destination(routes,n); break;
            case 3: laters(routes, n); break;
            case 4: delays(routes, n); break;
            case 5: return 0;
        }
    }
#endif CHECKER
}
void interval(trip routes[], int n){
    int month1,month2, day1, day2, i;
    fprintf(stdout,"the days please");
    fscanf(stdin, "%d/%d to %d/%d", &month1,&day1, &month2, &day2);
    day1 = month1*30 + day1;
    day2 = month2*30 + day2;
    for (i = 0; i < n; i++){
        if (routes[i].day >= day1 && routes[i].day <= day2){
            fprintf(stdout, "%s %s %s \n", routes[i].code, routes[i].dep, routes[i].dest);
        }
    }
}
void depart(trip routes[], int n){
    char city[LEN];
    int i ;
    fprintf(stdout,"the departure city please");
    fscanf(stdin, "%s", city);
    for (i = 0; i < n; i++){
        if (strcmp(routes[i].dep, city) == 0){
            fprintf(stdout, "%s %s %s\n", routes[i].code, routes[i].dep, routes[i].dest);
        }
    }
}
void destination(trip routes[], int n){
    char city[LEN];
    int i ;
    fprintf(stdout,"the destination please");
    fscanf(stdin, "%s", city);
    for (i = 0; i < n; i++){
        if (strcmp(routes[i].dest, city) == 0){
            fprintf(stdout, "%s %s %s\n", routes[i].code, routes[i].dep, routes[i].dest);
        }
    }
}
void laters(trip routes[], int n){
    int month1,month2, day1, day2, i;
    fprintf(stdout,"the days please");
    fscanf(stdin, "%d/%d to %d/%d", &month1,&day1, &month2, &day2);
    day1 = month1*30 + day1;
    day2 = month2*30 + day2;
    for (i = 0; i < n; i++){
        if (routes[i].delay != 0 && (routes[i].day >= day1 && routes[i].day <= day2)){
            fprintf(stdout, "%s %s %s\n", routes[i].code, routes[i].dep, routes[i].dest);
        }
    }
}
void delays(trip routes[], int n){
    char code[LEN];
    int i, sum = 0;
    fprintf(stdout,"the code please");
    fscanf(stdin, "%s", code);
    for (i = 0; i < n; i++){
        if ((strcmp(routes[i].code, code)==0) && routes[i].delay != 0){
            sum += routes[i].delay;
        }
    }
    fprintf(stdout, "%s %d\n", code, sum);
}

