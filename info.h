/*
 * info.h
 *
 *  Created on: Sep 26, 2020
 *      Author: HP
 */

#ifndef INFO_H_
#define INFO_H_

#include <iostream>
using namespace std;

class info
{
	string keyword;
	string author;
	string name;
	string shelf;
public:
	// constructors
	info();
	info(string keyword, string name, string author, string shelf);

	// getters
	string get_keyword() const;
	string get_shelf() const;
	string get_name() const;
	string get_author() const;

	// setters
	void set_keyword(string keyword);
	void set_shelf(string shelf);
	void set_name(string name);
	void set_author(string author);

	// method
	bool equals(info inf) const;
};

#endif /* INFO_H_ */
