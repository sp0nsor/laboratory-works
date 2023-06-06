#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

using namespace std;

#define BUFFER_SIZE 1024

int main() {
    setlocale(LC_ALL, "ru");

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "Ошибка инициализации Winsock." << endl;
        return 1;
    }

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "Ошибка создания сокета." << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    if (inet_pton(AF_INET, "127.0.0.1", &(serverAddress.sin_addr)) <= 0) {
        cerr << "Ошибка установки IP-адреса сервера." << endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }
    serverAddress.sin_port = htons(17);

    if (connect(clientSocket, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress)) == SOCKET_ERROR) {
        cerr << "Ошибка подключения к серверу." << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    cout << "Подключение к серверу установлено. Ожидание цитаты..." << endl;

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    if (recv(clientSocket, buffer, BUFFER_SIZE - 1, 0) == SOCKET_ERROR) {
        cerr << "Ошибка получения цитаты." << endl;
    }
    else {
        cout << "Полученная цитата: " << buffer << endl;
    }

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}