//Memory Leak
#include <iostream>

class StateBase;

class Context{
public:
	Context(StateBase*sb):_sb(sb){}
	void Request();
	void setState(StateBase*sb){_sb=sb;}
private:
	StateBase*_sb;
};

class StateBase{
public:
	virtual void Handler(Context*ctx)=0;
};

class SC:public StateBase{
public:
	virtual void Handler(Context*ctx);
};

class SB:public StateBase{
public:
	virtual void Handler(Context*ctx);
};

class SA:public StateBase{
public:
	virtual void Handler(Context*ctx);
};

void Context::Request()
{
	_sb->Handler(this);
}

void SA::Handler(Context*ctx)
{
	std::cout<<"SA Handler"<<std::endl;
	ctx->setState(new SB());
}

void SB::Handler(Context*ctx)
{
	std::cout<<"SB Handler"<<std::endl;
	ctx->setState(new SC());
}

void SC::Handler(Context*ctx)
{
	std::cout<<"SC Handler"<<std::endl;
	ctx->setState(new SA());
}

int main()
{
	Context*ctx=new Context(new SA());
	ctx->Request();
	ctx->Request();
	ctx->Request();
	ctx->Request();

	delete ctx;
	return 0;
}

