#include <bits/stdc++.h>
using namespace std;

int N, K;
int X[100];

void Result()
{
    for (int i = 1; i <= K; i++)
    {
        char a = X[i] + 64;
        cout << a;
    }
    cout << endl;
}

void Try(int i)
{
    for (int j = X[i - 1] + 1; j <= N - K + i; j++)
    {
        X[i] = j;
        if (i == K)
            Result();
        else Try(i + 1);
    }
}

int main()
{
    cin >> N >> K;
    X[0] = 0;
    Try(1);
    return 0;
}
