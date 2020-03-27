/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _UAPI_LINUX_ELF_H
#define _UAPI_LINUX_ELF_H

#include <linux/types.h>

#ifndef _LINUX_ELF_EM_H
#define _LINUX_ELF_EM_H

/* These constants define the various ELF target machines */
#define EM_NONE		0
#define EM_M32		1
#define EM_SPARC	2
#define EM_386		3
#define EM_68K		4
#define EM_88K		5
#define EM_486		6	/* Perhaps disused */
#define EM_860		7
#define EM_MIPS		8	/* MIPS R3000 (officially, big-endian only) */
				/* Next two are historical and binaries and
				   modules of these types will be rejected by
				   Linux.  */
#define EM_MIPS_RS3_LE	10	/* MIPS R3000 little-endian */
#define EM_MIPS_RS4_BE	10	/* MIPS R4000 big-endian */

#define EM_PARISC	15	/* HPPA */
#define EM_SPARC32PLUS	18	/* Sun's "v8plus" */
#define EM_PPC		20	/* PowerPC */
#define EM_PPC64	21	 /* PowerPC64 */
#define EM_SPU		23	/* Cell BE SPU */
#define EM_SH		42	/* SuperH */
#define EM_SPARCV9	43	/* SPARC v9 64-bit */
#define EM_IA_64	50	/* HP/Intel IA-64 */
#define EM_X86_64	62	/* AMD x86-64 */
#define EM_S390		22	/* IBM S/390 */
#define EM_CRIS		76	/* Axis Communications 32-bit embedded processor */
#define EM_V850		87	/* NEC v850 */
#define EM_M32R		88	/* Renesas M32R */
#define EM_H8_300	46	/* Renesas H8/300,300H,H8S */
#define EM_MN10300	89	/* Panasonic/MEI MN10300, AM33 */
#define EM_BLACKFIN     106     /* ADI Blackfin Processor */
#define EM_FRV		0x5441	/* Fujitsu FR-V */
#define EM_AVR32	0x18ad	/* Atmel AVR32 */

/*
 * This is an interim value that we will use until the committee comes
 * up with a final number.
 */
#define EM_ALPHA	0x9026

/* Bogus old v850 magic number, used by old tools. */
#define EM_CYGNUS_V850	0x9080
/* Bogus old m32r magic number, used by old tools. */
#define EM_CYGNUS_M32R	0x9041
/* This is the old interim value for S/390 architecture */
#define EM_S390_OLD	0xA390
/* Also Panasonic/MEI MN10300, AM33 */
#define EM_CYGNUS_MN10300 0xbeef


#endif /* _LINUX_ELF_EM_H */

/* 32-bit ELF base types. */
typedef uint32_t	Elf32_Addr;
typedef uint16_t	Elf32_Half;
typedef uint32_t	Elf32_Off;
typedef uint32_t	Elf32_Sword;
typedef uint32_t	Elf32_Word;

/* 64-bit ELF base types. */
typedef uint64_t	Elf64_Addr;
typedef int16_t	Elf64_Half;
typedef int16_t	Elf64_SHalf;
typedef uint64_t	Elf64_Off;
typedef int32_t	Elf64_Sword;
typedef int32_t	Elf64_Word;
typedef uint64_t	Elf64_Xword;
typedef int64_t	Elf64_Sxword;

/* These constants are for the segment types stored in the image headers */
#define PT_NULL    0
#define PT_LOAD    1
#define PT_DYNAMIC 2
#define PT_INTERP  3
#define PT_NOTE    4
#define PT_SHLIB   5
#define PT_PHDR    6
#define PT_TLS     7               /* Thread local storage segment */
#define PT_LOOS    0x60000000      /* OS-specific */
#define PT_HIOS    0x6fffffff      /* OS-specific */
#define PT_LOPROC  0x70000000
#define PT_HIPROC  0x7fffffff
#define PT_GNU_EH_FRAME		0x6474e550

#define PT_GNU_STACK	(PT_LOOS + 0x474e551)

/*
 * Extended Numbering
 *
 * If the real number of program header table entries is larger than
 * or equal to PN_XNUM(0xffff), it is set to sh_info field of the
 * section header at index 0, and PN_XNUM is set to e_phnum
 * field. Otherwise, the section header at index 0 is zero
 * initialized, if it exists.
 *
 * Specifications are available in:
 *
 * - Oracle: Linker and Libraries.
 *   Part No: 817–1984–19, August 2011.
 *   http://docs.oracle.com/cd/E18752_01/pdf/817-1984.pdf
 *
 * - System V ABI AMD64 Architecture Processor Supplement
 *   Draft Version 0.99.4,
 *   January 13, 2010.
 *   http://www.cs.washington.edu/education/courses/cse351/12wi/supp-docs/abi.pdf
 */
#define PN_XNUM 0xffff

/* These constants define the different elf file types */
#define ET_NONE   0
#define ET_REL    1
#define ET_EXEC   2
#define ET_DYN    3
#define ET_CORE   4
#define ET_LOPROC 0xff00
#define ET_HIPROC 0xffff

