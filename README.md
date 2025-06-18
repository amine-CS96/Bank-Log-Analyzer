
# Bank Log Analyzer  — Bank Transactions Log Management and Analysis

## Description

This C program reads, displays, and analyzes a log file containing bank transactions. It offers a command-line menu interface to:

 - Load and display the raw contents of the log file.
 - Calculate and show useful statistics such as the total number of transactions, total deposit and withdrawal amounts, and the largest transactions.

The goal is to practice file handling, string processing, and basic statistical calculations in C.



## Features

* Read and print the log file line by line.
* Count the total number of transactions.
* Compute total amounts for deposits and withdrawals.
* Identify the largest deposit and withdrawal amounts.
* Display summary statistics.

---

## Project Structure

* `main.c` — contains the main menu and calls the analysis functions.
* `log.h` — includes functions for loading, analyzing, and displaying log data.
* `log.txt` — sample log file containing bank transaction data used for testing the program.
---

## Compilation & Execution

```bash
gcc src/main.c -o transaction-log-analyzer
./transaction-log-analyzer
```

---

## Usage

1. Run the program.
2. Choose a menu option:

   * **1**: Load and display the log file.
   * **2**: Show calculated statistics.
   * **3**: Exit.
3. Enter the log file name (e.g., `log.txt`).

---

## Expected Log File Format

The log file should contain structured blocks representing transactions, with each transaction spanning multiple lines. Transactions are identified as either "Withdrawal" or others to differentiate operation types. The program reads and processes this specific format.

---

## Highlights & Learning Outcomes

* Advanced file handling in C.
* Robust input/output and error checking.
* Text parsing using `fscanf` and string handling.
* Simple statistical computations (max, sum, count).
* Modular design with a dedicated header file.

---

## Limitations & Possible Improvements

* Support for more flexible file formats (e.g., CSV).
* Enhanced user interface (e.g., GUI).
* Export statistics to a file.
* More robust error handling and data validation.

---

## License


This project is licensed under the MIT License — you are free to use, copy, modify, merge, publish, and distribute the software, provided that the original author is credited and the license notice is included in all copies or substantial portions of the software.

See the [LICENSE](LICENSE) file for full terms.

---
