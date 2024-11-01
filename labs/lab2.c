
################### DRAW A GRAPH  ####################

int main(){
    int a =1,b = 2,c  =3,x,y, x0 = -20,xn = 20,n = 20,i,j,step,y0 = -20 ,yn = 20;
    FILE *fpout = fopen("output.txt", "w");
    step = (xn - x0)/n;
    for (i = 0; i <= n; i++){
        x = x0 + i*step;
        y = a*x*x + b*x + c;
        if (y>=y0 && y<=yn){
            for (j = round(y-y0); j>0; j--) fprintf(fpout, " ");
            fprintf(fpout, "*");
        }
        fprintf(fpout, "\n");
    }
    fclose(fpout);
}

###################  21 SYMBOLS ONLY    ################

FILE *fpin = fopen("source.txt","r"), *fpout = fopen("output.txt", "w");
    const int STRLEN = 21;
    int l = 0;
    char word[STRLEN];
    while(fscanf(fpin,"%s", word) == 1){
        if(l+1+strlen(word)>STRLEN){
            fprintf(fpout,"\n%s", word);
            l = strlen(word);
        }
        else{
            if(l!=0){
                fprintf(fpout," %s",word);
                l += 1+strlen(word);
            }
            else{
                fprintf(fpout,"%s",word);
                l += strlen(word);
            }
        }
    }
    fclose(fpin);fclose(fpout);
    return 0;

################## ORDERED NAMES  ######################

FILE *fpin = fopen("input.txt","r"), *fpout = fopen("output.txt", "w");
    const int MAXR = 50;
    int ordered = 1;
    char line0[MAXR], line1[MAXR];
    fgets(line0, MAXR, fpin);
    while(fgets(line1, MAXR, fpin) != NULL && ordered){
        if(strcmp(line0,line1) > 0) ordered = 0;
        strcpy(line0,line1);
    }
    fclose(fpin);fclose(fpout);
    return ordered;

###################  SCHOLARsHIPS  ####################

int main(){
    FILE *fpin = fopen("input.txt","r"), *fpout = fopen("output.txt", "w");
    float sum, grade, avg;
    int c;
    char name[51];
    while(fgets(name, 51, fpin)!= NULL){
        sum = 0;
        c = 0;
        while(fscanf(fpin,"%f", &grade)== 1){
            sum += grade;
            c++;
        }
        avg = sum/c;
        if (avg > 87.0) fprintf(fpout, "%s", name);
    }
    fclose(fpin);fclose(fpout);
    return 0;
}

###################   COORDINATES      #####################

FILE *fpin = fopen("input.txt","r"), *fpout = fopen("output.txt", "w");
    float x,y;
    int i,j;
    for(i = -1; i <=1 ; i += 2){
        for(j = -1; j <=1 ; j += 2) {
            fprintf(fpout,"quadrant %d %d\n", i, j);
            while (fscanf(fpin, "(%f,%f)\n", &x, &y) == 2) {
                if ((x*i> 0.0 || (x==0.0 && i>0)) && ((y*j >0.0) || (y == 0.0 && j>0))){
                    fprintf(fpout, "%f %f\n", x, y);
                }
            }
            rewind(fpin);
            fprintf(fpout,"\n");
        }
    }

################### INTERSECTION  ######################

int main(){
    int i,j,ni,data0[20], data1[20], found = 0;
    for (i=ni=0; i <20; i++){
        found = 0;
        for(j = 0; j < 20 && (!found); j++) if(data0[i]==data1[j]) found = 1;
        if (found) data0[ni++] = data0[i];
    }
    for (i= 0; i<ni; i++) printf("%d", data0[i])
}

################### BINARY SEARCH ####################

int BinarySearch(int list[], int N, int k){
    int l,r,m, found = 0;
    l = 0;
    r = N-1;
    while(l <= r){
        m = (l + r)/2;
        if(k == list[m]) return m;
        if (list[m] < k) l = m+1;
        else if (k < list[m]) r = m -1;
    }
    return -1;
}

