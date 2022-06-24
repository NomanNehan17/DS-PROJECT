#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

int TotalSize;
int MyArray[1000] = {0};

int menu();

void random()
{
    int i, j;
    // int MyArray[1000];
    int range;
    int siz;
    system("cls");
    cout << "Enter array size: ";
    cin >> siz;
    TotalSize = siz;
    cout << "Enter number range: ";
    cin >> range;
    for (i = 0; i < siz; i++)
    {
        MyArray[i] = 1 + (rand() % range);
    }

    /* cout << "Enter numbers: ";
     for(i=0; i< siz; i++)
     {
         cin >> MyArray[i];
     } */

    cout << endl
         << endl;
    cout << "Printing Generated........." << endl;
    for (i = 0; i < siz; i++)
    {
        cout << MyArray[i] << " ";
    }
    cout << endl
         << endl
         << endl;

    sort(MyArray, MyArray + siz);

    cout << "Printing Sorted........." << endl;
    for (int j = 0; j < siz; j++)
        cout << MyArray[j] << " ";

    cout << endl
         << endl;
    return;
}

void insert()
{
    int n, i, item, temp, flag = 0;

    n = TotalSize;

    cout << "Enter New Element to Insert: ";
    cin >> item;
    // MyArray[n] = item;

    for (i = n; i >= 0 + 1; i--)
    {
        if (MyArray[i - 1] < item)
        {
            MyArray[i] = item;
            break;
        }
        else
            MyArray[i] = MyArray[i - 1];
    }

    cout << endl
         << "The New Array is: " << endl;
    for (i = 0; i < n + 1; i++)
    {
        cout << MyArray[i] << " ";
    }
    cout << endl
         << endl;

    TotalSize += 1;
    // menu();

    return;
}

void delet()
{
    int i, pos, n;
    n = TotalSize;

    cout << "Enter Position: ";
    cin >> pos;
    pos = pos - 1;

    for (i = pos; i < n; i++)
    {
        MyArray[i] = MyArray[i + 1];
    }
    n--;

    cout << endl
         << "The New Array is: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << MyArray[i] << " ";
    }
    cout << endl
         << endl;

    TotalSize -= 1;
    // menu();
    return;
}

void del2()
{
    int n, i, num;
    n = TotalSize;
    cout << "Enter Number: ";
    cin >> num; // element

    int flg = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (MyArray[i] == num && MyArray[i + 1] != num)
        {
            MyArray[i] = MyArray[i + 1];
            flg = 1;
        }
        else if (flg == 1)
        {
            MyArray[i] = MyArray[i + 1];
        }
        else
            MyArray[i] = MyArray[i];
    }

    TotalSize -= 1;
    cout << endl
         << "The New Array is: " << endl;
    for (i = 0; i < n - 1; i++)
    {
        cout << MyArray[i] << " ";
    }

    return;
}

void search()
{
    int n, item;

    n = TotalSize;
    cout << endl
         << "Enter to search: ";
    cin >> item;

    int begin = 0, end = n - 1, loc = 0;
    int mid = (begin + end) / 2;
    while (begin <= end && MyArray[mid] != item)
    {
        if (item < MyArray[mid])
            end = mid - 1;
        else
            begin = mid + 1;
        mid = (begin + end) / 2;
    }
    if (MyArray[mid] == item)
    {
        loc = mid;
        cout << endl
             << endl
             << item << " is found at location " << loc + 1 << "!" << endl
             << endl;
    }
    else
        cout << endl
             << item << " is not found in the array!" << endl
             << endl;
    return;
}

void display()
{
    int i, n;
    n = TotalSize;

    cout << endl
         << "The Array is: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << MyArray[i] << " ";
    }
    cout << endl
         << endl;

    // menu();
    return;
}

int menu()
{
    cout << endl
         << "\tMenu" << endl
         << endl;
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Search" << endl;
    cout << "4. Display" << endl;
    cout << "5. Exit" << endl
         << endl;

    int input;
    cout << "Enter Menu Serial: ";
    cin >> input;

    if (input == 5)
        exit(0);
    else
        return input;
}

void splash()
{
    // system("cls");
    string welcm = "Welcome to the Project";
    cout << "\t";
    for (int i = 0; i < welcm.size(); i++)
    {
        cout << welcm[i];
        Sleep(100);
    }
    cout << endl
         << endl
         << endl;

    return;
}

int main()
{
    random();
    splash();

Menu:
    int user_select = menu();

    if (user_select == 1)
        insert();
    else if (user_select == 2)
    {
        int choice;
        cout << endl
             << "1. Delete by Number" << endl;
        cout << "2. Delete by Position" << endl;
        cout << endl
             << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            del2();
        else
            delet();
    }
    else if (user_select == 3)
        search();
    else if (user_select == 4)
        display();

    // system("cls");
    goto Menu;
    // cout << "Bangladesh" << endl << endl;

    return 0;
}
