#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;

    cout << "enter no. of pages:" << endl;
    cin >> n;
    cout << "enter no. of frames:" << endl;
    cin >> m;

    vector<int> frame(m, -1); 
    vector<int> rs(n);

    cout << "enter the pages:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> rs[i];
    }

    int j = 0, avail, c = 0;
    cout << "FIFO algo:" << endl;
    cout << "str  pages  hit/fault" << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << rs[i] << "    ";
        avail = 0;
        for (int k = 0; k < m; k++)
        {
            if (frame[k] == rs[i])
            {
                avail = 1;
                for (int k = 0; k < m; k++)

                {
                    cout << frame[k] << " ";
                }
                cout << "  H" << endl;
            }
        }
        if (avail == 0)
        {
            frame[j] = rs[i];
            j = (j + 1) % m;
            c++;
            for (int k = 0; k < m; k++)

            {
                cout << frame[k] << " ";
            }
            cout << "  F" << endl;
        }
        cout << endl;
    }
    cout << "no. of page faults : " << c << endl;

  
    

    return 0;
}