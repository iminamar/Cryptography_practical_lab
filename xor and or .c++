#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "amar";
    cout << "AND OPERTION WITH 0:" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        cout << char(s[i] & 0);
    }
    cout << "AND OPERTION WITH 127:" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        cout << char(s[i] & 127);
    }
    cout << endl;
    cout << "OR OPERTION WITH 0:" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        cout << char(s[i] || 0);
    }
    cout << "OR OPERTION WITH 127:" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        cout << char(s[i] || 127);
    }
    cout << endl;
    cout << "XOR OPERTION WITH 0:" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        cout << char(s[i] ^ 0);
    }
    cout << "XOR OPERTION WITH 127:" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        cout << char(s[i] ^ 127);
    }
    cout << endl;
    return 0;
}