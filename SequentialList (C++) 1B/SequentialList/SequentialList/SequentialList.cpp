// .cpp files contain code definitions for methods that have been declared
// in the according .hpp file. The skeleton has been set up here for you.
// That is, the methods have been initiated, and your mission, should you 
// choose to accept it (which you should for marks), is to fill in each method
// with the appropriate code.
//
// A note about the "::" syntax: generally, this means "the thing on the right
// belongs to the thing on the left." So, SequentialList::empty() means the method
// empty() belongs to the class SequentialList. This allows empty() to access (and
// potentially change) the member variables in class SequentialList.

#include "SequentialList.hpp"

// This is the constructor.
SequentialList::SequentialList(unsigned int cap)
{
}

SequentialList::~SequentialList()
{
}

bool SequentialList::empty() const
{
}

unsigned int SequentialList::size() const
{
}

unsigned int SequentialList::capacity() const
{
}

bool SequentialList::full() const
{
}

void SequentialList::print() const
{
}

// NOTE on inserts: do NOT grow the array if we reach capacity. Simply return false.
bool SequentialList::insert_front(DataType val)
{
}

bool SequentialList::remove_front()
{
}

bool SequentialList::insert_back(DataType val)
{
}

bool SequentialList::remove_back()
{
}

bool SequentialList::insert(DataType val, unsigned int index)
{
}

bool SequentialList::remove(unsigned int index)
{
}

unsigned int SequentialList::search(DataType val) const
{
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
}

bool SequentialList::replace(unsigned int index, DataType val)
{
}
