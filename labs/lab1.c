********** opening ***********
FILE *fp; char line[50];
    char row[20];
    fp = fopen("doc.txt","r");
    while (!feof(fp)){
        fgets(line, 48, fp );
        printf("%s", line);
    }

********** cube volume *********
int main(){
    int result;
    result = cubeVolume(2);
    printf("%d", result);
    return 0;
}
int cubeVolume(int sidelength){
    int volume;
    volume = pow(sidelength, 3);
    return volume;
}
********** determinant **********
float a,b,c,delta, x0,x1;
    printf("numbers a,b,c of the 2nd order equation");
    scanf("%f%f%f", &a,&b,&c);
    delta = b*b - 4*a*c;
    if (delta == 0){
        x0 = -b/2*a;
        printf("the two solutions are %f and %f", x0, x0);
        return 0;
    }
    else if( delta > 0){
        x0 = (-b + sqrt(delta))/2*a;
        x1 = (-b - sqrt(delta))/2*a;
        printf("the two solutions are %f and %f", x0, x1);
        return 0;
    }
    else if (delta < 0){
        x0 = -b/2*a;
        printf("the two solutions are %f + i*%f and %f - i*%f", x0, (sqrt(-delta)/2*a), x0,(sqrt(-delta)/2*a));
        return 0;
    }
    return 0;

*****************  harmonic series *************

 int n,i;
    float hn = 0.0;
    printf("the number please");
    scanf("%d",&n);
    for (i = 1; i <=n; i ++){
        hn = hn + 1.0/i;
    }
    printf ("well your result is: %f", hn);
    return 0;
     ############### careful about RETURN s ############

***************  binary conversion ***************

void binary(int n){
    int p;
    for (p = 1; 2*p <= n; p = p*2);
    while (p > 0){
        if (p<= n){
            printf("1");
            n = n - p;
        }
        else{
            printf("0");
        }
        p = p/2;
    }
    printf("\n");
}
****************  encode and decode ***********
#define MAX 50
int main() {
    char filename[MAX + 1], ch;
    FILE *fpin, *fpout;
    printf("input:");
    scanf("%s", filename);
    fpin = fopen(filename, "r");
    printf("output:");
    scanf("%s", filename);
    fpout = fopen(filename, "w");
    while(fscanf(fpin,"%c", &ch) ==1){
        if (ch >= '0' && ch <= '9'){
            fprintf(fpout,"%c", '0' + ('9' - ch));
        }
        else if (ch >= 'A' && ch <= 'Z' ){
            fprintf(fpout, "%c", 'a' + ('Z' - ch));
        }
        else if (ch >= 'a' && ch <= 'z'){
            fprintf(fpout, "%c", 'A' + ('z' - ch));
        }
    }
    fclose(fpin); fclose(fpout);
    return 0;
}

************************ UPPERING *********************

#define MAX 5
int main(){
    char word[MAX + 1]; int i;
    gets(word);
    for (i = 0; i < MAX; i ++){
        word[i] = toupper(word[i]);
    }
    printf("%s", word);
}

********************* advanced rectangle ****************

void rectangle(int b, int h){
    int i,j;
    for (i = 1;i <= b; i++){
        for (j = 1; j<=h;j++){
            if (i != 1 && i != b && j != 1 && j != h){
                printf(" ");
            }
            else printf("*");
        }
        printf("\n");
    }
}

**************** text formatter ***************

void formatting( char nin[], char nout[], int lmax){
    const int STRLN = 21;
    FILE *fpin = fopen(nin, "r");
    FILE *fpout = fopen(nout,"w");
    char word[STRLN];
    int l = 0;
    while(fscanf(fpin, "%s",word) == 1){
        if (l+1+strlen(word) > lmax){
            fprintf(fpout, "\n%s", word);
            l = strlen(word);
        }
        else{
            fprintf(fpout, "%s%s", l==0? "":" ",word);
            l += 1 + strlen(word);
        }
    }
    fclose(fpin); fclose(fpout);
}

******************** drawing *******************
int main(){
    float x,x0,xn,y,ymin,ymax,a,b,c;
    int step,n, i,j;
    FILE *fpout;
    step = (xn - x0)/n;
    for (i = 0; i <= n; i++){
        x = x0 + i*step;
        y = a*x*x + b*x + c;
        if (y >= ymin && y <= ymax){
            for (j = round(y - ymin); j > 0 ; j--)
                fprintf(fpout," ");
            fprintf(fpout,"*");
        }
        fprintf(fpout,"\n");
    }
    fclose(fpout);
}

************* monotonous ********************

