#include <bits/stdc++.h>
using namespace std;

int main()
{


    // VECTORS
    vector<int> v;  // declaration of vector of type int named as v

    // push_back()  , push back at the end of vector 
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << endl;
    }
    

    // pop_back() , removes last element
    v.pop_back();

    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << endl;
    }

    // front(), back()
    cout << v.front() << endl;
    cout << v.back() << endl;

    vector<int>::iterator it;  // iterators are pointers
    it = v.begin();

    for(it; it!= v.end(); it++)
    {
        cout << *it << " ";
    }

    vector<int> v2{1, 2, 3};
    v2.push_back(4);

    vector<int> v3(v2);
    
    
    
    // ORDERED MAP
    //  map< key_type , value_type >  map_name;
    map<int, string> m;

    map<int, string> m1={{23, "Kritika"}};

    m[23] = "Kritika";
    cout << m[23] << endl;
    
    m.insert(pair<int, string>(41, "John"));
    cout << m[41] << endl;
    
    map<int, string>::iterator it = m.begin();  // begin returns the base address of the map
    for(it; it != m.end(); it++)
    {   
        cout << "Key : " << it->first << "\nValue: " << it->second << endl;
    }
    // empty
    if(m.empty())
    {
        cout << "Map is empty" << endl;
    }
    else
    {
        cout << "Map is not empty" << endl; 
    }    
    // size
    cout << m.size() << endl;

    // clear
    m1.clear();
    if(m1.empty())
    {
        cout << "Map is empty" << endl;
    }
    else
    {
        cout << "Map is not empty" << endl; 
    }
    

    map<string, vector<int>> a;


    // find()  , finds a key
    int n;
    cin >> n;
    auto it1 = m.find(n);
    if(it1!=m.end())
        cout << n << " is found" << endl;
    else
    {
        cout << n << " is not found" << endl;
    }
    
    
    // UNORDERED MAP
    unordered_map<int, string> m;
    
    m[23] = "Kritika";
    m[41] = "Rohan";
    m[60] = "qwerty";
    m[100] = "qwert";
    m[12] = "Tanya";

    cout << m[23] << endl;

    // iterator
    unordered_map<int, string>::iterator it = m.begin();
    for(it; it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
  
  
    // SET and UNORDERED SET
    set<int> s;

    // insert
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(-1);

    set<int>::iterator it = s.begin();   // it is a pointer
    for(it; it != s.end(); it++)
    {
        cout << *it << endl;   // * gives the value stored in the pointer
    }

    // size()
    cout << s.size() << endl;

    // erase() - removes an element from the set
    s.erase(1);
    for(it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;   // * gives the value stored in the pointer
    }

    // find
    it = s.find(2);  // present - iterator to that element
    cout << *it << endl;


    // empty()
    s.empty() ? cout << "Set is Empty" << endl : cout << "Set is not Empty" << endl;

    // clear()
    s.clear();
    s.empty() ? cout << "Set is Empty" << endl : cout << "Set is not Empty" << endl;


    unordered_set<int> us;
    cout << us.size() << endl;
    
    
    // pair
    pair<int , char> p;
    p.first = 100;
    p.second = 'k';

    cout << p.first << " " << p.second << endl;

    p = make_pair(10, 'a');
    cout << p.first << " " << p.second << endl;

    pair<int, char> q;
    q = make_pair(10, 'a');

    if(p==q)  // p>=q , p<=q , p!=q , p=q
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not Same" << endl;
    }
    
    
    // TUPLE
    tuple<int, int, int, string> t{5, 2, 3, "Kritika"};

    // get<index = 0>(tuple_length = t)
    cout << get<0>(t) << get<1>(t) << get<2>(t) << " " << get<3>(t) << endl;   

    // make tuple
    tuple<int, int, int, string> t1;
    t1 = make_tuple(1, 2, 3, "Mahima");
    cout << get<0>(t1) << get<1>(t1) << get<2>(t1) << " " << get<3>(t1) << endl;   

    int x, y, z;
    string name;
    tie(x, y, z, name) = t;  // tie to unpack the values of a tuple
    cout << get<0>(t1) << get<1>(t1) << get<2>(t1) << " " << get<3>(t1) << endl;   


    // LIST
    // Declaration of list
    list<int> l1;

    // Declaration with initialization 
    list<int> l2{1,2,3,4};

    // iterator declaration
    list<int>::iterator it;
    it = l1.begin();

    // another way of declaring the iterator
    // automatically decides the datatype
    // we need to initialize the container here only
    auto it1 = l2.begin(); 

    for(it1; it1 != l2.end(); it1++)
    {
        cout << *it1 << " ";
    }
    cout << endl;

    // adding elements
    
    l1.push_back(1);  // 1
    l1.push_back(2);  // 1 2
    l1.push_back(3);  // 1 2 3
    l1.push_back(4);  // 1 2 3 4
    l1.push_front(5); // 5 1 2 3 4
    l1.push_front(6);  // 6 5 1 2 3 4
    l1.push_front(7);  // 7 6 5 1 2 3 4

    // deleting elements
    l1.pop_back();  // 7 6 5 1 2 3
    l1.pop_front();  // 6 5 1 2 3

    // remove
    l1.remove(1);  // 6 5 2 3  

    // size() - size of list
    cout << l1.size() << endl;

    // sort() - sort in ascending order
    l1.sort();
    for(it=l1.begin(); it != l1.end(); it++)
    {
        cout << *it << " ";
    }

    // sort in descending order
    l1.sort(greater<int>());
    for(it=l1.begin(); it != l1.end(); it++)
    {
        cout << *it << " ";
    }

    // clear() - clears the whole list
    l1.clear();
    
    
    // STACK
    // declaring stack
    stack<int> s;

    // PUSH()
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.top() << endl;

    // POP
    s.pop();
    cout << s.top() << endl;  // After removal

    // SIZE
    cout << s.size() << endl;

    // EMPTY
    s.empty() ? cout << "Empty Stack" << endl : cout << "Stack not Empty" << endl;

  return 0;
}
