#include<stdio.h>
#define N 16
typedef struct{
	char num[10];
	int s;
}STREC;
int fun(STREC *a,STREC *b){
	int n=0;
	int low=100;
	for(int i=0;i<sizeof(*a);i++){
		if(a[i].s<=low){
			low=a[i].s;
		}
	}
	for(int i=0;i<sizeof(*a);i++){
		if(a[i].s==low){
			b[n]=a[i];
			n++;
		}
	}
	return n;
}
int main(){
	STREC s[N] = {
		{"GA05",85},{"GA03",76},{"GA02",69},{"GA04",85},{"GA01",91},{"GA07",72},
		{"GA08",64},{"GA06",87},{"GA015",85},{"GA013",91},{"GA012",64},{"GA014",91},
		{"GA011",91},{"GA017",64},{"GA018",64},{"GA016",72}
	};
	STREC h[N];
	int n=0;
	FILE *out;
	n = fun(s,h);
	printf("the %d lowest score : \n",n);
	for(int i=0;i<n;i++){
		printf("%s%4d\n",h[i].num,h[i].s);
	}
	printf("\n");
	out=fopen("/usr/local/github/DataStructure/二级/out.dat","w");
	fprintf(out,"%d\n",n);
	for(int i=0;i<n;i++){
		fprintf(out,"%4d\n",h[i].s);
	}
	fclose(out);
	return 0;
}