/* This is the info that is needed to parse the dynamic section of the file */
#define DT_NULL		0
#define DT_NEEDED	1
#define DT_PLTRELSZ	2
#define DT_PLTGOT	3
#define DT_HASH		4
#define DT_STRTAB	5
#define DT_SYMTAB	6
#define DT_RELA		7
#define DT_RELASZ	8
#define DT_RELAENT	9
#define DT_STRSZ	10
#define DT_SYMENT	11
#define DT_INIT		12
#define DT_FINI		13
#define DT_SONAME	14
#define DT_RPATH 	15
#define DT_SYMBOLIC	16
#define DT_REL	        17
#define DT_RELSZ	18
#define DT_RELENT	19
#define DT_PLTREL	20
#define DT_DEBUG	21
#define DT_TEXTREL	22
#define DT_JMPREL	23
#define DT_ENCODING	32
#define OLD_DT_LOOS	0x60000000
#define DT_LOOS		0x6000000d
#define DT_HIOS		0x6ffff000
#define DT_VALRNGLO	0x6ffffd00
#define DT_VALRNGHI	0x6ffffdff
#define DT_ADDRRNGLO	0x6ffffe00
#define DT_ADDRRNGHI	0x6ffffeff
#define DT_VERSYM	0x6ffffff0
#define DT_RELACOUNT	0x6ffffff9
#define DT_RELCOUNT	0x6ffffffa
#define DT_FLAGS_1	0x6ffffffb
#define DT_VERDEF	0x6ffffffc
#define	DT_VERDEFNUM	0x6ffffffd
#define DT_VERNEED	0x6ffffffe
#define	DT_VERNEEDNUM	0x6fffffff
#define OLD_DT_HIOS     0x6fffffff
#define DT_LOPROC	0x70000000
#define DT_HIPROC	0x7fffffff

/* This info is needed when parsing the symbol table */
#define STB_LOCAL  0
#define STB_GLOBAL 1
#define STB_WEAK   2

#define STT_NOTYPE  0
#define STT_OBJECT  1
#define STT_FUNC    2
#define STT_SECTION 3
#define STT_FILE    4
#define STT_COMMON  5
#define STT_TLS     6

#define ELF_ST_BIND(x)		((x) >> 4)
#define ELF_ST_TYPE(x)		(((unsigned int) x) & 0xf)
#define ELF32_ST_BIND(x)	ELF_ST_BIND(x)
#define ELF32_ST_TYPE(x)	ELF_ST_TYPE(x)
#define ELF64_ST_BIND(x)	ELF_ST_BIND(x)
#define ELF64_ST_TYPE(x)	ELF_ST_TYPE(x)

typedef struct dynamic{
  Elf32_Sword d_tag;
  union{
    Elf32_Sword	d_val;
    Elf32_Addr	d_ptr;
  } d_un;
} Elf32_Dyn;

typedef struct {
  Elf64_Sxword d_tag;		/* entry tag value */
  union {
    Elf64_Xword d_val;
    Elf64_Addr d_ptr;
  } d_un;
} Elf64_Dyn;

/* The following are used with relocations */
#define ELF32_R_SYM(x) ((x) >> 8)
#define ELF32_R_TYPE(x) ((x) & 0xff)

#define ELF64_R_SYM(i)			((i) >> 32)
#define ELF64_R_TYPE(i)			((i) & 0xffffffff)

typedef struct elf32_rel {
  Elf32_Addr	r_offset;
  Elf32_Word	r_info;
} Elf32_Rel;

typedef struct elf64_rel {
  Elf64_Addr r_offset;	/* Location at which to apply the action */
  Elf64_Xword r_info;	/* index and type of relocation */
} Elf64_Rel;

typedef struct elf32_rela{
  Elf32_Addr	r_offset;
  Elf32_Word	r_info;
  Elf32_Sword	r_addend;
} Elf32_Rela;

typedef struct elf64_rela {
  Elf64_Addr r_offset;	/* Location at which to apply the action */
  Elf64_Xword r_info;	/* index and type of relocation */
  Elf64_Sxword r_addend;	/* Constant addend used to compute value */
} Elf64_Rela;

typedef struct elf32_sym{
  Elf32_Word	st_name;
  Elf32_Addr	st_value;
  Elf32_Word	st_size;
  unsigned char	st_info;
  unsigned char	st_other;
  Elf32_Half	st_shndx;
} Elf32_Sym;

typedef struct elf64_sym {
  Elf64_Word st_name;		/* Symbol name, index in string tbl */
  unsigned char	st_info;	/* Type and binding attributes */
  unsigned char	st_other;	/* No defined meaning, 0 */
  Elf64_Half st_shndx;		/* Associated section index */
  Elf64_Addr st_value;		/* Value of the symbol */
  Elf64_Xword st_size;		/* Associated symbol size */
} Elf64_Sym;


#define EI_NIDENT	16

typedef struct elf32_hdr{
  unsigned char	e_ident[EI_NIDENT];
  Elf32_Half	e_type;
  Elf32_Half	e_machine;
  Elf32_Word	e_version;
  Elf32_Addr	e_entry;  /* Entry point */
  Elf32_Off	e_phoff;
  Elf32_Off	e_shoff;
  Elf32_Word	e_flags;
  Elf32_Half	e_ehsize;
  Elf32_Half	e_phentsize;
  Elf32_Half	e_phnum;
  Elf32_Half	e_shentsize;
  Elf32_Half	e_shnum;
  Elf32_Half	e_shstrndx;
} Elf32_Ehdr;

typedef struct elf64_hdr {
  unsigned char	e_ident[EI_NIDENT];	/* ELF "magic number" */
  Elf64_Half e_type;
  Elf64_Half e_machine;
  Elf64_Word e_version;
  Elf64_Addr e_entry;		/* Entry point virtual address */
  Elf64_Off e_phoff;		/* Program header table file offset */
  Elf64_Off e_shoff;		/* Section header table file offset */
  Elf64_Word e_flags;
  Elf64_Half e_ehsize;
  Elf64_Half e_phentsize;
  Elf64_Half e_phnum;
  Elf64_Half e_shentsize;
  Elf64_Half e_shnum;
  Elf64_Half e_shstrndx;
} Elf64_Ehdr;

/* These constants define the permissions on sections in the program
   header, p_flags. */
#define PF_R		0x4
#define PF_W		0x2
#define PF_X		0x1