int main(){
    int monotonous = 1;
    int i;
    float xi,xj;
    printf("x0 ="); scanf("%f", &xi);
    for (i = 1; i <N && monotonous == 1; i++){
        printf("x%d =",i); scanf("%f", &xj);
        if (xi > xj) monotonous = 0;
        xj = xi;
    }
    printf("%d", monotonous);
}

*************** order verification ***************

int verifyOrder(FILE *fp){
    const int MAX = 70;
    char row0[MAX + 1], row1[MAX + 1];
    fgets(row0, MAX, fp);
    while (fgets(row1, MAX, fp) != NULL){
        if (strcmp(row1,row0)< 0) return 0;
        strcpy(row0, row1);
    }
    return 1;
}

************ temprature verification ************

int verifyTemp(FILE *fp){
    float t0,t1,t2;
    fscanf(fp,"%f%f", &t0,&t1);
    if (abs(t0 - t1) > 5) return 0;
    while(fscanf(fp, "%f", &t2) == 1){
        if (abs(t0 -t2) > 5 || abs(t1 - t2) >5) return 0;
        t0 = t1;
        t1 = t2;
    }
    return 1;
}

************* student grants ************

#define MAX 100
int main (){
    char s0[MAX + 1], s1[MAX + 1];
    int ne,exmin;
    float avmin, average, grade, total;
    FILE *fpin, *fpout;
    printf("input / output"); scanf("%s%s", s0,s1);
    fpin = fopen(s0,"r");fpout = fopen(s1,"w");
    printf("minimum exams / minimum average"); scanf("%d%f", &exmin,&avmin);
    while(fgets(s0, MAX, fpin) != NULL){
        fgets(s1, MAX, fpin);
        ne = 0; average = 0.0;
        while(fscanf(fpin,"%f", &grade) == 1){
            total += grade; ne ++;
        }
        average = total/ne;
        if (average >= avmin && ne >= exmin) fprintf(fpout, "%s%s\n", s0, s1);
    }
    fclose(fpin); fclose(fpout);
}

*************** grouping coordinates ******************

#define MAX 100
void selector(FILE *fpin,FILE *fpout, int sx, int sy);
void sort(){
    FILE *fpin, *fpout;
    char namein[MAX +1], nameout[MAX + 1];
    printf("input/ output");scanf("%s%s", namein, nameout);
    fpin = fopen(namein,"r"); fpout = fopen(nameout,"r");
    selector(fpin, fpout, 1,1); rewind(fpin);
    selector(fpin, fpout, -1,1); rewind(fpin);
    selector(fpin, fpout, -1,-1); rewind(fpin);
    selector(fpin, fpout, 1,-1); rewind(fpin);
    fclose(fpin);fclose(fpout);
}
void selector(FILE *fi,FILE *fo, int sx, int sy){
    float x,y;
    int xOK, yOK;
    while (fscanf(fi,"%f%f", &x,&y) ==2){
        xOK = x*sx > 0 || (x == 0 && sx > 0);
        yOK = y*sy >0 || (y == 0 && sy > 0);
        if (xOK && yOK) fprintf(fo, "%f %f\n",x,y);
    }
}

************* named matrices ***************

int main(){
    int i,j;
    char M[7][10] = {"monday","tuesday","wednesday"};
    for (i = 0; i < 7; i++){
        for (j = 0; j < 10; j++){
            printf("%c ", M[i][j]);
        }
        printf("\n");
    }
}

*********** equality **************

int main(){
    char first, last, word[5 + 1] = "hello";
    first = word[0];
    last = word[strlen(word) - 1];
    printf("%c %c %c %c", first, last, word[0], word[4]);
    first = 'z';
    last = 'z';
    printf("%c %c %c %c", first, last, word[0], word[4]);
}

************** binary ****************

void binary(int n){
    int bit[32],i = 0;
    do{bit[i++] = n%2;
    n = n/2;
    } while(n>0);
    i --;
    while(i>=0){
        printf("%d",bit[i]);
        i += -1;
    }
    printf("\n");
}

************* organizer ******************

#define STRL 20
#define MAX 225
int main(){
    FILE *fpin, *fpout;
    int i,l;
    char word[STRL +1], line[MAX + 1] = "";
    l = 0;
    fpin = fopen("encode.txt","r"); fpout = fopen("encoded.txt", "w");
    while (fscanf(fpin,"%s", word)==1){
        if (l + 1 +strlen(word) <= MAX){
            if (l!=0) {strcat(line," "); l+=1;}
            strcat(line, word);
            l += strlen(word);  // it completely misses start from the beginning
        }
        else{
            for (i = 0; i < (l-MAX)/2; i++) fprintf(fpout,"%s"," ");
            fprintf(fpout,"%s\n", line);
            strcpy(line, word);
            l = strlen(word);
        }
    }

}
####################       GCD      ######################
int main() {
    int p,q;
    printf("numbers");
    scanf("%d%d", &p, &q);
    while (p !=q){
        if (p>q) p = p - q;
        else q = q - p;
    }
    printf("%d  %d", p,q);
    return 0;
}

