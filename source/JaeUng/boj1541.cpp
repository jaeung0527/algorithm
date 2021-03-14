#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans;
    scanf("%d", &ans);

    bool subtract = false;
    while(true)
    {
        char op;
        scanf("%c", &op);
        if(op == '\n')
            break;
        if(op == '-')
            subtract = true;
        
        int num;
        scanf("%d", &num);
        if(subtract) ans -= num;
        else ans += num;
    }
    printf("%d", ans);
}