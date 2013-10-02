#include <iostream>

class Prototype{
public:
	Prototype(int num):num(num){}
	virtual ~ Prototype(){}
	virtual Prototype*clone()=0;
	void print(){std::cout<<num<<std::endl;}
protected:
	int num;
};

class CP1:public Prototype{
public:
	CP1(int num):Prototype(num){}
	virtual ~ CP1(){}
	virtual Prototype*clone()
	{
		return new CP1(num--);
	}
};

class CP2:public Prototype{
public:
	CP2(int num):Prototype(num){}
	virtual ~ CP2(){}
	virtual Prototype*clone()
	{
		return new CP2(num--);
	}
};

int main()
{
	Prototype*a=new CP1(1);
	Prototype*b=new CP2(10);
	Prototype*c=a->clone();
	Prototype*d=b->clone();
	a->print();b->print();
	c->print();d->print();
	delete a;delete b;delete c;delete d;
}	