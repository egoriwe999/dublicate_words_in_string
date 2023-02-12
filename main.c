#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"
#include <time.h>

#define d " \t" // DELIM
#define p "> " // Ввод в ридлайне
#define pref " " // пробел

char *chet(const char *);

int main(){
        long double timeTaken;
        clock_t start, end;
        char *input = myreadline(p);
        while (input !=NULL){
                printf("Your string:\n");
                printf("\"%s\"\n", input);
                start = clock();
                char *output =chet(input);
                end = clock();
                timeTaken = (long double) (end - start)/CLOCKS_PER_SEC; // переводим в секунды
                printf("Time elapsed: %Lf\n", timeTaken);
                printf("New string:\n");
                printf("\"%s\"\n", output);
                free(input);
                free(output);
                input = myreadline(p);
        }
        return 0;
}

char *chet(const char *str){
        char *s = mystrdup(str);
        int s_len = mystrlen(s);
        char *res = calloc((s_len*2)+2,sizeof(char));
        int len = 0;
        char *word = mystrtok(s, d); // d - DELIM в примере
        int pref_len = mystrlen(pref); // Размер пробела для дублирования слов
        while(word != NULL){
                int w_len = mystrlen(word);
                if (w_len>0){
                        int d_len;  // double len of word
                        if (w_len % 2 == 0){
                                d_len = w_len + w_len;
                                char* new_word= calloc(d_len+pref_len + 1,sizeof(char));
                                int j;
                                int k = 0;
                                int f = 0;
                                for(j=0;j<w_len;j++){
                                        new_word[j] = word[j];
                                }
                                for(size_t i=w_len-1; i<w_len; i++){
                                        new_word[j] = pref[0];
                                }
                                for (size_t i=w_len;i<(d_len);i++){
                                        new_word[i+1]=word[k];
                                        k++;
                                }
                                mymemcpy(res+len, new_word, (d_len+pref_len) *sizeof(char));
                                free(new_word);
                                len = len+d_len+1;
                        }
                        if(w_len %2 != 0){
                                mymemcpy(res+len, word, w_len*sizeof(char));
                                len +=w_len;
                        }
                        res[len]= ' ';
                        ++len;
                }
                        word = mystrtok(NULL,d); // берем еще словоa
        }
        free(s);
        if(len > 0){
                --len; // убирает последний пробел
        }
        res[len]= '\0';
        res = realloc(res,(len+1)*sizeof(char));
        return res;
}
