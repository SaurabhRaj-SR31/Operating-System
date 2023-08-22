#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k, l, m, total_frames, total_pages;

    cout << "enter no. of pages:" << endl;
    cin >> total_pages;
    cout << "enter no. of frames:" << endl;
    cin >> total_frames;

    vector<int> pages(total_pages);
    vector<int> frames(total_frames, -1);
    vector<int> temp(total_frames);

    int a, b;
    int page_fault = 0, position;

    cout << "enter the pages:" << endl;
    for (int i = 0; i < total_pages; i++)
    {
        cin >> pages[i];
    }


    cout << "LRU algo:" << endl;
    cout << "str  pages  hit/fault" << endl;

    for (n = 0; n < total_pages; n++)
    {
    bool c = false;
        cout << pages[n] << "  ";
        a = 0, b = 0;
        for (m = 0; m < total_frames; m++)
        {
            if (frames[m] == pages[n])
            {
                a = 1;
                b = 1;
                break;
            }
        }
        if (a == 0)
        {
            for (m = 0; m < total_frames; m++)
            {
                if (frames[m] == -1)
                {
                    frames[m] = pages[n];
                    b = 1;
                    c = true;
                    page_fault++;
                    break;
                }
            }
        }
        if (b == 0)
        {
            for (m = 0; m < total_frames; m++)
            {
                temp[m] = 0;
            }
            for (k = n - 1, l = 1; l <= total_frames - 1; l++, k--)
            {
                for (m = 0; m < total_frames; m++)
                {
                    if (frames[m] == pages[k])
                    {
                        temp[m] = 1;
                    }
                }
            }
            for (m = 0; m < total_frames; m++)
            {
                if (temp[m] == 0)
                    position = m;
            }
            frames[position] = pages[n];
            c = true;
            page_fault++;
        }

        for (m = 0; m < total_frames; m++)
        {
            cout << frames[m] << " ";
        }
        if (c == true)
        {

            cout << "  F" << endl;
        }
        else
        {
            cout << "  H" << endl;
        }
    }
    cout << "Total Number of Page Faults:" << page_fault << endl;

    return 0;
}