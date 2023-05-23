#include <bits/stdc++.h>
using namespace std;
bool primeNumber(long int n)
{
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

long int squareRoot(long int num)
{
    int count = 0;
    for (int n = 1; n <= num; n += 2)
    {
        num = num - n;
        count++;
        if (num == 0)
            break;
    }
    cout << count;
}

int main()
{
    long int n;
    cin >> n;
    // cout << "Square Root: " << squareRoot(n);
    if (primeNumber(n))
    {
        cout << "TRUE\n";
    }
    else
    {
        cout << "FALSE\n";
    }
    return 0;
}
// wap to find the square root of a large interger number of the range long int efficiently using use a user defined fucntion
// wap to check a large interger number of the range long int is prime or not using the user defined funtion of the previous experiment