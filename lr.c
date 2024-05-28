#include"lr.h"
#include<stdio.h>
#define YES 1
#define NO 0
#define MAXLINE 1000
#define MAX_ROWS 10
#define MAX_COLS 10

int lab1 (){
     float l, v1, t;
    printf("Vvedite rasoyanie v metrah: ");
    scanf("%f", &l);
    printf("Vvedite skorost v km/chas ");
    scanf("%f", &v1);

    v1=v1*1000/3600;
    t=l/v1;

    printf("%.2f", t);

    return 0;
}

int lab2()
{
    float eps, x, res, adding, i;
    printf("¬ведите eps:");
    scanf("%f", &eps);
    printf("¬ведите x: ");
    scanf("%f", &x);
    adding = 1;
    res = adding;
    printf("adding = %f; ", adding);
    printf("res = %f;\n", res);
    i = 1;
    while(adding > eps)
    {
        float power, powed;
        power = 0;
        powed = 1;
        while(power < i){
            power = power + 1;
            powed = powed * x;
        }
        float fact, j;
        fact = 1;
        j = 0;
        while(j < i){
            fact = fact * (j+1);
            j = j + 1;
        }
        adding = (powed / fact);
        if(adding > eps){
            printf("powed = %f; ", powed);
            printf("fact = %f; ", fact);
            printf("adding = %f; ", adding);
            res = res + adding;
            printf("res = %f;\n", res);
        }
        i = i + 1;
    }
    printf("final result = %f", res);

    return 0;
}

int lab3 ()
{
     int c;
    int cnt;


    cnt = 0;
    while( (c = getchar()) != EOF )
    {
        if(c == ' '){
            cnt = cnt + 1;
        }
        if(c == '.')
        {
            printf("number of words = %d\n", cnt );
            cnt = 0;
        }
    }
    return 0;
}

int lab4 (){
    char prefix[MAXLINE];
    char line[MAXLINE];
    char res[MAXLINE];
    char c;
    int flag = NO;
    int is_good = YES;
    int prefix_pos = 0;
    int pos = 0;
    int start = 0;
    int j;
    int res_pos = 0;
    if (!fgets(prefix, MAXLINE, stdin)) {
        return 1;
    }
    int prefix_len = 0;
    while (prefix[prefix_len] != '\0' && prefix[prefix_len] != '\n') {
        prefix_len++;
    }
    if (prefix[prefix_len] == '\n') {
        prefix[prefix_len] = '\0';
    }
    if (!fgets(line, MAXLINE, stdin)) {
        return 1;
    }
    int line_len = 0;
    while (line[line_len] != '\0' && line[line_len] != '\n') {
        line_len++;
    }
    if (line[line_len] == '\n') {
        line[line_len] = '\0';
    }

    do {
        c = line[pos];

        if (c == ' ' || c == '.' || c == ',' || c == '\0') {
            if (flag == NO) {
                for (j = start; j < pos; j++) {
                    res[res_pos++] = line[j];
                }
                if (c != '\0') {
                    res[res_pos++] = c;
                }
            }

            prefix_pos = 0;
            start = pos + 1;
            flag = NO;
            is_good = YES;
        } else {
            if (is_good == YES && flag == NO) {
                if (line[pos] != prefix[prefix_pos]) {
                    flag = YES;
                } else {
                    if (prefix[prefix_pos + 1] == '\0') {
                        is_good = NO;
                    } else {
                        prefix_pos++;
                    }
                }
            }
        }

        pos++;
    } while (c != '\0');

    res[res_pos] = '\0';
    puts(res);

    return 0;
}

int lab5 (){
  int a[10];
  printf("Enter the array of 10 elements\n");
  for (int i = 0; i < 10; i++) {
    scanf("%i", &a[i]);
  }

  int f = 1;
  for (int i = 0; i < 5; i++) {
    if (a[i] != a[9 - i]) {
      f = 0;
    }
  }
  if (f == 1) {
    printf("Array is a palindrome");
  } else {
    printf("Array is not a palindrome");
  }
  return 0;
}
int lab6 (){
    int n=3, k=4, cnto=0, cntp=0;
    int arr[n][k];
    for (int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            scanf("%d", &arr[i][j]);
            if (arr[i][j]<0){
                cnto+=1;
            }
            if (arr[i][j]>0){
                cntp+=1;
            }
        }
    }
    if (cnto<cntp){
        for (int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                 if(arr[i][j]<0){
                arr[i][j]=0;
                }
            }
        }
    }
    if (cnto>cntp){
       for (int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                    if(arr[i][j]>0){
                arr[i][j]=0;
                }
            }
        }
    }
    for (int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                printf("%d ", arr[i][j]);
            }printf("\n");
        }
return 0;
}
int lab7 (){
    unsigned long N;
    unsigned long mask = 0;
    int count = 0;
    const int bit_s = sizeof(unsigned long) * 8;

    printf("Vvedite desyatichnoe chislo: ");
    scanf("%lu", &N);

    for (int i = 0; i < bit_s; ++i) {

        if (N & (1 << i)) {
            count++;
        } else {

            if (count >= 3) {

                for (int j = 0; j < count; ++j) {
                    mask |= (1 << (i - j - 1));
                }
            }
            count = 0;
        }
    }


    if (count >= 3) {
        for (int j = 0; j < count; ++j) {
            mask |= (1 << (bit_s - j - 1));
        }
    }
    unsigned long result = N&~mask;

    printf("nachalnoe: %lu\n", N);
    printf("izmenennoe: %lu\n", result);

    return 0;
}

