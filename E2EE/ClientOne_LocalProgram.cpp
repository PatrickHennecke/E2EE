#include <iostream>
#include "ClientOne_LocalProgram.h"
#include "DummyServer.h"
//#include <stdlib.h>
#include <cstdint>
#include <time.h>
#include <string>
#include <vector>

using std::uint64_t;

clientOne::clientOne()
	: clientOne_privateKey(0),
	clientOne_publicKey(0),
	RecievedKey(0),
	clientOne_SecuredKey(0),
	secured_message(),
	recieved_message()
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

	clientOne_publicKey = (g ^ clientOne_privateKey);

	// For debug only
	//display_clientOne_privateKey();
}

// For Debugging purposes only
void clientOne::display_clientOne_privateKey() const
{
	std::cout << "Private Key from Client One in Local Program is " << clientOne_privateKey << std::endl;
}

void clientOne::sendKey()
{
	generatePublicKey();

	server_object.relay_clientOne_publicKey(clientOne_publicKey);

	Display_clientOne_publicKey();
}

void clientOne::Display_clientOne_publicKey() const
{
	// For debugging use cout
	std::cout << std::endl;
	std::cout << "Public Key from Client One in Local Program is " << clientOne_publicKey << std::endl;
	std::cout << std::endl;
	//server_object.display_clientOne_publicKey();
}

void clientOne::Handshake_complete()
{
	RecievedKey = server_object.send_clientTwo_publicKey();

	display_recievedKey();
}

void clientOne::display_recievedKey() const
{
	std::cout << std::endl;
	std::cout << "Client One Recieved " << RecievedKey << std::endl;
}

void clientOne::calculateSecuredKey()
{
	Handshake_complete();

	clientOne_SecuredKey = (RecievedKey ^ clientOne_privateKey) % n;

	displaySecurePublicKey();
}

void clientOne::displaySecurePublicKey() const
{
	std::cout << std::endl;
	std::cout << "Client One's Secured Public Key is " << clientOne_SecuredKey << std::endl;
}

// This function allows user to type a message that will be sent to the server
void clientOne::get_Message()
{
	if (clientOne_SecuredKey != 0) {
		std::cout << std::endl;
		std::cout << "Client One's message: ";
		std::getline(std::cin, message);
	}


	EncryptMessage(message, clientOne_SecuredKey);
}

void clientOne::send_Message()
{
}

// This function will be used to transform the message into unicode
uint64_t clientOne::Transform_Message(std::string& securemessage)
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

void clientOne::read_Transform(uint64_t newMessage)
{
	std::cout << std::endl << "Transformed message is " << newMessage << std::endl << std::endl;
}

// Now rather than a pure end to end encyrption example I'm implementing client-end encryption
// ostensibly this would be safer for most attacks (excluding middle man)
// This function is using ElGamal Encrytion
uint64_t clientOne::EncryptMessage(std::string& securemessage, uint64_t newkey)
{
	uint64_t transformed_message;

	transformed_message = Transform_Message(securemessage);
	// Note, in ElGamal encryption, to get our cyphertext we multiply the secured key by the string message
	// However, we can transform the message into ascii and then multiply by the secured key

	read_Transform(transformed_message);

	secured_message = newkey * transformed_message;

	return secured_message;
}

void clientOne::read_Encrypted()
{
	std::cout << std::endl << "Encrypted message is " << EncryptMessage(message, clientOne_SecuredKey) << std::endl;
}

void clientOne::decrypt_Message(uint64_t encrypted_message)
{
	uint64_t decrypted;

	decrypted = encrypted_message / clientOne_SecuredKey;

	client_Twos_message = std::to_string(decrypted);
}

void clientOne::read_Recieved_Message()
{
}

clientOne::~clientOne()
{
}

