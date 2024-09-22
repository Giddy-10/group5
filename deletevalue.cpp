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

int linearsearch()
{
    int x = getsearchval();
    for (int i = 0; i < n; i++)
    {
        if (list[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void deletevalue(int index=-1)
{
    if(index=-1)
    {
        cout << "Delete unsuccessful.\n";
        return;
    }
    for(int i=index; i < n-1; i++)
    {
        list[i] = list[i+1];
    }
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
}
