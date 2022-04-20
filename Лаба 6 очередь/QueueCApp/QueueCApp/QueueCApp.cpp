#include <iostream>
#include <iomanip>
#include <vector>

#include "PriorityQueue.h"

std::vector<std::pair< std::vector<int>, int>> usersData
{
	{ {8, 11, 5, 4,  1, 9, 11, 8       }, {3} },  //выше — лучше (приоритет)
	{ {2,  3, 2, 1,  3, 4,  5, 1,  2, 1}, {3} },
	{ {6,  3, 8, 2,  1, 4,  6, 8,  7   }, {3} },
	{ {5,  4, 3, 4,  2, 1,  5, 4,  3   }, {2} },
	{ {8,  6, 8, 2,  3, 2,  1, 3, 12, 7}, {1} },
	{ {7,  6, 5, 7, 11, 3,  7, 8,  6, 4}, {1} }
	/*
	{ {4, 2, 1}, {3} },
	{ {5, 2, 2}, {2} },
	{ {8, 7, 7}, {2} }
	*/
};

int main()
{
	PriorityQueue queue;
	std::vector<int> userBufs = { 0, 0, 0, 0, 0, 0 };

	//загрузка значений в очередь
	for (int i = 0; i < usersData.size(); i++)
	{
		for (int j = 0; j < usersData[i].first.size(); j++)
		{
			queue.pushItem(usersData[i].first[j], usersData[i].second, i);
		}
	}

	int ticksPerTact = 1;
	int inputTime = 0;

	std::cout << "Enter ticks per tact number: ";
	std::cin >> ticksPerTact;
	std::cout << "Enter input time: ";
	std::cin >> inputTime;
	std::cout << std::endl;

	int tickCount = 0;
	int idleTickCount = 0;

	//обработка
	while (!queue.isEmpty())
	{
		QueueItem* item = queue.getLastFree(userBufs);

		//цикл по тикам
		for (int i = 0; i < ticksPerTact; i++)
		{
			tickCount++;

			//обновление буферов
			for (int i = 0; i < userBufs.size(); i++)
			{
				if ((item != nullptr) && (item->userID == i))
				{
					continue;
				}

				if (userBufs[i] > 0)
					userBufs[i]--;
			}

			if (item == nullptr)
			{
				idleTickCount++;
			}
			else
			{

				if (item->value > 0)
					(item->value)--;
				else
				{
					userBufs[item->userID] = inputTime;
					queue.removeItemByAddress(item);
					item = nullptr;
				}
			}
		}

	}

	float efficiency = (float)(tickCount - idleTickCount) / tickCount * 100;
	std::cout << std::endl << "Efficiency = " << std::setprecision(3) << efficiency << "%" << std::endl;

	return 0;
}
