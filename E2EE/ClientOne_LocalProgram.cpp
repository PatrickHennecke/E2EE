#include <iostream>
#include "ClientOne_LocalProgram.h"
#include "DummyServer.h"
//#include <stdlib.h>
#include <cstdint>
#include <time.h>

using std::uint64_t;

clientOne::clientOne()
	: clientOne_privateKey(0),
	clientOne_publicKey(0),
	RecievedKey(0),
	clientOne_SecuredKey(0)
{
	std::cout << "Client One" << std::endl;

	server_object.createConnection();
	n = server_object.sendKey1();
	g = server_object.sendKey2();

	srand(time(0));

	sendKey();
}

// This function sends request to start conversation with client two
void clientOne::startConversation()
{
	server_object.DisplayKey1();
	server_object.DisplayKey2();
	
}

// This function creates the private key for client one
void clientOne::createKey()
{
	// Create client one's key
		// potential key from 1 to n
	clientOne_privateKey = 1 + (rand() % (n - 1));
}

// This function generates the new public key for client one
void clientOne::generatePublicKey()
{
	createKey();

	clientOne_publicKey = (g ^ clientOne_privateKey) % n;

	// For debug only
	//display_clientOne_privateKey();
}

// For Debugging purposes only
void clientOne::display_clientOne_privateKey()
{
	std::cout << "Private Key from Client One in Local Program is " << clientOne_privateKey << std::endl;
}

void clientOne::sendKey()
{
	generatePublicKey();

	server_object.relay_clientOne_publicKey(clientOne_publicKey);

	//Display_clientOne_publicKey();
}

void clientOne::Display_clientOne_publicKey()
{
	// For debugging use cout
	std::cout << std::endl;
	std::cout << "Public Key from Client One in Local Program is " << clientOne_publicKey << std::endl;
	std::cout << std::endl;
	server_object.display_clientOne_publicKey();
}

// THIS IS WHERE MY CODE BREAKS
// 

void clientOne::Handshake_complete()
{
	RecievedKey = server_object.send_clientTwo_publicKey();

	//display_recievedKey();
}

void clientOne::display_recievedKey()
{
	std::cout << std::endl;
	std::cout << "Client One Recieved " << RecievedKey << std::endl;
}

void clientOne::calculateSecuredKey()
{
	Handshake_complete();

	clientOne_SecuredKey = (RecievedKey ^ clientOne_privateKey);

	displaySecurePublicKey();
}

void clientOne::displaySecurePublicKey()
{
	std::cout << std::endl;
	std::cout << "Client One's Secured Public Key is " << clientOne_SecuredKey << std::endl;
}

