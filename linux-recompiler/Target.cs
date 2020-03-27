// This source code is a part of Sharp Linux Recompiler
// Copyright (C) 2020. rollrat. Licensed under the MIT Licence.

using ELFSharp.ELF;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace linux_recompiler
{
    public class Target
    {
        public byte[] Bytes { get; private set; }
        public IELF ELF { get; private set; }
        FileStream fs;

        public Target(string program_path)
        {
            Bytes = File.ReadAllBytes(program_path);
            fs = new FileStream("test/1. Hello World/a.out", FileMode.Open);
            ELF = ELFReader.Load(fs, false);
        }

        ~Target()
        {
            fs.Close();
        }


    }
}
