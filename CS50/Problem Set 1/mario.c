#include<stdio.h>
#include<cs50.h>

int d_height(){
    int height;
     do{
        printf("Height : ");
        height= get_int();
    }
    while (height < 0 || height > 23);
    
    return height;
}

int main(){
    int i,w,s,p,j;
    int h = d_height();
    w = h+1;
    
    for(i=1;i<=h;i++){
        p = i+1;
        s = w - p;
        for(j=0;j<s;j++){
            printf(" ");
        }
        for (j=0;j<p;j++){
            printf("#");
        }
        printf("\n");
    }
}