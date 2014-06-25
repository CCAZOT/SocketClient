#pragma once
#include "Socket.h"

class CClientSocket: public CPharmaSocket
{
private:

public:
	CClientSocket(void);
	~CClientSocket(void);
	SOCKET CreerSocketC();															//Methode permettant de creer une socket.
	SOCKADDR_IN ConfigSocketC(int PORT, char* IpAddress);			//Methode permettant de configurer une socket.
	int Connexion(void);									//Methode permettant de se connecter a une socket.
	bool send_SocketDelivrance(void);
	bool send_SocketConnexion(void);
};

