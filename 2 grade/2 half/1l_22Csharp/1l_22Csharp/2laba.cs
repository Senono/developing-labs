using System;
using System.Text.RegularExpressions;

namespace _1l_22Csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            string login;
            Regex logReg = new Regex(@"^[a-zA-Z]{1}\w{1,9}(?!.)");
            
            while (true)
            {
                Console.WriteLine("Введите логин: ");
                login = Console.ReadLine();
                if (logReg.IsMatch(login)) break;
                Console.WriteLine("Некорректный логин");
            }

            Console.WriteLine("Ok!");
        }
    }
}
