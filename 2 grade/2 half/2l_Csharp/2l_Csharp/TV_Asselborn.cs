using System;

namespace _2l_Csharp
{
    class Televisor
    {
        private int channel = 0;

        public void currentCh()
        {
            Console.WriteLine("Текущий канал: " + channel);
        }
        public void next() // Включить следующий канал
        {
            channel++;
            currentCh();
        }
        public void previous() // Включить предыдущий канал
        {
            if (channel != 0)
            {
                channel--;
                currentCh();
            } else
            {
                Console.WriteLine("Канал не может быть меньше нуля");
            }
        }
        public void switchCh(int ch)
        {
            channel = ch;
            currentCh();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Televisor myTV = new Televisor();
            myTV.currentCh();
            myTV.next();
            myTV.switchCh(8);
            myTV.previous();
        }
    }
}
