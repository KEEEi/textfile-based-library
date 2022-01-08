# textfile based library database
This is the program that keeps track of libraries, books, and library holdings (of books.) This program should essentially prompt the user to enter a one letter command, and process the command.

## Command
- a (for add), which should then read in one of:
  - b, which should then read a string (with no spaces) representing an ISBN, an integer
    representing a published year, a string (with no spaces) representing an author name,
    and then a string (possibly with spaces) representing a book title. 
  - l (i.e. lowercase ’L’), which should then read a string (with no spaces) representing the
    name of a library, another string (with no spaces) representing the city name for the
    library, and in integer representing the zip code for the library. 
  - h, which should then read a string (with no spaces in it) representing an ISBN and
    another string (with no spaces in it) representing a Library. This pair would represent
    a new book to add to the specified library. If the book is a new book in that library, it
    should be considered copy #1 of that book in that library. If it is the second time that
    the book has been added to the library, then it should be considered copy #2, and so
    on. 
 
- l (that is, the letter ’l’ for ”list”), which should then read in one of:
  - b, which should list all of the books, including ISBN number, published date, author
    name, and book title. The book does not have to be part of any library’s holdings to be
    in this listing (but the book could be part of a library’s holdings.)
  - l (lowercase ’L’), which should list all of the libraries, including the names, locations,
    and zip codes of each library.
    
- f (for ”find”), which should also read in the ISBN of a book. It should then print out each
    library holding that matches this book, being sure to include the library name, the ISBN
    number, the publish date, the author name, the book title, and the copy number.

- q (for ”quit”), which should stop the running program.

## Example Execution
Suppose the first time you run the program, you do the following (>>> is the program’s prompt to
the user):
```
>>> a b 654321 2020 Tanaka C++!
>>> a b 123456 2002 Hasegawa Java is Cool!
>>> l b
654321 2020 Tanaka C++!
123456 2002 Hasegawa Java is Cool!
```
Then, suppose you run the program again (possibly without stopping the above running pro-
gram):
```
>>> a b 666 1991 Gates Windows for All
>>> l b
654321 2020 Tanaka C++!
123456 2002 Hasegawa Java is Cool!
666 1991 Gates Windows for All
>>>q
```
