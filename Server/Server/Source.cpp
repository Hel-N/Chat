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

SOCKET сonnect_socket; // Подключаемые пользователи
vector<SOCKET> Connections; // Все подключенные пользователи
//map<string, SOCKET> Connections; // Все подключенные пользователи
vector<bool> online_connections;
SOCKET listen_socket; // Сокет для подключения
int client_count = 0;

void SendMessageToClients(int clientID);

int main(){
	setlocale(LC_ALL, "Rus");

	WSAData data;
	WORD socket_version = MAKEWORD(2, 2); //--??? Версия сокетов

	if (WSAStartup(socket_version, &data)){
		cout << "Error WSAStartup!" << WSAGetLastError() << endl; // Сделать задержку!
		return 0;
	}

	addrinfo hints;  //??????
	addrinfo *result;

	ZeroMemory(&hints, sizeof(hints));

	hints.ai_family = AF_INET; // Сокет Интернета
	hints.ai_flags = AI_PASSIVE; //???
	hints.ai_socktype = SOCK_STREAM; // Тип сокета (потоковый сокет (с установкой соединения))
	hints.ai_protocol = IPPROTO_TCP;

	getaddrinfo(NULL, Port, &hints, &result);

	if ((listen_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol)) < 0){
		cout << "Error socket!" << WSAGetLastError() << endl; // Сделать задержку!
		WSACleanup(); // Деиницилизация библиотеки Winsock
		return 0;
	}

	if (bind(listen_socket, result->ai_addr, result->ai_addrlen)){
		cout << "Error bind!" << WSAGetLastError() << endl; // Сделать задержку!
		closesocket(listen_socket); // закрываем сокет!
		WSACleanup(); // Деиницилизация библиотеки Winsock
		return 0;
	}

	if (listen(listen_socket, SOMAXCONN)){ // SOMAXCONN-????? (Размер очереди, количество подключений)
		cout << "Error listen!" << WSAGetLastError() << endl; // Сделать задержку!
		closesocket(listen_socket); // закрываем сокет!
		WSACleanup(); // Деиницилизация библиотеки Winsock
		return 0;
	}

	freeaddrinfo(result); //удаление информации

	cout << "Сервер готов к работе..." << endl;

	char message_ready[] = "Соединение установлено";

	while (true){
		if (сonnect_socket = accept(listen_socket, NULL, NULL)){ //null - ?????????
			Connections.push_back(сonnect_socket);
			online_connections.push_back(true);
			client_count++; //если он oтключился???????!!!

			/*//Получение ника пользователя
			char* buff = new char[1024];
			int nsize;
			if ((nsize = recv(сonnect_socket, buff, sizeof(buff), NULL)) != SOCKET_ERROR){
			buff[nsize] = '\0';
			string str = buff;
			Connections[str] = сonnect_socket;
			}*/

			send(сonnect_socket, message_ready, strlen(message_ready), NULL);
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)SendMessageToClients, (LPVOID)(client_count - 1), NULL, NULL); // Создаем поток и запускаем функцию в потоке
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