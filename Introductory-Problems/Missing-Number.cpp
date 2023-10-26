#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    long long int arr[n - 1];
    long long int sum = 0, GaussSum = n*(n+1)/2;
    
    for (long long int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << GaussSum - sum << endl;
    return 0;
}

/* One method is to sort the array in o(nlogn) and the do a linear search to find the missing number.
The optimal O(n) appraoach is finding the sum on n terms, assuming there were no missing number, and the subtracting the actual sum of all elements of the array to find the missing number.
*/
