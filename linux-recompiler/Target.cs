// This source code is a part of Sharp Linux Recompiler
// Copyright (C) 2020. rollrat. Licensed under the MIT Licence.

using ELFSharp.ELF;
using ELFSharp.ELF.Sections;
using SharpDisasm;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace linux_recompiler
{
    public class Target
    {
        public byte[] Bytes { get; private set; }
        public IELF ELF { get; private set; }
        FileStream fs;
        public List<(ISymbolEntry, List<Instruction>)> Functions { get; private set; }

        public Target(string program_path)
        {
            Bytes = File.ReadAllBytes(program_path);
            fs = new FileStream(program_path, FileMode.Open);
            ELF = ELFReader.Load(fs, false);
            Functions = new List<(ISymbolEntry, List<Instruction>)>();

            var funcs = ((ISymbolTable)ELF.GetSection(".symtab")).Entries.Where(x => x.Type == SymbolType.Function).ToList();
            var symfuncs = new Dictionary<ulong, ISymbolEntry>();
            var symextern = new List<ISymbolEntry>();
            funcs.ForEach(x => {
                var os = (x as SymbolEntry<ulong>).Value;
                if (os != 0)
                    symfuncs.Add(os, x);
                else
                    symextern.Add(x);
                });

            var insts = disasm(ELF.GetSection(".text").GetContents()).ToList();
            var symbols = symfuncs.ToList();
            var symbols_index = 0;
            ulong base_offset = (ELF.GetSection(".text") as Section<ulong>).Offset;
            symbols.Sort((x,y) => x.Key.CompareTo(y.Key));
            symbols.Add(new KeyValuePair<ulong, ISymbolEntry>(ulong.MaxValue, null));

            //foreach (var func in funcs)
            //{
            //    var se = (func as SymbolEntry<int>);
            //    Functions.Add(func, disasm(Bytes.Skip(se.Value).Take(se.Size).ToArray()));
            //}

            var added = new HashSet<ISymbolEntry>();

            for (int i = 0; i < insts.Count; )
            {
                if (insts[i].Offset + base_offset == symbols[symbols_index].Key)
                {
                    var func = new List<Instruction>();
                    for (; i < insts.Count && insts[i].Offset + base_offset < symbols[symbols_index + 1].Key; i++)
                    {
                        func.Add(insts[i]);
                    }
                    for (int j = func.Count - 1; j >= 0; j--)
                    {
                        if (func[j].Mnemonic == SharpDisasm.Udis86.ud_mnemonic_code.UD_Inop)
                            func.RemoveAt(j);
                        else
                            break;
                    }
                    Functions.Add((symbols[symbols_index].Value, func));
                    added.Add(symbols[symbols_index].Value);
                    symbols_index += 1;
                }
                else if (insts[i].Offset + base_offset > symbols[symbols_index].Key)
                {
                    symbols_index++;
                }
                else
                {
                    i++;
                }
            }

            symbols.RemoveAt(symbols.Count - 1);
            Functions.Add((symbols.Where(x => x.Value.Name == "_init").Single().Value, 
                disasm(ELF.GetSection(".init").GetContents()).ToList()));
            added.Add(symbols.Where(x => x.Value.Name == "_init").Single().Value);

            foreach (var ise in symbols)
            {
                if (!added.Contains(ise.Value))
                    Functions.Add((ise.Value, new List<Instruction>()));
            }

            ;
        }

        ~Target()
        {
            fs.Close();
        }

        static List<Instruction> disasm(byte[] bytes)
        {
            ArchitectureMode mode = ArchitectureMode.x86_64;
            var disasm = new Disassembler(
                bytes,
                mode, 0, true);

            Disassembler.Translator.IncludeAddress = true;
            Disassembler.Translator.IncludeBinary = true;

            return disasm.Disassemble().ToList();
        }
    }
}
