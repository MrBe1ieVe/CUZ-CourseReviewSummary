/***************************************************************************
�������ƣ�TCPEx_Server.cpp
��    �ܣ�����̨����״̬���е�TCPͨ�ŷ���������ʵ�ּ򵥵����ݴ��书��
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

	wVersionRequested=MAKEWORD( 2, 2 );
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) 
	{
		cout<<"����WinSockʧ�ܣ�";
		return 0;
	}

	//�������ڼ������׽���
	SOCKET sockSrv = socket(AF_INET,SOCK_STREAM,0); //���������������׽���
	if (sockSrv == INVALID_SOCKET)
	{
		cout<<"socket() fail:"<<WSAGetLastError()<<endl;
		return 0;
	}

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//�Զ������ַ���ֽ�˳��ת��
	addrSrv.sin_port = htons(DEFAULT_PORT);//�ֽ�˳��ת�� 

	//�󶨱�������IP�Ͷ˿�
	err = bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	if ( err != 0 ) 
	{
		cout<<"bind() fail:"<<WSAGetLastError()<<endl;
		return 0;
	}
	
	//����
	err = listen(sockSrv,5);
	if ( err != 0 ) 
	{
		cout<<"listen() fail:"<<WSAGetLastError()<<endl;
		return 0;
	}

	cout<<"Server waiting...:"<<endl;

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);

	while(1)
	{
		SOCKET sockConn = accept(sockSrv,(SOCKADDR*)&addrClient,&len);//���տͻ�������������
		if (sockConn == INVALID_SOCKET)
		{
			cout<<"accept() fail:"<<WSAGetLastError()<<endl;
			break;
		}

		char sendBuf[1024],hostname[100];
		if (gethostname(hostname,100) != 0) //��ȡ��������
			strcpy(hostname,"None");
		sprintf(sendBuf,"welcome %s connected to %s!",inet_ntoa(addrClient.sin_addr),hostname);

		err = send(sockConn,sendBuf,strlen(sendBuf)+1,0); //��������
		if (err == SOCKET_ERROR)
		{
			cout<<"send() fail:"<<WSAGetLastError()<<endl;
			break;
		}

		char recvBuf[1024] = "\0";
		iLen = recv(sockConn,recvBuf,1024,0);//��������
		if (iLen == SOCKET_ERROR)
		{
			cout<<"recv() fail:"<<WSAGetLastError()<<endl;
			break;
		}

		recvBuf[iLen] = '\0';
		cout<<recvBuf<<endl;
		closesocket(sockConn); //�ر��׽���
	}

	closesocket(sockSrv);//�رշ����������׽���
	WSACleanup();

	return 0;
}