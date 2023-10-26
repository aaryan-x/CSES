#include <bits/stdc++.h>
using namespace std;

/*
You are given a list of n integers, and your task is calculating the number of distinct values in the list.
This can be done using two different approaches, one where we can sort the vector of numbers and find distinct values by checking if vector[i+1] != vector[i]. This would include an inbuilt sort and would be O(n*logn).
A more efficient approach is using the set data structure, which works on the principles of set theory and only stores the unique values. This would require only one iteration through all elements, therefore, it would be O(n). 
*/

int main() {
    int n;
    cin>>n;
    set <int> S;
 
    for(int i=0; i<n;i++){
        int p;
        cin>>p;
        S.insert(p);
    }
    cout<< S.size()<<endl;
 
    return 0;
}


/*

Approach 1: using inbuilt sort function O(n*logn)
    
    vector <int> v;
    for(int i=0; i<n;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int count=0;
    for(int i=0; i<n;i++){
        if(v[i]!=v[i+1]){
            count++;
        }
    }
    cout<<count<<endl;
  
*/
