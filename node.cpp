/*
 * node.cpp
 *
 *  Created on: Sep 19, 2020
 *      Author: HP
 */

#include "node.h"
using namespace std;

// constructors
node::node()
{
    ch = '\0';
    inf = info();
    children = vector();
}
node::node(char ch) : ch(ch)
{
    inf = info();
    children = vector();
}
;
node::node(char ch, info information) : ch(ch), inf(information) // @suppress("Symbol is not resolved")
{
    children = vector();
}
;

//getters
char node::get_ch()
{
    return ch;
}

info node::get_info()

{
    return inf;
}
vector&
node::get_children()
{
    return children;
}

//setters
void node::set_info(info new_info)
{
	inf.set_keyword(new_info.get_keyword());
    inf.set_author(new_info.get_author());
    inf.set_name(new_info.get_name());
    inf.set_shelf(new_info.get_shelf());
}
