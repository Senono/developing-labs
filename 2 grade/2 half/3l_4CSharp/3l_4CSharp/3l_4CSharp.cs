using System;

namespace _3l_4CSharp
{
    abstract class Human
    {
        public string Name { get; set; }
        public abstract void sayHello();
    }

    class Nation : Human
    {
        private string Hello { get; set; }

        public Nation(string name, string hello)
        {
            Name = name;
            Hello = hello;
        }

        public override void sayHello()
        {
            Console.WriteLine(Hello + ", " + Name);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Nation russian = new Nation("Елена", "здравствуйте");
            russian.sayHello();
            Nation usa = new Nation("Elena", "hello");
            usa.sayHello();
        }
    }
}
