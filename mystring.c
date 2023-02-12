#include <stdlib.h>
#include "mystring.h"
#include <stdio.h>

size_t mystrlen(const char *s) {
    int res = 0;
    while(*s) { // идём до конца строки и увеличиваем res
        ++s, ++res;
    }
    return res;
}

char *mystrdup(const char *str){
        char *newstr;
        int len=mystrlen(str);
        int i;
        newstr = malloc((len+1)*sizeof(char));
        for(i=0;i<len;i++){
                newstr[i]=str[i];
        }
        newstr[i] = '\0'; // конец строки
        return newstr;
}

char *mystrtok(char *str, char *delim){
        static char *trash; // trash - буфер , для повторного использования
        if(str == NULL){
                str = trash;
                if(str==NULL){ // если ничему не равно
                        return NULL;
                }
        }
        if(*str==*delim){
                str++;
        }
        if(*str == '\0'){ //выполняется, если строка состоит только из разделителей (DELIM)
                        return NULL;
        }
        char *res = str; // *res указывает на строку buf. В последующем меняется строка buf, а возвращается указатель res
        while(1){ //взятие одного слова
                if(*str == '\0'){
                        trash = str;  //конец строки, следующий вызов вернет NULL
                        return res;
                }
                if(*str == *delim){
                        *str = '\0';   //отделяется слово от строки
                        trash = str + 1; //оставшаяся часть строки записывается в lastBuf
            return res;
        }
        str++;
    }
}

void mymemcpy(char *str2, char *str1, size_t n){
        for(size_t i=0; i<n; i++){
                str2[i]= str1[i];
        }
}

char *myreadline(char *prompt){ // принимает приглашение на ввод и возвращает указатель на строку
        char buf[81] = {0};
        char *res = NULL;
        int len = 0;
        int n = 1;
        printf("%s", prompt);
        while(n>0){
                n = scanf("%80[^\n]", buf);
                if (n < 0) {
                        return NULL;
                }
                else if (n > 0){
                        int chunk_len = mystrlen(buf);
                        int str_len = len + chunk_len;
                        res = realloc(res, str_len + 1);
                        mymemcpy(res+len, buf, chunk_len);
                        len = str_len;
                }
                else{
                        scanf("%*c"); // чистка буфера от \n
                }
        }
        if(len > 0){
                res[len] = '\0';
        }
        else{
                res = calloc(1, sizeof(char)); // для того если мы введём enter и у нас строка нулевая была
        }
        return res;
}

