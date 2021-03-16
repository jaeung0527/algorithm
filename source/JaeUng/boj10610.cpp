#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int sum = 0;
    vector<char> N;
    for(char c : s)
    {
        sum += c - '0';
        N.push_back(c);
    }
    sort(N.begin(), N.end(), greater<char>());

    if(N[N.size()-1] != '0' || sum % 3 != 0) 
    {
        cout << -1;
    }
    else
    { 
        cout << N.data();
    }
}