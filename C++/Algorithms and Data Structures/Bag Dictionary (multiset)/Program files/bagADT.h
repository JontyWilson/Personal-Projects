#ifndef BAGADT_H
#define	BAGADT_H

#include <stdlib.h>
#include "book.h"

template <typename E>
class Bag {
public:
	Bag() {}            // base constructor
	virtual ~Bag() {}   // base destructor

	// Insert a new item into the bag -- return false if fails and true if
	// successful
	virtual bool addItem(const E& item) = 0;

	// Looks for 'item' in the bag and if found updates 'item' with the 
	// bag value and returns true.  Otherwise 'item' is left unchanged
	// and the method returns false.
	virtual bool remove(E& item) = 0;

	// Removes the top record from the bag, puts it in returnValue, and
	// returns true if the bag is not empty.  If the bag is empty the 
	// function returns false and returnValue remains unchanged.
	virtual bool removeTop(E& returnValue) = 0;

	// Finds the record using returnValue and if the record is found updates
	// returnValue based on the contents of the bag and returns true.  If the
	// record is not found the function returns false.  Works just like remove()
	// except that the found record is not removed from the bag.
	virtual bool find(E& returnValue) const = 0;

	// Inspect the top of the bag.  If the bag is empty return
	// false and leave 'item' unchanged; otherwise, return true and update 
	// 'item' with the contents of the bag.
	virtual bool inspectTop(E& item) const = 0;

	// empties the bag
	virtual void emptyBag() = 0;

	// use the += operator to add an item to the bag
	virtual bool operator+=(const E& addend) = 0;

	// get the number of items in the bag
	virtual int size() const = 0;

	// get the capacity of the bag (size of your bag's array)
	virtual int bagCapacity() const = 0;


};

#endif	/* BAGADT_H */

