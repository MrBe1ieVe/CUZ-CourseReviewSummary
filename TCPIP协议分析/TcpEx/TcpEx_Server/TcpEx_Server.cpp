/***************************************************************************
程序名称：TCPEx_Server.cpp
功    能：控制台命令状态运行的TCP通信服务器程序，实现简单的数据传输功能
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

	wVersionRequested=MAKEWORD( 2, 2 );
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) 
	{
		cout<<"加载WinSock失败！";
		return 0;
	}

	//创建用于监听的套接字
	SOCKET sockSrv = socket(AF_INET,SOCK_STREAM,0); //创建服务器监听套接字
	if (sockSrv == INVALID_SOCKET)
	{
		cout<<"socket() fail:"<<WSAGetLastError()<<endl;
		return 0;
	}

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//自动分配地址，字节顺序转换
	addrSrv.sin_port = htons(DEFAULT_PORT);//字节顺序转换 

	//绑定本地主机IP和端口
	err = bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	if ( err != 0 ) 
	{
		cout<<"bind() fail:"<<WSAGetLastError()<<endl;
		return 0;
	}
	
	//监听
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
		SOCKET sockConn = accept(sockSrv,(SOCKADDR*)&addrClient,&len);//接收客户进程连接请求
		if (sockConn == INVALID_SOCKET)
		{
			cout<<"accept() fail:"<<WSAGetLastError()<<endl;
			break;
		}

		char sendBuf[1024],hostname[100];
		if (gethostname(hostname,100) != 0) //获取主机名称
			strcpy(hostname,"None");
		sprintf(sendBuf,"welcome %s connected to %s!",inet_ntoa(addrClient.sin_addr),hostname);

		err = send(sockConn,sendBuf,strlen(sendBuf)+1,0); //发送数据
		if (err == SOCKET_ERROR)
		{
			cout<<"send() fail:"<<WSAGetLastError()<<endl;
			break;
		}

		char recvBuf[1024] = "\0";
		iLen = recv(sockConn,recvBuf,1024,0);//接收数据
		if (iLen == SOCKET_ERROR)
		{
			cout<<"recv() fail:"<<WSAGetLastError()<<endl;
			break;
		}

		recvBuf[iLen] = '\0';
		cout<<recvBuf<<endl;
		closesocket(sockConn); //关闭套接字
	}

	closesocket(sockSrv);//关闭服务器监听套接字
	WSACleanup();

	return 0;
}