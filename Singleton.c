#include <iostream>

class Singleton{
public:
	//private static readonly object _lockThis = new object();
	static Singleton*getInstance(){
		if(!_instance)
		{
			//lock (_lockThis)
             {
             	//if (_instance == null)
             	_instance=new Singleton;
             }
		}
			
		return _instance;
	}
 	~ Singleton(){};

	void getAddress()
	{
		std::cout<<this<<std::endl;
	}

private:
	Singleton(){};
	static Singleton*_instance;
};

Singleton* Singleton::_instance = NULL;


int main()
{
	Singleton*a=Singleton::getInstance();
	a->getAddress();
	Singleton*b=Singleton::getInstance();
	b->getAddress();
	delete a;a=b=0;
}