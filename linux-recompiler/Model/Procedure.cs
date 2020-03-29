// This source code is a part of Sharp Linux Recompiler
// Copyright (C) 2020. rollrat. Licensed under the MIT Licence.

using SharpDisasm;
using System;
using System.Collections.Generic;
using System.Text;

namespace linux_recompiler.Model
{
    public class Procedure
    {
        public string Name { get; private set; }
        public ulong Index { get; private set; }
        public ulong Length { get; private set; }
        public List<MInstruction> Instructions { get; private set; }
        public List<BasicBlock> BasicBlocks { get; private set; }
    }
}