typedef struct elf32_phdr{
  Elf32_Word	p_type;
  Elf32_Off	p_offset;
  Elf32_Addr	p_vaddr;
  Elf32_Addr	p_paddr;
  Elf32_Word	p_filesz;
  Elf32_Word	p_memsz;
  Elf32_Word	p_flags;
  Elf32_Word	p_align;
} Elf32_Phdr;

typedef struct elf64_phdr {
  Elf64_Word p_type;
  Elf64_Word p_flags;
  Elf64_Off p_offset;		/* Segment file offset */
  Elf64_Addr p_vaddr;		/* Segment virtual address */
  Elf64_Addr p_paddr;		/* Segment physical address */
  Elf64_Xword p_filesz;		/* Segment size in file */
  Elf64_Xword p_memsz;		/* Segment size in memory */
  Elf64_Xword p_align;		/* Segment alignment, file & memory */
} Elf64_Phdr;

/* sh_type */
#define SHT_NULL	0
#define SHT_PROGBITS	1
#define SHT_SYMTAB	2
#define SHT_STRTAB	3
#define SHT_RELA	4
#define SHT_HASH	5
#define SHT_DYNAMIC	6
#define SHT_NOTE	7
#define SHT_NOBITS	8
#define SHT_REL		9
#define SHT_SHLIB	10
#define SHT_DYNSYM	11
#define SHT_NUM		12
#define SHT_LOPROC	0x70000000
#define SHT_HIPROC	0x7fffffff
#define SHT_LOUSER	0x80000000
#define SHT_HIUSER	0xffffffff

/* sh_flags */
#define SHF_WRITE		0x1
#define SHF_ALLOC		0x2
#define SHF_EXECINSTR		0x4
#define SHF_RELA_LIVEPATCH	0x00100000
#define SHF_RO_AFTER_INIT	0x00200000
#define SHF_MASKPROC		0xf0000000

/* special section indexes */
#define SHN_UNDEF	0
#define SHN_LORESERVE	0xff00
#define SHN_LOPROC	0xff00
#define SHN_HIPROC	0xff1f
#define SHN_LIVEPATCH	0xff20
#define SHN_ABS		0xfff1
#define SHN_COMMON	0xfff2
#define SHN_HIRESERVE	0xffff
 
typedef struct elf32_shdr {
  Elf32_Word	sh_name;
  Elf32_Word	sh_type;
  Elf32_Word	sh_flags;
  Elf32_Addr	sh_addr;
  Elf32_Off	sh_offset;
  Elf32_Word	sh_size;
  Elf32_Word	sh_link;
  Elf32_Word	sh_info;
  Elf32_Word	sh_addralign;
  Elf32_Word	sh_entsize;
} Elf32_Shdr;

typedef struct elf64_shdr {
  Elf64_Word sh_name;		/* Section name, index in string tbl */
  Elf64_Word sh_type;		/* Type of section */
  Elf64_Xword sh_flags;		/* Miscellaneous section attributes */
  Elf64_Addr sh_addr;		/* Section virtual addr at execution */
  Elf64_Off sh_offset;		/* Section file offset */
  Elf64_Xword sh_size;		/* Size of section in bytes */
  Elf64_Word sh_link;		/* Index of another section */
  Elf64_Word sh_info;		/* Additional section information */
  Elf64_Xword sh_addralign;	/* Section alignment */
  Elf64_Xword sh_entsize;	/* Entry size if section holds table */
} Elf64_Shdr;

#define	EI_MAG0		0		/* e_ident[] indexes */
#define	EI_MAG1		1
#define	EI_MAG2		2
#define	EI_MAG3		3
#define	EI_CLASS	4
#define	EI_DATA		5
#define	EI_VERSION	6
#define	EI_OSABI	7
#define	EI_PAD		8

#define	ELFMAG0		0x7f		/* EI_MAG */
#define	ELFMAG1		'E'
#define	ELFMAG2		'L'
#define	ELFMAG3		'F'
#define	ELFMAG		"\177ELF"
#define	SELFMAG		4

#define	ELFCLASSNONE	0		/* EI_CLASS */
#define	ELFCLASS32	1
#define	ELFCLASS64	2
#define	ELFCLASSNUM	3

#define ELFDATANONE	0		/* e_ident[EI_DATA] */
#define ELFDATA2LSB	1
#define ELFDATA2MSB	2

#define EV_NONE		0		/* e_version, EI_VERSION */
#define EV_CURRENT	1
#define EV_NUM		2

#define ELFOSABI_NONE	0
#define ELFOSABI_LINUX	3

#ifndef ELF_OSABI
#define ELF_OSABI ELFOSABI_NONE
#endif

/*
 * Notes used in ET_CORE. Architectures export some of the arch register sets
 * using the corresponding note types via the PTRACE_GETREGSET and
 * PTRACE_SETREGSET requests.
 */
#define NT_PRSTATUS	1
#define NT_PRFPREG	2
#define NT_PRPSINFO	3
#define NT_TASKSTRUCT	4
#define NT_AUXV		6
/*
 * Note to userspace developers: size of NT_SIGINFO note may increase
 * in the future to accomodate more fields, don't assume it is fixed!
 */
