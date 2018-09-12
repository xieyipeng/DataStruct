#include<stdio.h>
float fun(int a,int b){
	return (a+b);
}
int main(){
	int a=2,b=5,c=8;
	printf("%3.0f\n",fun((int)fun(a+c,b),a-c));
	return 0;
}
