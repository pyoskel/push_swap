_This project has been created as part of the 42 curriculum by **pabartoc** (42 Heilbronn)._

# 🔄 push_swap

## 📝 Description

`push_swap` is an algorithmic project at 42 School that challenges you to sort data on a stack using a highly limited set of instructions. The goal is to calculate and output the smallest possible sequence of operations to perfectly sort a randomized stack of integers.

The challenge lies not only in writing a functional sorting algorithm but also in adhering to strict performance benchmarks (e.g., sorting 500 numbers in under 5500 moves) while strictly following the 42 Norminette rules (e.g., memory management, restricted file structure, maximum 25 lines per function).

---

## 🧠 The Algorithmic Strategy

This project uses a hybrid approach that dynamically adapts to the size of the input stack to guarantee the most efficient solution.

### 1. Parsing & Validation
Before any sorting occurs, the input goes through a rigorous safety check:
* Checks for duplicate numbers.
* Checks for non-numeric characters.
* A built-in "Overflow Protection" (length validation) that prevents Segmentation Faults from astronomically large inputs (e.g., `9999999999999999999`) before `ft_atol` is even called.

### 2. Stack Normalization (Indexing)
Instead of calculating with the actual, chaotic integer values (e.g., `-999`, `42`, `2000000`), the stack is assigned a ranking system. The absolute smallest number gets the rank/index `0`, the second smallest gets `1`, up to `N-1`. 
This eliminates the problem of negative numbers and massive gaps between values, perfectly preparing the stack for bitwise comparison.

### 3. Small Sort (Up to 5 Elements)
For tiny stacks, the main algorithm is too expensive. A highly optimized, hardcoded logic is used instead:
* **The Equator Logic (`size / 2`):** The stack is logically divided in half. To bring a specific number to the top, the program calculates the geometrically shortest path in milliseconds. If the number is in the upper half, it rotates forward (`ra`). If it has crossed the "equator" into the lower half, rotating backwards through the bottom of the stack (`rra`) is mathematically shorter.

---

## 🔬 Deep Dive: Radix Sort in Base-2

For large datasets (100 or 500 numbers), a **Bitwise Radix Sort** algorithm is deployed. 

Traditional Radix Sort evaluates numbers in Base-10 (decimal), which requires 10 separate physical buckets (0 to 9) to sort each digit. However, the strict rules of `push_swap` limit us to exactly **two stacks (A and B)**. To overcome this limitation, we adapt the algorithm to use **Base-2 (Binary)**, where the only digits are `0` and `1`.

**How it works:**
Since we normalized our stack into clean ranks (`0` to `N-1`), we can look at these ranks as binary numbers. The algorithm iterates through the bits of these indices from right to left (Least Significant Bit to Most Significant Bit) using a simple bitwise shift and mask: `(index >> i) & 1`.

The sorting rule is incredibly simple, stubborn, and fast:
1. **If the current bit is `0`:** Push the number to Stack B (`pb`).
2. **If the current bit is `1`:** Keep the number in Stack A, but rotate it to the bottom (`ra`).

After evaluating a single bit for all numbers in Stack A, we push everything back from Stack B to Stack A (`pa`). 
Without the computer ever asking the question *"Is number A greater than number B?"*, repeating this process for every bit results in a mathematically flawless, perfectly sorted stack.

---

## 📂 Project Structure

The code is strictly modularized to respect the 42 Norminette (max. 5 functions per file).

```text
.
├── Makefile
├── README.md
├── checker_linux           # The official 42 evaluation tool
├── inc
│   └── push_swap.h         # Main header, structs & prototypes
├── libft                   # Custom Standard C Library
│   ├── Makefile
│   ├── inc
│   │   └── libft.h
│   └── src
│       ├── ft_atoi.c
│       ├── ft_split.c
│       └── ... (additional libft functions)
└── src
    ├── index.c             # Normalization and ranking of integers
    ├── push.c              # Operations: pa, pb
    ├── push_swap.c         # Main function, parsing & error handling
    ├── radix.c             # The main Bitwise Radix Sort algorithm
    ├── rev_rotate.c        # Operations: rra, rrb, rrr
    ├── rotate.c            # Operations: ra, rb, rr
    ├── small_sort.c        # Specialized algorithms for 3 to 5 numbers
    ├── stack_utils.c       # Linked list utilities (new_node, add_back, free)
    ├── swap.c              # Operations: sa, sb, ss
    ├── utils.c             # General memory management
    └── validation.c        # Strict error checking for user input
```

---

## 🛠️ Installation & Compilation

The project includes a `Makefile` that compiles the code cleanly using the `-Wall -Wextra -Werror` flags.

```bash
# Compiles the program including the libft
make

# Removes generated object files (.o)
make clean

# Removes object files AND the executable
make fclean

# Rebuilds the entire project from scratch
make re
```

---

## 🚀 Usage & Local Testing

The program accepts a list of integers. These can be passed individually or as a single formatted string.

