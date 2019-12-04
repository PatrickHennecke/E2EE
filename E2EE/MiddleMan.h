#pragma once
#include <iostream>

class MiddleMan {
private:
	int key;
	std::string message;
	int generatePublicKeyclientOne() {}; //For both clients
	int generatePublicKeyclientTwo() {};
	std::string DecryptclientOne(std::string message, int newkey) {};
	std::string DecryptclientTwo(std::string message, int newkey) {};
	std::string SendtoclientOne(std::string message, int newkey) {};
	std::string SendtoclientTwo(std::string message, int newkey) {};
};