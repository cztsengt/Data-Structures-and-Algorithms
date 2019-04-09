#include "DynamicStack.hpp"
#include <iostream>
#include <string>

using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	items_ = new StackItem[16];
	capacity_ = 16;
	size_ = 0;
	init_capacity_ = 16;
}

DynamicStack::DynamicStack(unsigned int capacity_)
{
	std::cout << "In the not default constructor" << std::endl; 
	if (capacity_ == 0) {
		std::cout << "Going to the default!" << std::endl;
		DynamicStack();
	}
	else
	{
		std::cout << "Creating a custom capacity" << std::endl;
		items_ = new StackItem[capacity_];
		(*this).capacity_ = capacity_;
		size_ = 0;
		init_capacity_ = capacity_;
	}
}

DynamicStack::~DynamicStack()
{
	delete[] items_;
}

bool DynamicStack::empty() const
{
	if (size_ == 0)
		return true;
	return false;
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if (size_ != capacity_)
		items_[size_] = value;
	else
	{
		StackItem * items_new = new StackItem[capacity_ * 2];
		for (int i = 0; i < capacity_; i++)
			items_new[i] = items_[i];
		items_new[capacity_] = value;
		capacity_ = capacity_ * 2;
		delete[] items_;
		items_ = items_new;
	}
	size_++;
}

StackItem DynamicStack::pop()
{
	if (size_ == 0)
		return EMPTY_STACK;
	StackItem thingToReturn = items_[size_ - 1]; // The item to return is at location size - 1
	size_--;
	if ((size_ <= capacity_ * (1.0 / 4))  && capacity_ / 2 >= init_capacity_)
	{
		StackItem * items_half = new StackItem[capacity_ / 2];
		for (int i = 0; i < size_; i++)
			items_half[i] = items_[i];
		capacity_ = capacity_ / 2;
		delete[] items_;	// This is erroring out because of a "Heap cooruption detected" for some reason
		items_ = items_half;
	}
	return thingToReturn;
}

StackItem DynamicStack::peek() const
{
	if (size_ == 0)
		return EMPTY_STACK;
	StackItem thingToReturn = items_[size_ - 1];
	return thingToReturn;
}

void DynamicStack::print() const
{
	std::cout << "\n";
	if (empty())
		std::cout << EMPTY_STACK;
	for (int i = size_ - 1; i >= 0; i--)
	{
		std::cout << i << " " << items_[i] << "\n";
	}
	std::cout << "\n";
}