#define NT_SIGINFO      0x53494749
#define NT_FILE         0x46494c45
#define NT_PRXFPREG     0x46e62b7f      /* copied from gdb5.1/include/elf/common.h */
#define NT_PPC_VMX	0x100		/* PowerPC Altivec/VMX registers */
#define NT_PPC_SPE	0x101		/* PowerPC SPE/EVR registers */
#define NT_PPC_VSX	0x102		/* PowerPC VSX registers */
#define NT_PPC_TAR	0x103		/* Target Address Register */
#define NT_PPC_PPR	0x104		/* Program Priority Register */
#define NT_PPC_DSCR	0x105		/* Data Stream Control Register */
#define NT_PPC_EBB	0x106		/* Event Based Branch Registers */
#define NT_PPC_PMU	0x107		/* Performance Monitor Registers */
#define NT_PPC_TM_CGPR	0x108		/* TM checkpointed GPR Registers */
#define NT_PPC_TM_CFPR	0x109		/* TM checkpointed FPR Registers */
#define NT_PPC_TM_CVMX	0x10a		/* TM checkpointed VMX Registers */
#define NT_PPC_TM_CVSX	0x10b		/* TM checkpointed VSX Registers */
#define NT_PPC_TM_SPR	0x10c		/* TM Special Purpose Registers */
#define NT_PPC_TM_CTAR	0x10d		/* TM checkpointed Target Address Register */
#define NT_PPC_TM_CPPR	0x10e		/* TM checkpointed Program Priority Register */
#define NT_PPC_TM_CDSCR	0x10f		/* TM checkpointed Data Stream Control Register */
#define NT_PPC_PKEY	0x110		/* Memory Protection Keys registers */
#define NT_386_TLS	0x200		/* i386 TLS slots (struct user_desc) */
#define NT_386_IOPERM	0x201		/* x86 io permission bitmap (1=deny) */
#define NT_X86_XSTATE	0x202		/* x86 extended state using xsave */
#define NT_S390_HIGH_GPRS	0x300	/* s390 upper register halves */
#define NT_S390_TIMER	0x301		/* s390 timer register */
#define NT_S390_TODCMP	0x302		/* s390 TOD clock comparator register */
#define NT_S390_TODPREG	0x303		/* s390 TOD programmable register */
#define NT_S390_CTRS	0x304		/* s390 control registers */
#define NT_S390_PREFIX	0x305		/* s390 prefix register */
#define NT_S390_LAST_BREAK	0x306	/* s390 breaking event address */
#define NT_S390_SYSTEM_CALL	0x307	/* s390 system call restart data */
#define NT_S390_TDB	0x308		/* s390 transaction diagnostic block */
#define NT_S390_VXRS_LOW	0x309	/* s390 vector registers 0-15 upper half */
#define NT_S390_VXRS_HIGH	0x30a	/* s390 vector registers 16-31 */
#define NT_S390_GS_CB	0x30b		/* s390 guarded storage registers */
#define NT_S390_GS_BC	0x30c		/* s390 guarded storage broadcast control block */
#define NT_S390_RI_CB	0x30d		/* s390 runtime instrumentation */
#define NT_ARM_VFP	0x400		/* ARM VFP/NEON registers */
#define NT_ARM_TLS	0x401		/* ARM TLS register */
#define NT_ARM_HW_BREAK	0x402		/* ARM hardware breakpoint registers */
#define NT_ARM_HW_WATCH	0x403		/* ARM hardware watchpoint registers */
#define NT_ARM_SYSTEM_CALL	0x404	/* ARM system call number */
#define NT_ARM_SVE	0x405		/* ARM Scalable Vector Extension registers */
#define NT_ARM_PAC_MASK		0x406	/* ARM pointer authentication code masks */
#define NT_ARM_PACA_KEYS	0x407	/* ARM pointer authentication address keys */
#define NT_ARM_PACG_KEYS	0x408	/* ARM pointer authentication generic key */
#define NT_ARC_V2	0x600		/* ARCv2 accumulator/extra registers */
#define NT_VMCOREDD	0x700		/* Vmcore Device Dump Note */
#define NT_MIPS_DSP	0x800		/* MIPS DSP ASE registers */
#define NT_MIPS_FP_MODE	0x801		/* MIPS floating-point mode */
#define NT_MIPS_MSA	0x802		/* MIPS SIMD registers */

/* Note header in a PT_NOTE section */
typedef struct elf32_note {
  Elf32_Word	n_namesz;	/* Name size */
  Elf32_Word	n_descsz;	/* Content size */
  Elf32_Word	n_type;		/* Content type */
} Elf32_Nhdr;

/* Note header in a PT_NOTE section */
typedef struct elf64_note {
  Elf64_Word n_namesz;	/* Name size */
  Elf64_Word n_descsz;	/* Content size */
  Elf64_Word n_type;	/* Content type */
} Elf64_Nhdr;

#endif /* _UAPI_LINUX_ELF_H */










/* 
 *	HT Editor
 *	elfstruc.h
 *
 *	Copyright (C) 1999-2002 Stefan Weyergraf
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License version 2 as
 *	published by the Free Software Foundation.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*	mostly assembled from TIS ELF 1.1g and BFD-ELF 	*/

#ifndef __ELFSTRUC_H__
#define __ELFSTRUC_H__

/* all architectures */
typedef unsigned char elf_unsigned_char;

/* 32bit architectures */
typedef uint32_t elf32_addr;
typedef uint16_t elf32_half;
typedef uint32_t elf32_off;
typedef uint32_t elf32_sword;
typedef uint32_t elf32_word;

/* 64bit architectures */
typedef uint64_t elf64_addr;
typedef uint64_t elf64_off;
typedef uint64_t elf64_sword;
typedef uint64_t elf64_word;
typedef uint32_t elf64_half;
typedef uint16_t elf64_quarter;

/*
 *	ELF header
 */

/* e_ident */
#define ELF_EI_MAG0			0
#define ELF_EI_MAG1			1
#define ELF_EI_MAG2			2
#define ELF_EI_MAG3			3
#define ELF_EI_CLASS			4
#define ELF_EI_DATA			5
#define ELF_EI_VERSION			6
#define ELF_EI_OSABI			7
#define ELF_EI_ABIVERSION		8
#define ELF_EI_PAD			9

#define EI_NIDENT			16

