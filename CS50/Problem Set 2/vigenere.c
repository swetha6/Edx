#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char caesar_ch(char ch, int key);
bool isalpha_str(string s);
int char2int(char keychar);

int main(int argc, string argv[1]){
    
    if (argc != 2) 
    {
        printf("Usage: %s <int key>\n", argv[0]);
        return 1;
    }
    if (!isalpha_str(argv[1]))
    {
        printf("Keyword must contain only alphabetical characters.\n");
        return 1;
    }
    printf("plaintext: ");
    string keyword = argv[1];
    string cleartext = get_string();
    int n = strlen(cleartext);
    printf("ciphertext:");
     for (int i = 0, keyword_index = 0; i < n; i++){
        char clear_ch = cleartext[i];
        char key=char2int(keyword[keyword_index]);
        printf("%c",caesar_ch(cleartext[i],key));
        int n2=strlen(keyword);
        if (isalpha(clear_ch))
        {
            keyword_index = (keyword_index + 1) % n2;
        }
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

bool isalpha_str(string s)
{
    int n1=strlen(s);
    for (int i = 0; i < n1; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}
int char2int(char keychar)
{
    return (int) (tolower(keychar) - 97);
}