int lab1_1 () {
 float l, v1, t;
 printf("Vvedite rasoyanie v metrah: ");
 scanf("%f", &l);
 do
 {
 printf("Vvedite polozhitelnuu skorost v km/chas ");
 printf("V sluchae vvoda nekkorecktnih dannih programma zaprosit povtorny vvod. ");
 scanf("%f", &v1);
 }
 while(v1 <= 0);
 v1=v1*1000/3600;
 t=l/v1;

 printf("%.2f", t);

 return 0; }

 int lab2_1 () {
 float eps, x, res, adding = 1, i = 1;
 res = adding;
 printf("¬ведите eps:");
 scanf("%f", &eps);
 printf("¬ведите x: ");
 scanf("%f", &x);
 printf("adding = %f; ", adding);
 printf("res = %f;\n", res);

 while(adding > eps){
 float power = 0, powed = 1;
 while(power < i){
 power++;
 powed *= x;
 }
 float fact = 1, j;
 for (int j = 0; j < i; j++){
 fact = fact * (j+1);
 }
 adding = (powed / fact);
 if(adding > eps){
 printf("powed = %f; ", powed);
 printf("fact = %f; ", fact);
 printf("adding = %f; ", adding);
 res = res + adding;
 printf("res = %f;\n", res);
 }
 i++;
 }
 printf("final result = %f", res);

 return 0;}

 int lab3_1 () {
     int c; // текущий символ из потока
 int cnt; // счЄтчик
 int isNewWord = YES;

 // начальные присваивани€ (инициализаци€)
 cnt = 0;

 // цикл чтени€ символов из потока, св€занного с
 // клавиатурой



 while((c = getchar()) != EOF){
 if(c == ' '){
 isNewWord = YES;
 } else if(c == '.'){
 printf("number of words = %d\n", cnt);
 cnt = 0;
 } else {
 if (isNewWord == YES){
 if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u' || c
== 'Y' || c == 'y'){
 cnt++;
 }
 isNewWord = NO;
 }
 }
 }


 return 0;

 }

 int lab4_1 () {
     char prefix[MAXLINE];
    char line[MAXLINE];
    char res[MAXLINE];
    char c;
    int flag = NO;
    int is_good = YES;
    int prefix_pos = 0;
    int pos = 0;
    int start = 0;
    int j;
    int res_pos = 0;
    if (!fgets(prefix, MAXLINE, stdin)) {
        return 1;
    }
    int prefix_len = 0;
    while (prefix[prefix_len] != '\0' && prefix[prefix_len] != '\n') {
        prefix_len++;
    }
    if (prefix[prefix_len] == '\n') {
        prefix[prefix_len] = '\0';
    }
    if (!fgets(line, MAXLINE, stdin)) {
        return 1;
    }
    int line_len = 0;
    while (line[line_len] != '\0' && line[line_len] != '\n') {
        line_len++;
    }
    if (line[line_len] == '\n') {
        line[line_len] = '\0';
    }

    do {
        c = line[pos];

        if (c == ' ' || c == '.' || c == ',' || c == '\0') {
            if (flag == NO) {
                for (j = start; j < pos; j++) {
                    res[res_pos++] = line[j];
                }
                if (c != '\0') {
                    res[res_pos++] = c;
                }
            }

            prefix_pos = 0;
            start = pos + 1;
            flag = NO;
            is_good = YES;
        } else {
            if (is_good == YES && flag == NO) {
                if (line[pos] != prefix[prefix_pos]) {
                    flag = YES;
                } else {
                    if (prefix[prefix_pos + 1] == '\0') {
                        is_good = NO;
                    } else {
                        prefix_pos++;
                    }
                }
            }
        }

        pos++;
    } while (c != '\0');

    res[res_pos] = '\0';
    puts(res);

    return 0;
}

 int lab_5 (){
  int a[10];
  printf("Enter the array of 10 elements\n");
  for (int i = 0; i < 10; i++) {
    scanf("%i", &a[i]);
  }

  int f = 1;
  for (int i = 0; i < 5; i++) {
    if (a[i] != a[9 - i]) {
      f = 0;
    }
  }
  if (f == 1) {
    printf("Array is a palindrome");
  } else {
    printf("Array is not a palindrome");
  }
  return 0;

 }

 int lab5_1 () {
     int a[10];
  printf("Enter the array of 10 elements\n");
  for (int i = 0; i < 10; i++) {
    scanf("%i", &a[i]);
  }

  int f = 1;
  int prev = 0;
  for (int i = 0; i < 5; i++) {
    if (a[i] != a[9 - i]) {
      f = 0; // ne palindrome
      break;
    }
    if (i > 0) {
        if (prev < a[i] && f == 1) {
            f = 2; // gorka
        }
        else if (prev > a[i] && f == 1) {
            f = 3; // zhelob
        }

        if (f == 2 && prev > a[i] || f == 3 && prev < a[i]) {
            f = 1; // ne gorka i ne zhelob
        }
    }
    prev = a[i];
  }
  if (f == 1) {
    printf("Array is a palindrome");
  } else if (f == 2){
    printf("Array is gorka");
  } else if (f == 3){
    printf("Array is zhelob");
  } else {
    printf("Array is not a palindrome");
  }
  return 0;
 }


int lab6_1(){
        int N=3,M=4;
    int shag = N * M;
    float koef = 1.27;
    int flag = 0;
    int arr[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    while (!flag) {
        shag = (int)(shag / koef);
        if (shag <= 1) {
            shag = 1;
            flag = 1;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int stepi = i * M + j + shag;
                if (stepi < N * M) {
                    if (arr[i][j] > arr[stepi / M][stepi % M]) {
                        int temp = arr[i][j];
                        arr[i][j] = arr[stepi / M][stepi % M];
                        arr[stepi / M][stepi % M] = temp;
                        flag = 0;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
return 0;
}

