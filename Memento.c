#include <iostream>

class Element{
public:
	Element(int a,int b):a(a),b(b){}
	int ga(){return a;}
	int gb(){return b;}
private:
	int a,b;
};

class Memento{
public:
	Memento(Element e):e(e){}
	int ga(){return e.ga();}
	int gb(){return e.gb();}
private:
	Element e;
};


class Originator{
public:
	Originator(){_a=0;_b=0;}
	void add()
	{
		std::cout<<_a<<" "<<_b<<std::endl;
		_a++;
	}
	Memento*createMO()
	{
		Element e(_a,_b);
		return new Memento(e);
	}
	void set(Memento*mo)
	{
		_a=mo->ga();
		_b=mo->gb();
	}
private:
	int _a,_b;
};


class Caretaker{
public:
	Caretaker(Memento*mo):mo(mo){}
	Memento*getMemento(){return mo;}
	~ Caretaker(){delete mo; mo=NULL;}
private:
	Memento*mo;
};

int main()
{
	Originator*or1=new Originator();
	or1->add();or1->add();
	Caretaker*cr=new Caretaker(or1->createMO());
	or1->add();or1->add();
	or1->set(cr->getMemento());
	or1->add();
	or1->set(cr->getMemento());
	or1->add();
	delete or1;delete cr;
	return 0;
}
