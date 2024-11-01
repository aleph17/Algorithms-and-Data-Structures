##############    WORDS    ################

#define LEN 20
#define CHECK 1
char* lowered(char word[]);
int main() {
    char paroli[LEN][6], word[26], *poi;
    int n, i, c, p;
    FILE *fpin = fopen("dictionary.txt", "r");
    fscanf(fpin, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(fpin, "%s", paroli[i]);
    }
#if CHECK
    fpin = fopen("input.txt", "r");
    for (i = 0; i < n; i++){
        fprintf(stdout, "\n printing for %s\n", paroli[i]);
        c = 0; p = 0;
        paroli[i][0] = tolower(paroli[i][0]);
        while(fscanf(fpin,"%s", word) != EOF) {
            c += 1;
            word[0] = tolower(word[0]);
            if (strstr(word, paroli[i]) != NULL && p <= 10) {
                fprintf(stdout, "%s (position %d)\n", word, c);
                p++;
            }
        }
        rewind(fpin);
    }
}

#endif CHECK


##################   BLACK RECTANGLES  ##################
#define NMAX 50
typedef struct{
    int pr;
    int pc;
    int h;
    int w;
} recs;
void readMatrix(int mat[][NMAX], int *nr, int *nc);
int isBlack(int mat[][NMAX], int r, int c);
void parametrize(int mat[][NMAX], int nb, recs blacks[]);

int main(){
    int nr, nc, r, c, mat[NMAX][NMAX], summer, nb = 0, i;
    recs blacks[250];
    readMatrix( mat, &nr, &nc);
    // registering the rectangles
    for (r = 0; r< nr; r++){
        for(c = 0; c < nc; c++){
            if (isBlack(mat, r, c)){
                blacks[nb].pr = r;
                blacks[nb].pc = c;
                blacks[nb].h = 1;
                blacks[nb].w = 1;
                nb++;
            }
        }
    }
    parametrize(mat, nb, blacks);
    for (i = 0; i < nb; i++){
        fprintf(stdout, "%d %d -- %d %d\n", blacks[i].pr, blacks[i].pc, blacks[i].w, blacks[i].h);
    }
}

void readMatrix(int mat[][NMAX], int *nr, int *nc){
    int r,c;
    FILE *fpin = fopen("input.txt", "r");
    fscanf(fpin,"%d %d", nr, nc);
    for (r = 0; r< *nr; r++){
        for(c = 0; c < *nc; c++){
            fscanf(fpin, "%d", &mat[r][c]);
        }
    }
}

int isBlack(int mat[][NMAX], int r, int c){
    int summer = 0;
    if(r > 0 && c > 0) summer = mat[r-1][c] + mat[r][c-1];
    else{
        if(r>c) summer = mat[r-1][c];
        else if (r<c) summer = mat[r][c-1];
    }
    if(summer == 0 && mat[r][c] == 1) return 1;
    else return 0;
}

void parametrize(int mat[][NMAX], int nb, recs blacks[]){
    int i,c,r;
    for (i = 0; i < nb; i++){
        //row wise
        c = blacks[i].pc;
        while(mat[blacks[i].pr][++c] == 1){
            blacks[i].w++;
        }
        //column wise
        r = blacks[i].pr;
        while(mat[++r][blacks[i].pc] == 1){
            blacks[i].h++;
        }
    }
}

###################   SELECTION SORT   ###################

#define NMAX 100
int main(){
    FILE *fpin = fopen("input.txt", "r");
    int i, nr, nc, j, c, r, min, temp, outer, inner, swap;
    fscanf(fpin, "%d", &nr);
    int mat[nr][NMAX];
    for (i = 0; i < nr; i++){
        fscanf(fpin, "%d", &nc);
        for (j = 0; j < nc; j++)
          fscanf(fpin, "%d", &mat[i][j]);
    }
    // selection sort
    for (r = 0; r < nr; r++){
        swap = 0
        for(i = 0; i < nc - 1; i++){
            min = i;
            for (j = i+1; j< nc; j++){
                if (mat[r][min]> mat[r][j]) min = j;
            }
            printf("%d ", j - i - 1);
            if(min ! = i){
              temp = mat[r][i];
              mat[r][i] = mat[r][min];
              mat[r][min] = temp;
              swap++}
        }
        fprintf(stdout, "-- %d %d \n", i, swap);
    }
    for (i = 0; i < nr; i++){
        for (j = 0; j < nc; j++)
            fprintf(stdout, "%d", mat[i][j]);
        fprintf(stdout, "\n");
    }
    return 0;
}

###################   INSERTION  SORT   ####################

