#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char caesar_ch(char ch, int key);
bool is_int(string s);

int main(int argc, string argv[1]){
    
    if (argc != 2 || !is_int(argv[1])) 
    {
        printf("Usage: %s <int key>\n", argv[0]);
        return 1;
    }
    printf("plaintext: ");
    string cleartext = get_string();
    int key = atoi(argv[1]);
    int n = strlen(cleartext);
    printf("ciphertext:");
    for(int i=0;i<n;i++){
        printf("%c",caesar_ch(cleartext[i],key));
    }
    printf("\n");
    
}

char caesar_ch(char ch, int key){
    if (isalpha(ch)){
        int s = 97;
        if(isupper(ch)){
            s=65;
        }
        return (char) ((((ch-s)+key)%26)+s);
    }
    else{
        return ch;
    }
}

bool is_int(string s)
{
    int n1=strlen(s);
    for (int i = 0;i < n1; i++){
        if (!isdigit(s[i])){
            return false;
        }
    }
    return true;
}