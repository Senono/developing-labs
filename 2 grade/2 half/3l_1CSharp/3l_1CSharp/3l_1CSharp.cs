using System;

namespace _3l_1CSharp
{
    class TV
    {
        private int volume;

        public int Volume
        {
            get
            {
                return volume;
            }
            set
            {
                if (value >= 0 && value < 101)
                {
                    volume = value;
                }
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            TV Televisor1 = new TV();
            Televisor1.Volume = 3;
            Console.WriteLine("Текущая громкость: " + Televisor1.Volume);
            Televisor1.Volume = 101;
            Console.WriteLine("Текущая громкость: " + Televisor1.Volume);
            Televisor1.Volume = 75;
            Console.WriteLine("Текущая громкость: " + Televisor1.Volume);
        }
    }
}