#define ELFMAG0 0x7f
#define ELFMAG1 'E'
#define ELFMAG2 'L'
#define ELFMAG3 'F'

#define ELFCLASSNONE			0
#define ELFCLASS32			1
#define ELFCLASS64			2

#define ELFDATANONE			0
#define ELFDATA2LSB			1
#define ELFDATA2MSB			2

#define ELFOSABI_SYSV			0
#define ELFOSABI_HPUX			1
#define ELFOSABI_NETBSD			2
#define ELFOSABI_LINUX			3
#define ELFOSABI_HURD			4
#define ELFOSABI_86OPEN			5
#define ELFOSABI_SOLARIS		6
#define ELFOSABI_MONTEREY		7
#define ELFOSABI_IRIX			8
#define ELFOSABI_FREEBSD		9
#define ELFOSABI_TRU64			10
#define ELFOSABI_MODESTO		11
#define ELFOSABI_OPENBSD		12
#define ELFOSABI_ARM			97
#define ELFOSABI_STANDALONE		255

/* e_type */
#define ELF_ET_NONE			0
#define ELF_ET_REL			1
#define ELF_ET_EXEC			2
#define ELF_ET_DYN			3
#define ELF_ET_CORE			4
#define ELF_ET_LOOS			0xFE00
#define ELF_ET_HIOS			0xFEFF
#define ELF_ET_LOPROC			0xFF00
#define ELF_ET_HIPROC			0xFFFF

/* e_machine */
#define ELF_EM_NONE			0
#define ELF_EM_M32			1
#define ELF_EM_SPARC			2
#define ELF_EM_386			3
#define ELF_EM_68K			4
#define ELF_EM_88K			5
#define ELF_EM_486			6	/* Intel 80486 */
#define ELF_EM_860			7	/* Intel 80860 */
#define ELF_EM_MIPS			8	/* MIPS R3000 (officially, big-endian only) */
#define ELF_EM_S370			9	/* IBM System/370 */
#define ELF_EM_MIPS_RS4_BE		10	/* MIPS R4000 big-endian */ /* Depreciated */
#define ELF_EM_MIPS_RS3_LE		10	/* MIPS R3000 little-endian (Oct 4 1999 Draft)*/ /* Depreciated */

#define ELF_EM_PARISC			15	/* HPPA */

#define ELF_EM_VPP550			17	/* Fujitsu VPP500 */
#define ELF_EM_SPARC32PLUS		18	/* Sun's "v8plus" */
#define ELF_EM_960			19	/* Intel 80960 */
#define ELF_EM_PPC			20	/* PowerPC */
#define ELF_EM_PPC64			21	/* 64-bit PowerPC */
#define ELF_EM_S390                     22	/* IBM S/390 */
#define ELF_EM_SPU                      23	/* Sony/Toshiba/IBM SPU */

