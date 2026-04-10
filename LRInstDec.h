#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "LRInstDefs.h"

// Print Binary Style Instruction
void print_binary( uint16_t inst )
{
   for ( int8_t i = 15; i >= 0; i-- )
   {
      switch (i)
      {
         case 7:         // 15-8 8-bit, opcode
            printf("-"); // ????????-???????? format
         defalut:;
      }
      printf("%hhd", (inst >> i) & 1);
   }
   printf("\n");
}

void print_inst( uint16_t inst )  {
   uint8_t opcode = 0x00;
   uint8_t data = 0x00;

   opcode = (uint8_t) (inst >> 8);
   data = (uint8_t) inst;

   // NOP
   if( (opcode >> 3) == NOP ) {
      printf(" OPCODE : NOP\n");
      return;
   }

   // ADD
   if( opcode == ADD || opcode == ADD_ALT) {
      printf(" OPCODE : ADD\n");
      printf(" FUNCTION : A = A + R[%u]\n", data);
      return;
   }

   // ADDI
   if( opcode == ADDI || opcode == ADDI_ALT) {
      printf(" OPCODE : ADDI\n");
      printf(" FUNCTION : A = A + (%hhd)\n", data);
      return;
   }

   // SUB
   if( opcode == SUB || opcode == SUB_ALT) {
      printf(" OPCODE : SUB\n");
      printf(" FUNCTION : A = A - R[%u]\n", data);
      return;
   }

   // SUBI
   if( opcode == SUBI || opcode == SUBI_ALT) {
      printf(" OPCODE : SUBI\n");
      printf(" FUNCTION : A = A - (%hhd)\n", data);
      return;
   }

   // SRA
   if( opcode == SRA) {
      printf(" OPCODE : SRA\n");
      printf(" FUNCTION : A = A >>> 1\n");
      return;
   }

   // LOAD
   if( opcode == LOAD) {
      printf(" OPCODE : LOAD\n");
      printf(" FUNCTION : A = R[%u]\n", data);
      return;
   }

   // LOADI
   if( opcode == LOADI) {
      printf(" OPCODE : LOADI\n");
      printf(" FUNCTION : A = %#04x\n", data);
      return;
   }

   // AND
   if( opcode == AND) {
      printf(" OPCODE : AND\n");
      printf(" FUNCTION : A = A & R[%u]\n", data);
      return;
   }

   // ANDI
   if( opcode == ANDI) {
      printf(" OPCODE : ANDI\n");
      printf(" FUNCTION : A = A & %#04x\n", data);
      return;
   }

   // OR
   if( opcode == OR) {
      printf(" OPCODE : OR\n");
      printf(" FUNCTION : A = A | R[%u]\n", data);
      return;
   }

   // ORI
   if( opcode == ORI) {
      printf(" OPCODE : ORI\n");
      printf(" FUNCTION : A = A | %#04x\n", data);
      return;
   }

   // XOR
   if( opcode == XOR) {
      printf(" OPCODE : XOR\n");
      printf(" FUNCTION : A = A ^ R[%u]\n", data);
      return;
   }

   // XORI
   if( opcode == XORI) {
      printf(" OPCODE : XORI\n");
      printf(" FUNCTION : A = A ^ %#04x\n", data);
      return;
   }

   // LOADHI
   if( opcode == LOADHI) {
      printf(" OPCODE : LOADHI\n");
      printf(" FUNCTION : A(15,8) = %#04x\n", data);
      return;
   }

   // LOADH2I
   if( opcode == LOADH2I) {
      printf(" OPCODE : LOADH2I\n");
      printf(" FUNCTION : A(23,16) = %#04x\n", data);
      return;
   }

   // LOADH3I
   if( opcode == LOADH3I) {
      printf(" OPCODE : LOADH3I\n");
      printf(" FUNCTION : A(31,24) = %#04x\n", data);
      return;
   }

   // STORE
   if( (opcode & 0xF8) == STORE) {
      printf(" OPCODE : XOR\n");
      printf(" FUNCTION : R[%u] = A\n", data);
      return;
   }

   // JAL
   if( (opcode & 0xF8) == JAL) {
      printf(" OPCODE : JAL\n");
      printf(" FUNCTION : PC = A, R[%u] = PC + 2\n", data);
      return;
   }

   // LDADDR
   if( (opcode & 0xF8) == LDADDR) {
      printf(" OPCODE : LDADDR\n");
      printf(" FUNCTION : AR = A\n");
      return;
   }

   // LDIND
   if( opcode == LDIND || opcode == LDIND_ALT) {
      printf(" OPCODE : LOADIND\n");
      printf(" FUNCTION : A = mem[AR + (%#04x << 2)]\n", data);
      return; 
   }

   // LDINDB
   if( opcode == LDINDB || opcode == LDINDB_ALT) {
      printf(" OPCODE : LOADINDB\n");
      printf(" FUNCTION : A = mem[AR + (%#04x)](7, 0)\n", data);
      return;
   }

   // LDINDH
   if( opcode == LDINDH || opcode == LDINDH_ALT) {
      printf(" OPCODE : LOADINDH\n");
      printf(" FUNCTION : A = mem[AR + (%#04x)](15, 0)\n", data);
      return;
   }

   // STIND
   if( opcode == STIND || opcode == STIND_ALT) {
      printf(" OPCODE : STOREIND\n");
      printf(" FUNCTION : mem[AR+(%#04x << 2)] = A\n", data);
      return; 
   }

   // STINDB
   if( opcode == STINDB || opcode == STINDB_ALT) {
      printf(" OPCODE : STOREINDB\n");
      printf(" FUNCTION : mem[AR + (%#04x)] = A(7, 0)\n", data);
      return;
   }

   // STINDH
   if( opcode == STINDH || opcode == STINDH_ALT) {
      printf(" OPCODE : STINDH\n");
      printf(" FUNCTION : mem[AR + (%#04x)] = A(15, 0)\n", data);
      return;
   }

   // BR
   if( opcode == BR) {
      printf(" OPCODE : BR\n");
      printf(" FUNCTION : PC = PC + o\n");
      return;
   }

   // BRZ
   if( opcode == BRZ) {
      printf(" OPCODE : BRZ\n");
      printf(" FUNCTION : if A == 0 PC = PC + o\n");
      return;
   }

   // BRNZ
   if( opcode == BRNZ) {
      printf(" OPCODE : BRNZ\n");
      printf(" FUNCTION : if A != 0 PC = PC + o\n");
      return;
   }

   // BRP
   if( opcode == BRP) {
      printf(" OPCODE : BRP\n");
      printf(" FUNCTION : if A >= 0 PC = PC + o\n");
      return;
   }

   // BRN
   if( opcode == BRN) {
      printf(" OPCODE : BRN\n");
      printf(" FUNCTION : if A < 0 PC = PC + o\n");
      return;
   }

   // SCALL
   if( opcode == SCALL) {
      printf(" OPCODE : SCALL\n");
      printf(" FUNCTION : System Call\n");
      return;
   }

   printf("Error OPCODE Format\n");
   return;
}