#################### CONNECTVITY QUICK FIND  #############

#define N 1000
void main(){
    int p,q,id[N], j,i, an;
    for (i = 0; i < N; i++) id[i] = i;
    while(scanf("%d %d", &p,&q) == 2){
        if (id[p] == id[q]) printf("already connected");
        else{
            printf("were not connected. not anymore!");
            for (i = 0, an = id[p]; i < N; i++) if (id[i] == an) id[i] = id[q];
        }
    }
}

##################  CONNECTIVITY QUICK UNION  #################

#define N 1000
void main(){
    int hp,hq, id[N], p,q, i;
    for (i = 0; i<N; i++) id[i] = i;
    printf("number p and q: ");
    while(scanf("%d %d", &p,&q) == 2){
        for(hp = p; hp!=id[hp]; hp = id[hp]);
        for(hq = q; hq!=id[hq]; hq = id[hq]);
        if(hp == hq) printf("they are already connected");
        else id[hp] = hq;
    }
}

################### QUICK UNION OPTIMIZATION ################

#define N 1000
void main(){
    int hp,hq, id[N], size[N], p,q, i;
    for (i = 0; i<N; i++) {id[i] = i; size[i] = 1}
    printf("number p and q: ");
    while(scanf("%d %d", &p,&q) == 2){
        for(hp = p; hp!=id[hp]; hp = id[hp]);
        for(hq = q; hq!=id[hq]; hq = id[hq]);
        if(hp == hq) printf("they are already connected");
        else{
            if(size[hp] <= size[hq]){
            id[hp] = hq; size[hq]+=size[hp];}
            else{ id[hq] = hp; size[hp] += size[hq];}
        }
    }
}

################ calculation  ###############

int main(){
    FILE *fpin = fopen("input.txt","r"), *fpout = fopen("output.txt", "w");
    int n1, n2, n3, disc = 0, max, min;
    fscanf(fpin,"%d",&n1);
    fscanf(fpin,"%d",&n2);
    if (n1 > n2){ max = n1; min = n2;}
    else { max = n2; min = n1;}
    while(fscanf(fpin,"%d",&n3) == 1){
        if( (n3 == n1 + n2) ||(n3 == n1 - n2) || (n3 == n1 * n2)|| ((n3 *n2 == n1) && n2 != 0)){
            if (n3 > max) max = n3;
            if (n3 < min) min = n3;
        }
        else disc++;
        n1 = n2;
        n2 = n3;
    }
    printf("%d  max %d  min  %d", disc, max, min);
    return 1;
}

############# MONTH TO NUMBER USING ARRAYS  ####################

typedef struct{
    int num;
    char name[10];
} tab;
int ReadTheTable( tab given[]);
int MonthToNumber(char month[], tab given[]);
int main(){
    tab table[12];
    char month[10];
    int n;
    if(ReadTheTable(table) != 0){
        do{
            printf("the month: "); scanf("%s", month);
            n = MonthToNumber(month, table);
            printf("the number is %d",n);
        }while(n>0);
    }
    return 1;
}
int ReadTheTable( tab given[]){
    FILE *fpin = fopen("input","r");
    int i;
    for (i = 0; i <12; i++){
        fscanf(fpin,"%d%s", &given[i].num, given[i].name);
    }
    fclose(fpin);
    return 1;
}
int MonthToNumber(char month[], tab given[]){
    int i;
    for (i = 0;i<12;i++){
        if (strcmp(given[i].name, month)==0){
            return given[i].num;
        }
    }
    return -1;
}

######################## COMMANDING  #####################

typedef enum{c_seek,c_print,c_end,c_err} coms;
#define MAX 51

