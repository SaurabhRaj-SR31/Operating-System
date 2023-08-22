#include <iostream>
#include <vector>
#define M 10
using namespace std;

void first_fit()
{
    int n, m;
    cout << "enter no. of blocks :" << endl;
    cin >> n;
    cout << "enter no. of processes :" << endl;
    cin >> m;
    vector<int> b(n);
    vector<int> p(m);
    vector<int> allocation(m, -1);

    cout << "enter size of blocks :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    cout << "enter size of processes :" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[j] >= p[i])
            {
                allocation[i] = j;
                b[j] -= p[i];
                break;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << i + 1 << " " << p[i] << " ";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1;
        }
        else
        {
            cout << "not allocated";
        }
        cout << endl;
    }
}

void best_fit()
{
    int n, m;
    cout << "enter no. of blocks :" << endl;
    cin >> n;
    cout << "enter no. of processes :" << endl;
    cin >> m;
    vector<int> b(n);
    vector<int> p(m);
    vector<int> allocation(m, -1);

    cout << "enter size of blocks :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    cout << "enter size of processes :" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }

    for (int i = 0; i < m; i++)
    {
        int bestidx = -1;
        for (int j = 0; j < n; j++)
        {
            if (b[j] >= p[i])
            {
                if (bestidx == -1)
                {
                    bestidx = j;
                }
                else if (b[bestidx] > b[j])
                {
                    bestidx = j;
                }
            }
        }
        if (bestidx != -1)
        {
            allocation[i] = bestidx;
            b[bestidx] -= p[i];
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << i + 1 << " " << p[i] << " ";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1;
        }
        else
        {
            cout << "not allocated";
        }
        cout << endl;
    }
}
void worst_fit()
{
    int n, m;
    cout << "enter no. of blocks :" << endl;
    cin >> n;
    cout << "enter no. of processes :" << endl;
    cin >> m;
    vector<int> b(n);
    vector<int> p(m);
    vector<int> allocation(m, -1);

    cout << "enter size of blocks :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    cout << "enter size of processes :" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }

    for (int i = 0; i < m; i++)
    {
        int bestidx = -1;
        for (int j = 0; j < n; j++)
        {
            if (b[j] >= p[i])
            {
                if (bestidx == -1)
                {
                    bestidx = j;
                }
                else if (b[bestidx] < b[j])
                {
                    bestidx = j;
                }
            }
        }
        if (bestidx != -1)
        {
            allocation[i] = bestidx;
            b[bestidx] -= p[i];
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << i + 1 << " " << p[i] << " ";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1;
        }
        else
        {
            cout << "not allocated";
        }
        cout << endl;
    }
}
int main()
{
    first_fit();
    best_fit();
    worst_fit();

    return 0;
}
