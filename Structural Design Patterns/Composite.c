#include <iostream>
#include <list>

//write a simple tree
//Some problems for delete tree
class NodeBase{
public:
	NodeBase(int value):value(value){}
	virtual ~ NodeBase(){}
	virtual void show(int depth){};
	virtual void add(NodeBase*n){};
protected:
	int value;
};

class Node:public NodeBase{
public:
	Node(int value):NodeBase(value){}
	virtual ~ Node()
	{
		for (std::list<NodeBase*>::iterator it = _iLists.begin(); it != _iLists.end(); it++)
		{
			//delete it;
			//it=NULL;
		}
	}
	virtual void show(int depth)
	{
		std::cout<<value<<"\\"<<depth<<": ";
		for (std::list<NodeBase*>::iterator it = _iLists.begin(); it != _iLists.end(); it++)
		{
			(*it)->show(depth+1);
		}
	}
	virtual void add(NodeBase*n)
	{
		_iLists.push_back(n);
	}
private:
	std::list<NodeBase*> _iLists;
};

int main()
{
	NodeBase*root=new Node(10);
	root->add(new Node(15));
	root->add(new Node(3));
	NodeBase*here=new Node(12);
	here->add(new Node(112));
	here->add(new Node(23));
	root->add(here);
	root->show(0);
	return 0;
}