#pragma once

#include "DummyServer.h"

using std::uint64_t;

class clientTwo {
private:
	// Variables
	uint64_t clientTwo_privateKey;
	// Functions
	void display_clientTwo_privateKey();

public:
	// Objects
	DummyServer server_object;
	// Variables
	uint64_t clientTwo_publicKey;
	uint64_t RecievedKey;
	uint64_t clientTwo_SecuredKey;
	uint64_t n;
	uint64_t g;
	//std::string message;
	// Functions
	clientTwo();
	void startConversation();
	void createKey();
	void generatePublicKey();
	void sendKey();
	void Display_clientTwo_publicKey();
	void Handshake_complete();
	void display_recievedKey();
	void calculateSecuredKey();
	void displaySecurePublicKey();
	//std::string EncryptMessage(std::string& message, int newkey);
	//std::string SendtoServer(std::string message, int newkey);
};