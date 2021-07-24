/*
 * node.h
 *
 *  Created on: Sep 19, 2020
 *      Author: HP
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include "vector.h"
#include "info.h"
using namespace std;

class node
{
	char ch;
	info inf;
	vector children;
public:
	// constructors
	node();
	node(char ch);
	node(char ch, info inf);

	//getters
	char get_ch();
	info get_info();
	vector& get_children();

	//setters
	void set_info(info new_info);
};

#endif /* NODE_H_ */
