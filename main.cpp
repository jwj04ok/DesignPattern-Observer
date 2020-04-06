// Observer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "header.h"

int main()
{
	Subject* aTwitter = new Twitter("Corona Beer");
	Observer* aSubscriber = new TwitterSubscriber("Mozzie", aTwitter);
	Observer* anotherSubscriber = new TwitterSubscriber("Satchmo", aTwitter);
	aTwitter->Add(aSubscriber);
	aTwitter->Add(anotherSubscriber);
	aTwitter->SetUpdates("Corona Beer has no relation with Coronavirus-19!");
	aTwitter->Notify();
	delete aTwitter; 
	delete aSubscriber;
	delete anotherSubscriber;
	return 0;

}


