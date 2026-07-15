# The Solace Lantern Library

A menu-driven C++ program that lets users manage a simple book library - add new books and view all saved entries. Book data is stored persistently in a text file, so information is saved between program runs.

## Features
- **Add a Book** - enter a title, author, genre, and rating (1-3)
- **View All Books** - display ever book currently saved
- **Persistent storage** - books are saved in a text file (`bookCollection.txt`) using file I/O, so data isn't lost when the program closes
- **Input validation** - handles invalid menu selections and non-numeric input without crashing

## Concepts Demonstrated

- File I/O with `ifstream` and `ofstream`
- Reading and writing text with `getline` vs. `cin >>`, and handling multi-word input (titles/authors with spaces)
- Converting between `string` and `int` with `stoi`
- Control structures: `do-while` loop, `if`/`else` conditionals
- Input validation using `cin.fail()`, `cin.clear()`, and `cin.ignore()`
- Variable scope and data types (`int`, `string`)

## How to Run
Compile and run using `clang++` (or any C++ compiler):

\`\`\`
clang++ library_system.cpp -o library_system
./library_system
\`\`\`

## Menu Options

\`\`\`
1. Add a Book
2. View All Books
3. Quit
\`\`\`

## What I Learned

This project deepend my understanding of file input/output in C++, especially the difference between `cin` >> (which stops at spaces) and `getline` (which reads a full line). I also learned how mixing these two input methods can leave leftover characters in the input buffer, and how to clear that with `cin.ignore()`. Debugging a crash caused by malformed data in the file taught methe importance of validating data before converting types, and of keeping stored data clean and consistently formatted.