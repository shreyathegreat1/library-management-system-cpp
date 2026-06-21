#include <iostream>
using namespace std;

class Library
{
public:
    string bookName[10];
    bool issued[10];
    int count = 0;

    // Add Book
    void addBook()
    {
        if (count == 10)
        {
            cout << "Library is full!\n";
            return;
        }

        cin.ignore();
        cout << "Enter Book Name: ";
        getline(cin, bookName[count]);

        issued[count] = false;
        count++;

        cout << "Book Added Successfully!\n";
    }

    // View Books
    void viewBooks()
    {
        if (count == 0)
        {
            cout << "No books available.\n";
            return;
        }

        cout << "\nBOOK LIST\n";

        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << ". " << bookName[i];

            if (issued[i])
                cout << " (Issued)";
            else
                cout << " (Available)";

            cout << endl;
        }
    }

    // Issue Book
    void issueBook()
    {
        int n;

        viewBooks();

        cout << "Enter Book Number to Issue: ";
        cin >> n;

        if (n >= 1 && n <= count)
        {
            if (issued[n - 1])
            {
                cout << "Book is already issued.\n";
            }
            else
            {
                issued[n - 1] = true;
                cout << "Book Issued Successfully!\n";
            }
        }
        else
        {
            cout << "Invalid Book Number!\n";
        }
    }

    // Return Book
    void returnBook()
    {
        int n;

        viewBooks();

        cout << "Enter Book Number to Return: ";
        cin >> n;

        if (n >= 1 && n <= count)
        {
            if (!issued[n - 1])
            {
                cout << "This book was not issued.\n";
            }
            else
            {
                issued[n - 1] = false;
                cout << "Book Returned Successfully!\n";
            }
        }
        else
        {
            cout << "Invalid Book Number!\n";
        }
    }
};

int main()
{
    Library lib;
    int choice;

    do
    {
        cout << "\nLIBRARY MANAGEMENT SYSTEM\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            lib.addBook();
            break;

        case 2:
            lib.viewBooks();
            break;

        case 3:
            lib.issueBook();
            break;

        case 4:
            lib.returnBook();
            break;

        case 5:
            cout << "Thank you for using the Library Management System!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
