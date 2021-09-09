using System;

namespace _10818
{
    class Program
    {
        static void Main(string[] args)
        {
            // BOJ Problem no.10818
            // author : thKwon(th.kwon29@gmail.com) - 2021/09/08
            
            int number = int.Parse(Console.ReadLine());
            //Console.WriteLine("debug - input : " + number);
            string[] inputArray = Console.ReadLine().Split();
            int max = -1000000, min = 1000000;
            foreach(string c in inputArray)
            {
                int i = int.Parse(c);
                if(i > max) max = i;
                if(i < min) min = i;
                
                //Console.WriteLine("debug - input : " + i + ", max : " + max + ", min : " + min);
            }
            
            Console.WriteLine(min + " " + max);
        }
    }
}

// note
// 한번 틀림(정수 최대범위만 확인하고 최소범위를 확인 안함 - -1000000 으로 고침)