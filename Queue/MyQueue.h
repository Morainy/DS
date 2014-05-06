#pragma once



template <typename T>
class queue
{
private:
	T * Data;
	int head;
	int  tear;
public:
	void enqueue(T a);
	queue();
	T dequeue();
	~queue();
	};