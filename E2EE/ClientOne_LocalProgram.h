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
	uint64_t clientOne_SecuredKey;
	std::string message;
	std::string client_Twos_message;
	// Functions
	void display_clientOne_privateKey() const;

public:
	// Objects
	DummyServer server_object;
	// Variables
	uint64_t clientOne_publicKey;
	uint64_t RecievedKey;
	uint64_t n;
	uint64_t g;
	uint64_t secured_message;
	uint64_t recieved_message;
	// Functions
	clientOne();
	void startConversation();
	void createKey();
	void generatePublicKey();
	void sendKey();
	void Display_clientOne_publicKey() const;
	void Handshake_complete();
	void display_recievedKey() const;
	void calculateSecuredKey();
	void displaySecurePublicKey() const;
	void get_Message();
	void send_Message();
	// Technically, client-end encryption
	uint64_t Transform_Message(std::string& securemessage);
	void read_Transform(uint64_t newMessage);
	uint64_t EncryptMessage(std::string& securemessage, uint64_t newkey);
	void read_Encrypted();
	void decrypt_Message(uint64_t encrypted_message);
	void read_Recieved_Message();
	//std::string SendtoServer(std::string message, int newkey);
	~clientOne();
};