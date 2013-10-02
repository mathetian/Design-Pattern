#include <iostream>
#include <string>

class Sender{
public:
	Sender(){}
	virtual ~ Sender(){std::cout<<"delete Sender"<<std::endl;}
	virtual void sendMessage(std::string text)
	{
		std::cout<<"Sender\\"+text<<std::endl;
	}
};

class Message{
public:
	Message(Sender*sender):sender(sender){}
	virtual ~ Message()
	{
		delete sender;
		sender=0;
		std::cout<<"delete Message"<<std::endl;
	}
	virtual void send(std::string str)
	{
		sender->sendMessage("general\\"+str);
	}
protected:
	Sender*sender;
};

class UrlMessage:public Message{
public:
	UrlMessage(Sender*sender):Message(sender){}
	virtual ~ UrlMessage()
	{
		std::cout<<"delete UrlMessage"<<std::endl;
	}
	virtual void send(std::string str)
	{
		sender->sendMessage("Url\\"+str);
	}
};

class EmailSender:public Sender{
public:
	EmailSender(){};
	virtual ~ EmailSender(){std::cout<<"delete EmailSender"<<std::endl;}
	virtual void sendMessage(std::string text)
	{
		std::cout<<"EmailSender\\"+text<<std::endl;
	}
};

int main()
{
	Message*msg=new Message(new EmailSender());
	Message*msg1=new UrlMessage(new Sender());
	msg->send("msg");
	msg1->send("msg1");
	delete msg;delete msg1;
	return 0;
}