#define ELF_EM_V800			36	/* NEC V800 series */
#define ELF_EM_FR20			37	/* Fujitsu FR20 */
#define ELF_EM_RH32			38	/* TRW RH32 */
#define ELF_EM_MCORE			39	/* Motorola M*Core */ /* May also be taken by Fujitsu MMA */
#define ELF_EM_RCE			39	/* Old name for MCore */
#define ELF_EM_ARM			40	/* ARM */
#define ELF_EM_OLD_ALPHA		41	/* Digital Alpha */
#define ELF_EM_SH			42	/* Hitachi SH */
#define ELF_EM_SPARCV9			43	/* SPARC v9 64-bit */
#define ELF_EM_TRICORE			44	/* Siemens Tricore embedded processor */
#define ELF_EM_ARC			45	/* Argonaut RISC Core, Argonaut Technologies Inc. */
#define ELF_EM_H8_300			46	/* Hitachi H8/300 */
#define ELF_EM_H8_300H			47	/* Hitachi H8/300H */
#define ELF_EM_H8S			48	/* Hitachi H8S */
#define ELF_EM_H8_500			49	/* Hitachi H8/500 */
#define ELF_EM_IA_64			50	/* Intel IA-64 Processor */
#define ELF_EM_MIPS_X			51	/* Stanford MIPS-X */
#define ELF_EM_COLDFIRE			52	/* Motorola Coldfire */
#define ELF_EM_68HC12			53	/* Motorola M68HC12 */
#define ELF_EM_MMA			54	/* Fujitsu Multimedia Accelerator */
#define ELF_EM_PCP			55	/* Siemens PCP */
#define ELF_EM_NCPU			56	/* Sony nCPU embedded RISC processor */
#define ELF_EM_NDR1			57	/* Denso NDR1 microprocesspr */
#define ELF_EM_STARCORE			58	/* Motorola Star*Core processor */
#define ELF_EM_ME16			59	/* Toyota ME16 processor */
#define ELF_EM_ST100			60	/* STMicroelectronics ST100 processor */
#define ELF_EM_TINYJ			61	/* Advanced Logic Corp. TinyJ embedded processor */
#define ELF_EM_X86_64			62	/* X86-64 (AMD Opteron) */
#define ELF_EM_PDSP                     63	/* Sony DSP Processor */
#define ELF_EM_PDP10                    64	/* Digital Equipment Corp. PDP-10 */
#define ELF_EM_PDP11                    65	/* Digital Equipment Corp. PDP-11 */
#define ELF_EM_FX66			66	/* Siemens FX66 microcontroller */
#define ELF_EM_ST9PLUS			67	/* STMicroelectronics ST9+ 8/16 bit microcontroller */
#define ELF_EM_ST7			68	/* STMicroelectronics ST7 8-bit microcontroller */
#define ELF_EM_68HC16			69	/* Motorola MC68HC16 Microcontroller */
#define ELF_EM_68HC11			70	/* Motorola MC68HC11 Microcontroller */
#define ELF_EM_68HC08			71	/* Motorola MC68HC08 Microcontroller */
#define ELF_EM_68HC05			72	/* Motorola MC68HC05 Microcontroller */
#define ELF_EM_SVX			73	/* Silicon Graphics SVx */
#define ELF_EM_ST19			74	/* STMicroelectronics ST19 8-bit microcontroller */
#define ELF_EM_VAX			75	/* Digital VAX */
#define ELF_EM_CRIS		 76	/* Axis Communications 32-bit embedded processor */
#define ELF_EM_JAVELIN	 77	/* Infineon Technologies 32-bit embedded cpu */
#define ELF_EM_FIREPATH	 78	/* Element 14 64-bit DSP processor */
#define ELF_EM_ZSP		 79	/* LSI Logic's 16-bit DSP processor */
#define ELF_EM_MMIX		 80	/* Donald Knuth's educational 64-bit processor */
#define ELF_EM_HUANY	 81	/* Harvard's machine-independent format */
#define ELF_EM_PRISM	 82	/* SiTera Prism */
#define ELF_EM_AVR		 83	/* Atmel AVR 8-bit microcontroller */
#define ELF_EM_FR30		 84	/* Fujitsu FR30 */
#define ELF_EM_D10V		 85	/* Mitsubishi D10V */
#define ELF_EM_D30V		 86	/* Mitsubishi D30V */
#define ELF_EM_V850		 87	/* NEC v850 */
#define ELF_EM_M32R		 88	/* Renesas M32R (formerly Mitsubishi M32R) */
#define ELF_EM_MN10300	 89	/* Matsushita MN10300 */
#define ELF_EM_MN10200	 90	/* Matsushita MN10200 */
#define ELF_EM_PJ		 91	/* picoJava */
#define ELF_EM_OPENRISC	 92	/* OpenRISC 32-bit embedded processor */
#define ELF_EM_ARC_A5	 93	/* ARC Cores Tangent-A5 */
#define ELF_EM_XTENSA	 94	/* Tensilica Xtensa Architecture */
#define ELF_EM_VIDEOCORE	 95	/* Alphamosaic VideoCore processor */
#define ELF_EM_TMM_GPP	 96	/* Thompson Multimedia General Purpose Processor */
#define ELF_EM_NS32K	 97	/* National Semiconductor 32000 series */
#define ELF_EM_TPC	 98	/* Tenor Network TPC processor */
#define ELF_EM_SNP1K	 99	/* Trebia SNP 1000 processor */
#define ELF_EM_ST200	100	/* STMicroelectronics ST200 microcontroller */
#define ELF_EM_IP2K	101	/* Ubicom IP2022 micro controller */
#define ELF_EM_MAX	102	/* MAX Processor */
#define ELF_EM_CR	103	/* National Semiconductor CompactRISC */
#define ELF_EM_F2MC16	104	/* Fujitsu F2MC16 */
#define ELF_EM_MSP430	105	/* TI msp430 micro controller */
#define ELF_EM_BLACKFIN	106	/* ADI Blackfin */
#define ELF_EM_SE_C33	107	/* S1C33 Family of Seiko Epson processors */
#define ELF_EM_SEP	108	/* Sharp embedded microprocessor */
#define ELF_EM_ARCA	109	/* Arca RISC Microprocessor */
#define ELF_EM_UNICORE	110	/* Microprocessor series from PKU-Unity Ltd. and MPRC of Peking University */
#define ELF_EM_EXCESS	111	/* eXcess: 16/32/64-bit configurable embedded CPU */
#define ELF_EM_DXP	112	/* Icera Semiconductor Inc. Deep Execution Processor */
#define ELF_EM_ALTERA_NIOS2	113	/* Altera Nios II soft-core processor */
#define ELF_EM_CRX	114	/* National Semiconductor CRX */
#define ELF_EM_XGATE	115	/* Motorola XGATE embedded processor */
#define ELF_EM_C166	116	/* Infineon C16x/XC16x processor */
#define ELF_EM_M16C	117	/* Renesas M16C series microprocessors */
#define ELF_EM_DSPIC30F	118	/* Microchip Technology dsPIC30F Digital Signal Controller */
#define ELF_EM_CE	119	/* Freescale Communication Engine RISC core */
#define ELF_EM_M32C	120	/* Renesas M32C series microprocessors */

#define ELF_EM_TSK3000	131	/* Altium TSK3000 core */
#define ELF_EM_RS08	132	/* Freescale RS08 embedded processor */

#define ELF_EM_ECOG2	134	/* Cyan Technology eCOG2 microprocessor */
#define ELF_EM_SCORE        135     /* Sunplus Score */
#define ELF_EM_DSP24	136	/* New Japan Radio (NJR) 24-bit DSP Processor */
#define ELF_EM_VIDEOCORE3	137	/* Broadcom VideoCore III processor */
#define ELF_EM_LATTICEMICO32 138	/* RISC processor for Lattice FPGA architecture */
#define ELF_EM_SE_C17	139	/* Seiko Epson C17 family */

#define ELF_EM_MMDSP_PLUS	160	/* STMicroelectronics 64bit VLIW Data Signal Processor */
#define ELF_EM_CYPRESS_M8C	161	/* Cypress M8C microprocessor */

#define ELF_EM_R32C	162	/* Renesas R32C series microprocessors */
#define ELF_EM_TRIMEDIA	163	/* NXP Semiconductors TriMedia architecture family */
#define ELF_EM_QDSP6	164	/* QUALCOMM DSP6 Processor */
#define ELF_EM_8051	165	/* Intel 8051 and variants */

