#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	capacity_ = 16;
	size_ = 0;
	head_ = 0;
	tail_ = 0;
	items_ = new QueueItem[capacity_];
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	capacity_ = capacity;
	size_ = 0;
	head_ = 0;
	tail_ = 0;
	items_ = new QueueItem[capacity_];
}

CircularQueue::~CircularQueue()
{
	delete items_;
}

bool CircularQueue::empty() const
{
	return size_ == 0;
}

bool CircularQueue::full() const
{
	return size_ == capacity_;
}

int CircularQueue::size() const
{
	return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
	if (size_ + 1 > capacity_)
		return 0;
	else if (size_ == 0)
	{
		items_[head_] = value;
		tail_ = head_ + 1;
	}
	else
	{
		items_[(tail_) % capacity_] = value;
		tail_ = (tail_ + 1) % capacity_;
	}
	size_++;
	return 1;

}

QueueItem CircularQueue::dequeue()
{
	if (size_ == 0)
		return EMPTY_QUEUE;
	QueueItem returnItem = items_[head_];
	head_ = (head_ + 1) % capacity_;
	size_--;
	return returnItem;
}

QueueItem CircularQueue::peek() const
{
	if (size_ > 0)
		return items_[head_];
	return EMPTY_QUEUE;

}

void CircularQueue::print() const
{
	std::cout << "\nItems in order:\n";
	if (size_ == 0)
		std::cout << EMPTY_QUEUE;
	for (int i = head_; i < head_ + size_; i++)
	{
		std::cout << (i - head_ + 1) << ".) " << items_[i%capacity_] << "\n";
	}
}
