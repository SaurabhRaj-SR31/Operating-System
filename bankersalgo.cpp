#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

int n; 
int m; 

int available[MAXN];       
int allocation[MAXN][MAXN]; 
int max_need[MAXN][MAXN];   
int need[MAXN][MAXN];      
   

void input()
{
    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the number of resources: ";
    cin >> m;

    cout << "Enter the available resources: ";
    for (int i = 0; i < m; i++)
    {
        cin >> available[i];
    }

    cout << "Enter the allocation matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> allocation[i][j];
        }
    }

    cout << "Enter the max need matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> max_need[i][j];
            need[i][j] = max_need[i][j] - allocation[i][j];
        }
    }
}

bool isSafe()
{
    vector<int> work(available, available + m);
    vector<bool> visited(n, false);
    int seq[n];
    int count = 0;

    while (count < n)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bool safe = true;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        safe = false;
                        break;
                    }
                }
                if (safe)
                {
                    visited[i] = true;
                    seq[count++] = i;
                    found = true;

                    for (int j = 0; j < m; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                }
            }
        }
        if (!found)
        {
            return false;
        }
    }

    for (auto i : seq)
    {
        cout << i << " ";
    }
    return true;
}

int main()
{
    input();

    if (isSafe())
    {
        cout << "The system is safe." << endl;
    }
    else
    {
        cout << "The system is not safe." << endl;
    }

    return 0;
}
