// E2EE.cpp Diffie-Hellman key exchange

/*Key is given to user
public key given to both clients
client one (user) sends message
Server relays message
message is recieved by client two 
*/

/* Prior to sending
User key: a (1<a<n) -> user calculates g^a mod n now this is public
Public key: g n (g is small prime, n is 4000 bits long)
Customer key: b (1<b<n) -> calculates g^b mod n now this is public

After sending
user recieves customer public key, vice versa
user takes g^b mod n calculates (g^b)^a mod n 
note g^ab = g^ba

Therefore, for both clients having their own private key that no one can view they can still share a connection with each other by generating a public key with their private keys.
Note, since we have g ^ some private key mod n we know that if someone was to view that number it would be extrememly hard for them to figure out what the private key is.
*/

#include <iostream>
#include "ClientOne_LocalProgram.h"
#include "ClientTwo_LocalProgram.h"

int main() {
	clientOne object_One;
	clientTwo object_Two;

	object_One.startConversation();

	object_One.calculateSecuredKey();
	object_Two.calculateSecuredKey();

	// Now that both secured keys are calculated, we see that they are equal which is exactly what we want when generating a shared public key.
	// Note, for better understanding read the top of the page

	std::cout << "End of Diffie-Hellman key exchange" << std::endl << std::endl;

	// CLEAN THIS UP
	//bool sent_message = false;

	//while (!sent_message) {
	//	object_One.get_Message();
	//	sent_message = true;
	//}

	//object_One.send_Message();

	//// Same problem as before, I believe we need to have a delay to see what client two is accurately given.

	//object_Two.Inbox_Message();
}
