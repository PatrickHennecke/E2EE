#include <iostream>
#include "ClientTwo_LocalProgram.h"
#include "DummyServer.h"
#include <stdlib.h>
#include <time.h>

using std::uint64_t;

clientTwo::clientTwo()
	:
	clientTwo_privateKey(0),
	clientTwo_publicKey(0),
	RecievedKey(0),
	clientTwo_SecuredKey(0)
{
	std::cout << "Client Two" << std::endl;

	server_object.createConnection();
	n = server_object.sendKey1();
	g = server_object.sendKey2();

	sendKey();
}

// This function sends request to start conversation with client one
void clientTwo::startConversation()
{
	
}

// This function creates the private key for client two
void clientTwo::createKey()
{
	// Create client two's key
		// potential key from 1 to n
	clientTwo_privateKey = 1 + (rand() % (n - 1));
}

// This function generates the new public key for client two
void clientTwo::generatePublicKey() {
	createKey();

	clientTwo_publicKey = (g ^ clientTwo_privateKey);

	// For debug only
	//display_clientTwo_privateKey();
}

// For Debugging purposes only
void clientTwo::display_clientTwo_privateKey()
{
	//std::cout << std::endl;
	std::cout << "Private Key from Client Two in Local Program is " << clientTwo_privateKey << std::endl;
	std::cout << std::endl;
	
}


void clientTwo::sendKey()
{
	generatePublicKey();

	server_object.relay_clientTwo_publicKey(clientTwo_publicKey);

	//Display_clientTwo_publicKey();
}

void clientTwo::Display_clientTwo_publicKey()
{
	// For debugging use cout
	std::cout << "Public Key from Client Two in Local Program is " << clientTwo_publicKey << std::endl;
	std::cout << std::endl;
	server_object.display_clientTwo_publicKey();
}

void clientTwo::Handshake_complete()
{
	RecievedKey = server_object.send_clientOne_publicKey();

	//display_recievedKey();
}

void clientTwo::display_recievedKey()
{
	std::cout << std::endl;
	std::cout << "Client Two recieved " << RecievedKey << std::endl;
}

void clientTwo::calculateSecuredKey()
{
	Handshake_complete();

	clientTwo_SecuredKey = (RecievedKey ^ clientTwo_privateKey);

	displaySecurePublicKey();
}

void clientTwo::displaySecurePublicKey()
{
	std::cout << std::endl;
	std::cout << "Client Two's Secured Public Key is " << clientTwo_SecuredKey << std::endl;
}
