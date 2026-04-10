#include "LRInstDec.h"

int main( void )
{
   printf( "\n********** Leros Instruction Decode **********" );
   uint32_t instr;
   while(1) {
      printf("\n Please input Instruction: ");
      scanf( "%04x", &instr );
         
      printf( "\n" );
      printf( " Your Instruction is : 0x%04x\n", instr );
      printf( " Binary Type is      : " );
      print_binary( (uint16_t)instr );
      print_inst( (uint16_t)instr );

   }
   

   return 0;
}
