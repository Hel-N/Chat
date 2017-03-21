#pragma comment (lib, "WS2_32.lib")
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <WinSock2.h>
#include <WS2tcpip.h>

#define Port "1234"

using namespace std;

SOCKET �onnect_socket; // ������������ ������������
vector<SOCKET> Connections; // ��� ������������ ������������
//map<string, SOCKET> Connections; // ��� ������������ ������������
vector<bool> online_connections;
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
			online_connections.push_back(true);
			client_count++; //���� �� o���������???????!!!

			/*//��������� ���� ������������
			char* buff = new char[1024];
			int nsize;
			if ((nsize = recv(�onnect_socket, buff, sizeof(buff), NULL)) != SOCKET_ERROR){
			buff[nsize] = '\0';
			string str = buff;
			Connections[str] = �onnect_socket;
			}*/

			send(�onnect_socket, message_ready, strlen(message_ready), NULL);
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)SendMessageToClients, (LPVOID)(client_count - 1), NULL, NULL); // ������� ����� � ��������� ������� � ������
		}
	}

	return 0;
}

void SendMessageToClients(int clientID){
	char *buff = new char[1024];
	char *buffmes = new char[1024];
	int nsize;

	bool startMessageFlag = false;
	string message = "";

	while (true){
		memset(buff, 0, sizeof(buff));
		if ((nsize = recv(Connections[clientID], buff, sizeof(buff), NULL)) != SOCKET_ERROR){
			buff[nsize] = '\0';

			if (buff[0] == '|'){
				startMessageFlag = true;
				message += buff;
			}
			else{
				if (buff[nsize - 1] == '|'){
					startMessageFlag = false;
					message += buff;
					//strcpy_s(buff, message.c_str());
				}
				else{
					message += buff;
				}
			}


		//string s = buff;
		//cout << s << endl;

		for (int i = 0; i < Connections.size() && !startMessageFlag; ++i){
			send(Connections[i], message.c_str(), strlen(message.c_str()), NULL);
			if (i == Connections.size() - 1)
				message = "";
		}
	}
}
delete buff;
}