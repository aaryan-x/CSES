#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(vector<pair<ll, ll>> movies){
    sort(movies.begin(), movies.end());
    ll curr = movies[0].first, count = 1;
    
    for (ll i = 0; i < movies.size(); i++){
        if (movies[i].second >= curr){
            curr = movies[i].first;
            count++;
        }
    }
    cout << count << endl;
}

int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> movies;
    for (ll i = 0; i < n; i++){
        ll start, end;
        cin >> start >> end;
        movies.push_back({end, start});
    }

    solve(movies);
    return 0;
}