int ReadCommand();
int main(){
    coms command;
    int toContinue = 1;
    char line[MAX];
    while(toContinue){
        command = ReadCommand();
        fgets(line, MAX, stdin);
        switch(command){
            case c_seek:printf("you got saken - %s", line); break;
            case c_print: printf("you got printed - %s", line); break;
            case c_end: printf("ok we end - %s", line); toContinue = 0; break;
            case c_err: printf("oops, error - %s", line); break;
            default: printf("something is wrong, let me check it out"); break;
        }
    }
}
int ReadCommand(){
    char scanned[MAX];
    coms c;
    char table[4][10] = {"seek", "print","end","error"};
    printf("the command please"); scanf("%s", scanned);
    for (c = c_seek; c< c_err;c++){
        if (strcmp(scanned,table[c])==0){
            return c;
        }
    }
    return c_err;
}
void StrLower( char s[]){
    int i, l = strlen(s);
    for (i = 0; i<l;i++){
        s[i] = tolower(s[i]);
    }
}

######################## palindrome ################

int palindrome(char word[]){
    int i, n = strlen(word);
    boolean pal = True;
    for (i = 0; i < n/2 && pal; i++){
        if (toupper(word[i]) == toupper(word[n - 1 - i])) pal = False;
    }
    return pal;
}

####################  Gomoku  ##############

boolean check(char table[][19], int r, int c, char s);
void AddPrint( char table[][19], int r, int c, char s);
boolean inrange( int r, int c);
int main(){
    char table[19][19];
    int r,c, i, j;
    boolean gameon = True, rightmove, won;
    for (i = 0; i <19; i++){
        for (j = 0; j < 19; j ++) table[i][j] = '.';
    }
    for (i = 0; i <19; i++) {
        for (j = 0; j < 19; j++) printf("%2c", table[i][j] = '.');
        printf("\n");
    }
    while(gameon){
        rightmove = False;
        while(!rightmove){
            printf("white to move (R/C)");
            if ((scanf("%d%d", &r, &c) == 2) && (table[r-1][c-1] == '.') && (inrange(r,c))) rightmove = True;
        }
        AddPrint(table, r,c, 'W');
        won = check(table, r,c, 'W');
        if (won) {printf("white won"); gameon = False; break;}
        rightmove = False;
        while(!rightmove){
            printf("black to move (R/C)");
            if ((scanf("%d%d", &r, &c) == 2) && (table[r-1][c-1] == '.') && (inrange(r,c))) rightmove = True;;
        }
        AddPrint(table, r,c, 'B');
        won = check(table, r,c, 'B');
        if (won) {printf("black won"); gameon = False; break;}
    }
    return 1;
}
boolean check(char table[][19], int r, int c, char s){
    boolean result = False, sequ = False;
    r--; c--;
    int i, j, cnt;
    // checking by row
    cnt = 0;
    sequ = False;
    for (i = 0; i < 9; i++){
        if ((c - 4 + i)> -1 && (c -4 +  i) < 19){
            if(table[r][c-4 + i] == s) sequ = True;
            else sequ = False;
            if (sequ) cnt++;
            else cnt = 0;
        }
        if (cnt == 5) return True;
    }
    //checking by column
    cnt = 0;
    sequ = False;
    for (i = 0; i < 9; i++){
        if ((r - 4 + i)> -1 && (r -4 +  i) < 19){
            if(table[r-4 + i][c] == s) sequ = True;
            else sequ = False;
            if (sequ) cnt++;
            else cnt = 0;
        }
        if (cnt == 5) return True;
    }
    //checking by diagonal upper left to lower right
    cnt = 0;
    sequ = False;
    for (i = 0; i < 9; i++){
        if ((r - 4 + i)> -1 && (r -4 +  i) < 19 && (c - 4 + i)> -1 && (c -4 +  i) < 19){
            if(table[r-4 + i][c-4 + i] == s) sequ = True;
            else sequ = False;
            if (sequ) cnt++;
            else cnt = 0;
        }
        if (cnt == 5) return True;
    }
    //checking by diagonal lower left to upper right
    cnt = 0;
    sequ = False;
    for (i = 0; i < 9; i++){
        if ((r + 4 - i)> -1 && (r + 4 -  i) < 19 && (c - 4 + i)> -1 && (c -4 +  i) < 19){
            if(table[r + 4 - i][c -4 + i] == s) sequ = True;
            else sequ = False;
            if (sequ) cnt++;
            else cnt = 0;
        }
        if (cnt == 5) return True;
    }
    return False;
}
void AddPrint( char table[][19], int r, int c, char s){
    int i, j;
    table[r - 1][c - 1] = s;
    for (i = 0; i < 19; i++) {
         for (j = 0; j < 19; j++) printf("%2c",table[i][j]);
         printf("\n");
         }
}
boolean inrange( int r, int c){
    if( r>0 && r<20 && c>0 && c < 20) return True;
    else return False;
}

