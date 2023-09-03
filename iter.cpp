/*
 * itertor.cpp
 *
 *  Created on: 28-Aug-2020
 *      Author: HP
 */

#include "iter.h"

//constructor
iter::iter(node **vals, int index) : vals(vals), index(index)
{
}
;

//getter
node*
iter::get_val() const
{
    return vals[index];
}

int iter::get_index() const
{
    return index;
}

//setter
void iter::set_val(node *val)
{
    vals[index] = val;
}

//methods
void iter::move_next()
{
    index++;
}

bool iter::equals(iter itr) const
{
    if (this->vals == itr.vals && this->index == itr.index)
    {
        return true;
    }
    else
    {
        return false;
    }
}
