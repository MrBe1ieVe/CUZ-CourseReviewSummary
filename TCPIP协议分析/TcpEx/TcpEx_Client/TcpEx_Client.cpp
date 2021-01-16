/***************************************************************************
�������ƣ�TCPEx_Client.cpp
��    �ܣ�����̨����״̬���е�TCPͨ�ſͻ�����ʵ�ּ򵥵����ݴ��书��
���Ի�����VC++.NET 2005
��    �ߣ�Betta.LI
˵    ����
***************************************************************************/
#include <winsock2.h>
#include  <iostream> 
using namespace std;
#include <string.h>

int main(int argc, char *argv[])
{
	const int DEFAULT_PORT = 5000; 
	WORD wVersionRequested;
	WSADATA wsaData;
	int err,iLen;

	if (argc < 2) {
		cout<<"Command:TcpEx_Client ServerIP"<<endl;
		return 0;
	} 

	wVersionRequested=MAKEWORD( 2, 2 );
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) 
	{
		cout<<"����WinSockʧ�ܣ�";
		return 0;
	}

	//�����������ӵ��׽���
	SOCKET sockClient = socket(AF_INET,SOCK_STREAM,0);
	if (sockClient == INVALID_SOCKET)
	{
		cout<<"socket() fail:"<<WSAGetLastError()<<endl;
		return 0;
	}

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_addr.S_un.S_addr = inet_addr(argv[1]);
	addrSrv.sin_port = htons(DEFAULT_PORT); 

	err = connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));//�������ӷ���������
	if ( err == INVALID_SOCKET ) 
	{
		cout<<"connect() fail:"<<WSAGetLastError()<<endl;
		return 0;
	}

	char sendBuf[1024],hostname[100];
	if (gethostname(hostname,100) != 0) //��ȡ��������
		strcpy(hostname,"None");
	strcpy(sendBuf,hostname);
	strcat(sendBuf," have conneted to you!");
	err = send(sockClient,sendBuf,strlen(sendBuf)+1,0); //��������
	if (err == SOCKET_ERROR)
	{
		cout<<"send() fail:"<<WSAGetLastError()<<endl;
		return 0;
	}

	char recvBuf[1024];
	iLen = recv(sockClient,recvBuf,1024,0); //��������
	if (iLen == 0)
		return 0;
	else if (iLen == SOCKET_ERROR)
	{
		cout<<"recv() fail:"<<WSAGetLastError()<<endl;
		return 0;
	}
	else
	{
		recvBuf[iLen] = '\0';
		cout<<recvBuf<<endl;
	}

	closesocket(sockClient); //�ر��׽���
	WSACleanup();
}
