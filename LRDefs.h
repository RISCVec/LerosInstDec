// LRInstDefs.h

// opcode
// use 8-bit uint8_t to store
// unused bit default to zero
#define NOP                0x00 // 00000---
#define ADD                0x08 // 00001000
#define ADD_ALT            0x0A // 00001010
#define ADDI               0x09 // 00001001
#define ADDI_ALT           0x0B // 00001011
#define SUB                0x0C // 00001100
#define SUB_ALT            0x0E // 00001110
#define SUBI               0x0D // 00001101
#define SUBI_ALT           0x0F // 00001111
#define SRA                0x10 // 00010---
//#define -                  0x18  // 00011---
#define LOAD               0x20 // 00100000
#define LOADI              0x21 // 00100001
#define AND                0x22 // 00100010
#define ANDI               0x23 // 00100011
#define OR                 0x24 // 00100100
#define ORI                0x25 // 00100101
#define XOR                0x26 // 00100110
#define XORI               0x27 // 00100111
#define LOADHI             0x29 // 00101001
#define LOADH2I            0x2A // 00101010
#define LOADH3I            0x2B // 00101011
#define STORE              0x30 // 00110---
#define OUT                0x38 // 0011100?
#define OUT_ALT            0x3A // 0011101?
#define IN                 0x04 // 0000010?
#define IN_ALT             0x06 // 0000011?
#define JAL                0x40 // 01000---
//#define -                0x48 // 01001---
#define LDADDR             0x50 // 01010---
#define LDIND              0x60 // 01100000
#define LDIND_ALT          0x64 // 01100100
#define LDINDB             0x61 // 01100001
#define LDINDB_ALT         0x65 // 01100101
#define LDINDH             0x62 // 01100010
#define LDINDH_ALT         0x66 // 01100110
#define STIND              0x70 // 01110000
#define STIND_ALT          0x74 // 01110100
#define STINDB            0x71 // 01110001
#define STINDB_ALT        0x75 // 01110101
#define STINDH            0x72 // 01110010
#define STINDH_ALT        0x76 // 01110110
#define BR                 0x80 // 1000nnnn
#define BRZ                0x90 // 1001nnnn
#define BRNZ               0xA0 // 1010nnnn
#define BRP                0xB0 // 1011nnnn
#define BRN                0xC0 // 1100nnnn
#define SCALL              0xFF // 11111111