#define ELF_EM_STXP7X	166	/* STMicroelectronics STxP7x family */
#define ELF_EM_NDS32	167	/* Andes Technology compact code size embedded RISC processor family */
#define ELF_EM_ECOG1	168	/* Cyan Technology eCOG1X family */
#define ELF_EM_ECOG1X	168	/* Cyan Technology eCOG1X family */
#define ELF_EM_MAXQ30	169	/* Dallas Semiconductor MAXQ30 Core Micro-controllers */
#define ELF_EM_XIMO16	170	/* New Japan Radio (NJR) 16-bit DSP Processor */
#define ELF_EM_MANIK	171	/* M2000 Reconfigurable RISC Microprocessor */
#define ELF_EM_CRAYNV2	172	/* Cray Inc. NV2 vector architecture */
#define ELF_EM_RX	173	/* Renesas RX family */
#define ELF_EM_METAG	174	/* Imagination Technologies META processor architecture */
#define ELF_EM_MCST_ELBRUS	175	/* MCST Elbrus general purpose hardware architecture */
#define ELF_EM_ECOG16	176	/* Cyan Technology eCOG16 family */
#define ELF_EM_CR16	177	/* National Semiconductor CompactRISC 16-bit processor */
#define ELF_EM_ETPU	178	/* Freescale Extended Time Processing Unit */
#define ELF_EM_SLE9X	179	/* Infineon Technologies SLE9X core */
#define ELF_EM_L1OM	180	/* Intel L1OM */
#define ELF_EM_K1OM	181	/* Intel K1OM */
#define ELF_EM_INTEL182	182	/* Reserved by Intel */
#define ELF_EM_AARCH64	183	/* ARM 64-bit architecture */
#define ELF_EM_ARM184	184	/* Reserved by ARM */
#define EFL_EM_AVR32	185	/* Atmel Corporation 32-bit microprocessor family */
#define ELF_EM_ALPHA    0x9026

/* e_version */
#define ELF_EV_NONE			0
#define ELF_EV_CURRENT			1

struct ELF_HEADER {
	elf_unsigned_char e_ident[EI_NIDENT];
};

struct ELF_HEADER32 {
	elf32_half e_type;
	elf32_half e_machine;
	elf32_word e_version;
	elf32_addr e_entry;
	elf32_off e_phoff;
	elf32_off e_shoff;
	elf32_word e_flags;
	elf32_half e_ehsize;
	elf32_half e_phentsize;
	elf32_half e_phnum;
	elf32_half e_shentsize;
	elf32_half e_shnum;
	elf32_half e_shstrndx;
};

struct ELF_HEADER64 {
	elf64_quarter e_type;
	elf64_quarter e_machine;
	elf64_half e_version;
	elf64_addr e_entry;
	elf64_off e_phoff;
	elf64_off e_shoff;
	elf64_half e_flags;
	elf64_quarter e_ehsize;
	elf64_quarter e_phentsize;
	elf64_quarter e_phnum;
	elf64_quarter e_shentsize;
	elf64_quarter e_shnum;
	elf64_quarter e_shstrndx;
};

/*
 *	ELF section header
 */

/* indices */
#define ELF_SHN_UNDEF		0
#define ELF_SHN_ABS		0xfff1
#define ELF_SHN_COMMON		0xfff2

/* sh_type */
#define ELF_SHT_NULL		0
#define ELF_SHT_PROGBITS	1
#define ELF_SHT_SYMTAB		2
#define ELF_SHT_STRTAB		3
#define ELF_SHT_RELA		4
#define ELF_SHT_HASH		5
#define ELF_SHT_DYNAMIC		6
#define ELF_SHT_NOTE		7
#define ELF_SHT_NOBITS		8
#define ELF_SHT_REL		9
#define ELF_SHT_SHLIB		10
#define ELF_SHT_DYNSYM		11

#define ELF_SHT_INIT_ARRAY	14
#define ELF_SHT_FINI_ARRAY	15
#define ELF_SHT_PREINIT_ARRAY	16

/* sh_flags */
#define ELF_SHF_WRITE			(1<<0)
#define ELF_SHF_ALLOC			(1<<1)
#define ELF_SHF_EXECINSTR		(1<<2)
// 1<<3 missing
#define ELF_SHF_MERGE			(1<<4)
#define ELF_SHF_STRINGS			(1<<5)
#define ELF_SHF_INFO_LINK		(1<<6)
#define ELF_SHF_LINK_ORDER		(1<<7)
#define ELF_SHF_OS_NONCONFORMING	(1<<8)

struct ELF_SECTION_HEADER32 {
	elf32_word sh_name;
	elf32_word sh_type;
	elf32_word sh_flags;
	elf32_addr sh_addr;     
	elf32_off sh_offset;
	elf32_word sh_size;
	elf32_word sh_link;
	elf32_word sh_info;
	elf32_word sh_addralign;
	elf32_word sh_entsize;
};

struct ELF_SECTION_HEADER64 {
	elf64_half sh_name;
	elf64_half sh_type;
	elf64_word sh_flags;
	elf64_addr sh_addr;
	elf64_off sh_offset;
	elf64_word sh_size;
	elf64_half sh_link;
	elf64_half sh_info;
	elf64_word sh_addralign;
	elf64_word sh_entsize;
};

/*
 *	ELF program header
 */

#define ELF_PT_NULL		0
#define ELF_PT_LOAD		1
#define ELF_PT_DYNAMIC		2
#define ELF_PT_INTERP		3
#define ELF_PT_NOTE		4
#define ELF_PT_SHLIB		5
#define ELF_PT_PHDR		6
#define ELF_PT_TLS		7          /* Thread-local storage segment  */
#define ELF_PT_NUM		8          /* Number of defined types       */
#define ELF_PT_GNU_EH_FRAME	0x6474e550 /* GCC .eh_frame_hdr segment     */
#define ELF_PT_GNU_STACK	0x6474e551 /* Indicates stack executability */
#define ELF_PT_GNU_RELRO	0x6474e552 /* Read-only after relocation    */ 
#define ELF_PT_PAX_FLAGS	0x65041580 /* Indicates PaX flag markings */
#define ELF_PT_OPENBSD_RANDOMIZE	0x65a3dbe6 /* Fill with random data. */
#define ELF_PT_OPENBSD_WXNEEDED	0x65a3dbe7 /* Program does W^X violations */
#define ELF_PT_OPENBSD_BOOTDATA	0x65a41be6 /* Section for boot arguments */