##################    from b0 to b1   ####################

void conversion(int n, int b);

int main(){
    int b0, b1, p, n, digit, end = 0;
    char c;
    printf("b0 (2 ... 9)"); scanf("%d", &b0);
    printf("b1 (2 ... 9)"), scanf("%d\n", &b1);
    n = 0;
    while(!end){
        scanf("%c", &c);
        if (c == ' ' || c == '\n'){
            conversion(n,b1);
            n = 0;
        }
        else{
            digit = c - '0';
            if (digit >= 0 && digit <= b0 - 1){
                n = b0*n + digit;
            }
            else end = 1;
        }
    }
}
void conversion(int n, int b){
    int p;
    for (p = 1; b*p <= n; p = b*p);
    while (p>0){ // if p = 0 works the loop will never stop
        if(n-p >= 0){
            printf("%d", n/p);
            n = n%p; // it is about division and remainder
        }
        else printf("0");
        p = p/b;
    }
}

############  COMPLIMENT   ############

#define MAX  30
int main(){
    char c, name[MAX + 1];
    FILE *fpin, *fpout;
    printf("input file"); scanf("%s", name);
    fpin = fopen(name,"r");
    printf("output file"); scanf("%s", name);
    fpout = fopen(name,"w");
    while (fscanf(fpin, "%c", &c) == 1){
        if (c >= '0' && c <= '9'){
            c = '0' + ('9' - c);
        }
        else if (c >= 'a' && c <= 'z'){
            c = 'a' + ('z' - c);
        }
        else if (c >= 'A' && c <= 'Z'){
            c = 'A' + ('Z' - c);
        }
        fprintf(fpout, "%c", c);
    }
    fclose(fpin); fclose(fpout);
}

#####################   LAB1 ###########################

int main() {
    FILE *fpin,*fpout;
    char line[50], op;
    float a,b;
    fpin = fopen("operations.txt", "r");
    fpout = fopen("Output.txt", "w");
    do {
        fscanf(fpin, " %c", &op);
        fscanf(fpin, "%f", &a);
        fscanf(fpin, "%f", &b);
        switch (op) {
            case ('+'):
                fprintf(fpout, "%c %.2f\n", op, a + b);
                break;
            case ('-'):
                fprintf(fpout, "%c %.2f\n", op, a - b);
                break;
            case ('*'):
                fprintf(fpout, "%c %.2f\n", op, a * b);
                break;
            case ('/'):
                fprintf(fpout, "%c %.2f\n", op, a / b);
                break;
        }
    } while(!feof(fpin));
}

#################### Euler GCF  ###########################

int main(){
    int a,b, rem, work =1, count = 0;
    while (work){
        printf("numbers A and B (not equal):"); scanf("%d %d", &a,&b);
        rem = 1;
        count += 1;
        while (rem != 0 && a != b){
            rem = a % b;
            a = b;
            b = rem;
        }
        printf("%d\n", a);
        if (count == 10) {
            work = 0;
        }
    }
}

########################  FIBONACCI  #########################

int main(){
    int cont = 1;
    while (cont){
        unsigned int x0 = 0, x1 = 1, x2, N, i;
        scanf("%d", &cont);
        scanf("%d", &N);
        printf("Fibonacci: %d %d ", x0,x1);
        for (i = 0; i < N -2; i++){
            x2 = x0 + x1;
            printf("%d ", x2);
            x0 = x1;
            x1 = x2;
        }
        x0 = 1;
        x1 = 2;
        printf("\nTribonacci: %d %d ", x0, x1);
        for (i = 0; i < N -2; i++){
            x2 = x0 * x1;
            printf("%d ", x2);
            x0 = x1;
            x1 = x2;
        }
    }
}

################### RECTANGLE  #######################

void rec (int w, int h);
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    rec(a,b);
    return 0;
}

void rec(int w, int h){
    int i,j;
    for (i = 0; i <= h-1; i++){
        for (j = 0; j <= w -1; j++) {
            if (i == 0 || i == h - 1) printf("*");
            else{
                if (j == 0 || j == w -1) printf("*");
                else printf(" ");
            }
        }
        printf("\n");
    }
}
