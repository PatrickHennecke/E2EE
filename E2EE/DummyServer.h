#pragma once

#include <iostream>
#include <cstdint>

using std::uint64_t;

class DummyServer {
	// Creates two public keys
public:
	// Variables
	uint64_t key1;
	uint64_t key2;
	uint64_t clientOne_publicKey;
	uint64_t clientTwo_publicKey;
	uint64_t relay_Message;
	// Functions
	DummyServer();
	void createKey1();
	void createKey2();
	uint64_t sendKey1();
	uint64_t sendKey2();
	void DisplayKey1() const;
	void DisplayKey2() const;
	void createConnection();
	void relay_clientOne_publicKey(uint64_t& Client_One);
	void relay_clientTwo_publicKey(uint64_t& Client_Two);
	// Need to send public keys to appropriate clients
	uint64_t send_clientOne_publicKey();
	uint64_t send_clientTwo_publicKey();
	void display_clientOne_publicKey() const;
	void display_clientTwo_publicKey() const;
	uint64_t Relay_clientOne_Message(std::string message);
	uint64_t Relay_clientTwo_Message(std::string message);
	~DummyServer();

private:
	//DummyServer() = default;
	
	
};