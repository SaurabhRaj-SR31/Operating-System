#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r[100], t = 0, n, s, s1, c = 0;
    cout << "enter no.of request:" << endl;
    cin >> n;

    cout << "enter  requests:" << endl;
    for (int i = 0; i < n; i++)
    {

        cin >> r[i];
    }

    cout << "enter initial position of head:" << endl;
    cin >> s;
    cout << s << "-> ";
    while (c != n)
    {
        int minm = INT_MAX, d, index;
        for (int i = 0; i < n; i++)
        {
            d = abs(r[i] - s);
            if (minm > d)
            {
                minm = d;
                index = i;
            }
        }
        t += minm;
        cout << r[index] << "-> ";
        s = r[index];
        r[index] = INT_MAX;
        c++;
    }

    cout << endl;
    cout << "total:" << t << endl;
    return 0;
}