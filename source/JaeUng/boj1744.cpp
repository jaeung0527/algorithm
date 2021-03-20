#include <bits/stdc++.h>

using namespace std;

vector<int> seq;

int solve(int N)
{
    int ans = 0;
    sort(seq.begin(), seq.end());
    int i = 0;
    while(i + 1 < seq.size() && seq[i] <= 0 && seq[i + 1] <= 0)
    {
        ans += seq[i] * seq[i + 1];
        i += 2; 
    }

    int j = seq.size() - 1;
    while(j - 1 >= 0 && seq[j] > 1 && seq[j - 1] > 1)
    {
        ans += seq[j] * seq[j - 1];
        j -= 2;
    }

    for(int k = i; k <= j; k++)
    {
        ans += seq[k];
    } 
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    while(N--)
    {
        int num;
        cin >> num;
        seq.push_back(num);
    }
    cout << solve(N);
}