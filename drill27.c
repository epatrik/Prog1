#include <stdio.h>

void print(char* p,int x){

    printf("p is \"%s\" and x is %i\n",p,x);
}

int main(){

    char h[]="Hello";
    char w[]="World!";
    

    printf("Hello, World!\n");
    printf("%s, %s\n",h,w);
    print("foo",7);

    return 0;
}
