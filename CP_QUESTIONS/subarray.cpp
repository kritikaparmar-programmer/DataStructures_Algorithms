// subarray
#include <bits/stdc++.h> 
using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            for(int k=i; k<=j; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}


// Maximum subarray sum  // O(n**3)

#include <bits/stdc++.h> 
using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int maxSum = INT_MIN;

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int sum = 0;
            for(int k=i; k<=j; k++)
            {
                sum += arr[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum << endl;
}


// Cumulative sum approach

#include <bits/stdc++.h> 
using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int currSum[n+1];
    currSum[0] = 0;

    for(int i=1; i<=n; i++)
    {
        currSum[i] = currSum[i-1] + arr[i-1];
    }

    int maxSum = INT_MIN;
    for(int i=1; i<=n; i++)
    {
        int sum = 0;
        for(int j=0; j<i; j++)
        {
            sum = currSum[i] - currSum[j];
            maxSum = max(sum, maxSum);
        }
    }
    cout << maxSum << endl;
}

// KADANE'S Algorithm
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int currentSum = 0;
    int maxsum = INT_MIN;
    for(int i=0; i<n; i++)
    {
        currentSum += arr[i];
        if(currentSum < 0)
        {
            currentSum = 0;
        }
        maxsum = max(maxsum, currentSum);
    }
    cout<< maxsum << endl;
}