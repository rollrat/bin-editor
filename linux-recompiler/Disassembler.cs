// This source code is a part of Sharp Linux Recompiler
// Copyright (C) 2020. rollrat. Licensed under the MIT Licence.

using SharpDisasm;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace linux_recompiler
{
    public class Disassembler
    {
        public static List<Instruction> Disasm(byte[] bytes)
        {
            ArchitectureMode mode = SharpDisasm.ArchitectureMode.x86_64;
            var disasm = new SharpDisasm.Disassembler(
                bytes,
                mode, 0, true);

            SharpDisasm.Disassembler.Translator.IncludeAddress = true;
            SharpDisasm.Disassembler.Translator.IncludeBinary = true;

            return disasm.Disassemble().ToList();
        }
    }
}
