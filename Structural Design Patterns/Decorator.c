#include <iostream>
#include <string>

class SandWich{
public:
	virtual ~ SandWich(){}
	virtual int getPrice()=0;
	virtual std::string getDescription()=0;
};

class TunaSandwich:public SandWich{
public:
	virtual ~ TunaSandwich(){}
	virtual int getPrice()
	{
		return 1;
	}
	virtual std::string getDescription()
	{
		return "TunaSandwich";
	}
};

class VeggieSandwich:public SandWich{
public:
	virtual ~ VeggieSandwich(){};
	virtual int getPrice()
	{
		return 10;
	}
	virtual std::string getDescription()
	{
		return "VeggieSandwich";
	}
};

class SandWichDectorBase : public SandWich{
public:
	SandWichDectorBase(SandWich*sw):sandwich(sw){}
	virtual ~ SandWichDectorBase(){}
	virtual int getPrice()
	{
		return sandwich->getPrice();
	}
	virtual std::string getDescription()
	{
		return sandwich->getDescription();
	}
private:
	SandWich*sandwich;
};

class Corn: public SandWichDectorBase{
public:
	Corn(SandWich*sw):SandWichDectorBase(sw){}
	virtual ~ Corn(){}
	virtual int getPrice()
	{
		return SandWichDectorBase::getPrice()+2;
	}
	virtual std::string getDescription()
	{
		return "Corn\\"+SandWichDectorBase::getDescription();
	}
};

class Olives: public SandWichDectorBase{
public:
	Olives(SandWich*sw):SandWichDectorBase(sw){}
	virtual ~ Olives(){}
	virtual int getPrice()
	{
		return SandWichDectorBase::getPrice()+3;
	}
	virtual std::string getDescription()
	{
		return "Olives\\"+SandWichDectorBase::getDescription();
	}
};

int main()
{
	SandWich*sw=new TunaSandwich();
	std::cout<<sw->getPrice()<<":"<<sw->getDescription()<<std::endl;
	SandWich*cornSw=new Corn(sw);
	std::cout<<cornSw->getPrice()<<":"<<cornSw->getDescription()<<std::endl;
	delete sw;delete cornSw;
	sw=NULL;cornSw=NULL;
	return 0;
}