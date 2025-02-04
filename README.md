**ZefyrGB - A Gameboy Emulator written in C**
By: Paul Warwick

**Preface**

    This began as a personal interest project of mine on 2/1/2025.
After struggling with my passion for software due to the current market outlook,
I thought back to my early days where I was impressed by systems such
as the GameBoy. Those consoles pre-2k and in the early 2000's were engineered
with great constraints and care in ways we don't quite see in today's abundant world.
There is something elegant about being so close to the machine while programming. 
The thought to recreate a system I loved not only has shown to be a daunting
task (writing this part on my first day of documentation diving), but also seems like
it would be much more rewarding than most software design tasks I've dealt with in my
past. 


**Roadmap**

It is prudent to do a sort of test-driven development for this type of system, as it has
so many working parts within it, and many are cycle-critical. 

Step 1: Emulation of the CPU. I would like to get the CPU as close to perfect as I can,
so as to not have to come back to it later on. This requires creation and testing of the opcodes
used within the GameBoy system (there are many). 

Step 2: System timer and interrupts. 

Step 3: Pixel processing Unit (PPU). Translating ROM into a screen. I'm thinking SDL could be 
a good library to work on this with.

Step 4: Memory Bank Controller (MBC). This is the portion which determines what part of a 
games ROM the GameBoy can "see" at any given time. Some games require distinct types of MBC, while
others like Tetris require none.

Step 5: Audio Processing Unit (APU). This is skippable, and might be fun to implement to some extent.

**CPU Emulation (SM83 AKA DMG-CPU)**



Notes:

    - Main subsystems consist of a control unit, register file, ALU, 
    and an IDU (Increment/decrement unit).

        - Control Unit: The control unit decodes & executes instructions, and also generates
        control signals for the rest of the CPU core. It also checks and dispatches
        interrupts.

        - Register File: This holds most of hte state of the CPU within registers. contains a 
        16-bit program counter (PC), a 16-bit stack pointer (SP), an 8-bit accumulator (A), a
        flag register (F), and also 16-bit general purpose registers which consist of two 8-bit
        halves, such as BC, DE, and HL. It also has special purpose 8-bit registers in the
        instruction register (IR), and the interrupt enabler (IE).

        - ALU: The arithmetic logic unit. It has two 8-bit ports for input and it is capable of
        performing various calculations. This subsystem outputs its results to either the register
        file or the CPU data bus.

        - IDU: The increment/decrement unit. Capable of only simple increment/decrement operations
        as the name implies. These actions are performed on the 16-bit address bus value, yet they
        are performed independently of the ALU, which is good for CPU performance. Outputs go back
        to the register file always, and can then be written to a register. 

    - This CPU took portions of the popular Intel 8080, as well as the Zilog Z80.

    - It is an 8-bit CPU core. 

    - The CPU uses a design technique known as "fetch/execute overlap" which improves
    CPU performance through doing opcode fetches in parallel with instruction execution
    when possible.

    - 2 memory operations cannot happen at the same time in this system.

        







**Sources**

The Ultimate Gameboy Talk
https://www.youtube.com/watch?v=HyzD8pNlpwI

Game Boy: Complete Technical Reference by gekkio
https://gekkio.fi/files/gb-docs/gbctr.pdf

The Emulation Development Subreddit
https://www.reddit.com/r/EmuDev/

GBDev Pan Docs
https://gbdev.io/pandocs/About.html