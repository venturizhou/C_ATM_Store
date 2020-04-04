#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int all_letters(char*s);
int num_in_range(char*s, char b, char t);
int len_diff(char *s1, char*s2);
void rm_left_space(char *s);
void rm_right_space(char *s);
void rm_space(char*s);
void shorten(char*s, int new_len);
int find(char*h, char*n);
char *ptr_to(char*h, char*n);
int is_empty(char*s);
char *str_zip(char *s1, char*s2);

int main(void){
    char name[] = "     Ricky";
    char name2[] = "Jamie";
    char name3[] = "Bobby      ";
    char name4[] = " A B C D E";

    puts("");
    puts("REMOVE LEFT SPACE");
    printf("%s\n", name);
    rm_left_space(name);
    printf("%s\n", name);
    

    puts("");
    puts("REMOVE RIGHT SPACE");
    printf("%s", name3);
    printf("%s\n","<-end");
    rm_right_space(name3);
    printf("%s", name3);
    printf("%s\n","<-end");

    puts("");
    puts("REMOVE SPACE");
    printf("%s\n", name4);
    rm_space(name4);
    printf("%s\n", name4);
    puts("");

    puts("FIND FUNCTIONS");
    puts("Find l in hello");
    printf("%d\n", find("hello", "l"));
    puts("Find q in hello");
    printf("%d\n", find("hello", "q"));    
    puts("");

    puts("POINTER TO");
    puts("Find l in hello");
    printf("%s\n", ptr_to("hello", "l"));
    puts("Find q in hello");
    printf("%s\n", ptr_to("hello", "w"));    
    puts("");

    puts("IS EMPTY");
    puts("Checking empty string");
    printf("%d\n", is_empty(" "));
    puts("Checking nonempty string");
    printf("%d\n", is_empty("?"));
    puts("");

    puts("STRING ZIP");
    printf("%s\n", name2);
    printf("%s\n", name3);
    printf("%s\n", str_zip(name2,name3));
}

int all_letters(char*s){
    for (size_t i = 0; s[i] != '\0'; i++){
        if (!isalpha(s[i])){
            return 0;
        }
    }return 1;
}

int num_in_range(char*s1, char b, char t){
    int count = 0;
    for(size_t i = 0; s1[i] != '\0'; i++){
        if (s1[i]==b){
            count++;
            for(;s1[i] != '\0' && s1[i] != t; i++){
                count++;
            }
        }
        if(s1[i] =='\0'){
            return 0;
        }
    }
    return count;
}

int len_diff(char *s1, char*s2){
    int count = 0;
    for(;*s1 != '\0' && *s2 != '\0'; s1++, s2++){
    }
    if (*s1 != '\0'){
        for(;*s1 != '\0'; s1++){
            count++;
        }return count;
    }else if (*s2 != '\0'){
        for(;*s2 != '\0'; s2++){
            count++;
        }return count;
    }return 0;
}

void rm_left_space(char *s){

    int n = 0;
    while(isspace(s[n])){
        n++;
    }
    int i = 0;
    for(; s[n] != '\0'; i++, n++){
        s[i] = s[n];
    }s[i] = '\0';
    // char *temp = s;

    // while(isspace(*temp)){
    //     temp++;
    // }
    // int i = 0;
    // for(; *temp != '\0'; i++, temp++){
    //     s[i] = *temp;
    //     printf("%c\n",temp[0]);
    // }s[i] = '\0';
}

void shorten(char*s, int new_len){
    int length = 0;
    for(int i = 0; s[i] != '\0'; i++){
        length++;
    }
    if (new_len < length){
        s[new_len] = '\0';
    }
}

void rm_space(char*s){
    int n = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if (!isspace(s[i])){
            s[n++] = s[i];
        }
    }s[n] = '\0';
}

void rm_right_space(char*s){
    int n = -1;
    int i = 0;
    for(; s[i] != '\0'; i++){
        if(!isspace(s[i])){
            n = i;
        }
    }s[++n] = '\0';
}

int find(char *h, char*n){
    for(int i = 0; h[i] != '\0';i++){
        if(h[i]==*n){
            return i;
        }
    }return -1;
}

char *ptr_to(char*h, char*n){
    for(; *h !='\0'; h++){
        if(*h==*n){
            return h;
        }
    }return "NULL";
}

int is_empty(char*s){
    for(; *s != '\0'; s++){
        if(!isspace(*s)){
            return 0;
        }
    }return 1;
}

char *str_zip(char *s1, char*s2){
    size_t length1= 0;
    size_t length2 = 0;
    for(;s1[length1]!='\0';length1++);
    for(;s2[length2]!='\0';length2++);
    char *temp = malloc(length1+length2+1);
  
    size_t k = 0;
    for(;k<(length1+length2);){
        if(*s1!='\0'){
            temp[k++] = *s1++;
        }
        if(*s2!='\0'){
            temp[k++] = *s2++;
        }
    }temp[k] = '\0';
    return temp;
}