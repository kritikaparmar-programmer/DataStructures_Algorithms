#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Matrix Transpose
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    for(int i=0; i<3; i++)
    {
        for(int j=i; j<3; j++)   // to traverse only the elements present above diagonal 
        {
            // swap
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Matrix Multiplication
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int m1[n1][n2];
    int m2[n1][n3];
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            cin >> m1[i][j];
        }
    }
    for(int i=0; i<n2; i++)
    {
        for(int j=0; j<n3; j++)
        {
            cin >> m2[i][j];
        }
    }
    int ans[n1][n3];
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n3; j++)
        {
            ans[i][j] = 0;
        }
    }
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n3; j++)
        {
           for(int k=0; k<n2; k++)
           {
               ans[i][j] += m1[i][k] * m2[k][j];
           } 
        }
    }
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n3; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


// Matrix Search
// Elements are sorted

// This is an approach different than linear search O(nm)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int target;
    cin >> target;
    int matrix[m][n];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    
    int r=0, c=n-1;  // starting search from top right , we can also search from left bottom 
    bool found = false;
    while(r < m and c >= 0)
    {
        if(matrix[r][c] == target)
        {
            found = true;
            break;
        }
        else if(matrix[r][c] > target)
            c--;   // moving left
        else
        {
            r++;   // moving down
        }
    }
    if(found)
        cout << "Element found";
    else
    {
        cout << "Element not found";
    }
    return 0;
}