#include <iostream>

class SubjectBase{
public:
	virtual void dealWithIt()=0;
};

class RealSubject:public SubjectBase{
public:
	virtual void dealWithIt()
	{
		std::cout<<"RealSubject dealWithIt"<<std::endl;
	}
};

class Proxy:public SubjectBase{
public:
	virtual void dealWithIt()
	{
		if(_rs==NULL)
			_rs=new RealSubject();
		std::cout<<"Proxy dealWithIt"<<std::endl;
		_rs->dealWithIt();
	}
private:
	RealSubject*_rs;
};

int main()
{
	Proxy*pxy=new Proxy();
	pxy->dealWithIt();
	delete pxy;
	pxy=NULL;
	return 0;
}