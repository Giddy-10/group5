#include <iostream>

using namespace std;

int n;
int list[100];

void getvalues()
{
    cout << "How many values?\n";
    cin >> n;
    cout << "\nWrite the values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
}

void display()
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << list[i] << "\t";
    }
    cout << "\n";
}

void selectionsort()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (list[j] < list[i])
                swap(list[i], list[j]);
        }
    }
}

int getsearchval()
{
    int x;
    cout << "\nSearch for: ";
    cin >> x;
    return x;
}

void searchresult(int status, int x, int index = 0)
{
    if (status == 0)
    {
        cout << x << " was found at index " << index << ".\n\n";
    }
    else
    {
        cout << x << " was not found.\n\n";
    }
}

void linearsearch()
{
    int x = getsearchval();
    for (int i = 0; i < n; i++)
    {
        if (list[i] == x)
        {
            searchresult(0, x, i);
            return;
        }
    }
    searchresult(1, x);
}

void binarysearch()
{
    int min, max, mid, x;
    min = 0;
    max = n;
    mid = (max + min) / 2;

    x = getsearchval();

    selectionsort();

    while (max >= min)
    {
        int midval = list[mid];
        if (midval == x)
        {
            searchresult(0, x, mid);
            return;
        }
        else if (midval > x)
        {
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
        mid = (max + min) / 2;
    }
    searchresult(1, x);
}

int main()
{
    getvalues();

    int alg = 0;
    while (alg != 1 && alg != 2)
    {
        cout << "\n1:\tLinear Search\n2:\tBinary Search\n\n1 or 2: ";
        cin >> alg;
    }

    if (alg == 1)
    {
        linearsearch();
    }
    else
    {
        binarysearch();
    }
}
