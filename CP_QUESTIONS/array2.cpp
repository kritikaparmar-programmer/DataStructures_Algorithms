// find subarray of given sum
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n, s;
    cin >> n >> s;

    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int i=0, j=0, st=-1, en=-1, sum=0;

    while (j<n && sum+a[j] <= s)
    {
        sum += a[j];
        j++;
    }

    if(sum == s)
    {
        cout << i+1 << " " << j << endl;
        return 0;
    }

    while(j<n)
    {
        sum += a[j];
        while(sum > s)
        {
            sum -= a[i];
            i++;
        }

        if(sum == s)
        {
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }

    cout << st << " " << en << endl;
    

}


// minimum positive number that is not present in the array 

#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n, s;
    cin >> n >> s;

    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    const int N = 1e6+2 ; 
    bool check[N];
    for(int i=0; i<N; i++)
    {
        check[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        if(a[i] >= 0)
        {
            check[a[i]] = 1;
        }
    }

    int ans = -1;
    for(int i=1; i<N; i++)
    {
        if(check[i] == 0)
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

}



