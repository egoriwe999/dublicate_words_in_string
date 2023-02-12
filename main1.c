#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

#define d " \t"
#define p "> "
#define pref " "

char *chet(const char *);

int main(){
        char *input = readline(p);
        while (input !=NULL){
                printf("Your string:\n");
                printf("\"%s\"\n", input);
                char *output =chet(input);
                printf("New string:\n");
                printf("\"%s\"\n", output);
                free(input);
                free(output);
                input = readline(p);
        }
        return 0;
}

char *chet(const char *str){
        char *s = strdup(str);
        int s_len = strlen(s);
        char *res = calloc(s_len*2,sizeof(char));
        int len = 0;
        char *word = strtok(s, d); // d - DELIM в примере
        int pref_len = strlen(pref); // Размер пробела для дублирования слов
        while(word != NULL){
                int w_len = strlen(word);
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
                                memcpy(res+len, new_word, (d_len+pref_len) *sizeof(char));
                                free(new_word);
                                len = len+d_len+1;
                        }
                        if(w_len %2 != 0){
                                memcpy(res+len, word, w_len*sizeof(char));
                                len +=w_len;
                        }
                        res[len]= ' ';
                        ++len;
                }
                        word = strtok(NULL,d);
        }
        free(s);
        if(len > 0){
                --len; // убирает последний пробел
        }
        res[len]= '\0';
        res = realloc(res,(len+1)*sizeof(char));
        return res;
}
