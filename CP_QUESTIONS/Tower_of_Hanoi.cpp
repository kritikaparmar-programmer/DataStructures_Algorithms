#include <bits/stdc++.h>
using namespace std;


void tower_of_Hanoi(int n, char src, char dest, char help)
{
    if(n == 0)
    {
        return;
    }

    tower_of_Hanoi(n-1, src, help, dest);
    cout << "Move from src " << src << " to " << dest << " destination " << endl;

    tower_of_Hanoi(n-1, help, dest, src);
    
}


int main()
{
    tower_of_Hanoi(3, 'A', 'C', 'B');

    return 0;
}


/*  Output- 
Move from src A to C destination 
Move from src A to B destination 
Move from src C to B destination 
Move from src A to C destination 
Move from src B to A destination 
Move from src B to C destination 
Move from src A to C destination
*/