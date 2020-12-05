/*
----------------------------------------------
Author: Jayachandra Kasarla
Date: 05/12/2020
GitHub: https://www.github.com/jaychandra6
LICENSE: MIT

----------------------------------------------
Libraries required:
stdio.h for standard I/O and FILE manipulations
stdlib.h for dynamic memory allocation

----------------------------------------------
Resources used:

Blog posts from Emulator101
https://www.emulator101.com

Let's write a disassembler by Adam Hacks
https://www.youtube.com/watch?v=OpZ_soK--TQ

----------------------------------------------
Instruction sets can be found here:

http://www.emulator101.com/8080-by-opcode.html

----------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>


//disassembler takes a buffer and program counter

int disassemble(unsigned char *buffer, int pc){
	//first read opcode from the ROM
	//each opcode is a single byte
	
	//the following code will store one single byte from the ROM or the buffer we allocated
	unsigned char *opcode = &buffer[pc];
	
	//opbytes will tell us by how much the program counter should be
	//incremented in order to fetch the correct instruction

	int opbytes = 1;
	
	//print the program counter in hexadecimal format
	printf("%04x ", pc);

	//following switch block will check every byte from the ROM and prints it according 
	//to the pre-defined instructions.
	switch(*opcode){
		case 0x00:
		case 0x08:
		case 0x10:
		case 0x18:
		case 0x28:
		case 0x38:
		case 0xcb:
		case 0xd9:
		case 0xdd:
		case 0xed:
		case 0xfd:
			printf("NOP");
			break;
		case 0x01:
			//LXI performs operation on two bytes, so we print next two bytes of the buffer
			//and assign opbytes = 3
			//LXI is performed on B register
			printf("LXI\tB, #$0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0x02:
			printf("STAX\tB");
			break;
		case 0x03:
			printf("INX\tB");
			break;
		case 0x04:
			printf("INR\tB");
			break;
		case 0x05:
			printf("DCR\tB");
			break;
		case 0x06:
			//MVI Instruction performs operation on next single byte
			//So, we fetch the next byte from the buffer using opcode[1]
			//and return opbytes = 2
			printf("MVI\tB, #$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0x07:
			printf("RLC");
			break;
		case 0x09:
			printf("DAD\tB");
			break;
		case 0x0a:
			printf("LDAX\tB");
			break;
		case 0x0b:
			printf("DCX\tB");
			break;
		case 0x0c:
			printf("INR\tC");
			break;
		case 0x0d:
			printf("DCR\tC");
			break;
		case 0x0e:
			printf("MVI\tC, #$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0x0f:
			printf("RRC");
			break;
		case 0x11:
			printf("LXI\tD, #$0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0x12:
			printf("STAX\tD");
			break;
		case 0x13:
			printf("INX\tD");
			break;
		case 0x14:
			printf("INR\tD");
			break;
		case 0x15:
			printf("DCR\tD");
			break;
		case 0x16:
			printf("DCR\tD");
			break;
		case 0x17:
			printf("RAL");
			break;
		case 0x19:
			printf("DAD\tD");
			break;
		case 0x1a:
			printf("LDAX\tD");
			break;
		case 0x1b:
			printf("DCX\tD");
			break;
		case 0x1c:
			printf("INR\tE");
			break;
		case 0x1d:
			printf("DCR\tE");
			break;
		case 0x1e:
			printf("MVI\tE, #$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0x1f:
			printf("RAR");
			break;
		case 0x20:
			printf("RIM");
			break;
		case 0x21:
			printf("LXI\tH, #$0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0x22:
			printf("SHLD\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0x23:
			printf("INX\tH");
			break;
		case 0x24:
			printf("INR\tH");
			break;
		case 0x25:
			printf("DCR\tH");
			break;
		case 0x26:
			printf("MVI\tH, #$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0x27:
			printf("DAA");
			break;
		case 0x29:
			printf("DAD\tH");
			break;
		case 0x2a:
			printf("LHLD\t 0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0x2b:
			printf("DCX\tH");
			break;
		case 0x2c:
			printf("INR\tL");
			break;
		case 0x2d:
			printf("DCR\tL");
			break;
		case 0x2e:
			printf("MVI\tL, #$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0x2f:
			printf("CMA");
			break;
		case 0x30:
			printf("SIM");
			break;
		case 0x31:
			printf("LXI\tSP, #$0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0x32:
			printf("STA\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0x33:
			printf("INX\tSP");
			break;
		case 0x34:
			printf("INR\tM");
			break;
		case 0x35:
			printf("DCR\tM");
			break;
		case 0x36:
			printf("MVI\tM, #$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0x37:
			printf("STC");
			break;
		case 0x39:
			printf("DAD\tSP");
			break;
		case 0x3a:
			printf("LDA\t0x%02x%02X", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0x3b:
			printf("DCX\tSP");
			break;
		case 0x3c:
			printf("INR\tA");
			break;
		case 0x3d:
			printf("DCR\tA");
			break;
		case 0x3e:
			printf("MVI\tA, #$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0x3f:
			printf("CMC");
			break;
		case 0x40:
			printf("MOV\tB, B");
			break;
		case 0x41:
			printf("MOV\tB, C");
			break;
		case 0x42:
			printf("MOV\tB, D");
			break;
		case 0x43:
			printf("MOV\tB, E");
			break;
		case 0x44:
			printf("MOV\tB, H");
			break;
		case 0x45:
			printf("MOV\tB, L");
			break;
		case 0x46:
			printf("MOV\tB, M");
			break;
		case 0x47:
			printf("MOV\tB, A");
			break;
		case 0x48:
			printf("MOV\tC, B");
			break;
		case 0x49:
			printf("MOV\tC, C");
			break;
		case 0x4a:
			printf("MOV\tC, D");
			break;
		case 0x4b:
			printf("MOV\tC, E");
			break;
		case 0x4c:
			printf("MOV\tC, H");
			break;
		case 0x4d:
			printf("MOV\tC, L");
			break;
		case 0x4e:
			printf("MOV\tC, M");
			break;
		case 0x4f:
			printf("MOV\tC, A");
			break;
		case 0x50:
			printf("MOV\tD, B");
			break;
		case 0x51:
			printf("MOV\tD, C");
			break;
		case 0x52:
			printf("MOV\tD, D");
			break;
		case 0x53:
			printf("MOV\tD, E");
			break;
		case 0x54:
			printf("MOV\tD, H");
			break;
		case 0x55:
			printf("MOV\tD, L");
			break;
		case 0x56:
			printf("MOV\tD, M");
			break;
		case 0x57:
			printf("MOV\tD, A");
			break;
		case 0x58:
			printf("MOV\tE, B");
			break;
		case 0x59:
			printf("MOV\tE, C");
			break;
		case 0x5a:
			printf("MOV\tE, D");
			break;
		case 0x5b:
			printf("MOV\tE, E");
			break;
		case 0x5c:
			printf("MOV\tE, H");
			break;
		case 0x5d:
			printf("MOV\tE, L");
			break;
		case 0x5e:
			printf("MOV\tE, M");
			break;
		case 0x5f:
			printf("MOV\tE, A");
			break;
		case 0x60:
			printf("MOV\tH, B");
			break;
		case 0x61:
			printf("MOV\tH, C");
			break;
		case 0x62:
			printf("MOV\tH, D");
			break;
		case 0x63:
			printf("MOV\tH, E");
			break;
		case 0x64:
			printf("MOV\tH, H");
			break;
		case 0x65:
			printf("MOV\tH, L");
			break;
		case 0x66:
			printf("MOV\tH, M");
			break;
		case 0x67:
			printf("MOV\tH, A");
			break;
		case 0x68:
			printf("MOV\tL, B");
			break;
		case 0x69:
			printf("MOV\tL, C");
			break;
		case 0x6a:
			printf("MOV\tL, D");
			break;
		case 0x6b:
			printf("MOV\tL, E");
			break;
		case 0x6c:
			printf("MOV\tL, H");
			break;
		case 0x6d:
			printf("MOV\tL, L");
			break;
		case 0x6e:
			printf("MOV\tL, M");
			break;
		case 0x6f:
			printf("MOV\tL, A");
			break;
		case 0x70:
			printf("MOV\tM, B");
			break;
		case 0x71:
			printf("MOV\tM, C");
			break;
		case 0x72:
			printf("MOV\tM, D");
			break;
		case 0x73:
			printf("MOV\tM, E");
			break;
		case 0x74:
			printf("MOV\tM, H");
			break;
		case 0x75:
			printf("MOV\tM, L");
			break;
		case 0x76:
			printf("HLT");
			break;
		case 0x77:
			printf("MOV\tM, A");
			break;
		case 0x78:
			printf("MOV\tA, B");
			break;
		case 0x79:
			printf("MOV\tA, C");
			break;
		case 0x7a:
			printf("MOV\tA, D");
			break;
		case 0x7b:
			printf("MOV\tA, E");
			break;
		case 0x7c:
			printf("MOV\tA, H");
			break;
		case 0x7d:
			printf("MOV\tA, L");
			break;
		case 0x7e:
			printf("MOV\tA, M");
			break;
		case 0x7f:
			printf("MOV\tA, A");
			break;
		case 0x80:
			printf("ADD\tB");
			break;
		case 0x81:
			printf("ADD\tC");
			break;
		case 0x82:
			printf("ADD\tD");
			break;
		case 0x83:
			printf("ADD\tE");
			break;
		case 0x84:
			printf("ADD\tH");
			break;
		case 0x85:
			printf("ADD\tL");
			break;
		case 0x86:
			printf("ADD\tM");
			break;
		case 0x87:
			printf("ADD\tA");
			break;
		case 0x88:
			printf("ADC\tB");
			break;
		case 0x89:
			printf("ADC\tC");
			break;
		case 0x8a:
			printf("ADC\tE");
			break;
		case 0x8b:
			printf("ADC\tE");
			break;
		case 0x8c:
			printf("ADC\tH");
			break;
		case 0x8d:
			printf("ADC\tL");
			break;
		case 0x8e:
			printf("ADC\tM");
			break;
		case 0x8f:
			printf("ADC\tA");
			break;
		case 0x90:
			printf("SUB\tB");
			break;
		case 0x91:
			printf("SUB\tC");
			break;
		case 0x92:
			printf("SUB\tD");
			break;
		case 0x93:
			printf("SUB\tE");
			break;
		case 0x94:
			printf("SUB\tH");
			break;
		case 0x95:
			printf("SUB\tL");
			break;
		case 0x96:
			printf("SUB\tM");
			break;
		case 0x97:
			printf("SUB\tA");
			break;
		case 0x98:
			printf("SBB\tB");
			break;
		case 0x99:
			printf("SBB\tC");
			break;
		case 0x9a:
			printf("SBB\tD");
			break;
		case 0x9b:
			printf("SBB\tE");
			break;
		case 0x9c:
			printf("SBB\tH");
			break;
		case 0x9d:
			printf("SBB\tL");
			break;
		case 0x9e:
			printf("SBB\tM");
			break;
		case 0x9f:
			printf("SBB\tA");
			break;
		case 0xa0:
			printf("ANA\tB");
			break;
		case 0xa1:
			printf("ANA\tC");
			break;
		case 0xa2:
			printf("ANA\tD");
			break;
		case 0xa3:
			printf("ANA\tE");
			break;
		case 0xa4:
			printf("ANA\tH");
			break;
		case 0xa5:
			printf("ANA\tL");
			break;
		case 0xa6:
			printf("ANA\tM");
			break;
		case 0xa7:
			printf("ANA\tA");
			break;
		case 0xa8:
			printf("XRA\tB");
			break;
		case 0xa9:
			printf("XRA\tC");
			break;
		case 0xaa:
			printf("XRA\tD");
			break;
		case 0xab:
			printf("XRA\tE");
			break;
		case 0xac:
			printf("XRA\tH");
			break;
		case 0xad:
			printf("XRA\tL");
			break;
		case 0xae:
			printf("XRA\tM");
			break;
		case 0xaf:
			printf("XRA\tA");
			break;
		case 0xb0:
			printf("ORA\tB");
			break;
		case 0xb1:
			printf("ORA\tC");
			break;
		case 0xb2:
			printf("ORA\tD");
			break;
		case 0xb3:
			printf("ORA\tE");
			break;
		case 0xb4:
			printf("ORA\tH");
			break;
		case 0xb5:
			printf("ORA\tL");
			break;
		case 0xb6:
			printf("ORA\tM");
			break;
		case 0xb7:
			printf("ORA\tA");
			break;
		case 0xb8:
			printf("CMP\tB");
			break;
		case 0xb9:
			printf("CMP\tC");
			break;
		case 0xba:
			printf("CMP\tD");
			break;
		case 0xbb:
			printf("CMP\tE");
			break;
		case 0xbc:
			printf("CMP\tH");
			break;
		case 0xbd:
			printf("CMP\tL");
			break;
		case 0xbe:
			printf("CMP\tM");
			break;
		case 0xbf:
			printf("CMP\tA");
			break;
		case 0xc0:
			printf("RNZ");
			break;
		case 0xc1:
			printf("POP\tB");
			break;
		case 0xc2:
			printf("JNZ\t0x%02x%02X", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xc3:
			printf("JMP\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xc4:
			printf("CNZ\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xc5:
			printf("PUSH\tB");
			break;
		case 0xc6:
			printf("ADI\t#$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0xc7:
			printf("RST\t0");
			break;
		case 0xc8:
			printf("RZ");
			break;
		case 0xc9:
			printf("RET");
			break;
		case 0xca:
			printf("JZ\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xcc:
			printf("CZ\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xcd:
			printf("CALL\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xce:
			printf("ACI\t#$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0xcf:
			printf("RST\t1");
			break;
		case 0xd0:
			printf("RNC");
			break;
		case 0xd1:
			printf("POP\tD");
			break;
		case 0xd2:
			printf("JNC\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xd3:
			printf("OUT\t#$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0xd4:
			printf("CNC\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xd5:
			printf("PUSH\tD");
			break;
		case 0xd6:
			printf("SUI\t#$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0xd7:
			printf("RST\t2");
			break;
		case 0xd8:
			printf("RC");
			break;
		case 0xda: 
			printf("JC\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xdb:
			printf("IN\t#$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0xdc:
			printf("CC\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xde:
			printf("SBI\t#$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0xdf:
			printf("RST\t3");
			break;
		case 0xe0:
			printf("RPO");
			break;
		case 0xe1:
			printf("POP\tH");
			break;
		case 0xe2:
			printf("JPO\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xe3:
			printf("XTHL");
			break;
		case 0xe4:
			printf("CPO\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xe5:
			printf("PUSH\tH");
			break;
		case 0xe6:
			printf("ANI\t#$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0xe7:
			printf("RST\t4");
			break;
		case 0xe8:
			printf("RPE");
			break;
		case 0xe9:
			printf("PCHL");
			break;
		case 0xea:
			printf("JPE\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xeb:
			printf("XCHG");
			break;
		case 0xec:
			printf("CPE\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xee:
			printf("XRI\t#$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0xef:
			printf("RST\t5");
			break;
		case 0xf0:
			printf("RP");
			break;
		case 0xf1:
			printf("POP\tPSW");
			break;
		case 0xf2:
			printf("JP\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xf3:
			printf("DI");
			break;
		case 0xf4: 
			printf("CP\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xf5:
			printf("PUSH\tPSW");
			break;
		case 0xf6:
			printf("ORD\t#$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0xf7:
			printf("RST\t6");
			break;
		case 0xf8:
			printf("RM");
			break;
		case 0xf9:
			printf("SPHL");
			break;
		case 0xfa:
			printf("JM\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xfb:
			printf("EI");
			break;
		case 0xfc:
			printf("CM\t0x%02x%02x", opcode[2], opcode[1]);
			opbytes = 3;
			break;
		case 0xfe:
			printf("CPI\t#$0x%02x", opcode[1]);
			opbytes = 2;
			break;
		case 0xff:
			printf("RST\t7");
			break;
		
		default:
			// Unknown instruction
			printf("Unknown Instruction: 0x%02x\t",*opcode);
			break;
	}

	printf("\n");

	//return the number of opbytes, so that we can increment the program counter correctly
	return opbytes;
}


int main(int argc, char *argv[]){
	
	//open the file
	FILE *fp = fopen(argv[1], "rb");
	
	//error handling
	if(fp == NULL){
		printf("Error: Could not open file: \"%s\"\n", argv[1]);
		exit(1);
	}
	
	//Read the file into memory buffer
	//first get the file size using fseek
	fseek(fp, 0, SEEK_END); //seek the cursor to the end of the file
	int fsize = ftell(fp); //store the size of the file
	fseek(fp, 0, SEEK_SET); //set the cursor to the beginning of the file

	//allocate a buffer using malloc() to store the file in it
	unsigned char *buffer = malloc(fsize);
	
	//now read the file into the buffer using fread()
	fread(buffer, fsize, 1, fp);
	fclose(fp); //close the file
	
	//perform the disassembly
	
	//initialize the program counter
	int pc = 0;
	
	//Now, we disassemble every instruction using a while loop
	
	while(pc<fsize){
		pc += disassemble(buffer, pc);
	}

	//Important, free the allocated buffer
	free(buffer);

	return 0;
}
