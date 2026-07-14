#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    //Declare Variables
    int choice, bookRating;

    string bookTitle,
           bookAuthor,
           bookGenre,
           bookRatingStr;

    //Start of 'The Solace Latern Library' management  system
    cout << "INSTRUCTIONS: Use the below menu to access THE SOLACE LATERN LIBRARY management system by entering the desired number (1-3) to access our book managment system.\n";

    //Library system management system - start of the do-while loop
    do {
        cout << "\n1. Add a Book\n";
        cout << "\n2. View All Books\n";
        cout << "\n3. Quit\n";

        cout << "\nEnter number choice (1-3) to run the program: ";
        cin >> choice;

        if (cin.fail()){
           cin.clear();
           cin.ignore(1000, '\n');
           cout << "\nERROR: Invalid input. Please enter a number." << endl;

           continue; //continues the loop if user inputs incorrect number
        }

        //Add Book to library system
        if (choice == 1){

            cin.ignore(1000, '\n'); //needed to clear leftover key entry from cin >> choice

            cout << "Add book title: ";
            getline(cin, bookTitle);

            cout << "Add book author: ";
            getline(cin, bookAuthor);

            cout << "Add book genre: ";
            getline(cin, bookGenre);

            cout << "Add a book rating (1-5): ";
            cin >> bookRating;

            ofstream addBook;
            addBook.open("bookCollection.txt", ios::app);
            addBook << bookTitle << endl;
            addBook << bookAuthor << endl;
            addBook << bookGenre << endl;
            addBook << bookRating << endl;

            addBook.close(); //close add book
        }

        //View books in the library system
        if (choice == 2){
            ifstream savedBook;
            savedBook.open("bookCollection.txt");

            while (getline(savedBook,bookTitle)){
                getline(savedBook, bookAuthor);
                getline(savedBook, bookGenre);
                getline(savedBook, bookRatingStr);

                if (!bookRatingStr.empty()){
                    bookRating = stoi(bookRatingStr);
                }
            
                bookRating = stoi(bookRatingStr); //convert string to int

                cout << "Title: " << bookTitle << endl;
                cout << "Author: " << bookAuthor << endl;
                cout << "Genre: " << bookGenre << endl;
                cout << "Rating: " << bookRating << endl;
            }

            savedBook.close(); //close saved book
        }

        //
        if ((choice != 1) && (choice != 2) && (choice != 3)){
            cout << "\nERROR: Invalid choice selected. Please try again.\n" << endl;
        }

    } while (choice != 3);

    return 0;
}