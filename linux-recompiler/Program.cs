// This source code is a part of Sharp Linux Recompiler
// Copyright (C) 2020. rollrat. Licensed under the MIT Licence.

using SharpDisasm;
using System;

namespace linux_recompiler
{
    class Program
    {
        static void Main(string[] args)
        {
            var t = new Target(@"C:\Users\rollrat\source\repos\linux-recompiler\test\1. Hello World\a.out");

            foreach (var func in t.Functions)
            {
                Console.WriteLine($"{func.Item1.Name}:");
                func.Item2.ForEach(x => Console.WriteLine($"{x}"));
                Console.WriteLine($"");
            }

            ;
        }
    }
}
