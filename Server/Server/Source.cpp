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
//vector<SOCKET> Connections; // ��� ������������ ������������
vector<SOCKET> newConnectSockets; //������,������� ����������,�� ���� ��� ����
int pos_new_socket_without_nick = 0;
map<string, SOCKET> Connections; // ��� ������������ ������������
vector<bool> online_connections;
SOCKET listen_socket; // ����� ��� �����������
int client_count = 0;

void SendMessageToClients(int clientID);
pair<string, string> TakeNicksFromMessage(string message);

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

	char message_ready[] = "|���������� �����������|";

	while (true){
		if (�onnect_socket = accept(listen_socket, NULL, NULL)){ //null - ?????????
			newConnectSockets.push_back(�onnect_socket);
			online_connections.push_back(true);
			client_count++; //���� �� o���������???????!!!

			send(�onnect_socket, message_ready, strlen(message_ready), NULL);
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)SendMessageToClients, (LPVOID)(client_count - 1), NULL, NULL); // ������� ����� � ��������� ������� � ������
		}
	}

	return 0;
}

void SendMessageToClients(int UserID){
	char *buff = new char[1024];
	char *buffmes = new char[1024];
	int nsize;

	bool startMessageFlag = false;
	bool startNickFlag = false;
	//bool newNickFlag = false;
	//bool newMessageFlag = false;
	string message = "";
	string nick = "";

	while (true){
		memset(buff, 0, sizeof(buff));
		if ((nsize = recv(newConnectSockets[UserID], buff, sizeof(buff), NULL)) != SOCKET_ERROR){
			buff[nsize] = '\0';

			for (int i = 0; i < strlen(buff); ++i){
				if (buff[i] == '|'){
					if (!startMessageFlag){
						startMessageFlag = true;
						message += buff[i];
						continue;
					}
					else{
						message += buff[i];
						startMessageFlag = false;
						//newMessageFlag = true;

						//�������� ���������
						pair<string, string> pNick = TakeNicksFromMessage(message);
						if (pNick.first == pNick.second){
							send(Connections[pNick.first], message.c_str(), strlen(message.c_str()), NULL);
						}
						else{
							send(Connections[pNick.first], message.c_str(), strlen(message.c_str()), NULL);
							send(Connections[pNick.second], message.c_str(), strlen(message.c_str()), NULL);
						}
						message = "";
					}
				}

				if (buff[i] == '@'){
					if (!startNickFlag){
						startNickFlag = true;
						nick += buff[i];
						continue;
					}
					else{
						nick += buff[i];
						startNickFlag = false;
						//newNickFlag = true;

						//����� ������ � �����
						Connections[nick] = newConnectSockets[pos_new_socket_without_nick];
						pos_new_socket_without_nick++;

						for (int i = 0; i < pos_new_socket_without_nick-1; ++i){
							send(newConnectSockets[i], nick.c_str(), strlen(nick.c_str()), NULL);
						}

						for (auto it = Connections.begin(); it != Connections.end(); ++it){
							send(newConnectSockets[pos_new_socket_without_nick - 1], (it->first).c_str(), strlen((it->first).c_str()), NULL);
						}

						nick = "";
					}
				}

				if (startMessageFlag){
					message += buff[i];
					continue;
				}

				if (startNickFlag){
					nick += buff[i];
					continue;
				}
			}
		}
	}
	delete buff;
}

pair<string, string> TakeNicksFromMessage(string message){
	string nick1, nick2;

	int num = 0;

	for (int i = 1; i < message.size(); ++i){
		if (message[i] != ':')
			nick1 += message[i];
		else
			break;
	}

	for (int i = message.size() - 2; i >= 0; --i){
		if (message[i] != ':')
			nick2 += message[i];

		else
			break;
	}

	reverse(nick2.begin(), nick2.end());

	return make_pair('@' + nick1 + '@', '@' + nick2 + '@');
}