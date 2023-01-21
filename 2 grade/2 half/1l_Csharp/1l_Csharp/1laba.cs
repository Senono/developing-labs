using System;
using System.IO;
using System.Text;

namespace _1l_Csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            string FileName = "numbers.txt";

            FileStream file = new FileStream(FileName, FileMode.OpenOrCreate, FileAccess.Write);
            file.SetLength(0);
            StreamWriter writer = new StreamWriter(file);
            
            for (int i = 1; i < 501; i++) writer.Write(i + ", ");
            writer.Close();
        }
    }
}
