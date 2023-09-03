/*
 * trie.h
 *
 *  Created on: Sep 19, 2020
 *      Author: HP
 */

#ifndef TRIE_H_
#define TRIE_H_

#include <iostream>
#include "node.h"
#include "vector.h"

class trie
{
	node *root;
	string file;

	node* find_node(string key);
	void collect(node *x, stringstream &prefix, stringstream &results);
public:
	trie();
	trie(string file);
	~trie();

	info find(string key);
	void insert(string key, info inf);
	bool remove(string key);
	void find_byAuthor(string key, string &all, string &names,
			string &shelves) const;
	void find_byName(string keyword, string &_all, string &_names,
			string &_shelves) const;
	void words(string &all, string &names, string &authors,
			string &shelves) const;
	void infos(string str) const;
	vector keywords(string prefix);
	stringstream keys_with_string(string prefix);
};

#endif /* TRIE_H_ */
