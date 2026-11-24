<div align="center">

# ðŸª– Military Personnel & Soldier Management System
### High-Performance Command-Line Management Suite Engineered in C++ Using Advanced Data Structures

[![Language: C++17](https://img.shields.io/badge/Language-C%2B%2B17%20%7C%20C%2B%2B20-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Data Structures](https://img.shields.io/badge/Focus-Data%20Structures%20%26%20Algorithms-orange?style=for-the-badge&logo=codereview)](https://github.com/bini576)
[![Platform: Cross-Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Windows-lightgrey?style=for-the-badge)](#)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)

<p align="center">
  <a href="#-overview">Overview</a> â€¢
  <a href="#-key-features">Key Features</a> â€¢
  <a href="#-data-structures--complexity">Data Structures</a> â€¢
  <a href="#-compilation--installation">Compilation</a> â€¢
  <a href="#-usage-guide">Usage</a>
</p>

</div>

---

## ðŸ“Œ Overview

The **Soldier Management System** is a modular, memory-efficient console application built in modern C++. Designed for military administrative personnel and defense logistics coordinators, this system manages service records, ranks, deployments, medical clearance states, and unit assignments with deterministic speed and minimal system resource footprint.

Rather than relying on heavyweight database engines, the project demonstrates core Computer Science fundamentalsâ€”implementing custom **Linked Lists**, dynamic memory allocators, fast lookup algorithms, and disk serialization routines directly in C++.

---

## âœ¨ Key Features

- **Full Personnel Record Lifecycle (CRUD):**
  - **Create:** Enlist new soldiers with unique Service IDs, full name, military rank, combat unit/division, and deployment status.
  - **Read / Search:** High-speed lookup by Service ID, unit division, or rank classification.
  - **Update:** Seamlessly update promotion status, assigned combat post, or medical readiness markers.
  - **Delete:** Safely discharge or decommission personnel records with full heap memory deallocation.
- **Record Sorting & Filtering:** Multi-field sorting (alphabetical, rank hierarchy, or service seniority).
- **Persistent Storage (File I/O):** Saves and loads personnel state to disk using structured file serialization, preventing data loss between sessions.
- **Robust Input Validation:** Defense against buffer overflow errors and invalid user inputs in the CLI console.
- **Zero External Dependencies:** Compiles natively across any standard C++ compiler without external libraries.

---

## ðŸ§¬ Data Structures & Complexity Analysis

```
  [ Head Pointer ]
         â”‚
         â–¼
  â”Œâ”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”      â”Œâ”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”      â”Œâ”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”
  â”‚ Soldier Recordâ”‚      â”‚ Soldier Recordâ”‚      â”‚ Soldier Recordâ”‚
  â”‚ ID: AF-1049   â”‚ â”€â”€â”€â–º â”‚ ID: AF-1050   â”‚ â”€â”€â”€â–º â”‚ ID: AF-1051   â”‚ â”€â”€â”€â–º NULL
  â”‚ Next: 0x7ffd..â”‚      â”‚ Next: 0x7ffd..â”‚      â”‚ Next: 0x0000..â”‚
  â””â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”˜      â””â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”˜      â””â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”˜
```

| Component | Underlying Data Structure | Time Complexity (Search) | Time Complexity (Insert) | Time Complexity (Delete) |
|:---|:---|:---:|:---:|:---:|
| **Personnel Registry** | Doubly/Singly Linked List | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ | $\mathcal{O}(n)$ |
| **Sorted Hierarchy** | In-Memory MergeSort / QuickSort | $\mathcal{O}(n \log n)$ | â€” | â€” |
| **ID Lookup Index** | Direct ID Pointer Array / Hash Buckets | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ |

### Why Linked Structures?
1. **Dynamic Scaling:** Military units expand and contract continuously; linked nodes avoid the expensive array re-allocations required by static vectors.
2. **Deterministic Memory Footprint:** Allocates memory strictly per enlistment, freeing nodes immediately upon discharge to eliminate memory leaks.

---

## ðŸš€ Compilation & Installation

### Prerequisites
- Modern C++ Compiler (`g++`, `clang++`, or MSVC supporting C++17+)
- `make` or `cmake` (optional)

### 1. Clone the Repository
```bash
git clone https://github.com/bini576/Soldier-Management-System.git
cd Soldier-Management-System
```

### 2. Compile via GCC / Clang
```bash
# On Linux / macOS
g++ -std=c++17 -Wall -Wextra -O2 src/*.cpp -o soldier_management

# On Windows (PowerShell with MinGW / GCC)
g++ -std=c++17 -Wall -Wextra -O2 src/*.cpp -o soldier_management.exe
```

---

## ðŸ’» Usage Guide

Launch the compiled executable in your terminal:

```bash
./soldier_management
# or on Windows
.\soldier_management.exe
```

### Main Console Menu Interface

```text
=====================================================
       MILITARY PERSONNEL MANAGEMENT SYSTEM v1.2      
=====================================================
  [1] Enlist New Soldier
  [2] Display All Active Records
  [3] Search Soldier by Service ID
  [4] Update Soldier Details (Rank / Unit / Status)
  [5] Discharge / Remove Soldier Record
  [6] Sort Records by Rank or Service Length
  [7] Save Records to Persistent Storage
  [8] Load Records from Disk
  [0] Exit System
=====================================================
  Enter your choice: 
```

### Sample Record Output
```text
-----------------------------------------------------
Service ID   : AF-2024-8841
Full Name    : Biniyam A. Afework
Rank         : Lieutenant (Security Operations)
Unit         : Cyber Defense Battalion 1
Deployment   : Active (Campus Defense)
Medical Status: Class A (Combat Ready)
-----------------------------------------------------
```

---

## ðŸ›¡ï¸ Memory Safety Best Practices

- Explicit pointer hygiene and destructor invocation (`delete` / `free`) preventing dangling pointers.
- Strict input sanitation on standard input streams (`std::cin`) to prevent buffer exploits and infinite console loops.
- File stream integrity checks before serializing or reading binary record headers.

---

## ðŸ“„ License & Author

Distributed under the **MIT License**.

- **Author:** [Biniyam Ademasu Afework](https://github.com/bini576)
- **Degree:** B.Sc. Cyber Security, Bahir Dar University
- **GitHub:** [@bini576](https://github.com/bini576)
- **LinkedIn:** [linkedin.com/in/biniyam-ademasu](https://linkedin.com/in/biniyam-ademasu)
- **Email:** [admasubiniyam96@gmail.com](mailto:admasubiniyam96@gmail.com)
