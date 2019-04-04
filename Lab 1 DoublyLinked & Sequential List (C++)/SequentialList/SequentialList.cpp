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
#include <iostream>
using namespace std;

// This is the constructor.
SequentialList::SequentialList(unsigned int cap)
{
	capacity_ = cap;
	size_ = 0;
	data_ = new SequentialList::DataType[cap];
}

SequentialList::~SequentialList()
{
	delete[] data_;
}

bool SequentialList::empty() const
{
	return size_ == 0;
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::full() const
{
	return size_ == capacity_;
}

void SequentialList::print() const
{
	for (int i = 0; i < (int)size_; i++)
		cout << i << " " << data_[i] << "\n";
}

// NOTE on inserts: do NOT grow the array if we reach capacity. Simply return false.
bool SequentialList::insert_front(DataType val)
{
	if (size_ >= capacity_)
		return 0;
	if (size_ != 0)
		for (int i = size_ - 1; i >= 0; i--)
			data_[i + 1] = data_[i];
	data_[0] = val;
	size_ += 1;
	return 1;
}

bool SequentialList::remove_front()
{
	if (size_ == 0)
		return 0;
	if (size_ != 1)
		for (int i = 1; i < size_; i++)
			data_[i - 1] = data_[i];
	size_--;
	return 1;
}

bool SequentialList::insert_back(DataType val)
{
	if (size_ >= capacity_)
		return false;
	data_[size_] = val;
	size_++;
	return 1;
}

bool SequentialList::remove_back()
{
	if (size_ == 0)
		return 0;
	size_--;
	return 1;
}

bool SequentialList::insert(DataType val, unsigned int index) //assuming array index given
{
	if (size_ == capacity_ || index > size_ || index < 0)
		return 0;

	if (index != size_)
		for (int i = (int)size_; i > index; i--)
			data_[i + 1] = data_[i];
	data_[index] = val;
	size_++;
	return 1;
}

bool SequentialList::remove(unsigned int index)
{
	if (size_ == 0 || index < 0 || index >= size_)
		return 0;
	for (int i = index; i < size_ - 1; i++)
	{
		data_[i] = data_[i + 1];
	}
	size_--;
	return 1;
}

unsigned int SequentialList::search(DataType val) const
{
	for (int i = 0; i < size_; i++)
		if (data_[i] == val)
			return i;
	return size_;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if (size_ == 0)
		return 0;
	else if (index >= size_ || index < 0)
		return data_[size_ - 1];
	return data_[index];
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if (index >= size_ || index < 0)
		return 0;
	data_[index] = val;
	return 1;
}
