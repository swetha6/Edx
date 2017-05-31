#include<stdio.h>
#include<cs50.h>

int main(){
    printf("Minutes: ");
    int min = get_int();
    
    int bot;
    bot = min * 12;
    printf("Bottles : %d\n",bot);
}