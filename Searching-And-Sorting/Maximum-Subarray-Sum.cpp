#include<bits/stdc++.h>
using namespace std;
 
long long maxSubArraySum(long long arr[], long long n){
	long long sum = 0, maxSum = INT_MIN;
	long long maxElement = INT_MIN;
 
	for (int i = 0; i < n; i++){
		sum += arr[i];
		maxSum = max(maxSum, sum);
 
		if (sum < 0){
			sum = 0;
		}
 
		if (arr[i] > maxElement){
			maxElement = arr[i];
		}
	}
 
	if (maxElement < 0){
		maxSum = maxElement;
	}
 
	return maxSum;
}
 
int main(){
	long long n;
	cin >> n;
	long long arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
  
	cout << maxSubArraySum(arr, n) << endl;
	return 0;
}

/*This is O(n) solution based on Kadane's Algorithm, which works on the intuition that the maximum sum can never be negative and therefore whenever the sum becomes negative, we update the value of sum to be zero.
Also, if all the elements in an array are negative, then the largest element would be the maxSum and therefore we find the largest element as well.*/
