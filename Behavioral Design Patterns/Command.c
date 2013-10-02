#include <iostream>
#include <vector>
//Like the example of website
class Robot{
public:
	Robot(){position=0;}
	~ Robot(){}
	void moveLeft(int flag)
	{
		if(flag==1) position-=1;
		else position+=1;
		if(flag==1)
			std::cout<<"excute LeftMovement:"<<position<<std::endl;
		else
			std::cout<<"undo LeftMovement:"<<position<<std::endl;
	}
	void moveRight(int flag)
	{
		if(flag==1) position+=1;
		else position-=1;
		if(flag==1)
			std::cout<<"excute RightMovement:"<<position<<std::endl;
		else
			std::cout<<"undo RightMovement:"<<position<<std::endl;
	}
private:
	int position;
};

class Movement{
public:
	Movement(Robot*robot):robot(robot){}
	virtual ~ Movement(){}
	virtual void excute(int flag)=0;
public:
	Robot*robot;
};

class Controller{
public:
	void excute(Movement*a)
	{
		vCommands.push_back(a);
		a->excute(1);
	}
	void undo()
	{
		
		Movement*cur=vCommands[vCommands.size()-1];
		cur->excute(0);
		vCommands.pop_back();
	}
private:
	std::vector<Movement*>vCommands;
};



class LeftMovement:public Movement{
public:
	LeftMovement(Robot*robot):Movement(robot){}
	virtual ~ LeftMovement(){}
	virtual void excute(int flag)
	{
		robot->moveLeft(flag);
	}
};

class RightMovement:public Movement{
public:
	RightMovement(Robot*robot):Movement(robot){}
	virtual ~ RightMovement(){}
	virtual void excute(int flag)
	{
		robot->moveRight(flag);
	}
};

int main()
{
	Robot*robot=new Robot();
	Movement*a=new LeftMovement(robot);
	Movement*b=new RightMovement(robot);
	Movement*c=new LeftMovement(robot);
	Movement*d=new RightMovement(robot);
	Controller*ctl=new Controller();
	ctl->excute(a);ctl->excute(c);
	ctl->excute(d);ctl->excute(b);
	
	ctl->undo();
	ctl->undo();
	return 0;
}