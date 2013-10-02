#include <iostream>

class StrategyBase{
public:
	virtual void call()=0;
};

class Client{
public:
	void setStrategy(StrategyBase*sb){_sb=sb;}
	void call(){_sb->call();}
private:
	StrategyBase*_sb;
};

class CSA:public StrategyBase{
public:
	virtual void call()
	{
		std::cout<<"CSA called"<<std::endl;
	}
};

class CSB:public StrategyBase{
public:
	virtual void call()
	{
		std::cout<<"CSB called"<<std::endl;
	}
};

class CSC:public StrategyBase{
public:
	virtual void call()
	{
		std::cout<<"CSC called"<<std::endl;
	}
};

int main()
{
	Client*cl=new Client();
	cl->setStrategy(new CSA());
	cl->call();
	cl->setStrategy(new CSB());
	cl->call();
	cl->setStrategy(new CSC());
	cl->call();
	return 0;
}