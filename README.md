# HELIOS Memory Manager

## Description
The **HELIOS Memory Manager** is a core component of the HELIOS operating system project. It provides a robust, object-oriented memory allocation system designed to manage heap memory blocks. 

This implementation uses a **First-Fit Allocation Algorithm**, which efficiently scans and manages available memory segments to ensure optimal resource utilization during process execution.

## Features
- **Dynamic Allocation:** Handles memory requests using an efficient search-and-allocate cycle.
- **Resource Reclaiming:** Supports deallocation to prevent memory fragmentation and leakage.
- **Encapsulation:** Built with strong object-oriented principles, hiding raw memory details behind a safe, public interface.
- **Modularity:** Designed as a standalone component to be easily integrated into larger kernel architectures.

## Technical Specifications
- **Algorithm:** First-Fit
- **Language:** C++
- **Management:** Uses `std::vector` for block registry and Lambda expressions for high-performance searching.

## Usage
### Compilation
To compile the manager using `g++`, run the following command in your terminal:

```bash
g++ MemoryManager.cpp -o memory_manager
