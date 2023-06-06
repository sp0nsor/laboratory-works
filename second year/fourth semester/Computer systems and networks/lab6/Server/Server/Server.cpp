#include <iostream>
#include <winsock2.h>

using namespace std;

#define BUFFER_SIZE 1024

int main() {
    setlocale(LC_ALL, "ru");

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "Ошибка инициализации Winsock." << endl;
        return 1;
    }

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        cerr << "Ошибка создания сокета." << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(17);

    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        cerr << "Ошибка привязки сокета." << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    if (listen(serverSocket, 1) == SOCKET_ERROR) {
        cerr << "Ошибка прослушивания сокета." << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Сервер запущен. Ожидание подключений..." << endl;

    SOCKET clientSocket;
    sockaddr_in clientAddress{};
    int clientAddressSize = sizeof(clientAddress);
    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressSize);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "Ошибка принятия подключения." << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Подключение принято. Отправка цитаты..." << endl;

    const char* quote = "This is the Quote of the Day!";
    if (send(clientSocket, quote, strlen(quote), 0) == SOCKET_ERROR) {
        cerr << "Ошибка отправки цитаты." << endl;
    }

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