#define NMAX 100
int main(){
    FILE *fpin = fopen("input.txt", "r");
    int i, nr, nc, j, c, r, min, temp, outer, inner, swap;
    fscanf(fpin, "%d", &nr);
    int mat[nr][NMAX];
    for (i = 0; i < nr; i++){
        fscanf(fpin, "%d", &nc);
        for (j = 0; j < nc; j++)
          fscanf(fpin, "%d", &mat[i][j]);
    }
    // insertion sort
    for (r = 0; r < nr; r++){
        swap = 0; outer = 0;
        for (i = 1; i< nc; i++){
            outer++; inner = 0;
            for(j = i; j>0; j--){
                inner++;
                if(mat[r][j-1] > mat[r][j]){
                    temp = mat[r][j-1];
                    mat[r][j-1] = mat[r][j];
                    mat[r][j] = temp;
                    swap++;
                }
            }
            printf("%d ", inner);
        }
        printf(" -- %d %d\n", outer, swap);
    }
    for (i = 0; i < nr; i++){
        for (j = 0; j < nc; j++)
            fprintf(stdout, "%d", mat[i][j]);
        fprintf(stdout, "\n");
    }
    return 0;
}


######################   BIG ENDIAN   ##################

void printEncoding(void *p, int size, int bigEndian);
void convert(int c);

int main(){
    float af = 1.2;
    double ad = 1.2;
    int test = 1, i, j, num[8], bigEndian = 0;
    char* fntest;
    fntest = (char *) &test;
    printf("%d\n%d\n",  sizeof(af), sizeof(ad));
    if (*fntest == 0) bigEndian = 1;
    fscanf(stdin, "%f\n", &af);
    printEncoding((void *) &af, sizeof(af), bigEndian);
    printf("\n");
//    printEncoding((void *) &ad, sizeof(ad), bigEndian);
    return 0;
}

void printEncoding(void *p, int size, int bigEndian){
    unsigned char *c;
    int i;
    for (i = 0; i < size; i++){
        if (bigEndian == 1){
            c = (unsigned char*) (p+i);
            convert(*c);
        }
        else {
            c = (unsigned char*)((p + size - 1) -i);
            convert(*c);
        }
    }
}
void convert(int c){
    int i, num[8];
    for (i = 7; i >= 0; i--){
        num[i] = c%2;
        c = c/2;
    }
    for (i = 0; i < 8; i++){
        printf("%d", num[i]);
    }
}

#####################  DELETED STRING ##############

# define NMAX 15
int main(){
    char str[NMAX] = "ThisIsAString";
    int pos[NMAX] = {7, 4, 2, 0, 11, -1}, i, j;
    for (i = 0; pos[i] != -1; i++){
        for (j = pos[i]; str[j] !='\0'; j++) str[j] = str[j+1];
        for(j = i + 1; pos[j] != -1; j++){
            if (pos[j] > pos[i]) pos[j]--;
        }
    }
    puts(str);
}

###################  STRING VOWEL  ##############

int main(){
    char str[NMAX] = "forExample";
    int n = 4, i, j, vowel;
    for(i = 0; str[i + n -1] != '\0'; i++){
        vowel = 0;
        for(j = i; j < i+n; j++){
            if (tolower(str[j]) == 'a' || tolower(str[j]) == 'e' || tolower(str[j]) == 'i'|| tolower(str[j]) == 'o' || tolower(str[j]) == 'u'){
                vowel++;
            }
        }
        if (vowel == 2){
            for(j = i; j < i+n; j++) printf("%c", str[j]);
            printf("\n");
        }
    }
}

############### CARTESIAN SUM ###########

# define NMAX 100
int main(){
    char str[NMAX] = "forExample";
    int n = 4, i, j, p = 0, v1[3] = {2,1,3}, v2[5] = {4,5,3,6}, d1 = 3, d2 = 4;
    typedef struct{
        int x;
        int y;
    } cartesian;
    cartesian prod[NMAX], x;
    for (i = 0; i < d1; i++){
        for(j = 0; j < d2; j++){
            prod[p].x = v1[i];
            prod[p++].y = v2[j];
        }
    } // ready | p is the number of elements
    for (i = 1; i < p; i++){
        x = prod[i];
        j = i;
        while((x.x + x.y) < (prod[j - 1].x + prod[j - 1].y) && j>0){
            prod[j] = prod[j - 1];
            j--;
        }
        prod[j] = x;
    }
    //sorted
    for (i = 0; i< p; i++){
        fprintf(stdout, "(%d, %d) ", prod[i].x, prod[i].y);
    }
}

###############  characters on a matrix  ###########

# define nr 4
# define nc 5
int main(){
    char A[nr][nc] = {{'x', 'c', 'e', 'c', 'a'},{'w', 'a', 'e', 'c', 'q'},{'d', 't', 'p', 'a', 'z'},{'p', 'c', 'a', 't', 'f'}}, str[4] = "cat";
    int r, c, i, len = strlen(str), cnt = 0, ok;
    for (r = 0; r < nr; r++){
        for(c = 0; c < nc; c++){
            ok  = 1;
            for (i = 0; i < len && ok && (i+len)<= nc; i++){
                if(A[r][c+i] != str[i]) ok = 0;
            }
            if (ok) cnt++;
            ok = 1;
            for (i = 0; i < len && ok && (i + len)<= nr; i++){
                if(A[r + i][c] != str[i]) ok = 0;
            }
            if (ok) cnt++;
        }
    }
    printf("%d", cnt);
}

