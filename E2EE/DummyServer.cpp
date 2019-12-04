#include <iostream>
#include "DummyServer.h"
//#include <stdlib.h>
#include <cstdint>
#include <time.h>

using std::uint64_t;

uint64_t send_to_clientOne;
uint64_t send_to_clientTwo;

DummyServer::DummyServer()
	:
	key1(0),
	key2(0),
	clientOne_publicKey(0),
	clientTwo_publicKey(0)
{
	// Generate key1 and key2 using a pseudo random number generator
	srand(time(0));
}

// This function generates key1 using pseudo random number generator
void DummyServer::createKey1()
{
	// Test for key1
		// potential key
	uint64_t potentialkey = rand();

	// Boolean to see if key is prime
	bool keyGood = false;

	// Loop until value of keyGood is changed
	while (!keyGood) {
		// to keep track if key fails a test
		int strike = 0;

		// Check if potential key is prime
		// NOTE if you want to not allow small primes, change i
		for (int i = 2; i < sqrt(potentialkey)/2; i++) {
			if (potentialkey % i == 0) {
				strike++;
			}
		}

		if (strike > 0) {
			// If there is a strike, run it again
			potentialkey = rand();
			keyGood = false;
		}
		else {
			// If no strikes, assign to key and exit loop
			key1 = potentialkey;
			keyGood = true;
		}
	}
}

// This function generates key2 using pseudo random number generator
void DummyServer::createKey2()
{
	// Test for key2
	// potential key
	uint64_t potentialkey = rand() % key1;

	// Boolean to see if key is prime
	bool keyGood = false;

	// Loop until value of keyGood is changed
	while (!keyGood) {
		// to keep track if key fails a test
		int strike = 0;

		// Check if potential key is coprime to key1 - 1
		// NOTE if you want to not allow small primes, change i
		for (int i = 2; i < sqrt(key1 - 1) / 2; i++) {
			if (potentialkey % i == 0) {
				strike++;
			}
		}

		if (strike > 0) {
			// If there is a strike, run it again
			potentialkey = rand() % key1;
			keyGood = false;
		}
		else {
			// If no strikes, assign to key and exit loop
			key2 = potentialkey;
			keyGood = true;
		}
	}
}

// This function returns key1
uint64_t DummyServer::sendKey1()
{
	return key1;
}

// This function returns key2
uint64_t DummyServer::sendKey2()
{
	return key2;
}

// For debugging purposes
void DummyServer::DisplayKey1()
{
	//Send to both clients

	// For debugging use cout
	std::cout << std::endl;
	std::cout << "key 1 from dummy server is " << key1 << std::endl;
}

// For debugging purposes
void DummyServer::DisplayKey2() {

	//Send to both clients

	// For debugging use cout
	std::cout << "key 2 from dummy server is " << key2 << std::endl;
	std::cout << std::endl;
}

// This function creates a "connection" by generating the needed keys and tells the user the keys are accessible
void DummyServer::createConnection()
{
	createKey1();
	createKey2();

	std::cout << "Connection created, public keys are accessible." << std::endl;
}

// This function assigns number passed in to clientOne_publicKey variable
void DummyServer::relay_clientOne_publicKey(uint64_t& Client_One)
{
	clientOne_publicKey = Client_One;
	send_to_clientTwo = clientOne_publicKey;
}

// This function assigns number passed in to clientTwo_publicKey variable
void DummyServer::relay_clientTwo_publicKey(uint64_t& Client_Two)
{
	clientTwo_publicKey = Client_Two;
	send_to_clientOne = clientTwo_publicKey;
}

uint64_t DummyServer::send_clientOne_publicKey()
{
	return send_to_clientTwo;
}

uint64_t DummyServer::send_clientTwo_publicKey()
{
	return send_to_clientOne;
}

void DummyServer::display_clientOne_publicKey()
{
	std::cout << "Public Key from Client One in Dummy Server is " << clientOne_publicKey << std::endl;
	std::cout << std::endl;
}

void DummyServer::display_clientTwo_publicKey()
{
	std::cout << "Public Key from Client Two in Dummy Server is " << clientTwo_publicKey << std::endl;
}

// This function relays encrypted message from client One
//std::string DummyServer::Relay_clientOne_Message(std::string message, uint64_t number)
//{
//	return std::string();
//}

// This function relays encrypted message from client Two
//std::string DummyServer::Relay_clientTwo_Message(std::string message, uint64_t number) {
//	return std::string();
//}