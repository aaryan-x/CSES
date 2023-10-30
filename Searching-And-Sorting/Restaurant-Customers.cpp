#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

void solve(vector<pair<ll, bool>> array)
{
    sort(array.begin(), array.end());
    ll maxPeople = 0, curr = 0;

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i].second == true)
            curr++;
        else
            curr--;
        maxPeople = max(maxPeople, curr);
    }

    cout << maxPeople << endl;
}

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, bool>> array;
    for (int i = 0; i < n; i++)
    {
        int arrival, departure;
        cin >> arrival >> departure;
        array.pb({arrival, true});
        array.pb({departure, false});
    }

    solve(array);
    return 0;
}
