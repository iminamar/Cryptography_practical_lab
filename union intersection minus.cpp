#include <bits/stdc++.h>
using namespace std;

void print_union_intersection(vector<int> v)
{
    int s = v.size();
    map<int, int> mp;
    for (int i = 0; i < s; i++)
    {
        mp[v[i]]++;
    }

    cout << "A UNION B\n{ ";
    for (auto i : mp)
    {
        cout << i.first << " ";
    }
    cout << "}\n";

    cout << "A Intersection B\n{ ";
    for (auto i : mp)
    {
        if (i.second > 1)
        {
            cout << i.first << " ";
        }
    }
    cout << "}\n";
}

void diff(int a[], int b[], int n, int m)
{
    map<int, int> mp;
    for (int i = 0; i < m; i++)
    {
        mp[b[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp[a[i]] == 0)
        {
            cout << a[i] << " ";
        }
    }
}
int main()
{
    int n = 5, m = 6;
    int a[n] = {0, 1, 4, 6, 8};
    int b[m] = {2, 3, 5, 6, 7, 8};
    vector<int> v;
    for (int i = 0; i < m + n; i++)
    {
        if (i < n)
        {
            v.push_back(a[i]);
        }
        else
        {
            v.push_back(b[i - n]);
        }
    }
    print_union_intersection(v);
    diff(a, b, n, m);
    return 0;
}
// below difference function runs in O(n^2)
// void difference(int a[], int b[], int n, int m)
// {
//     int count = 0;
//     int j;
//     cout << "A - B\n{ ";
//     for (int i = 0; i < n; i++)
//     {
//         for (j = 0; j < m; j++)
//         {
//             if (a[i] == b[j])
//             {
//                 break;
//             }
//         }
//         if (j == m)
//         {
//             cout << a[i] << " ";
//         }
//     }
//     cout << " }";
// }