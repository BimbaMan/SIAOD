#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <vector>

typedef struct _QueueItem
{
	int value;
	int priority;
	int userID;
} QueueItem;

class PriorityQueue
{
private:
	std::vector<QueueItem> m_Queue;

public:
	~PriorityQueue();

	void pushItem(int value, int priority, int id);
	QueueItem popItem();
	void removeItemByAddress(QueueItem* addr);

	QueueItem begin();
	QueueItem end();

	QueueItem* getLastFree(std::vector<int>& inputBufs);
	void eraseByAddres(QueueItem* item);

	bool isEmpty();

	void print();
};

#endif