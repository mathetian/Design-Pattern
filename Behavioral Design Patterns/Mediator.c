#include <iostream>
#include <vector>

class MediatorBase;

class ColleagueBase{
public:
	virtual void change(){};
	virtual void notify(std::string str){};
	ColleagueBase(MediatorBase*mb);
protected:
	MediatorBase*mb;
};

class MediatorBase{
public:
	MediatorBase(){}
	void add(ColleagueBase*cb)
	{
		pcList.push_back(cb);
	}
	void notify(std::string str,ColleagueBase*cb)
	{
		for(int i=0;i<pcList.size();i++)
		{
			if(pcList[i]==cb) continue;
			pcList[i]->notify("MediatorBase");
		}
	}
private:
	std::vector<ColleagueBase*> pcList;
};

ColleagueBase::ColleagueBase(MediatorBase*mb)
{
	this->mb=mb;
	this->mb->add(this);
}	

class CCA:public ColleagueBase{
public:
	CCA(MediatorBase*mb):ColleagueBase(mb){}
	virtual void change()
	{
		std::cout<<"CCA changed"<<std::endl;
		mb->notify("CCA",this);
	}
	virtual void notify(std::string str)
	{
		std::cout<<str<<" CCA notified"<<std::endl;
	}
};

class CCB:public ColleagueBase{
public:
	CCB(MediatorBase*mb):ColleagueBase(mb){}
	virtual void change()
	{
		std::cout<<"CCB changed"<<std::endl;
		mb->notify("CCB",this);
	}
	virtual void notify(std::string str)
	{
		std::cout<<str<<" CCB notified"<<std::endl;
	}
};

class CCC:public ColleagueBase{
public:
	CCC(MediatorBase*mb):ColleagueBase(mb){}
	virtual void change()
	{
		std::cout<<"CCC changed"<<std::endl;
		mb->notify("CCC",this);
	}
	virtual void notify(std::string str)
	{
		std::cout<<str<<" CCC notified"<<std::endl;
	}
};



int main()
{
	MediatorBase*mb=new MediatorBase();
	ColleagueBase*a=new CCA(mb);ColleagueBase*b=new CCB(mb);
	ColleagueBase*c=new CCC(mb);

	ColleagueBase*d=new CCA(mb);ColleagueBase*e=new CCB(mb);
	ColleagueBase*f=new CCC(mb);

	b->change();

	delete mb;delete a,b,c,d,e,f;
	return 0;
}
