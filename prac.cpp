#include <iostream>
#include <vector>

// #include <chrono>
// #include<thread>
using namespace std;

// #define MAXCAPACITY 5

// int buff[MAXCAPACITY];
// int mutex = 1;
// int empty = 0, full = MAXCAPACITY;
// int in = 1, out = 1;
// int item = 0;
// void wait(int &s)
// {
//     while (s <= 0)
//         ;
//     s--;
// }
// void signal(int &s)
// {
//     s++;
// }

// void produce()
// {
//     wait(empty);
//     wait(mutex);
//     item++;
//     buff[in] = item;
//     std::cout << "Produced data " << buff[in] << std::endl;
//     in = in % MAXCAPACITY + 1;
//     signal(mutex);
//     signal(full);
// }

// void consume()
// {
//     wait(full);
//     wait(mutex);

//     int citem = buff[out];
//     std::cout << " Consumed Data = " << buff[out] << std::endl;
//     out = out % MAXCAPACITY + 1;
//     signal(mutex);
//     signal(empty);
// }

// int main()
// {
//     in = 1, out = 1;
//     int i, NumThreads;
//     NumThreads = 5;

//     for (i = 0; i < 5; i++)
//     {
//         std::thread producers(&produce,null);
//         std::thread consumers(&consume,nullptr);
//     }

//     for (i = 0; i < NumThreads; i++)
//     {
//         producers.join();
//         consumers.join();
//     }
//     delete[] producers;
//     delete[] consumers;

// return 0;
// }
int avail[100];
int all[100][100];
int maximum[100][100];
int need[100][100];
int n, m;

void input()
{

    cout << "enter process:" << endl;
    cin >> n;

    cout << "enter resources:" << endl;
    cin >> m;
    cout << "enter available:" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> avail[i];
    }

    cout << "enter allocation:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> all[i][j];
        }
    }

    cout << "enter max:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maximum[i][j];
            need[i][j] = maximum[i][j] - all[i][j];
        }
    }
}
bool isSafe()
{
    vector<int> work(avail, avail + m);
    vector<bool> visited(n, false);

    int seq[n];
    int c = 0;
    while (c < n)
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
                    seq[c++] = i;
                    found = true;
                    for (int j = 0; j < m; j++)
                    {
                        work[j] += all[i][j];
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