#include "PriorityQueue.h"

#include <iostream>

PriorityQueue::~PriorityQueue()
{
	while (!this->isEmpty())
		this->popItem();
}

void PriorityQueue::pushItem(int value, int priority, int id)
{
	unsigned int i = 0;
	while ((i < m_Queue.size()) && (priority > m_Queue[i].priority))
		i++;
	m_Queue.insert(m_Queue.begin() + i, {value, priority, id});
}

QueueItem PriorityQueue::popItem()
{
	QueueItem res = m_Queue.back();
	m_Queue.pop_back();
	return res;
}

void PriorityQueue::removeItemByAddress(QueueItem * addr)
{
	if (addr == nullptr)
		return;

	for (int i = 0; i < m_Queue.size(); i++)
	{
		if (&(m_Queue[i]) == addr)
		{
			m_Queue.erase(m_Queue.begin() + i);
			return;
		}
	}
}

QueueItem PriorityQueue::begin()
{
	return m_Queue[0];
}

QueueItem PriorityQueue::end()
{
	return m_Queue[m_Queue.size() - 1];
}

QueueItem* PriorityQueue::getLastFree(std::vector<int>& inputBufs)
{
	for (int i = m_Queue.size()-1; i >= 0; i--)
	{
		int id = m_Queue[i].userID;
		if (inputBufs[id] == 0)
		{
			return &m_Queue[i];
		}
	}

	return nullptr;
}

void PriorityQueue::eraseByAddres(QueueItem* item)
{
	if (item == nullptr)
		return;

	int i = 0;
	while (i < m_Queue.size())
	{
		if (item == &(m_Queue[i]))
		{
			m_Queue.erase(m_Queue.begin() + i);
		}
	}
}

bool PriorityQueue::isEmpty()
{
	return m_Queue.empty();
}

void PriorityQueue::print()
{
	if (this->isEmpty())
		std::cout << "Empty";
	else
	{
		for (unsigned int i = 0; i < m_Queue.size(); i++)
		{
			if ((i != 0) && (i % 5 == 0))
				std::cout << std::endl;

			std::cout << "[v" << m_Queue[i].value << "][p" << m_Queue[i].priority << "][u" << m_Queue[i].userID <<"]   ";
		}
	}

	std::cout << std::endl << "------------------------------------------------------------------------" << std::endl;
}
