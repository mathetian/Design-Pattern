#include <iostream>

class AlgorithmBase{
public:
	virtual void excute()
	{
		step1();
		step2();
	}
	virtual void step1()=0;
	virtual void step2()=0;
};

class ConcreteAlgorithmA:public AlgorithmBase{
public:
	virtual void step1()
	{
		std::cout<<"ConcreteAlgorithmA step1"<<std::endl;
	}
	virtual void step2()
	{
		std::cout<<"ConcreteAlgorithmA step2"<<std::endl;
	}
};

class ConcreteAlgorithmB:public AlgorithmBase{
public:
	virtual void step1()
	{
		std::cout<<"ConcreteAlgorithmB step1"<<std::endl;
	}
	virtual void step2()
	{
		std::cout<<"ConcreteAlgorithmB step2"<<std::endl;
	}
};

int main()
{
	AlgorithmBase*ab=new ConcreteAlgorithmA();
	ab->excute();
	delete ab;ab=NULL;
	ab=new ConcreteAlgorithmB();
	ab->excute();
	delete ab;ab=NULL;
	return 0;
}