struct ELF_PROGRAM_HEADER32 {
	elf32_word p_type;
	elf32_off p_offset;
	elf32_addr p_vaddr;
	elf32_addr p_paddr;
	elf32_word p_filesz;
	elf32_word p_memsz;
	elf32_word p_flags;
	elf32_word p_align;
} PACKED;

struct ELF_PROGRAM_HEADER64 {
	elf64_half p_type;
	elf64_half p_flags;
	elf64_off p_offset;
	elf64_addr p_vaddr;
	elf64_addr p_paddr;
	elf64_word p_filesz;
	elf64_word p_memsz;
	elf64_word p_align;
};

struct ELF_NHEADER32 {
	elf32_word n_descsz;
	elf32_word n_namesz;
	elf32_word n_type;
} PACKED;

/*
 *	ELF symbol
 */

#define ELF_STB_LOCAL		0
#define ELF_STB_GLOBAL		1
#define ELF_STB_WEAK		2

#define ELF_STT_NOTYPE		0
#define ELF_STT_OBJECT		1
#define ELF_STT_FUNC		2
#define ELF_STT_SECTION		3
#define ELF_STT_FILE		4
#define ELF_STT_COMMON		5

#define ELF32_ST_BIND(i)		((i)>>4)
#define ELF32_ST_TYPE(i)		((i)&0xf)
#define ELF32_ST_INFO(b,t)	(((b)>>4)|((t)&0xf))

#define ELF64_ST_BIND(i)		((i)>>4)
#define ELF64_ST_TYPE(i)		((i)&0xf)
#define ELF64_ST_INFO(b,t)	(((b)>>4)|((t)&0xf))

struct ELF_SYMBOL32 {
	elf32_word st_name;
	elf32_addr st_value;
	elf32_word st_size;
	elf_unsigned_char st_info;
	elf_unsigned_char st_other;
	elf32_half st_shndx;
} PACKED;

struct ELF_SYMBOL64 {
	elf64_half st_name;
	elf_unsigned_char st_info;
	elf_unsigned_char st_other;
	elf64_quarter st_shndx;
	elf64_word st_value;
	elf64_word st_size;
} PACKED;

/*
 *	ELF relocation
 */

#define ELF32_R_SYM(i)		((i)>>8)
#define ELF32_R_TYPE(i)		((unsigned char)(i))
#define ELF32_R_INFO(s,t)	(((s)<<8)+(unsigned char)(t))

#define ELF_R_386_NONE			0
#define ELF_R_386_32			1
#define ELF_R_386_PC32			2
#define ELF_R_386_GOT32			3
#define ELF_R_386_PLT32			4
#define ELF_R_386_COPY			5
#define ELF_R_386_GLOB_DAT		6
#define ELF_R_386_JMP_SLOT		7
#define ELF_R_386_RELATIVE		8
#define ELF_R_386_GOTOFF		9
#define ELF_R_386_GOTPC			10

#define ELF_R_X86_64_NONE		0
#define ELF_R_X86_64_64			1
#define ELF_R_X86_64_PC32		2
#define ELF_R_X86_64_GOT32		3
#define ELF_R_X86_64_PLT32		4
#define ELF_R_X86_64_COPY		5
#define ELF_R_X86_64_GLOB_DAT		6
#define ELF_R_X86_64_JUMP_SLOT		7
#define ELF_R_X86_64_RELATIVE		8
#define ELF_R_X86_64_GOTPCREL		9
#define ELF_R_X86_64_32			10
#define ELF_R_X86_64_32S		11
#define ELF_R_X86_64_16			12
#define ELF_R_X86_64_PC16		13
#define ELF_R_X86_64_8			14
#define ELF_R_X86_64_PC8		15

struct ELF_REL32 {
	elf32_addr	r_offset;
	elf32_word	r_info;
} PACKED;

struct ELF_REL64 {
	elf64_addr	r_offset;
	union {
		elf64_word	r_info;
		struct {
			elf64_half r_type;
			elf64_half r_sym;
		};
	};
} PACKED;

struct ELF_RELA32 {
	elf32_addr	r_offset;
	elf32_word	r_info;
	elf32_sword	r_addend;
} PACKED;

struct ELF_RELA64 {
	elf64_addr	r_offset;
	union {
		elf64_word	r_info;
		struct {
			elf64_half r_type;
			elf64_half r_sym;
		};
	};
	elf64_sword	r_addend;
} PACKED;

extern byte ELF_HEADER_struct[];
extern byte ELF_HEADER32_struct[];
extern byte ELF_SECTION_HEADER32_struct[];
extern byte ELF_PROGRAM_HEADER32_struct[];
extern byte ELF_SYMBOL32_struct[];
extern byte ELF_REL32_struct[];
extern byte ELF_RELA32_struct[];
extern byte ELF_HEADER64_struct[];
extern byte ELF_SECTION_HEADER64_struct[];
extern byte ELF_PROGRAM_HEADER64_struct[];
extern byte ELF_SYMBOL64_struct[];
extern byte ELF_REL64_struct[];
extern byte ELF_RELA64_struct[];

struct ELFAddress {
	union {
		uint32 a32;
		uint64 a64;
	};
};

#endif /* __ELFSTRUC_H__ */