#include <iostream>
#include "ClientTwo_LocalProgram.h"
#include "DummyServer.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>


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
void clientTwo::display_clientTwo_privateKey() const
{
	//std::cout << std::endl;
	std::cout << "Private Key from Client Two in Local Program is " << clientTwo_privateKey << std::endl;
	std::cout << std::endl;
	
}


void clientTwo::sendKey()
{
	generatePublicKey();

	server_object.relay_clientTwo_publicKey(clientTwo_publicKey);

	Display_clientTwo_publicKey();
}

void clientTwo::Display_clientTwo_publicKey() const
{
	// For debugging use cout
	std::cout << "Public Key from Client Two in Local Program is " << clientTwo_publicKey << std::endl;
	std::cout << std::endl;
	//server_object.display_clientTwo_publicKey();
}

void clientTwo::Handshake_complete()
{
	RecievedKey = server_object.send_clientOne_publicKey();

	display_recievedKey();
}

void clientTwo::display_recievedKey() const
{
	std::cout << std::endl;
	std::cout << "Client Two recieved " << RecievedKey << std::endl;
}

void clientTwo::calculateSecuredKey()
{
	Handshake_complete();

	clientTwo_SecuredKey = (RecievedKey ^ clientTwo_privateKey) % n;

	displaySecurePublicKey();
}

void clientTwo::displaySecurePublicKey() const
{
	std::cout << std::endl;
	std::cout << "Client Two's Secured Public Key is " << clientTwo_SecuredKey << std::endl;
}

void clientTwo::get_Message()
{
	if (clientTwo_SecuredKey != 0) {
		std::cout << std::endl;
		std::cout << "Client One's message: ";
		std::getline(std::cin, message);
	}


	EncryptMessage(message, clientTwo_SecuredKey);
}

uint64_t clientTwo::Transform_Message(std::string& securemessage)
{
	// Ideally since I'm going to be multiplying the secured key with the unicode I want to store the unicode into uint64_t
	std::vector<uint64_t> transform;
	uint64_t new_message = 0;
	std::string ascii;

	for (uint64_t i = 0; i <= securemessage.length(); i++) {
		transform.push_back(securemessage[i]);
	}

	int j = 0;
	while (transform[j] != 0) {
		ascii += std::to_string(transform[j++]);
	}

	new_message = std::stold(ascii);

	return new_message;
}

void clientTwo::read_Transform(uint64_t newMessage)
{
	std::cout << std::endl << "Transformed message is " << newMessage << std::endl << std::endl;
}

uint64_t clientTwo::EncryptMessage(std::string& securemessage, uint64_t newkey)
{
	uint64_t transformed_message;

	transformed_message = Transform_Message(securemessage);
	// Note, in ElGamal encryption, to get our cyphertext we multiply the secured key by the string message
	// However, we can transform the message into ascii and then multiply by the secured key

	read_Transform(transformed_message);

	secured_message = newkey * transformed_message;

	return secured_message;
}

void clientTwo::read_Encrypted()
{
	std::cout << std::endl << "Encrypted message is " << EncryptMessage(message, clientTwo_SecuredKey) << std::endl;
}

void clientTwo::decrypt_Message(uint64_t encrypted_message)
{
	uint64_t decrypted;

	decrypted = encrypted_message / clientTwo_SecuredKey;

	client_Ones_message = std::to_string(decrypted);
}

void clientTwo::read_Recieved_Message()
{
}

clientTwo::~clientTwo()
{
}
