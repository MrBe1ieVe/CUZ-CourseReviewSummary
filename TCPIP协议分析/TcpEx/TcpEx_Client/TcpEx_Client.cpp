/***************************************************************************
程序名称：TCPEx_Client.cpp
功    能：控制台命令状态运行的TCP通信客户程序，实现简单的数据传输功能
调试环境：VC++.NET 2005
作    者：Betta.LI
说    明：
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
		cout<<"加载WinSock失败！";
		return 0;
	}

	//创建用于连接的套接字
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

	err = connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));//请求连接服务器进程
	if ( err == INVALID_SOCKET ) 
	{
		cout<<"connect() fail:"<<WSAGetLastError()<<endl;
		return 0;
	}

	char sendBuf[1024],hostname[100];
	if (gethostname(hostname,100) != 0) //获取主机名称
		strcpy(hostname,"None");
	strcpy(sendBuf,hostname);
	strcat(sendBuf," have conneted to you!");
	err = send(sockClient,sendBuf,strlen(sendBuf)+1,0); //发送数据
	if (err == SOCKET_ERROR)
	{
		cout<<"send() fail:"<<WSAGetLastError()<<endl;
		return 0;
	}

	char recvBuf[1024];
	iLen = recv(sockClient,recvBuf,1024,0); //接收数据
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

	closesocket(sockClient); //关闭套接字
	WSACleanup();
}
