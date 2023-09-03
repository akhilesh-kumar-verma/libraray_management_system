//============================================================================
// Name        : project.cpp
// Author      : Akhilesh Kumar Verma
// Version     :
// Copyright   : Your copyright notice
// Description : Project for library management
//============================================================================
#include <iostream>
#include <sstream>
#include "trie.h"
#include "file_handling.h"
using namespace std;

int main()
{
	// trie library ("file.txt");
	trie library;
	file_handling_beg(library, "file.txt");
	bool ch = true;
	while (ch)
	{
		cout << "Selection menu:" << endl;
		cout << "1.    Insert" << endl;
		cout << "2.    Delete" << endl;
		cout << "3.    Search by keyword" << endl;
		cout << "4.    List all books" << endl;
		cout << "5.    Search" << endl;
		cout << "0.    Exit" << endl;
		cout << "Enter your choice: " << flush;
		char input;
		cin >> input;
		switch (input)
		{
		case '1':
		{
			cout << "Enter the keyword to be inserted: " << flush;
			string keyword;
			cin >> keyword;

			cout << "Enter the Name of the book: " << flush;
			string name;
			cin >> name;

			cout << "Enter the Author of the book: " << flush;
			string author;
			cin >> author;

			cout << "Enter the Shelf details: " << flush;
			string shelf;
			cin >> shelf;

			library.insert(keyword, info(keyword, author, name, shelf));
		}
			break;
		case '2':
		{
			cout << "Enter the keyword to be deleted: " << flush;
			string keyword;
			cin >> keyword;

			library.remove(keyword);
		}
			break;
		case '3':
		{

			stringstream str;
			string keyword;
			while (true)
			{
				cout << "Enter the keyword: " << str.str() << flush;
				string st;
				cin >> st;
				str << st;
				cout << library.keys_with_string(str.str()).str() << endl;
				cout << "Have you found it? " << flush;
				string choice;
				cin >> choice;
				if (choice == "Y" || choice == "y" || choice == "yep"
						|| choice == "yes")
				{
					break;
				}
			}

			keyword = str.str();
			info book = library.find(keyword);

			cout << "Selection menu:" << endl;
			cout << "1.    Author" << endl;
			cout << "2.    Complete name of book" << endl;
			cout << "3.    Shelf" << endl;
			cout << "4.    Keyword" << endl;
			cout << "5.    All" << endl;
			cout << "Enter your choice: " << flush;
			char input;
			cin >> input;

			switch (input)
			{
			case '1':
				cout << "Author: " << book.get_author() << endl;
				break;
			case '2':
				cout << "Name: " << book.get_name() << endl;
				break;
			case '3':
				cout << "Shelf: " << book.get_shelf() << endl;
				break;
			case '4':
				cout << "Keyword: " << book.get_keyword() << endl;
				break;
			case '5':
				cout << "Keyword: " << book.get_keyword() << endl;
				cout << "Name: " << book.get_name() << endl;
				cout << "Author: " << book.get_author() << endl;
				cout << "Shelf: " << book.get_shelf() << endl;
				break;
			default:
				cout << "Enter valid choice" << endl;
			}
		}
			break;
		case '4':
		{
			string all, authors, names, shelves;
			library.words(all, names, authors, shelves);

			cout << "Selection menu:" << endl;
			cout << "1.    Author" << endl;
			cout << "2.    Complete name of book" << endl;
			cout << "3.    Shelf" << endl;
			cout << "4.    All" << endl;
			cout << "Enter your choice: " << flush;
			char input;
			cin >> input;

			switch (input)
			{
			case '1':
				cout << "List of all authors" << endl;
				cout << authors << endl;
				break;
			case '2':
				cout << "List of all books" << endl;
				cout << names << endl;
				break;
			case '3':
				cout << "List of all occupied shelves" << endl;
				cout << shelves << endl;
				break;
			case '4':
				cout << "List of all books" << endl;
				cout << all << endl;
				break;
			default:
				cout << "Enter valid choice" << endl;
			}
		}
			break;
		case '5':
		{
			cout << "Selection menu:" << endl;
			cout << "1.    by Author" << endl;
			cout << "2.    by Name" << endl;
			cout << "Enter your choice: " << flush;
			char input;
			cin >> input;

			switch (input)
			{
			case '1':
			{
				cout << "Enter the name author: " << flush;
				string author, all, names, shelves;
				cin >> author;
				library.find_byAuthor(author, all, names, shelves);
				cout << "List of all books" << endl;
				cout << all;
			}
				break;
			case '2':
			{
				cout << "Enter the name of Book: " << flush;
				string name, all, authors, shelves;
				cin >> name;
				library.find_byName(name, all, authors, shelves);
				cout << "List of all books" << endl;
				cout << all;
			}
				break;
			default:
				cout << "Wrong input." << endl;
			}

		}
			break;
		case '0':
			ch = false;
			break;
		default:
			cout << "Enter valid choice." << endl;
		}
	}
	library.infos("file.txt");
	return 0;
}

/*
 #include <sstream>
 #include <iostream>
 #include "trie.h"
 #include "file_handling.h"
 using namespace std;

 int main()
 {
 // trie library ("file.txt");
 trie library;
 file_handling_beg(library, "file.txt");

 stringstream str;
 while (true)
 {
 cout << str.str() << endl;
 string st;
 cin >> st;
 str << st;
 cout << library.keys_with_string(str.str()).str() << endl;
 cout << "Have you found it" << endl;
 string choice;
 cin >> choice;
 if (choice == "Y" || choice == "y" || choice == "yep" || choice == "yes")
 {
 break;
 }
 }
 return 0;
 }
 */
