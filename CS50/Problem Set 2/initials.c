#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include<ctype.h>

int main(){
    int i,n;
    string name = get_string();
    if(name[0]!=' '){
        printf("%c",toupper(name[0]));
    }
    n = strlen(name);
    for(i=1;i<n;i++){
        if(name[i-1] ==' ' && isalpha(name[i])){
            printf("%c",toupper(name[i]));
        }
    }
    printf("\n");
}