#pragma once

#include <iostream>
//#include <stdlib.h>
#include <cstdint>
#include "DummyServer.h"

using std::uint64_t;

class clientOne {
private:
	// Variables
	uint64_t clientOne_privateKey;
	// Functions
	void display_clientOne_privateKey();

public:
	// Objects
	DummyServer server_object;
	// Variables
	uint64_t clientOne_publicKey;
	uint64_t RecievedKey;
	uint64_t clientOne_SecuredKey;
	uint64_t n;
	uint64_t g;
	//std::string message;
	// Functions
	clientOne();
	void startConversation();
	void createKey();
	void generatePublicKey();
	void sendKey();
	void Display_clientOne_publicKey();
	void Handshake_complete();
	void display_recievedKey();
	void calculateSecuredKey();
	void displaySecurePublicKey();
//	//std::string EncryptMessage(std::string& message, int newkey);
//	//std::string SendtoServer(std::string message, int newkey);
};