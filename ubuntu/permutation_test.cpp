#include<iostream>
#include<algorithm>
using namespace std;
	/**
	测试c++ next_permutation(arr,arr.size()) 函数：
	a. 函数模板：next_permutation(arr, arr+size);
	b. 参数说明：
			arr： 数组名;
			size：数组元素个数;
	c. 函数功能： 返回值为bool类型，当当前序列不存在下一个排列时，函数返回false，否则返回true，排列好的数在数组中存储;
	d. 注意：在使用前需要对欲排列数组按升序排序，否则只能找出该序列之后的全排列数。比如，如果数组num初始化为2,3,1，那么输出就变为了：{2 3 1} {3 1 2} {3 2 1}.
	e. 头文件：#include<algorithm>
	**/
	
	//对应的有：prev_permutation(arr,arr.size())函数。
int main(){
	int arr[] = {3, 2, 1};
	cout<<"prev_permutation() 对arr进行全排列："<<endl;
	do{
		cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] <<'\n';
	}while(prev_permutation(arr, arr+3));
	
	int arr1[] = {1, 2, 3};
	cout<<"next_permutation() 对arr1进行全排列："<<endl;
	do{
		cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[2] <<'\n';
	}while(next_permutation(arr1, arr1+3));
	return 0;
}
