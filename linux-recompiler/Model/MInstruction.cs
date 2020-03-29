// This source code is a part of Sharp Linux Recompiler
// Copyright (C) 2020. rollrat. Licensed under the MIT Licence.

using SharpDisasm;
using System;
using System.Collections.Generic;
using System.Text;

namespace linux_recompiler.Model
{
    public class MInstruction
    {
        public bool IsBranch { get; set; }
        public bool HasCondition { get; set; }
        public BasicBlock ToTrue { get; set; }
        public BasicBlock ToFalse { get; set; }

        public bool IsCall { get; set; }
        public Procedure Callee { get; set; }

        public Instruction Instruction { get; set; }
        public BasicBlock Parent { get; set; }

        public MInstruction(Instruction inst, BasicBlock bb)
        {
            Parent = bb;
            Instruction = inst;

            if (inst.Mnemonic == SharpDisasm.Udis86.ud_mnemonic_code.UD_Icall)
            {
                IsCall = true;
            }
            else if (inst.Mnemonic == SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijmp)
            {
                IsBranch = true;
                HasCondition = false;
            }
            else
            {
                switch (inst.Mnemonic)
                {
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ija:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijae:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijb:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijbe:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijcxz:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijecxz:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijg:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijge:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijl:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijle:
                    //case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijmp:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijno:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijnp:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijns:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijnz:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijo:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijp:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijrcxz:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijs:
                    case SharpDisasm.Udis86.ud_mnemonic_code.UD_Ijz:
                        IsBranch = true;
                        HasCondition = true;
                        break;
                }

            }

        }
    }
}
