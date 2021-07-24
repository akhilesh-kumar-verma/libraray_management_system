/*
 * itertor.h
 *
 *  Created on: 28-Aug-2020
 *      Author: HP
 */

#ifndef ITER_H_
#define ITER_H_

#include <iostream>

class node;
class iter
{
	node **vals;
	int index;
public:
	//constructor
	iter()
	{
		vals = NULL;
		index = -1;
	}
	iter(node **vals, int index);

	//getters
	node* get_val() const;
	int get_index() const;

	//setters
	void set_val(node *new_val);

	//methods
	void move_next();
	bool equals(iter itr) const;
};

#endif /* ITER_H_ */
