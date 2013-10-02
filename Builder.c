#include <iostream>
#include <vector>
#include <string>
using namespace std;
//product
class VStr{
public:
	void getStrs()
	{
		/* for(string::iterator it = vecStr.begin(); it != vecStr.end(); ++it)
		 	cout<<*it<<" ";
		 cout<<endl;*/
		 for(int i=0;i<vecStr.size();i++)
		 	cout<<vecStr[i]<<" ";
		 cout<<endl;
	}	
	void add(string str)
	{
		vecStr.push_back(str);
	}
private:
	vector<string>vecStr;
};

//Builder
class Converter{
public:
	Converter(){cout<<"Converter"<<endl;};
	virtual ~ Converter(){cout<<"delete Converter"<<endl;};
	virtual void process(string str){cout<<"Converter process"<<endl;};
	virtual void getProduct(){};
};
//ConcreteBuilder
class ASCIIConverter:public Converter{
public:
	ASCIIConverter(){cout<<"ASCIIConverter"<<endl;};
	virtual ~ ASCIIConverter(){cout<<"delete ASCIIConverter"<<endl;};
	virtual void process(string str){cout<<"ASCIIConverter process"<<endl;vv.add(str);};
	virtual void getProduct(){vv.getStrs();};
private:
	VStr vv;
};
class TexConverter:public Converter{
public:
	TexConverter(){cout<<"TexConverter"<<endl;};
	virtual ~ TexConverter(){cout<<"delete TexConverter"<<endl;};
	virtual void process(string str){cout<<"TexConverter process"<<endl;vv.add(str);};
	virtual void getProduct(){vv.getStrs();};
private:
	VStr vv;
};
//Director
class Reader{
public:
	Reader(Converter*cv):cv(cv){cout<<"Reader"<<endl;};
	virtual ~ Reader(){cout<<"delete Reader"<<endl;};
	void digest(string str){cout<<"begin Reader"<<endl;cv->process(str);cv->process(str);cv->process(str);};
private:
	Converter*cv;
};
//In this example, I emit product.
int main()
{
	Converter*acv=new ASCIIConverter();
	Converter*tcv=new TexConverter();
	Reader reader1(acv);
	Reader reader2(tcv);
	reader1.digest("hello");
	reader2.digest("world");
	acv->getProduct();
	tcv->getProduct();
	delete acv;
	delete tcv;
}