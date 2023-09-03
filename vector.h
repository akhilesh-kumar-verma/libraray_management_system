/*
 * vector.h
 *
 *  Created on: 23-Aug-2020
 *      Author: HP
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include "iter.h"

class node;

class vector
{
	node **vals;
	int size;
	int range;

	//helper method
	void ensure_range(int new_range);
public:
	vector();

	//getters
	int get_size() const;
	int get_capacity() const;

	//methods
	iter get_begin() const;
	iter get_end() const;

	iter get_nth(int n) const;

	void insert_after(iter itr, node *val);
	void prepend(node *val);

	iter remove_after(iter itr);
	iter remove_first();

	node* get_valat(int n) const;
	void set_valat(int n, node *val);
};

#endif /* VECTOR_H_ */
