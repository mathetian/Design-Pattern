#include <iostream>
#include <vector>
using namespace std;

class AP{
public:
	AP(){cout<<"ap"<<endl;};
	virtual ~ AP(){cout<<"del ap"<<endl;}
};
//product1
class AP1: public AP{
public:
	AP1(){cout<<"ap1"<<endl;};
	virtual ~ AP1(){cout<<"del ap1"<<endl;};
};

class CP1A : public AP1{
public:
	CP1A(){cout<<"ap1a"<<endl;};
	virtual ~ CP1A(){cout<<"del ap1a"<<endl;};
};

class CP1B : public AP1{
public:
	CP1B(){cout<<"ap1b"<<endl;};
	virtual ~ CP1B(){cout<<"del ap1b"<<endl;};
};
//product2
class AP2: public AP{
public:
	AP2(){cout<<"ap2"<<endl;};
	virtual ~ AP2(){cout<<"del ap2"<<endl;};
};

class CP2A : public AP2{
public:
	CP2A(){cout<<"ap2a"<<endl;};
	virtual ~ CP2A(){cout<<"del ap2a"<<endl;};
};

class CP2B : public AP2{
public:
	CP2B(){cout<<"ap2b"<<endl;};
	virtual ~ CP2B(){cout<<"del ap2b"<<endl;};
};

//Abstract Factory
class AF{
public:
	AF(){cout<<"af"<<endl;};
	virtual ~AF(){cout<<"del af"<<endl;};
	//core
	virtual AP*creatCP1(){};
	virtual AP*creatCP2(){};
};

class CFA : public AF{
public:
	CFA(){cout<<"cfa"<<endl;};
	virtual ~ CFA(){cout<<"del cfa"<<endl;};
	//core
	virtual AP*creatCP1(){return new CP1A();}
	virtual AP*creatCP2(){return new CP2A();}
};

class CFB : public AF{
public:
	CFB(){cout<<"cfb"<<endl;};
	virtual ~ CFB(){cout<<"del cfb"<<endl;};
	//core
	virtual AP*creatCP1(){return new CP1B();}
	virtual AP*creatCP2(){return new CP2B();}
};

int main()
{
	//factory
	AF*cfa=new CFA();
	AF*cfb=new CFB();
	typedef vector<AP*> _v_ap_typ;
	_v_ap_typ v;			
	v.push_back(cfa->creatCP1());
	v.push_back(cfa->creatCP2());
	v.push_back(cfb->creatCP1());
	v.push_back(cfb->creatCP2());

	 for ( _v_ap_typ::iterator it = v.begin(); it != v.end(); ++it)
        delete *it;
    v.clear();

    delete cfa;
    cfa=NULL;

    delete cfb;
    cfb=NULL;
    return 0;
}