#include <iostream>

class Product{
public:
	Product(){std::cout<<"Product"<<std::endl;}
	virtual ~ Product(){}
};

class ConcreteProductA:public Product{
public:
	ConcreteProductA(){std::cout<<"ConcreteProductA"<<std::endl;}
	virtual ~ ConcreteProductA(){}
};

class ConcreteProductB:public Product{
public:
	ConcreteProductB(){std::cout<<"ConcreteProductB"<<std::endl;}
	virtual ~ ConcreteProductB(){}
};

class FactoryBase{
public:
	FactoryBase(){std::cout<<"FactoryBase"<<std::endl;}
	virtual ~ FactoryBase(){}
	virtual Product* createProduct(int id){}
};

class ConcreteFactory:public FactoryBase{
public:
	ConcreteFactory(){std::cout<<"ConcreteFactory"<<std::endl;}
	virtual ~ ConcreteFactory(){}
	virtual Product* createProduct(int id)
	{
		if(id==0)
			return new ConcreteProductA();
		return new ConcreteProductB;
	}
};

int main()
{
	FactoryBase*cf=new ConcreteFactory;
	Product* a=cf->createProduct(0);
	Product* b=cf->createProduct(1);
	delete cf;cf=0;
	delete a;delete b;
	a=0;b=0;
	return 0;
}
