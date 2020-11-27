#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while(b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

int divisible(int n, int a, int b)  // find numbers upto n divisible by a or b
{
    int c1 = n / a;
    int c2 = n / b;
    int c3 = n / (a * b);

    return c1 + c2 - c3;
}

int main()
{
    int a, b, n;
    cin >> a >> b;
    cin >> n;
    cout << gcd(a, b) << endl;
    cout << divisible(n, a, b) << endl;
    return 0;
}