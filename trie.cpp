/*
 * trie.cpp
 *
 *  Created on: Sep 19, 2020
 *      Author: HP
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "trie.h"

// constructor
trie::trie()
{
	root = new node();
	file = "";
}

trie::trie(string file)
{
	string str[4];
	ifstream fin(file);
	if (!fin)
	{
		return;
	}
	while (!fin.eof())
	{
		for (int i = 0; i < 4; i++)
		{
			fin >> str[i];
		}
		insert(str[0], info(str[0], str[1], str[2], str[3]));
	}
	fin.close();
}

trie::~trie()
{
	cout << file << endl;
	if (file != "")
	{
		infos(file);
	}
}

node* trie::find_node(string key)
{
	node *ptr = root;
	for (unsigned int i = 0; i < key.size(); ++i)
	{
		char k = key[i];
		node *next = NULL;
		for (iter itr = ptr->get_children().get_begin();
				!ptr->get_children().get_end().equals(itr); itr.move_next())
		{
			if (itr.get_val()->get_ch() == k)
			{
				next = itr.get_val();
				break;
			}
		}
		if (next == NULL)
		{
			return NULL;
		}
		else
		{
			ptr = next;
		}
	}
	return ptr;
}

void trie::collect(node *ptr, stringstream &prefix, stringstream &results)
{
	if (ptr == NULL)
	{
		return;
	}

	if (!(ptr->get_info().equals(info())))
	{
		results << prefix.str() << endl;
	}
	for (iter itr = ptr->get_children().get_begin();
			!ptr->get_children().get_end().equals(itr); itr.move_next())
	{
		stringstream str;
		str << prefix.str() << itr.get_val()->get_ch() << flush;
		collect(itr.get_val(), str, results);
	}
}

// methods
stringstream trie::keys_with_string(string prefix)
{
	stringstream results, pre;
	pre << prefix;
	node *ptr = find_node(prefix);
	collect(ptr, pre, results);
	return results;
}

info trie::find(string key)
{
	node *ptr = root;
	for (unsigned int i = 0; i < key.size(); ++i)
	{
		char k = key[i];
		node *next = NULL;
		for (iter itr = ptr->get_children().get_begin();
				!ptr->get_children().get_end().equals(itr); itr.move_next())
		{
			if (itr.get_val()->get_ch() == k)
			{
				next = itr.get_val();
				break;
			}
		}
		if (next == NULL)
		{
			return info();
		}
		else
		{
			ptr = next;
		}
	}
	return ptr->get_info();
}

void trie::insert(string key, info inf)
{
	node *ptr = root;
	for (unsigned int i = 0; i < key.size(); ++i)
	{
		node *next = NULL;
		for (iter itr = ptr->get_children().get_begin();
				!ptr->get_children().get_end().equals(itr); itr.move_next())
		{
			if (itr.get_val()->get_ch() == key[i])
			{
				next = itr.get_val();
				break;
			}
		}
		if (next == NULL)
		{
			next = new node(key[i]);
			{
				ptr->get_children().insert_after(
						ptr->get_children().get_nth(
								ptr->get_children().get_size() - 1), next);
			}
		}
		ptr = next;
	}
	ptr->set_info(inf);
}

bool trie::remove(string key)
/*
 * Eagerly delete the key from the trie rooted at `root`.
 * Return whether the trie rooted at `root` is now empty.
 */
{
	bool
	_delete(node *ptr, string key, unsigned int d);
	return _delete(root, key, 0);
}

bool _delete(node *ptr, string key, unsigned int d)
{
	/*
	 * Clear the node corresponding to key[d], and delete the child key[d+1]
	 * if that sub-trie is completely empty, and return whether `node` has been
	 * cleared.
	 */
	if (d == key.size())
	{
		ptr->set_info(info());
	}
	else
	{
		char k = key[d];
		node *next_k = NULL;
		iter prvs;
		for (iter itr = ptr->get_children().get_begin();
				!ptr->get_children().get_end().equals(itr); itr.move_next())
		{
			if (itr.get_val()->get_ch() == k)
			{
				next_k = itr.get_val();
				break;
			}
			prvs = itr;
		}
		if (next_k != NULL && _delete(next_k, key, d + 1))
		{
			ptr->get_children().remove_after(prvs);
		}
	}
	return (ptr->get_children().get_size() == 0);
}

