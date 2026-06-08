# LC-3 Virtual Machine

A small implementation of the **LC-3 (Little Computer 3)** virtual machine written in **C++**.

This project demonstrates how a computer executes programs at a low level: loading machine code into memory, decoding instructions, updating registers, interacting with I/O, and moving through the classic **fetch → decode → execute** cycle.

The goal of this repository is not to emulate a modern operating system but to show how a minimal computer architecture works from the inside.

---

## What this repository shows

Inside this project you can see how:

* a program is loaded into virtual memory;
* a CPU starts execution from an origin address;
* instructions are decoded and executed;
* registers and condition flags change during runtime;
* branching and control flow work;
* terminal input/output is handled through trap routines.

The implementation follows the LC-3 model and keeps the execution flow explicit instead of hiding it behind abstractions.

---

## Architecture Overview

```text
Object File (.obj)
        │
        ▼
┌───────────────────┐
│ Program Loader    │
└─────────┬─────────┘
          │
          ▼
┌───────────────────┐
│ Virtual Memory    │
│ 0x0000 → 0xFFFF   │
└─────────┬─────────┘
          │
          ▼
┌───────────────────┐
│ Fetch Instruction │
└─────────┬─────────┘
          │
          ▼
┌───────────────────┐
│ Decode Opcode     │
└─────────┬─────────┘
          │
          ▼
┌───────────────────┐
│ Execute Operation │
└─────────┬─────────┘
          │
          ▼
┌───────────────────┐
│ Update Registers  │
└───────────────────┘
```


---

## Supported Behavior

The virtual machine supports execution of LC-3 programs and includes:

* 16-bit memory model;
* general purpose registers;
* program counter and condition flags;
* arithmetic and logical instructions;
* memory access instructions;
* jumps and branching;
* trap routines;
* keyboard and terminal interaction.

---

## Build

```bash
git clone https://github.com/rukiamuq-hard/LC-3-Virtual-Machine.git

cd LC-3-Virtual-Machine

mkdir build
cd build

cmake ..
cmake --build .
```

---

## Run Programs

Run any assembled LC-3 object file:

```bash
./lc3_vm <program.obj>
```

Example:

```bash
./lc3_vm examples/hello.obj
```

Execution starts after loading the object file into virtual memory and continues until the program reaches a halt state.

---

## Example Workflow

```text
hello.obj
   │
   ▼
Load into memory
   │
   ▼
Initialize CPU state
   │
   ▼
Execute instructions
   │
   ▼
Console output
```

---

## Project Structure

```text
LC-3-Virtual-Machine
│
├── src/            # VM implementation
├── include/        # Headers
├── examples/       # Sample programs
├── build/          # Build output
└── CMakeLists.txt
```

---

## Why LC-3

LC-3 is a simplified educational architecture designed to expose the main ideas behind real processors without the complexity of modern instruction sets. It makes instruction execution, memory access, and control flow easier to study and debug. ([jmeiners.com][1])

---

## License

See the repository license for usage details.

[1]: https://www.jmeiners.com/lc3-vm/?utm_source=chatgpt.com "Write your Own Virtual Machine"
