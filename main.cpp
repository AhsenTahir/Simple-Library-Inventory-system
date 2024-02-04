#include <iostream>
#include <string>
using namespace std;

struct Book
{

    string title;
    string author;
    int publication_year;
    int available_quantity;

} book[100]; // i am taking the limit of the library to contain 100 books

void add_book(int *index)
{
    cin.ignore();
    cout << "enter the title for the book " << endl;

    getline(cin, book[*index].title); // to take the whole line as input (including spaces
    cout << "enter the author for the book " << endl;

    getline(cin, book[*index].author); // to take the whole line as input (including spaces
    cout << "enter the publication year for the book " << endl;
    cin >> book[*index].publication_year;

    cout << "enter the availability quantity for the book " << endl;
    cin >> book[*index].available_quantity;
    (*index)++; // incrementing it so that whenever i add a new boook , the index for the new book moves forward
}
void display_all_books(int *index)
{

    int i;
    for (i = 0; i < (*index); i++)
    {

        cout << "\nTitle = " << book[i].title << "\nAuthor = " << book[i].author << "\nPublication Year = "
             << book[i].publication_year << "\nAvailability quantity  = " << book[i].available_quantity << endl;
    }
}

void search_book(int *index)
{
    cin.ignore();
    cout << "enter the book title you want to find :" << endl;
    string input_book;

    getline(cin, input_book);

    int i;

    for (i = 0; i < (*index); i++)
    {
        if (input_book == book[i].title)
        {
            cout << "\nTitle = " << book[i].title << "\nAuthor = " << book[i].author << "\nPublication Year = "
                 << book[i].publication_year << "\nAvailability quantity  = " << book[i].available_quantity << endl;
        }
    }
    cout << "BOOK SEARCHED SUCCESSFULLY" << endl;
}

void check_out_book(int *index)
{
    string input_book;
    cin.ignore();
    cout << "ENTER THE TITLE OF THE BOOK YOU WANT TO CHECK OUT :\n";

    getline(cin, input_book);
    int i;
    for (i = 0; i < (*index); i++)
    {
        if (input_book == book[i].title)
        {
            if (book[i].available_quantity <= 0)
            {
                cout << "THE BOOK IS OUT OF STOCK CAN'T CHECK OUT " << endl;
                break;
            }
            book[i].available_quantity -= 1; // reducing the avaiablity quantity
            cout << "BOOK " << book[i].title << " CHECKED OUT SUCCESSFULLY " << endl;
        }
    }
}

void return_book(int *index)
{
    cout << "ENTER THE TITLE OF THE BOOK YOU WANT TO RETURN " << endl;
    string input;
    cin.ignore();

    getline(cin, input);
    int i;
    for (i = 0; i < *index; i++)
    {
        if (input == book[i].title)
        {
            cout << "RETURNING THE BOOK " << input << endl;
            book[i].available_quantity++;
        }
    }
}
int main()
{
    int index = 0;
    int exit = 0;
    while (1) // for continous inputs
    {

        cout << "1. Add a book to the library.\n2. Display the list of all books in the library.\n3. Search for a book by its title.\n4. Check out a book (reduce the available quantity).\n5. Return a book (increase the available quantity)\n6.exit " << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "YOU ARE ADDING A BOOK \n"
                 << endl;
            add_book(&index);
            break;
        case 2:
            cout << "DISPLAYING ALL THE BOOKS IN THE LIBRARY \n"
                 << endl;
            display_all_books(&index);
            break;

        case 3:
            cout << "SEARCHING FOR A BOOK BY ITS TITLE  \n"
                 << endl;
            search_book(&index);
            break;
        case 4:
            cout << "CHECKING OUT A BOOK   \n"
                 << endl;
            check_out_book(&index);
            break;
        case 5:
            cout << "RETURNING A BOOK " << endl;
            return_book(&index);
            break;
        case 6:
            cout << "EXITING THE LOOP " << endl;
            exit = 1;
            break;
        }
        if (exit == 1)
        {
            break;
        }
    }
    return 0;
}