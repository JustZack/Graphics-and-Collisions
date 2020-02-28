#pragma once
#include <vector>
#include <future>
#include <thread>
#include "Task.h"

template <class T>
class ThreadPool
{
public:
	ThreadPool();
	
	void AddTask(Task<T>);

	/* Completes all taks in the todo vector */
	void Run();
private:
	std::vector<Task<T>> todo;
	unsigned int maxthreads = 4;
};

template <class T>
ThreadPool<T>::ThreadPool() {
	if (std::thread::hardware_concurrency() > 0)
		this->maxthreads = std::thread::hardware_concurrency();
}

template <class T>
void ThreadPool<T>::AddTask(Task<T> task) {
	this->todo.push_back(task);
}

template <class T>
void ThreadPool<T>::Run() {
	int running = 0, todoIndex = todo.size() - 1;
	std::vector<std::future<void>> returnVals;
	//While there are tasks to do
	while (todoIndex >= 0) {
		//Make an async call for each physical thread on the machine
		for (int i = 0; i < this->maxthreads && todoIndex >= 0; i++) {
			Task<T> t = todo[todoIndex]; todo.erase(todo.begin() + todoIndex--);
			returnVals.push_back(std::async(&Task<T>::operator(), &t));
			running++;
		}
		//Wait for each running thread to finish execution
		for (int i = 0; i < running; i++) {
			returnVals[i].get();
		}
		//Reset for next threads
		running = 0;
		returnVals.clear();
	}
}
