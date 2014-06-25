#include "Socket.h"
#include "ClientSocket.h"
#include "ServeurSocket.h"
#include <iostream>
using namespace std;

void main(void)
{
	CClientSocket Sc1;

	/*******************************************************************************************
	* PARTIE CLIENT SOCKET
	********************************************************************************************/
	char IpAdresse[15];
	int port = 3306;
	int sock_err;
	SOCKET Socket;
	char buffer[32] = "";

	Socket = Sc1.CreerSocketC();								//Creation Socket client

	if(Socket != INVALID_SOCKET)
	{
		cout << "Saisir l'adresse Ip du serveur: " << endl;		//Saisie de l'adresse du serveur
		memset(IpAdresse,'\0',sizeof(IpAdresse));
		cin.getline(IpAdresse,sizeof(IpAdresse));

		Sc1.ConfigSocketC(port,IpAdresse);

		sock_err = Sc1.Connexion();

		if(sock_err != SOCKET_ERROR)
		{
			cout << "Connexion a l'adresse " << IpAdresse << " sur le port " << port << endl;
			do
			{
				cout << "Veuillez saisir un message: ";
				cin >> buffer;

				sock_err = Sc1.Envoie(buffer, sizeof(buffer),0);

			}while(!(*buffer == 'Q'));
		}
	}
}
