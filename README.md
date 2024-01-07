<!---This ReadMe is a MarkDown File--->

# Library Management System (Trie Data Structure)

This is an implementation of the Trie Data Structure to store, access the
list of books present in a library. The Trie data structure is selected
because of its fast access, insertion, deletion (time complexity
proportional to length of key). This is done using C++ programming language
and files are used for database.

## Overview

In this project an interactive console application is made to interface the
data stored in the data structure. The operations supported in this project
include:
* Insertion of new book to database
* Issue of book from set of books in database (Delete)
* Return of issued book to database (Insert again)
*  Search of Book Keyword (By name, exploiting Trie functions)
* Search by Author/ Name (Traversal in a Trie)
* List all entries in the data base (Traversal)

The operations on Trie used are:
* Insert
* Delete
* Search
* Traversal

In addition to the data structure's implementation the project also
implements a database using text files to store data permanently. This is a
naive and inefficient implementation of the DBMS but the Trie is storing the
database so was required to be done in here only.

The 'test' folder already contains a file called file.txt containing data
for a set of books already present in library and the state is written to
this file on exit from program.

## Dependencies and Setup Instructions

In order to compile this C++ code you will need a C++ compiler. Following
command will compile and write the executable in test director where sample
file.txt is present to test the system. In this path is according to windows
notation.

```
g++ project.cpp trie.cpp file_handling.cpp info.cpp iter.cpp node.cpp vector.cpp -o test\project.exe
```

## Possible Improvements

* I prepared this for implementation of Trie Data Structure only as college
project. B/B+ trees are better suited for this task of database management.
* Only console app is made as interface of it. GUI and especially command
line interface can be made to support scripting on top of it.
