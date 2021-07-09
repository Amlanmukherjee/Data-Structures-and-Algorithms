#include <iostream>
#include <vector>

using namespace std;
template <class T>

void display(vector<T> &v)
{
    for(int i=0; i < v.size(); i++)
    {
        cout << v[i] <<" ";
    }
    cout << endl;
}

int32_t main()
{
    // WAYS TO CREATE VECTOR
    vector<int> vec1; //zero length vector
    vector<char> vec2(4); //4 element vector
    vector<char> vec3(vec2); //4 element vector from vec2
    vector<int> vec4(6, 3); // = {3, 3, 3, 3, 3, 3}
    
    // vec2.push_back('5');
    // display(vec2);

    display(vec4);

    // int element, n;
    // cout << "enter size of vector : ";
    // cin >> n;
    // for(int i=0; i<n; i++)
    // {
    //     cout <<"enter element :\n";
    //     cin >> element;
    //     vec1.push_back(element);
    // }
    //
    // display(vec1);
    // vec1.pop_back();
    // display(vec1);
    //
    // vector<int> :: iterator iter = vec1.begin();
    // vec1.insert(iter, 500);
    // display(vec1);

    return 0;
}