void trie::words(string &_all, string &_names, string &_authors,
		string &_shelves) const
{
	void wds(node *root, stringstream &all, stringstream &names,
			stringstream &authors, stringstream &shelves);
	stringstream all, names, authors, shelves;
	wds(root, all, names, authors, shelves);
	_all = all.str();
	_names = names.str();
	_authors = authors.str();
	_shelves = shelves.str();
}

void wds(node *root, stringstream &all, stringstream &names,
		stringstream &authors, stringstream &shelves)
{
	node *ptr = root;
	if (ptr != NULL)
	{
		if (!ptr->get_info().equals(info()))
		{
			all << ptr->get_info().get_keyword() << "    "
					<< ptr->get_info().get_name() << "    "
					<< ptr->get_info().get_author() << "    "
					<< ptr->get_info().get_shelf() << endl;
			authors << ptr->get_info().get_author() << endl;
			names << ptr->get_info().get_name() << endl;
			shelves << ptr->get_info().get_shelf() << endl;
		}

		for (iter itr = ptr->get_children().get_begin();
				!ptr->get_children().get_end().equals(itr); itr.move_next())
		{
			wds(itr.get_val(), all, names, authors, shelves);
		}
	}
}

void trie::find_byAuthor(string keyword, string &_all, string &_names,
		string &_shelves) const
{
	void byAuth(node *root, string keyword, stringstream &all,
			stringstream &names, stringstream &shelves);
	stringstream all, names, authors, shelves;
	byAuth(root, keyword, all, names, shelves);
	_all = all.str();
	_names = names.str();
	_shelves = shelves.str();
}

void byAuth(node *root, string keyword, stringstream &all, stringstream &names,
		stringstream &shelves)
{
	node *ptr = root;
	if (ptr != NULL)
	{
		if (!ptr->get_info().equals(info())
				&& keyword == ptr->get_info().get_author())
		{
			all << ptr->get_info().get_keyword() << "    "
					<< ptr->get_info().get_name() << "    "
					<< ptr->get_info().get_author() << "    "
					<< ptr->get_info().get_shelf() << endl;
			names << ptr->get_info().get_name() << endl;
			shelves << ptr->get_info().get_shelf() << endl;
		}

		for (iter itr = ptr->get_children().get_begin();
				!ptr->get_children().get_end().equals(itr); itr.move_next())
		{
			byAuth(itr.get_val(), keyword, all, names, shelves);
		}
	}
}

void trie::find_byName(string keyword, string &_all, string &_authors,
		string &_shelves) const
{
	void byName(node *root, string keyword, stringstream &all,
			stringstream &author, stringstream &shelves);
	stringstream all, authors, shelves;
	byName(root, keyword, all, authors, shelves);
	_all = all.str();
	_authors = authors.str();
	_shelves = shelves.str();
}

void byName(node *root, string keyword, stringstream &all,
		stringstream &authors, stringstream &shelves)
{
	node *ptr = root;
	if (ptr != NULL)
	{
		if (!ptr->get_info().equals(info())
				&& keyword == ptr->get_info().get_name())
		{
			all << ptr->get_info().get_keyword() << "    "
					<< ptr->get_info().get_author() << "    "
					<< ptr->get_info().get_shelf() << endl;
			authors << ptr->get_info().get_author() << endl;
			shelves << ptr->get_info().get_shelf() << endl;
		}

		for (iter itr = ptr->get_children().get_begin();
				!ptr->get_children().get_end().equals(itr); itr.move_next())
		{
			byName(itr.get_val(), keyword, all, authors, shelves);
		}
	}
}

void trie::infos(string str) const
{
	vector inf;
	void infs(node *root, vector &inf);
	infs(root, inf);
	ofstream fout;
	fout.open(str);
	for (iter itr = inf.get_begin(); !inf.get_end().equals(itr);
			itr.move_next())
	{
		info inform = itr.get_val()->get_info();
		//cout << endl
		//		<< "*********" << endl
		//		<< inform.get_keyword() << endl;
		fout << inform.get_keyword() << flush;
		fout << "\t" << inform.get_name() << flush;
		fout << "\t" << inform.get_author() << flush;
		fout << "\t" << inform.get_shelf() << endl;
	}
}

void infs(node *root, vector &inf)
{
	node *ptr = root;
	if (ptr != NULL)
	{
		if (!ptr->get_info().equals(info()))
		{
			inf.prepend(ptr);
		}

		for (iter itr = ptr->get_children().get_begin();
				!ptr->get_children().get_end().equals(itr); itr.move_next())
		{
			infs(itr.get_val(), inf);
		}
	}
}
