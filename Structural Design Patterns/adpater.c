#include <iostream>

class Adaptee{
public:
	void methodB()
	{
		std::cout<<"Adaptee methodB"<<std::endl;
	}
};

class ITarget{
public:
	virtual void method(){};
	virtual ~ ITarget(){};
};

class Client{
public:
	Client(ITarget*target):target(target){};
	virtual ~ Client(){}
	void Request()
	{
		std::cout<<"Request"<<std::endl;
		target->method();
	}
private:
	ITarget*target;
};

class Adapter:public ITarget{
public:
	virtual void method()
	{
		std::cout<<"Adapter method"<<std::endl;
	}
	virtual ~ Adapter(){delete ad;ad=NULL;}
	Adapter(){ad=new Adaptee;}
private:
	Adaptee*ad;
};	

int main()
{
	Client*client=new Client(new Adapter());
	client->Request();
	delete client;
	return 0;
}