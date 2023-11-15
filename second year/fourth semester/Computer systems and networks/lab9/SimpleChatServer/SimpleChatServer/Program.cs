using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace SimpleChatServer
{
    class Program
    {
        private static Dictionary<string, Socket> clients = new Dictionary<string, Socket>();
        private static string chatTheme = "Тема по умолчанию";

        static void Main(string[] args)
        {
            Console.WriteLine("Simple Chat Server");
            Console.WriteLine("Ожидание подключений...");

            // Создание TCP сокета и привязка его к указанному порту
            Socket serverSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            serverSocket.Bind(new IPEndPoint(IPAddress.Any, 8888));
            serverSocket.Listen(10);

            while (true)
            {
                // Принятие входящего подключения
                Socket clientSocket = serverSocket.Accept();

                // Создание отдельного потока для обработки подключенного клиента
                System.Threading.Thread clientThread = new System.Threading.Thread(() => HandleClient(clientSocket));
                clientThread.Start();
            }
        }

        static void HandleClient(Socket clientSocket)
        {
            string clientName = null;
            string clientAddress = clientSocket.RemoteEndPoint.ToString();

            try
            {
                while (true)
                {
                    // Получение данных от клиента
                    byte[] buffer = new byte[1024];
                    int bytesRead = clientSocket.Receive(buffer);

                    if (bytesRead == 0)
                    {
                        // Клиент отключился
                        break;
                    }

                    string message = Encoding.UTF8.GetString(buffer, 0, bytesRead);
                    string[] command = message.Split(' ');

                    // Обработка команды от клиента
                    if (command[0] == "SETNAME")
                    {
                        // Задание имени пользователя
                        clientName = command[1];
                        clients.Add(clientName, clientSocket);
                        SendMessageToClient(clientSocket, "Ваше имя установлено: " + clientName);
                    }
                    else if (command[0] == "GETUSERS")
                    {
                        // Получение списка пользователей на сервере
                        string userList = "Пользователи на сервере: ";
                        foreach (string userName in clients.Keys)
                        {
                            userList += userName + ", ";
                        }
                        SendMessageToClient(clientSocket, userList);
                    }
                    else if (command[0] == "BROADCAST")
                    {
                        // Отправка сообщения всем пользователям
                        string broadcastMessage = string.Join(" ", command, 1, command.Length - 1);
                        foreach (Socket socket in clients.Values)
                        {
                            SendMessageToClient(socket, "[" + clientName + "]: " + broadcastMessage);
                        }
                    }
                    else if (command[0] == "PRIVATE")
                    {
                        // Отправка приватного сообщения определенному пользователю
                        string targetUser = command[1];
                        string privateMessage = string.Join(" ", command, 2, command.Length - 2);
                        if (clients.ContainsKey(targetUser))
                        {
                            SendMessageToClient(clients[targetUser], "[Приватно от " + clientName + "]: " + privateMessage);
                        }
                        else
                        {
                            SendMessageToClient(clientSocket, "Пользователь " + targetUser + " не найден.");
                        }
                    }
                    else if (command[0] == "SETTHEME")
                    {
                        // Установка темы чата
                        chatTheme = string.Join(" ", command, 1, command.Length - 1);
                        foreach (Socket socket in clients.Values)
                        {
                            SendMessageToClient(socket, "Тема чата установлена: " + chatTheme);
                        }
                    }
                    else if (command[0] == "GETTHEME")
                    {
                        // Получение темы чата
                        SendMessageToClient(clientSocket, "Текущая тема чата: " + chatTheme);
                    }
                    else
                    {
                        SendMessageToClient(clientSocket, "Неизвестная команда.");
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка при обработке клиента: " + ex.Message);
            }
            finally
            {
                // Удаление клиента из списка при отключении
                if (clientName != null)
                {
                    clients.Remove(clientName);
                    Console.WriteLine("Клиент отключился: " + clientName + " [" + clientAddress + "]");
                }
                clientSocket.Close();
            }
        }

        static void SendMessageToClient(Socket clientSocket, string message)
        {
            byte[] buffer = Encoding.UTF8.GetBytes(message);
            clientSocket.Send(buffer);
        }
    }
}