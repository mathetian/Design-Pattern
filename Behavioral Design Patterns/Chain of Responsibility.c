#include <iostream>

//Not very good example
class HandlerBase{
public:
	HandlerBase(){};
	virtual ~ HandlerBase(){};
	virtual void setNext(HandlerBase*next)
	{
		_next=next;
	}
	virtual void HandlerMsg(int level)=0;
protected:
	HandlerBase*_next;
};

class ConcreteHandlerA:public HandlerBase{
public:
	ConcreteHandlerA(){};
	virtual ~ ConcreteHandlerA(){};
	virtual void HandlerMsg(int level)
	{
		if(level==1)
			std::cout<<"ConcreteHandlerA handler"<<std::endl;
		else _next->HandlerMsg(level);
	}
};

class ConcreteHandlerB:public HandlerBase{
public:
	ConcreteHandlerB(){};
	virtual ~ ConcreteHandlerB(){};
	virtual void HandlerMsg(int level)
	{
		if(level==2)
			std::cout<<"ConcreteHandlerB handler"<<std::endl;
		else _next->HandlerMsg(level);
	}
};

class ConcreteHandlerC:public HandlerBase{
public:
	ConcreteHandlerC(){};
	virtual ~ ConcreteHandlerC(){}
	virtual void HandlerMsg(int level)
	{
		if(level==3)
			std::cout<<"ConcreteHandlerC handler"<<std::endl;
		else _next->HandlerMsg(level);
	}
};

int main()
{
	HandlerBase*a=new ConcreteHandlerA();
	HandlerBase*b=new ConcreteHandlerB();
	HandlerBase*c=new ConcreteHandlerC();
	a->setNext(b);b->setNext(c);
	a->HandlerMsg(1);
	a->HandlerMsg(2);
	a->HandlerMsg(3);
	delete a;delete b;delete c;
	return 0;
}