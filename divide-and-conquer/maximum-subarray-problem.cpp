/*
maxCrossingSum finds the max sum of subarray which passes mid.
maxSubarraySum is recursively called for the left and right sub arrays.
*/
#include<iostream>
using namespace std;

int maxCrossingSum(int a[], int low, int mid, int high){
	int leftsum = -1000000;
	int rightsum = -1000000;
	int sum = 0;
	for(int i=mid; i>=low; i--){
		sum += a[i];
		if(sum > leftsum){leftsum = sum;}
	}
	sum = 0;
	for(int i=mid+1; i<=high; i++){
		sum += a[i];
		if(sum > rightsum){rightsum = sum;}
	}
	return leftsum + rightsum;
}

int maxSubarraySum(int a[], int low, int high){
	if(low == high){return a[low];}
	else{
		int mid = (low+high)/2;
		int leftsum = maxSubarraySum(a, low, mid);
		int rightsum = maxSubarraySum(a, mid+1, high);
		int crosssum = maxCrossingSum(a, low, mid, high);
		return std::max(std::max(leftsum, rightsum), crosssum);
	}
}

int main(){
	int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int n = sizeof(a)/sizeof(a[0]);
	int ans = maxSubarraySum(a, 0, n-1);
	cout << ans;
	return 0;
}