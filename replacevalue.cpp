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

int binarysearch()
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
            return mid;
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
    return -1;
}

void replacevalue(int index=-1)
{
    if(index == -1)
    {
        cout << "Unsuccessful. Value not found.\n";
        return;
    }

    int x;
    cout << "\nNew value: ";
    cin >> x;

    list[index] = x;
    selectionsort();
    cout << "Value successfully replaced.\n";
}

int main()
{
    getvalues();

    int index = binarysearch();
    replacevalue(index);

    display();
}