```bash
# Passing arguments individually:
./push_swap 42 1337 -5 0

# Passing arguments as a single string:
./push_swap "42 1337 -5 0"
```

### 1. Error Handling Tests (Edge-Cases)
The program is secured against all invalid inputs and properly throws an `Error` to the standard error output (`stderr`).
```bash
./push_swap 1 2 2             # Duplicate -> Error
./push_swap 1 2 3000000000    # Integer Overflow -> Error
./push_swap 00000000000000042 # Leading zeros -> OK (evaluated as 42)
./push_swap 1 2 abc           # Letters / Non-numeric -> Error
./push_swap ""                # Empty string -> Error / Clean exit
```

### 2. Memory Management (Valgrind Leaks)
The program has been heavily tested for memory leaks. Strings and `malloc` calls are completely freed and returned to the system in both success and error scenarios.
```bash
# Test with a single string (Checks if ft_split is freed correctly)
valgrind --leak-check=full ./push_swap "1 2 3"

# Test with multiple arguments and sorting logic
valgrind --leak-check=full ./push_swap 5 1 4 2 3

# Expected Output for both:
# "All heap blocks were freed -- no leaks are possible"
```

---

## 🎯 Evaluation (The Checker)

To prove that the generated instructions (`sa`, `ra`, `pb`, etc.) actually sort the stack correctly, 42 provides a binary program called `checker`. The output of `push_swap` is piped (`|`) directly into this checker.

*(Note: The `checker_linux` file must have execution rights. If it doesn't: run `chmod +x checker_linux` in your terminal).*

### Basic Tests
```bash
# 3 numbers (Should be sorted in max. 2-3 moves)
ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG

# 5 numbers (Should be sorted in max. 12 moves)
ARG="5 1 4 2 3"; ./push_swap $ARG | ./checker_linux $ARG
```

### The Ultimate Stress Tests (100 & 500 Numbers)
Using the Linux `shuf` command, we can generate massive, randomized stacks, feed them to the checker, and instantly count the number of instructions used (via `wc -l`).

**100 Numbers Test (Goal: Under 700 operations)**
```bash
ARG=$(seq 1 1000 | shuf -n 100 | tr '\n' ' '); \
./push_swap $ARG | ./checker_linux $ARG; \
./push_swap $ARG | wc -l
```

**500 Numbers Boss Fight (Goal: Under 5500 operations)**
```bash
ARG=$(seq 1 5000 | shuf -n 500 | tr '\n' ' '); \
./push_swap $ARG | ./checker_linux $ARG; \
./push_swap $ARG | wc -l
```
*(If the output here is `OK` and the instruction count is within the limits, the algorithm is ready to score 100/100 points in the evaluation!)*

---

## 📊 Visualizer

This project includes support for the [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer) by `o-reo` to visually demonstrate the Radix Sort algorithm in action.

### Prerequisites (Linux)
To compile and run the visualizer, you need a few standard graphics and build dependencies. You can install them via:
```bash
sudo apt-get update
sudo apt-get install cmake g++ clang libgl1-mesa-dev libglu1-mesa-dev libx11-dev libxrandr-dev libudev-dev libfreetype-dev
```

### Setup & Installation
1. **Compile the main program:** Ensure that the `push_swap` executable is built before running the visualizer.
   ```bash
   make
   ```
2. **Clone the visualizer:**
   ```bash
   git clone https://github.com/o-reo/push_swap_visualizer.git push_swap_visualizer
   ```
3. **Build the visualizer:** Navigate into the visualizer directory, create a build folder, and compile it.
   ```bash
   cd push_swap_visualizer
   mkdir build && cd build
   cmake ..
   make
   ```

### Usage
1. Launch the visualizer from inside the `build` directory:
   ```bash
   ./bin/visualizer
   ```
2. In the **Values** window on the right:
   - Enter the desired amount of numbers to sort (e.g., `100` or `500`).
   - Click **Shuffle** to generate a random stack.
   - Verify the **push_swap file path**. By default, it is set to `../../push_swap`. *(Note: If the visualizer does not register the commands, provide the **absolute path** to the executable).*
   - Click **Compute**. Wait a second until the status next to the button changes from `...` to **OK**.
3. In the **Controls** window:
   - Adjust the **Speed** slider (otherwise the animation might be very slow).
   - Click **Start** to watch the sorting process!

---

## 📚 Resources & Sources

The following resources were incredibly helpful for understanding the underlying data structures, bitwise manipulation, and 42-specific constraints required to complete this project:

* [Stack (Abstract Data Type) - Wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
* [42School Norminette Repository](https://github.com/42School/norminette)
* [Mastering Radix Sort: A Step-By-Step Guide to Efficient Data Sorting (Tomas Svojanovsky)](https://tomas-svojanovsky.medium.com/mastering-radix-sort-a-step-by-step-guide-to-efficient-data-sorting-ba389bde7667)
* [Radix Sort Algorithm Explained - Yogendra Singh](https://medium.com/@ys.yogendra22/radix-sort-sorting-c5b31152c48b)