#include<iostream>
#include<algorithm>
using namespace std;

int ans=0;

int ok(int arr[]){
	if(arr[0])

	return 1;
}


int main(){
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	do{
		if(ok(arr)==1){
			for(int i=0;i<10;i++){
				cout<<arr[i];
			}
			cout<<endl;
			
		}
		ans++;
	}while(next_permutation(arr,arr+10));
	cout<<ans<<endl;
	return 0;
}
