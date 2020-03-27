using ELFSharp.ELF;
using ELFSharp.ELF.Sections;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void PrintAsm(byte[] bb)
        {
            SharpDisasm.ArchitectureMode mode = SharpDisasm.ArchitectureMode.x86_64;
            var disasm = new SharpDisasm.Disassembler(
                bb,
                mode, 0, true);

            SharpDisasm.Disassembler.Translator.IncludeAddress = true;
            SharpDisasm.Disassembler.Translator.IncludeBinary = true;

            foreach (var insn in disasm.Disassemble())
            {
                Console.Out.WriteLine(insn.Offset);
                Console.Out.WriteLine(insn.ToString());
            }
        }



        static void Main(string[] args)
        {
            var binary = File.ReadAllBytes("test/1. Hello World/a.out");
            var fs = new FileStream("test/1. Hello World/a.out", FileMode.Open);
            var elf = ELFReader.Load(fs, false);


            var init = elf.GetSection(".init");
            PrintAsm(init.GetContents());

            var functions = ((ISymbolTable)elf.GetSection(".symtab")).Entries.Where(x => x.Type == SymbolType.Function);
            foreach (var f in functions)
            {
                var xx = (SymbolEntry<ulong>)f;
                Console.WriteLine(f.Name + " :: " + xx.Value.ToString("X"));
            }

            var code = (ProgBitsSection<ulong>)elf.GetSection(".text");
            var yx = code.GetContents();

            foreach (var header in elf.Sections)
            {
                if (header.Name == ".text" && !false)
                {
                    PrintAsm(header.GetContents());
                }

                Console.WriteLine(header);
            }
            ;
        }
    }
}
