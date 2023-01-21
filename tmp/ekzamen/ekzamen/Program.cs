using System;

namespace ekzamen
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = { 1, 1, -1, 0, -2, 2, 10, 1 };
            Console.WriteLine("Измененный массив: ");
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] == 1) arr[i] = -1;
                Console.WriteLine(arr[i]);
            }
        }
    }
}
