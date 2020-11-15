#include <bits/stdc++.h>
using namespace std;

int main()
{
   
    string str;
    cin >> str;
    cout << str << endl;

    string str1(5, 'k');
    cout << str1 << endl;

    string str2 = "KritikaParmar";
    cout << str2 << endl;

    string str3;
    getline(cin, str3);
    cout << str3 << endl;

    // Concatenation
    string s1 = "fam";
    string s2 = "ily";
    s1.append(s2);
    cout << s1 << endl;
    string s4 = "fam";
    string s3 = "ous";
    cout << s4 + s3 << endl;

    string abc = "srhsrgcv g jyftvvvve fgfh"
    abc.clear();
    cout << abc << endl;
    string s1 = "abc";
    string s2 = "xyz";

    cout << s1.compare(s2) << endl;   // -1 as s1 < s2
    cout << s2.compare(s1) << endl;  // 1 as s2 > s1

    string s3 = "abc";
    if(s1.compare(s3) == 0)
        cout << "Strings are equal" << endl;
    
    if(s1.empty())
        cout << "String is empty" << endl;
    else
    {
        cout << "String is not empty" << endl;
    }

    string s = "nincompoop";

    cout << s.find("poo") << endl;  // to find

    s.erase(3, 3);    // erase(index from which we want to delete, no of elements to delete)
    cout << s << endl;

    s.insert(2, "lol");
    cout << s << endl;

    cout << s.size() << endl;
    cout << s.length() << endl;

    for(int i=0; i<s.length(); i++)
        cout << s[i] << endl;

    string st = s.substr(6, 4);  // substr(pos, no of elements)
    cout << st << endl;

    string numstr = "786";
    int x = stoi(numstr);   // string to integer
    cout << x << endl;
    cout << x+2 << endl;

    int  y = 786;
    cout << to_string(y) << endl;  // integer to string
    cout << y + "2" << endl;

    string k = "vrnkjvurhqgh";
    sort(k.begin(), k.end());
    cout << k << endl;

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "adsfdtrbhw";

    //cout << 'a' - 'A' << endl;  // 32

    // Convert to upper case
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] >='a' && str[i] <= 'z')
            str[i] -= 32;
    }
    cout << str << endl;

    // Convert to lower case
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] >='A' && str[i] <= 'Z')
            str[i] += 32;
    }
    cout << str << endl;

    // Using inbuilt functions
    string s = "abcdefghijkl";

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;

    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Form the biggest number from the given numeric string
    // "53214" --> "54321"
    string numstr = "53214";

    // sort in descending order
    sort(numstr.begin(), numstr.end(), greater<int>());
    cout << numstr << endl;
   

    // Max occurence of an element in a string

    string s = "djheytgimvndjk";
    int freq[26];

    for(int i=0; i<26; i++)
    {
        freq[i] = 0;
    }

    for(int i=0; i<s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }

    char ans = 'a';
    int maxf = 0;
    for(int i=0; i<26; i++)
    {
        if(freq[i] > maxf)
        {
            maxf = freq[i];
            ans = i+'a';
        }
    }

    cout << maxf << " " << ans << endl; 

    return 0;
}