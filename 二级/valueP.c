#include<stdio.h>
float fun(int m,int n){
	int jiechengM = 1,jiechengN = 1,jiechengM_N = 1;
	if(m<=n){
		return 0;
	}else {
		int i = 0;
		while(i<m){
			jiechengM = jiechengM * (m - i);
			i++;
		}
		printf("m == %d\n",jiechengM);
		i = 0;
		while(i<n){
			jiechengN = jiechengN * (n - i);
			i++;
		}
		printf("n == %d\n",jiechengN);
		i = 0;
		while(i<(m - n)){
			jiechengM_N = jiechengM_N * ((m - n) - i);
			i++;
		}
		printf("m-n == %d\n",jiechengM_N);
	}
	return jiechengM / (jiechengN * jiechengM_N);
}
int main(){
	printf("hello\n");
	printf("p == %f\n",fun(12,8));
	return 0;
}
