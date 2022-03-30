#include <iostream>
using namespace std;

int fire(int n, int k)
{
    if (n == 1)
        return 1;
    else
        return (fire(n - 1, k) + k - 1) % n + 1;
}
int main()
{
    int n , k;
    cin>> n >>k;
    cout << fire(n, k);
    return 0;
}
