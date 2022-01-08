#include <algorithm>
#include <iostream> 
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

void book(); // function to add book info
void bookList(); // function to list all book info
void library(); // function to add library info
void libraryList(); // function to list all library info 
void add(); //funtion to add library and ISBN
void find(); //funtion to find library by ISBN and count the copy number

// read user inputs and call functions
int main(){
    char input_1, input_2;

    cout << ">>>";
    cin >> input_1;

    bool EXIT = false;

    while (!EXIT){

        if (input_1 == 'a'){ // if input is equal to 'a'

            cin >> input_2;

            switch (input_2) { 
            case('b'):// if input is equal to 'b'
                book(); 
                break;
            case('l'): // if input is equal to 'l'
                library(); 
                break;
            case('h'): // if input is equal to 'h'
                add(); 
                break;
            default:
                cout << "Try Again" << endl; //if the input is invalid, show warning message
                main(); 
            }
        }
        if (input_1 == 'l'){ // if input is equal to 'l'
            
            cin >> input_2; 

            switch (input_2){ 
            case('b'): // if input is equal to 'b'
                bookList(); 
                break;
            case('l'): // if input is equal to 'l'
                libraryList(); 
                break;
            default:
                cout << "Try Again" << endl; //if the input is invalid, show warning message
                main(); 
            
            }
        }

        if (input_1 == 'f') // if input is equal to 'f'
            find(); 

        if (input_1 == 'q') // if input is equal to 'q'
            EXIT = true; // exit the loop

    }
}

// read ISBN, published year, author name, book title, and store them into a txt file
void book(){

    string ISBN, name, title; 
    int year; 

    bool isNotEmpty = false; 
    cin >> ISBN >> year >> name >> title; 
    ofstream bookDatabaseC("bookDatabase.txt", ios::app); 
    ifstream bookDatabaseO("bookDatabase.txt"); 

    if (!isNotEmpty) { 
        bookDatabaseC << ISBN << " " << year << " " << name << " " << title << "\n"; 
        bookDatabaseC.seekp(0, ios::end); 
    }  

    bookDatabaseC.close(); 
    main();
}

// read library name, city name, zip code, and store them into a txt file
void library(){

    string library, city; 
    int zip; 

    bool isNotEmpty = false; 

    cin >> library >> city >> zip; 
    ofstream libraryDatabaseC("libraryDatabase.txt", ios::app); 
    ifstream libraryDatabaseO("libraryDatabase.txt"); 

    if (!isNotEmpty){ 
        libraryDatabaseC << library << " " << city << " " << zip << "\n"; 
        libraryDatabaseC.seekp(0, ios::end); 
    } 

    libraryDatabaseC.close(); 
    main(); 
}

// read library name and ISBN then store them into a txt file
void add(){

    string library, ISBN;
    bool isNotEmpty = false; 
    cin >> library >> ISBN; 
    ofstream addDatabaseC("addDatabase.txt", ios::app); 
    ifstream addDatabaseO("addDatabase.txt"); 

    if (!isNotEmpty){ 
        addDatabaseC << library << " " << ISBN << "\n"; 
        addDatabaseC.seekp(0, ios::end);
    } 

    addDatabaseC.close();
    main(); 
}

// list up all books' information
void bookList(){

    string ISBN, name, title;
    int year;

    ifstream bookList("bookDatabase.txt"); 

    while (bookList >> ISBN >> year >> name >> title){ 
        cout << ISBN << " " << year << " " << name << " " << title << endl;
    }
    
    bookList.close(); 
    main();
}

// list up all library's list
void libraryList(){

    string library, city;
    int zip;
    ifstream libraryList("libraryDatabase.txt");

    while (libraryList >> library >> city >> zip) { 
        cout << library << " " << city << " " << zip << endl;
    }

    libraryList.close();
    main();

}

// find library and count them by ISBN
void find(){ 

    string inputISBN, getISBN, getName, getTitle, getLibrary, bookISBN;
    int getYear;

    bool isNotEmpty = false;
    cin >> inputISBN;
    vector<string> libraryData;

    ifstream addDatabaseO("addDatabase.txt");
        while (addDatabaseO >> getISBN >> getLibrary) { 

            isNotEmpty = true; 
            
            if (inputISBN == getISBN){ 

                ifstream bookDatabaseO("bookDatabase.txt");

                while(bookDatabaseO >> bookISBN >> getYear >> getName >> getTitle){

                    if(bookISBN == inputISBN){
                        libraryData.push_back(getLibrary);
                        int ans = count(libraryData.begin(), libraryData.end(), getLibrary);

                        cout << getLibrary << ": " << getISBN << " " << getYear << " " << getName << " " << getTitle << " Copy Number: " << ans << "\n";
                    }
                }    
            }
        }

    main();
}