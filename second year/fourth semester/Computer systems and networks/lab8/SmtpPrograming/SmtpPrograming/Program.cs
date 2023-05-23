using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Net.Mail;

namespace SmtpPrograming
{
    class Program
    {
        static void Main(string[] args)
        {
            string settingsPath = @"D:\laboratory-works\second year\fourth semester\Computer systems and networks\lab8\SmtpPrograming\SmtpPrograming\settings.txt";
            string[] settings = File.ReadAllLines(settingsPath);

            string senderEmail = settings[0];
            string subject = settings[1];
            string body = settings[2];

            string recipientsPath = @"D:\laboratory-works\second year\fourth semester\Computer systems and networks\lab8\SmtpPrograming\SmtpPrograming\recipients.txt";
            string[] recipients = File.ReadAllLines(recipientsPath);

            foreach (string recipient in recipients)
            {
                try
                {
                    using (MailMessage mail = new MailMessage())
                    {
                        mail.From = new MailAddress(senderEmail);
                        mail.To.Add(recipient);
                        mail.Subject = subject;
                        mail.Body = body;

                        using (SmtpClient smtpClient = new SmtpClient("127.0.0.1", 25))
                        {
                            smtpClient.Credentials = new NetworkCredential(senderEmail, "stud");
                            smtpClient.Send(mail);
                        }
                    }

                    using (StreamWriter writer = new StreamWriter(@"D:\laboratory-works\second year\fourth semester\Computer systems and networks\lab8\SmtpPrograming\SmtpPrograming\log.txt", true))
                    {
                        writer.WriteLine($"Сообщение отправлено на адрес {recipient}");
                    }
                }
                catch (Exception ex)
                {
                    using (StreamWriter writer = new StreamWriter(@"D:\laboratory-works\second year\fourth semester\Computer systems and networks\lab8\SmtpPrograming\SmtpPrograming\log.txt", true))
                    {
                        writer.WriteLine($"Ошибка при отправке сообщения на адрес {recipient}: {ex.Message}");
                    }
                }
            }

            Console.WriteLine("Отправка сообщений завершена.");
            Console.ReadLine();
        }
    }
}