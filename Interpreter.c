//One Algorithm question: interpreter for, + - + - - 2 3 4 + - -5 6 + -7 8 9 10

//Some thing wrong for example
#include <iostream>
#include <queue>
#include <string>

class Expression{
public:
	Expression(){}
	virtual int Excute()=0;
};

class TerminalExpresion:public Expression{
public:
	TerminalExpresion(int value):value(value){}
	virtual int Excute()
	{
		std::cout<<value<<std::endl;
		return value;
	}
private:
	int value;
};

class AddExpresion:public Expression{
public:
	AddExpresion(Expression*_l,Expression*_r):_l(_l),_r(_r){}
	virtual int Excute()
	{
		std::cout<<"plus"<<std::endl;
		return _l->Excute()+_r->Excute();
	}
private:
	Expression*_l;
	Expression*_r;
};

class MinusExpresion:public Expression{
public:
	MinusExpresion(Expression*_l,Expression*_r):_l(_l),_r(_r){}
	virtual int Excute(){
		std::cout<<"minus"<<std::endl;
		return _l->Excute()-_r->Excute();
	}
private:
	Expression*_l;
	Expression*_r;
};


class MultiplyExpression:public Expression{
public:
	MultiplyExpression(Expression*_l,Expression*_r):_l(_l),_r(_r){}
	virtual int Excute()
	{
		return _l->Excute()*_r->Excute();
	}
private:
	Expression*_l;
	Expression*_r;
};

class DivideExpression:public Expression{
public:
	DivideExpression(Expression*_l,Expression*_r):_l(_l),_r(_r){}
	virtual int Excute()
	{
		return _l->Excute()/_r->Excute();
	}
private:
	Expression*_l;
	Expression*_r;
};

class Parser{
public:
	Expression*parse(std::queue<char>&str)
	{
		if(str.empty()) return NULL;
		while(isspace(str.front())) str.pop();
		if(str.empty()) return NULL;
		if(isDigital(str.front())==1)
			return new TerminalExpresion(getValue(str));
		parseOP(str);
	}

	Expression*parseOP(std::queue<char>&str)
	{
		if(str.empty()) return NULL;
		while(isspace(str.front())) str.pop();
		if(str.empty()) return NULL;

		switch(str.front())
		{
		case '+':
			str.pop();
			return new AddExpresion(parse(str),parse(str));
		case '-':
			str.pop();
			return new MinusExpresion(parse(str),parse(str));
		case '*':
			str.pop();
			return new MultiplyExpression(parse(str),parse(str));
		case '/':
			str.pop();
			return new DivideExpression(parse(str),parse(str));
		}
	}

	Expression*parse(std::string strs)
	{
		int len=strs.size();
		int i=0;std::queue<char>str;
		while(i<len)
		{
			str.push(strs[i]);
			i++;
		}
		return parse(str);
	}
private:
	int getValue(std::queue<char>&str)
	{
		int value=0;
		while(!str.empty()&&!isspace(str.front()))
		{
			value=value*10+str.front()-'0';
			str.pop();
		}
		return value;
	}

	int isDigital(char flag)
	{
		if(flag>='0'&&flag<='9')
			return 1;
		return 0;
	}
};

int main()
{
	Parser*p=new Parser();
	Expression*exp=p->parse("+ - 4 5 6");
	std::cout<<exp->Excute()<<std::endl;
	return 0;
}
