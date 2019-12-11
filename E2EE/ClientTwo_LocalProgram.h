#pragma once

#include "DummyServer.h"

using std::uint64_t;

class clientTwo {
private:
	// Variables
	uint64_t clientTwo_privateKey;
	uint64_t clientTwo_SecuredKey;
	std::string message;
	std::string client_Ones_message;
	// Functions
	void display_clientTwo_privateKey() const;

public:
	// Objects
	DummyServer server_object;
	// Variables
	uint64_t clientTwo_publicKey;
	uint64_t RecievedKey;
	uint64_t n;
	uint64_t g;
	uint64_t secured_message;
	uint64_t recieved_message;
	// Functions
	clientTwo();
	void startConversation();
	void createKey();
	void generatePublicKey();
	void sendKey();
	void Display_clientTwo_publicKey() const;
	void Handshake_complete();
	void display_recievedKey() const;
	void calculateSecuredKey();
	void displaySecurePublicKey() const;
	void get_Message();
	uint64_t Transform_Message(std::string& securemessage);
	void read_Transform(uint64_t newMessage);
	uint64_t EncryptMessage(std::string& securemessage, uint64_t newkey);
	void read_Encrypted();
	void decrypt_Message(uint64_t encrypted_message);
	void read_Recieved_Message();
	//std::string SendtoServer(std::string message, int newkey);
	~clientTwo();
};