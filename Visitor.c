#include <iostream>
#include <vector>

class ElementBase;

class VisitorBase{
public:
	virtual void visit(ElementBase*eb)=0;
};

class ElementBase{
public:
	virtual void visit(VisitorBase*cv)
	{
		cv->visit(this);
	}
	virtual std::string getName()=0;
};


class ObjectStructure{
public:
	virtual void add(ElementBase*eb)
	{
		vElements.push_back(eb);
	}

	virtual void visit(VisitorBase*cv)
	{
		for(int i=0;i<vElements.size();i++)
			vElements[i]->visit(cv);
	}
private:
	std::vector<ElementBase*> vElements;
};

class CEA:public ElementBase{
public:
	virtual std::string getName()
	{
		return "CEA";
	}
};

class CEB:public ElementBase{
public:
	virtual std::string getName()
	{
		return "CEB";
	}
};



class ConcreteVisitor:public VisitorBase{
public:
	virtual void visit(ElementBase*eb)
	{
		std::cout<<eb->getName()<<std::endl;
	}
};

int main()
{
	ObjectStructure*obs=new ObjectStructure();
	obs->add(new CEA());
	obs->add(new CEA());
	obs->add(new CEB());
	obs->add(new CEB());
	obs->visit(new ConcreteVisitor());
	return 0;
}