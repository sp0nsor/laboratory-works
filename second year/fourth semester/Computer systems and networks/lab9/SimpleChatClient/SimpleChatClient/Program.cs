using System;
using System.Net.Sockets;
using System.Text;

namespace SimpleChatClient
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Simple Chat Client");

            try
            {
                // Создание TCP сокета и подключение к серверу
                Socket clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                clientSocket.Connect("127.0.0.1", 8888);

                // Цикл взаимодействия с сервером
                while (true)
                {
                    Console.Write("> ");
                    string input = Console.ReadLine();

                    // Отправка команды серверу
                    byte[] buffer = Encoding.UTF8.GetBytes(input);
                    clientSocket.Send(buffer);

                    // Получение ответа от сервера
                    buffer = new byte[1024];
                    int bytesRead = clientSocket.Receive(buffer);
                    string message = Encoding.UTF8.GetString(buffer, 0, bytesRead);
                    Console.WriteLine(message);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }
        }
    }
}