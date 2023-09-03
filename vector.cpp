/*
 * vector.cpp
 *
 *  Created on: 23-Aug-2020
 *      Author: HP
 */

#include "vector.h"

vector::vector()
{
    vals = new node*;
    range = 1;
    size = 0;
}

//getters
int vector::get_size() const
{
    return size;
}

int vector::get_capacity() const
{
    return range;
}

//helper methods
void vector::ensure_range(int range)
{
    /*
     * exit quickly if the current capacity if already big enough to
     * accommodate the array.
     */
    if (this->range >= range)
    {
        return;
    }

    // Find the new capacity and allocate a new array for that capacity.
    int new_range = this->range * 2;
    while (new_range < range)
    {
        new_range *= 2;
    }
    node **vals = new node*[new_range];

    // Copying over old array
    for (int i = 0; i < this->size; ++i)
    {
        vals[i] = *(this->vals + i);
    }

    // Free up space from old vector
    delete[ ] this->vals;

    // Update the vector states
    this->vals = vals;
    this->range = new_range;
}

//methods
iter vector::get_begin() const
{
    return iter(vals, 0);
}

iter vector::get_end() const
{
    return iter(vals, size);
}

void vector::insert_after(iter itr, node *val)
{
    // first ensure capacity of the array to hold new element.
    ensure_range(size + 1);

    //then copy the elements after given iterator and make space for new value.
    for (int i = size - 1; i > itr.get_index(); i--)
    {
        vals[i + 1] = vals[i];
    }

    //set new value
    vals[itr.get_index() + 1] = val;

    //updated the vector state
    size++;
}

void vector::prepend(node *val)
{
    insert_after(iter(vals, -1), val);
}

iter vector::remove_after(iter itr)
{
    // copy the element to be deleted in a temporary variable.
    iter iterat(vals, itr.get_index() + 1);

    // copy the elements after the element to be deleted one location before.
    for (int i = itr.get_index() + 1; i < size - 1; ++i)
    {
        vals[i] = vals[i + 1];
    }

    // update the vector state
    size--;

    //return the iterator to the deleted element
    return iterat;
}

iter vector::remove_first()
{
    return remove_after(iter(vals, -1));
}

node*
vector::get_valat(int n) const
{
    return vals[n];
}

void vector::set_valat(int n, node *val)
{
    vals[n] = val;
}

iter vector::get_nth(int n) const
{
    return iter(vals, n);
}
