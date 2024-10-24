#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k, count = 0;
    cin >> n >> k;
    vector<pair<ll, ll>> movies(n);
  
    for (int i = 0; i < n; i++) {
        ll start, end;
        cin >> start >> end;
        movies[i] = {end, start};
    }

    sort(movies.begin(), movies.end());
    multiset<ll> endings;

    for (const auto &movie : movies) {
        ll start = movie.second;
        ll end = movie.first;

        // Find if there is a member available whose movie ends before the current movie starts
        auto it = endings.upper_bound(start);
        
        if (it != endings.begin()) {
            --it;  // Move to the member whose movie ends the closest to the current movie's start time
            endings.erase(it);  // Erase the member's current movie end time, as they are now free
            endings.insert(end);  // Assign the current movie to this member, updating their end time
            count++;
        } else if ((int)endings.size() < k) {
            // If there's still room for more members to watch movies, assign the current movie to a free member
            endings.insert(end);
            count++;
        }
    }
    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
