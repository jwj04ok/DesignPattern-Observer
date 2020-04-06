#pragma once
#ifndef header_h
#define header_h

#include <string>
#include <list>
#include <algorithm>

//Observer Base Class
class Observer
{
public:
	Observer() {}
	Observer(Observer& aObserver) {}
	Observer& operator = (Observer& aObserver) {}
	virtual ~Observer() {}

	virtual void Update() {}
};

//Subject Base Class
class Subject
{
public:
	Subject() {}
	Subject(Subject& aSubject) {}
	Subject& operator =(Subject& aSubject) {}
	virtual ~Subject() {}

	void Add(Observer* observer) { my_observers.push_back(observer); }		  //add new observer
	void Remove(Observer* observer) { my_observers.remove(observer); }        //remove observer from the list
	void Notify() //inform observer about the change of the Subject
	{
		std::list<Observer*>::iterator iter = my_observers.begin();
		for (auto each:my_observers)
			each->Update();
	}
	virtual void SetUpdates(std::string newinfo) { information = newinfo; } //set the update information 
	virtual std::string GetUpdates() { return information; }    //get the update information

private:
	std::list<Observer* > my_observers; //the list of all observers
protected:
	std::string information; //information to be notify
};

//practical example of a Subject
class Twitter : public Subject
{
private:
	std::string m_name; //Twitter Ownner name
public:
	Twitter(std::string name) : m_name(name) {}
	Twitter& operator =(Twitter& aTwitter) { m_name = aTwitter.m_name; }
	~Twitter() {}

	void SetUpdates(std::string newinfo) { information =   m_name + ": " +newinfo; } 
	std::string GetStatus() { return information; }
};

//practical example of an Observer 
class TwitterSubscriber : public Observer
{
private:
	std::string observerName;  //name of the observer
	Subject* observedTwitter;   //twitter to observe
public:
	TwitterSubscriber(std::string name, Subject* aTwitter) : observerName(name), observedTwitter(aTwitter) {}
	TwitterSubscriber& operator =(TwitterSubscriber& aTwitterSubscriber) { observerName = aTwitterSubscriber.observerName; }
	~TwitterSubscriber() {}

	void Update()  //receive new information from subscription
	{
		std::string newInfor = observedTwitter->GetUpdates();
		std::cout << observerName << " received information: " << newInfor << std::endl;
	}
};


#endif /* header_h */
