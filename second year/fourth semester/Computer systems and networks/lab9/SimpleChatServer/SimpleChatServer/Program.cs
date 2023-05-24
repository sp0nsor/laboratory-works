using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace SimpleChatServer
{

    class Program
    {
        static Dictionary<string, Socket> connectedClients = new Dictionary<string, Socket>();
        static string chatTheme = "Default Theme";

        static void Main(string[] args)
        {
            Console.WriteLine("Simple Chat Server");

            int port = 8888;

            TcpListener listener =  new TcpListener(IPAddress.Any, port);
            listener.Start();

            Console.WriteLine("Сервер запущен и прослушивает порт {0}", port);

            try
            {
                while (true)
                {
                    Socket clientSocket = listener.AcceptSocket();
                    ClientHendler hendler = new ClientHendler(clientSocket);
                    hendler.Start();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка: " + ex.Message);
            }
            finally
            {
                listener.Stop();
            }
        }
        class ClientHendler
        {
            private Socket clientSocket;
            private string clientName;

            public ClientHendler(Socket socket)
            {
                clientSocket = socket;
            }
            public void Start()
            {
                byte[] byffer = new byte[1024];
                int bytesRead = clientSocket.Receive(byffer);
                clientName = Encoding.UTF8.GetString(byffer, 0, bytesRead);

                connectedClients.Add(clientName, clientSocket);
                Console.WriteLine("Подключен новый клиент: " + clientName);
                
                string welcomeMessage = "Добро пожаловать, " + clientName + "!";
                SendToClient(clientSocket, welcomeMessage);

                SendToClient(clientSocket, "Текущая тема чата: " + chatTheme);

                SendConnectedUsers();

                while (true)
                {
                    bytesRead = clientSocket.Receive(byffer);
                    string comand = Encoding.UTF8.GetString(byffer, 0, bytesRead);

                    if (comand.StartsWith("/users"))
                    {
                        SendConnectedUsers();
                    }
                    else if (comand.StartsWith("/theme"))
                    {
                        string newTheme = comand.Substring(7);
                        SetChatTheme(newTheme);
                    }
                    else if (comand.StartsWith("/private"))
                    {
                        string[] parts = comand.Split(' ');
                        string recipient = parts[1];
                        string privateMessage = comand.Substring(9 + recipient.Length);
                        SendPrivateMessage(recipient, privateMessage);
                    }
                    else if (comand.StartsWith("/quit")){
                        DisconnectClient();
                        break;
                    }
                    else
                    {
                        SendToAllClients(clientName + ":" + comand);
                    }
                }
            }
            private void SendToClient(Socket socket, string message)
            {
                byte[] buffer = Encoding.UTF8.GetBytes(message);
                socket.Send(buffer);
            }
            private void SendToAllClients(string message)
            {
                foreach (Socket socket in connectedClients.Values) { 

                    SendToClient(socket, message);
                }
            }
            private void SendConnectedUsers()
            {
                string userList = "Пользватель на сервере: " + string.Join(", ", connectedClients.Keys);
                SendToClient(clientSocket, userList);
            }
            private void SetChatTheme(string newTheme)
            {
                chatTheme = newTheme;
                Console.WriteLine("Тема чата изменена на: " + newTheme);
            }
            private void SendPrivateMessage (string recipient, string message)
            {
                if(connectedClients.ContainsKey(recipient))
                {
                    Socket recipientSocket = connectedClients[recipient];
                    SendToClient(recipientSocket, "[Private]" + clientName + ": " + message);
                }
                else
                {
                    SendToClient(clientSocket, "Пользователь " + recipient + " не найден");
                }
            }
            private void DisconnectClient()
            {
                connectedClients.Remove(clientName);
                SendToAllClients("Пользватель " + clientName + " отключился");
                clientSocket.Close();
                Console.WriteLine("Клиент " + clientName + " отключен");
            }
        }
    }

}