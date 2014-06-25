#include "ClientSocket.h"


CClientSocket::CClientSocket(void)
{
	
}


CClientSocket::~CClientSocket(void)
{
}

SOCKET CClientSocket::CreerSocketC()
{
	Socket = socket(AF_INET, SOCK_STREAM, 0);	
	return(Socket);
}
	
SOCKADDR_IN CClientSocket::ConfigSocketC(int Port, char* IpAddress)
{
	 
   sin.sin_addr.s_addr = inet_addr(IpAddress);
   sin.sin_family = AF_INET;
   sin.sin_port = htons(Port);
   return(sin);

}

int CClientSocket::Connexion(void)
{
	sock_err = connect(Socket, (SOCKADDR*)&sin, sizeof(sin));
	return(sock_err);
}


bool CClientSocket::send_SocketDelivrance(void)
{
	return false;
}


bool CClientSocket::send_SocketConnexion(void)
{
	return false;
}