#################  FRAMES  ####################

# define NMAX 10
int main(){
    int A[NMAX][NMAX] = {{1,2,3,4,5},
                     {6,7,8,9,0},
                     {1,2,3,4,5},
                     {6,7,8,9,0},
                     {1,1,1,1,1}};
    int v[10],ar,ac, i, N = 5, r = 0, c = 0, size = N;
    for( i = 0; i< 10; i++) v[i] = 0;
    for(r = 0, c= 0; c < N/2 + 1 && r < N/2 + 1; r++, c++){
        for(ar = 0; ar < size; ar++){
            for(ac = 0; ac < size; ac++){
                v[r] += A[r+ar][c+ac];
            }
        }
        size -= 2;
    }
    for(i = 0; i < N; i++) printf("%d ", v[i]);
    return r;
}

################  CHESS PLAYERS  ############

#define MAXN 10
void displranking(int mat[MAXN][MAXN], int nr, int nc);
int main(){
    int nr = 4, nc = 3, mat[MAXN][MAXN] = {{3,1,0},
                                           {0,1,1},
                                           {1,1,1},
                                           {1,1,3}};
    displranking(mat, nr, nc);
    return 1;
}
void displranking(int mat[MAXN][MAXN], int nr, int nc){
    int r, c, max = 0, pr, pc;
    for (r = 0; r < nr; r++){
        for (c = 1;c < nc; c++){
            mat[r][c] += mat[r][c-1];
        }
    }
    for(c= 0; c < nc; c++){
        max = 0;
        for(r = 0; r< nr; r++) {
            if (mat[r][c] > max) {pr = r; max = mat[r][c];}
        }
        printf("day %d - player %d\n", c, pr);
    }
}

###################  AREA TOTALE  ################

int areaTotale(FILE *fp);

int main(){
    FILE* fp = fopen("input.txt", "r");
    return areaTotale(fp);
}

int areaTotale(FILE *fp){
    int mat[10][10], r,c, r0, c0, r1, c1, area= 0;
    for(r = 0; r < 10; r++) for(c = 0; c < 10; c++) mat[r][c] = 0;
    while(fscanf(fp, "%d %d %d %d", &r0, &c0, &r1, &c1) == 4){
        for(r = r0; r < r1; r++){
            for(c = c0; c < c1; c++){
                mat[r][c] = 1;
            }
        }
    }
    for(r = 0; r < 10; r++) for(c = 0; c < 10; c++) area += mat[r][c];
    return area;
}


################## STRINGS DONT CARE  ##############

int main(){
    char* s = "ci";
    char q[] = "hellofaurhfef;sodijfoiasdjfpiadsjfpoajgpjjknkjxvnxc";
    s = q;
    printf("%s", s);
}

###################   FIND THE PATH   ##################

int findpath(int mat[][11], int nr, int nc);
int main(){
    char mat[5][11] = {{'-','-', '*', '-', '*', '-', '*', '*', '*', '*', '-'},
                       {'*','*', '-', '*', '-', '*', '*', '*', '-', '-', '*'},
                       {'*','*','*','*','*','*','-','*','*','*','*'},
                       {'-','-', '*','-', '*','-', '*','-', '*','-', '*'},
                       {'*','*', '-', '*', '-', '*', '-', '*', '-', '*', '-'}
    };
    int nr = 5, nc = 11;
    printf("%d", findpath(mat, nr, nc));
}
int findpath(int mat[][11], int nr, int nc){
    int r, c, r0, found = 0, rc, start;
    for(r = 0; r < nr && !found; r++){
        if (mat[r][c] == '-'){
            found = 1;
            r0 = r;
            start = r;
            for( c = 1; c < nc && found; c++){
                for(found = 0, rc = r0-1; rc<= r0+ 1 && !found; rc++){
                    if(rc>=0 && rc<nc && mat[rc][c] == '-') {
                        found = 1;
                        r0 = rc;
                    }
                }
            }
        }
    }
    if (!found) return -1;
    else return start;
}

#################  EATING FROM BOTH ENDS  #############

void reverseString(char* s){
    int i, j;
    char temp;
    j = strlen(s) -1;
    i = 0;
    while(i<j){
        if(s[i]!= s[j]){
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        i++;
        j--;
    }
}

############# ODD SUBSEQUENCE  ###############
int Oddsubsequence(int v[], int n){
    int i,l = 0, lmax =0, res = -1;
    for(i = 0; i < n; i++){
        if(v[i]%2 ==0 || i == n-1){
            if(l > lmax){
                lmax = l;
                res = i - l;
            }
            l = 0;
        }
        else l++;
    }
    return res;
}

########### enum type #########
    enum lights {green, yellow, blue};
    enum lights a = blue;



