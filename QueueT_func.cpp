#include "QueueT.h"

QueueT::QueueT()
{
	cout<<"Enter QueueT constructor\n ========================"<<endl;
	currentsize=0;
	front=NULL;
	back=NULL;
	cout<<"Exit QueueT constructor\n ========================"<<endl;
	

}

void QueueT:: print() const
{
	if(currentsize!=0)
		for(NodeT* iter=front;iter!=NULL;iter=iter->next)
		{
			cout<<iter->data<<" ";
		}
		cout<<endl;

}


void QueueT:: enqueue(int value)
{
	cout<<"Enqueue Initialized\n ======================== "<<endl;
	if(currentsize==0)
	{
		NodeT* temp=new NodeT(value);
		back=temp;
		front=temp;
	}
	else
	{
		NodeT* temp=new NodeT(value);
		back->next=temp;
		back=temp;
	}
	currentsize++;
	cout<<"Exit Enqueue fucntion\n ======================== "<<endl;

}


QueueT:: ~QueueT()
{
	//cout<<"Destructor initialised\n ========================"<<endl;
	for(NodeT* iter=front;iter!=NULL;iter=front)
	{
		front=front->next;
		delete  iter;
	}
}


QueueT& QueueT:: operator=(const QueueT &tocopy)
{
	cout<<"Enter Operator\n ========================"<<endl;
	while(currentsize!=0)
	{
		dequeue();
	}
	
	for(NodeT* iter=tocopy.front;iter!=NULL;iter=iter->next)
	{
		enqueue(iter->data);
	}
	cout<<"Exit Operator\n ========================"<<endl;
	return *this;
	
}

QueueT :: QueueT(const QueueT &copy)
{
	cout<<"Enter Copy constrctor \n ========================"<<endl;
	currentsize=0;
	if(copy.currentsize!=0)
	for(NodeT* iter=copy.front;iter!=NULL;iter=iter->next)
	{
		enqueue(iter->data);
	}
	else
	{
		front=NULL;
		back=NULL;
	}
	
	cout<<" Exit Copy constrctor \n ========================"<<endl;
}


NodeT* QueueT:: getFront() const
{
	return front;
}


int QueueT::dequeue()
{
	cout<<"Enter Dequeue\n ========================"<<endl;
	if(currentsize!=0)
	{
		int temp=front->data;
		NodeT* discard=front;
		front=front->next;
		currentsize--;
		delete discard;
		cout<<"Exit Dequeue\n ========================"<<endl;
		return temp;
	}
	return -1;
}


bool QueueT:: empty() const
{
	if(currentsize==0)
		return true;
	return false;
}



int QueueT:: size() const
{
	return currentsize;
}

QueueT QueueT:: merge(const QueueT& copy)
{
	cout<<"Enter Merge\n ========================"<<endl;
	QueueT temp;
	int counter=0;
	NodeT* iter=front;
	NodeT* iter1=copy.front;

	while(counter<currentsize+copy.currentsize)
	{
		if(iter!=NULL && iter1!=NULL)
		{
			temp.enqueue(iter->data);
			temp.enqueue(iter1->data);
			iter=iter->next;
			iter1=iter1->next;
			counter=counter+2;
		}
		else if(iter1==NULL)
		{
			temp.enqueue(iter->data);
			iter=iter->next;
			counter++;
		}
		else if(iter==NULL)
		{
			temp.enqueue(iter1->data);
			iter=iter->next;
			counter++;
		}
	
	}
	cout<<"Exit Merge\n ========================"<<endl;
	return temp;
}



QueueT QueueT:: concatenate(const QueueT& con,const int n)
{
	int counter=0;
	for(NodeT* iter=con.front;iter!=NULL;iter=iter->next)
	{
		if(counter<n)
		{
			enqueue(iter->data);
			counter++;
		}
		else
		{
			break;
		}
	}
	return *this;
}