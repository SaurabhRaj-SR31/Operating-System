#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r[100], t=0, n, s;
    cout << "enter no.of request:" << endl;
    cin >> n;

    cout << "enter  requests:" << endl;
    for (int i = 0; i < n; i++)
    {

        cin >> r[i];
    }

    cout << "enter initial position of head:" << endl;
    cin >> s;

    t += abs(s - r[0]);
    cout << s << "-> " << r[0] << "-> ";

    for (int i = 1; i < n; i++)
    {
        t += abs(r[i] - r[i - 1]);
        cout << r[i] << "-> ";
    }

    cout << endl;
    cout << "total:" << t << endl;
    return 0;
}
