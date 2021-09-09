using System;

namespace _9498 {
    class Program {
        static void Main() {
            
            string input = Console.ReadLine();
            string[] inputArray = input.Split();
            int number = int.Parse(inputArray[0]);

            if(number >= 90) Console.WriteLine("A");
            else if(number >= 80) Console.WriteLine("B");
            else if(number >= 70) Console.WriteLine("C");
            else if(number >= 60) Console.WriteLine("D");
            else Console.WriteLine("F");
        }
    }
}
