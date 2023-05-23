#include <bits/stdc++.h>
using namespace std;
long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

long lcm(long a, long b)
{
    return a * b / gcd(a, b);
}
void primeFactors(long n, vector<long> &factors)
{
    long c = 2;
    while (n > 1)
    {
        if (n % c == 0)
        {
            factors.push_back(c);
            n /= c;
        }
        else
            c++;
    }
}

long findLCMUsingPrimeFactorization(long a, long b)
{
    long ans = 1;
    vector<long> factors1;
    vector<long> factors2;
    primeFactors(a, factors1);
    primeFactors(b, factors2);

    map<long, int> mp;
    map<long, int> mp2;
    for (int i = 0; i < factors1.size(); i++)
    {
        mp[factors1[i]]++;
    }
    for (int i = 0; i < factors2.size(); i++)
    {
        mp2[factors2[i]]++;
    }
    for (auto i : mp)
    {
        if (mp2.find(i.first) != mp2.end())
        {
            ans = ans * pow(i.first, max(i.second, mp2[i.first]));
        }
        else
        {
            ans = ans * pow(i.first, i.second);
        }
    }
    for (auto i : mp2)
    {
        if (mp.find(i.first) == mp.end())
        {
            ans = ans * pow(i.first, i.second);
        }
    }
    return ans;
}

int main()
{
    long a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    long result = findLCMUsingPrimeFactorization(a, b);
    cout << "LCM of " << a << " and " << b << " is: " << result << endl;
    return 0;
}
