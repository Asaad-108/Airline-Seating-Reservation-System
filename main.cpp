#include <iostream>
#include <fstream>
const int rows = 13;
const int cols = 6;
const int frist_class = 2;
const int business_class = 7;
const int economy_class = 13;
using namespace std;
void read(ifstream &fin, char **array)
{
    char temp;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fin >> temp;
            array[i][j] = temp;
        }
    }
}
void display(char **array)
{

    cout << "\tA\tB\tC\tD\tE\tF" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "Rows " << i + 1 << "\t";
        for (int j = 0; j < cols; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}
void delete_2D(char **array, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}
void assign_seat(char **array, int i, int j)
{
    array[i][j] = 'X';
}
int column_number(char c)
{
    int n = 0;
    if (c == 'A')
    {
        n = 1;
        return n;
    }
    else if (c == 'B')
    {
        n = 2;
        return n;
    }
    else if (c == 'C')
    {
        n = 3;
        return n;
    }
    else if (c == 'D')
    {
        n = 4;
        return n;
    }
    else if (c == 'E')
    {
        n = 5;
        return n;
    }
    else if (c == 'F')
    {
        n = 6;
        return n;
    }
}
int main()
{
    ifstream fin;
    fin.open("seating_plan.txt");
    char **array = NULL;
    array = new char *[rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new char[cols];
    }
    read(fin, array);
    char choice;
    int chooseClass = 0;
    int num = 0;

    do
    {
        cout << "press 1: to see the seating plan" << endl;
        cout << "press 2: to reserved a seat you want" << endl;
        cout << "press 3: to exit the program" << endl;
        cin >> num;
        if (num == 1)
        {
            cout << " * means the seat is aviable and X means the seat is already reserved  " << endl;
            display(array);
        }
        else if (num == 2)
        {
            cout << "press 1: for Frist class (rows 1-2)" << endl;
            cout << "press 2: for Business class (rows 3-7)" << endl;
            cout << "press 3: for Economy class (rows 8-13)" << endl;
            cin >> chooseClass;

            int r = 0;
            int c = 0;
            char a;
            cout << "enter the seat number you want " << endl;
            cout << "enter the row number" << endl;
            cin >> r;
            cout << "enter the column " << endl;
            cin >> a;
            c = column_number(a);
            if (chooseClass == 1 && r <= 0 || chooseClass == 1 && r > 2 || chooseClass == 2 && r <= 2 && chooseClass == 2 && r > 7 || chooseClass == 3 && r <= 7 || chooseClass == 3 && r > 13)
            {
                cout << "invalid seat selection :" << endl;
                break;
            }

            r = r - 1;
            c = c - 1;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (array[r][c] == '*')
                    {
                        assign_seat(array, r, c);
                        cout << "your seat is reserved:" << endl;
                        break;
                    }
                    else if (array[r][c] == 'X')
                    {
                        cout << "seat is already reserved tryanother seat:" << endl;
                        break;
                    }
                    else
                    {
                        cout << "invalid option" << endl;
                        break;
                    }
                }
                break;
            }
        }
        else if (num == 3)
        {
            break;
        }
        else
        {
            cout << "invalid choice" << endl;
        }
        cout << "do you want to continue ? if yes press y / if no press n:" << endl;
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "the program is ended" << endl;

    delete_2D(array, rows);
    return 0;
}