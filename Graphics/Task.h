#pragma once
#include "GridSection.h"
template <class T>
class Task
{
public:
	Task(T& obj);
	Task(const Task<T>& t);
	Task<T>& operator=(const Task<T>&);
	void operator()();
private:
	T& object;
};

template <class GridSection>
Task<GridSection>::Task(GridSection& section) : object(section) { }
template <class GridSection>
Task<GridSection>::Task(const Task<GridSection>& task) : object(task.object) { }
template <class GridSection>
Task<GridSection>& Task<GridSection>::operator=(const Task<GridSection>& task) {
	object = task.object;
	return *this;
}
template <class GridSection>
void Task<GridSection>::operator()() {
	object.DoCollisions();
}

