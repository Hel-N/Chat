#pragma comment (lib, "WS2_32.lib")
#include <iostream>
#include <vector>
#include <WinSock2.h>
#include <WS2tcpip.h>

#define Port "1234"

using namespace std;

SOCKET �onnect_socket; // ������������ ������������
vector<SOCKET> Connections; // ��� ������������ ������������
SOCKET listen_socket; // ����� ��� �����������
int client_count = 0;

void SendMessageToClients(int clientID);

int main(){
	setlocale(LC_ALL, "Rus");

	WSAData data;
	WORD socket_version = MAKEWORD(2, 2); //--??? ������ �������

	if (WSAStartup(socket_version, &data)){
		cout << "Error WSAStartup!" << WSAGetLastError() << endl; // ������� ��������!
		return 0;
	}

	addrinfo hints;  //??????
	addrinfo *result;

	ZeroMemory(&hints, sizeof(hints));

	hints.ai_family = AF_INET; // ����� ���������
	hints.ai_flags = AI_PASSIVE; //???
	hints.ai_socktype = SOCK_STREAM; // ��� ������ (��������� ����� (� ���������� ����������))
	hints.ai_protocol = IPPROTO_TCP;

	getaddrinfo(NULL, Port, &hints, &result);

	if ((listen_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol)) < 0){
		cout << "Error socket!" << WSAGetLastError() << endl; // ������� ��������!
		WSACleanup(); // �������������� ���������� Winsock
		return 0;
	}

	if (bind(listen_socket, result->ai_addr, result->ai_addrlen)){
		cout << "Error bind!" << WSAGetLastError() << endl; // ������� ��������!
		closesocket(listen_socket); // ��������� �����!
		WSACleanup(); // �������������� ���������� Winsock
		return 0;
	}

	if (listen(listen_socket, SOMAXCONN)){ // SOMAXCONN-????? (������ �������, ���������� �����������)
		cout << "Error listen!" << WSAGetLastError() << endl; // ������� ��������!
		closesocket(listen_socket); // ��������� �����!
		WSACleanup(); // �������������� ���������� Winsock
		return 0;
	}

	freeaddrinfo(result); //�������� ����������

	cout << "������ ����� � ������..." << endl;

	char message_ready[] = "���������� �����������";

	while (true){
		if (�onnect_socket = accept(listen_socket, NULL, NULL)){ //null - ?????????
			Connections.push_back(�onnect_socket);
			client_count++; //���� �� ���������???????!!!
			send(�onnect_socket, message_ready, strlen(message_ready), NULL);
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)SendMessageToClients, (LPVOID)(client_count - 1), NULL, NULL); // ������� ����� � ��������� ������� � ������
		}
	}

	return 0;
}

void SendMessageToClients(int clientID){
	char *buff = new char [1024];
	int nsize;
	while(true){
		memset(buff, 0, sizeof(buff));
		if ((nsize = recv(Connections[clientID], buff, sizeof(buff), NULL)) != SOCKET_ERROR){
			//cout << buff << endl;
			buff[nsize] = '\0';
			for (int i = 0; i < Connections.size(); ++i){
				send(Connections[i], buff, strlen(buff), NULL);
			}
		}
	}
	delete buff;
}