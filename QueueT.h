#include <iostream>
using namespace std;

class NodeT
{
public:
	NodeT* next;
	int data;
	NodeT(int value)
	{
			data=value;
			next=NULL;
	}
	
};

class QueueT
{
private:
	int currentsize;
	NodeT* back;
	NodeT* front;
public:
	//Default constructor
	//PRE: Must only creates empty class i.e do not try QueueT q1=5 and similar
	//POST: Creates a QueueT class variable with current size=0 and front and back pointing to NULL
	//PARAM: N/A
	QueueT();
	//Copy Constructor
	//Pre:
	//Post:
	//PARAM:
	QueueT(const QueueT& copy);
	//output function
	//Pre:
	//Post:
	//PARAM:
	void print() const;
	//Pre:
	//Post:
	//PARAM:
	void enqueue(const int value);
	//Destructor
	//Pre:
	//Post:
	//PARAM:
	~QueueT();
	//Pre:
	//Post:
	//PARAM:
	QueueT& operator=(const QueueT &tocopy);
	//Pre:
	//Post:
	//PARAM:
	NodeT* getFront() const;
	//Pre:
	//Post:
	//PARAM:
	int dequeue();
	//Pre:
	//Post:
	//PARAM:
	bool empty() const;
	//Pre:
	//Post:
	//PARAM:
	int size() const;
	//Pre:
	//Post:
	//PARAM:
	QueueT merge(const QueueT& copy);
	//Pre:
	//Post:
	//PARAM:
	QueueT concatenate(const QueueT& con,const int n);
	

};