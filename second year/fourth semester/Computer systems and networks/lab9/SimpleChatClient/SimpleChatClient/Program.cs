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

            string serverIP = "127.0.0.1";
            int serverPort = 8888;

            try
            {
                TcpClient client = new TcpClient(serverIP, serverPort);
                Console.WriteLine("Подключено к серверу {0}:{1}", serverIP, serverPort);

                Console.Write("Введите имя: ");
                string userName = Console.ReadLine();

                byte[] nameBuffer = Encoding.UTF8.GetBytes(userName);
                client.GetStream().Write(nameBuffer, 0, nameBuffer.Length);

                MessagerReceiver receiver = new MessagerReceiver(client);
                receiver.Start();

                while (true)
                {
                    string command = Console.ReadLine();

                    byte[] commandBuffer = Encoding.UTF8.GetBytes(command);
                    client.GetStream().Write(commandBuffer, 0, commandBuffer.Length);

                    if (command.StartsWith("/quit"))
                    {
                        break;
                    }
                }
                client.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка: " + ex.Message);
            }
            Console.WriteLine("Нажмите любую кнопку для выхода...");
            Console.ReadKey();
        }

        class MessagerReceiver
        {
            private TcpClient client;

            public MessagerReceiver(TcpClient client)
            {
                this.client = client;
            }

            public void Start()
            {
                try
                {
                    while (true)
                    {
                        byte[] buffer = new byte[1024];
                        int bytesRead = client.GetStream().Read(buffer, 0, buffer.Length);
                        string message = Encoding.UTF8.GetString(buffer, 0, bytesRead);
                        Console.WriteLine(message);
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Ошибка приема сообщения: " + ex.Message);
                }
            }
        }
    }
}