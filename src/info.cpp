/*
 * info.cpp
 *
 *  Created on: Sep 26, 2020
 *      Author: HP
 */

#include "info.h"
// constructors
info::info()
{
	keyword = shelf = name = author = "";
}
info::info(string keyword, string author, string name, string shelf) :
		keyword(keyword), author(author), name(name), shelf(shelf)
{
}
;

// getters
string info::get_keyword() const
{
	return keyword;
}
string info::get_shelf() const
{
	return shelf;
}

string info::get_name() const
{
	return name;
}

string info::get_author() const
{
	return author;
}

// setters
void info::set_keyword (string keyword)
{
	this->keyword = keyword;
}
void info::set_shelf(string shelf)
{
	this->shelf = shelf;
}
void info::set_name(string name)
{
	this->name = name;
}
void info::set_author(string author)
{
	this->author = author;
}

// method
bool info::equals(info inf) const
{
	return (inf.author == author && inf.name == name && inf.shelf == shelf);
}
