// Most registers are able to be accessed as either one 16bit or 2 8-bit registers.
#include <stdbool.h>

struct registers 
{
    // Accumulator and flags
    unsigned char A;
    unsigned char F;

    // BC
    unsigned char B;
    unsigned char C;

    // DE
    unsigned char D;
    unsigned char E;

    // HL
    unsigned char H;
    unsigned char L;
};

// Flag register is within lower 8bit of the AF register
// Ex. 0xZNHC0000
struct flags 
{
    // Zero flag (1 if current op results in zero)
    unsigned char z;

    // Subtraction flag (1 if subtraction performed)
    unsigned char n;

    // Half carry flag (1 if carry occurred from lower nibble of last op)
    // * lower nibble means lowest 4 bits * 
    unsigned char h;

    // Carry flag (1 if carry occurred in last op, or if A is smaller val in CP instr)
    unsigned char c;

    bool HALT;
};
