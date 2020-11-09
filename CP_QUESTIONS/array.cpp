/* Max till i 
#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int max_no = INT_MIN;
    for(int i=0; i<n; i++)
    {
        max_no = max(max_no, arr[i]);
        cout << "Max at pos " << i << " is " << max_no << endl;
    }
}*/

// No of subarrays - nC2 + n = n*(n+1)/2  - continuous
// No of subsequence - 2**n  // not continuous
// Every subarray is a Subsequence but every subsequence is not a subarray


/* Sum of all the subarrays of an array 
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n;
    cin>> n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    int curr_sum = 0;
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        curr_sum = 0;
        for(int j=i; j<n; j++)
        {
            curr_sum += a[j];
            // cout << a[j] << endl;
            cout << curr_sum << endl;
            sum += curr_sum;
        }
    }
    cout << "Total sum : " << sum << endl;
}*/

/*
// Google kickstart

#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n;
    cin>> n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    int ans = 2;
    int pd = a[1] - a[0];
    int j=2;
    int curr = 2;

    while(j < n)
    {
        if(pd == a[j] - a[j-1])
        {
            curr++;
        }
        else
        {
            pd = a[j] - a[j-1];
            curr = 2;
        }
        ans = max(ans, curr);
        j++;
    }
    cout << ans << endl;
}*/

// Record Breaking Day

#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n;
    cin>> n;
    int a[n+1];
    a[n] = -1;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    if(n==1)
    {
        cout << "1" << endl;
        return 0;
    }    
    int ans = 0;
    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        if(a[i] > mx && a[i] > a[i+1])
        {
            ans++;
        }
        mx=max(mx, a[i]);
    }
    cout << ans << endl;
}

// Aamazon question find element who is repeated but is at smaller index

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    const int N = 1e6+2; // 10^6
    int idx[N];
    for(int i=0; i<N; i++)
    {
        idx[i] = -1;
    }

    int minidx = INT_MAX;
    
    for(int i=0; i<n; i++)
    {
        if(idx[a[i]] != -1)
        {
            minidx = min(minidx, idx[a[i]]);
        }
        else
        {    
            idx[a[i]] = i;    
        }    
    }

    if(minidx == INT_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << minidx + 1 << endl; 
    } 

    return 0;
}