######################### PARABOLA WITH ARRAY  #######################

int main() {
    int NC = 20, NR = 80, i, j, a = 1, b = 1, c = 0, xmin = 0, xmax = 80, ymin = 0, ymax = 20, xstep, ystep, y, x, p;
    char table[80][20];
    for (i = 0; i < NR; i++)
        for (j = 0; j < NC; j++) table[i][j] = ' ';
    xstep = (xmax- xmin)/NR;
    ystep = (ymax - ymin)/NC;
    for (i = 0; i < NC; i ++){
        x = xmin + i*xstep;
        y = a*x*x + b*x + c;
        if (y >= ymin && y <= ymax){
            p = (ymax - y)/ystep;
            table[p][i] = '*';
        }
    }
    for (i = 0; i < NR; i++){
        for (j = 0; j < NC; j++) printf("%c", table[i][j]);
        printf("\n");}
    return 1;
}

################### SYMMETRIC PRINTING  #################

int main() {
    FILE *fpin = fopen("input.txt","r"), *fpout = fopen("output.txt", "w");
    char word[21], line[61] = "";
    int cnt =0, i, end = 0;
    while(!feof(fpin)){
        if (fscanf(fpin, "%s", word) != 1) end = 1;
        if ((cnt + strlen(word) + 1) < 61 && !end){
                cnt += strlen(word) + 1;
                strcat(line, word); strcat(line, " ");
        }
        else{
            for(i = 0; i < (60 - strlen(line))/2; i++) fprintf(fpout," ");
            fprintf(fpout,"%s\n",line);
            cnt = strlen(word) + 1; strcpy(line,word); strcat(line, " ");
        }
    }
    fclose(fpin);fclose(fpout);
    return 1;
}

##################  SELECTION SORT  ####################

int SelectionSort(int A[], int N) {
    int i,j, temp, imin;
    for (i = 0; i< N - 1; i++){
        imin = i;
        for(j = 0; j < N; j ++){
            if (A[j] < A[imin]) imin = j;
        }
        temp = A[imin];
        A[imin] = A[i];
        A[i] = temp;
    }
    return -1;
}

###################  MOTORWAY TOLL  ###############

#define N 25
typedef struct{
    char entry[N];
    char reach[N];
    float toll;
} data;
int main(){
    FILE *fpin = fopen("input.txt","r"), *fpout = fopen("output.txt", "w");
    char start[N], finish[N];
    int i,j, cnt =0;
    float cost = 0;
    data table[N];
    boolean found  = False;
    scanf("%s%s", start, finish);
    for (i = 0;i< N;i++){
        if(!feof(fpin)) fscanf(fpin,"%s%s%f\n",table[i].entry,table[i].reach, &table[i].toll);
    }
    // table is ready, now calculations
    for(i = 0; i< 25; i++){
        if(strcmp(table[i].entry, start)==0 && strcmp(table[i].reach, finish)==0){ cost = table[i].toll; found = True;}
    }
    // indirect access
    if (!found){
            for(i = 0; i< 25 && !found && cnt<4 ; i++){
                if(strcmp(table[i].reach, finish) == 0 && strcmp(table[i].entry, start)== 0) found = True;
                if(strcmp(table[i].entry, start)==0){
                    strcpy(start, table[i].reach);
                    cost += table[i].toll;
                    cnt++;
                }
            }
    }
    if (found){
        printf("%f", cost);
        return 1;
    }
    //strcmp(start, finish)==0
    fclose(fpin);fclose(fpout);
    return 0;
}
