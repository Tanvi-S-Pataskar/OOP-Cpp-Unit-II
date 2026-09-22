# Object Oriented Programming with C++: Unit II - Inheritance

**Academic Session 2025–2026**  
*Department of Artificial Intelligence & Data Science*  
*Zeal College of Engineering & Research, Pune*

---

## Course Overview

This repository contains practical implementations, real-time application models, and a mini-project for **Unit II: Inheritance** under the course **Object Oriented Programming with C++ (ADPC303)**. The primary objective of this unit is to demonstrate object-oriented software reusability, extensibility, and hierarchy design in C++.

---

## Syllabus & Theoretical Concepts

The source files in this repository cover core inheritance concepts outlined in the academic syllabus:

* **Base and Derived Classes:** Defining hierarchical relationships and class boundaries.
* **Access Control:** Utilizing protected members for controlled access in derived classes.
* **Inheritance Types:** Implementing hierarchical, multiple, and multilevel class structures.
* **Constructor Chaining:** Managing base and derived class initialization and cleanup sequences.
* **Polymorphism & Abstraction:** Overriding member functions, working with abstract base classes, and using pure virtual functions.
* **Memory & Resource Management:** Implementing virtual destructors and smart pointers (`std::unique_ptr`).

---

## Practical Implementations & Modules

### 1. Real-Time Applications

* **Employee Payroll System (`Real_Time_Applications/employee_payroll.cpp`)**  
  Models an enterprise payroll system using an abstract `Employee` base class with derived classes for Full-Time, Part-Time, and Intern positions. It demonstrates hierarchical inheritance, constructor chaining, and function overriding.

* **Digital Payment Gateway (`Real_Time_Applications/digital_payment_gateway.cpp`)**  
  Simulates a payment processing system supporting Credit Card, UPI, and Net Banking transactions. It focuses on runtime polymorphism, abstract interfaces, virtual destructors, and dynamic memory handling using standard smart pointers.

* **Vehicle Fleet Management (`Real_Time_Applications/vehicle_fleet_management.cpp`)**  
  Implements a fleet tracking system for Trucks, Delivery Vans, and Bikes. It illustrates base-class attribute sharing, protected data access, and method overriding.

### 2. Mini-Project

* **Banking System with Account Hierarchy (`Mini_Project/banking_system.cpp`)**  
  A consolidated mini-project featuring a core `Account` base class extended by `SavingsAccount`, `CurrentAccount`, and `FixedDepositAccount`. It implements deposit, withdrawal, and account-specific interest calculations using virtual functions.

---

## Compilation & Execution Guide

### Environment Setup
All code is written using the C++17 standard and tested on Windows using Visual Studio Code and the MSYS2 UCRT64 GCC toolchain (`g++`).

### Execution Commands

To compile and run any application, open PowerShell in the project directory and execute the following commands:

#### Real-Time Applications
`cd Real_Time_Applications`

Compile and run Employee Payroll System:  
`g++ employee_payroll.cpp -o employee_payroll.exe`  
`.\employee_payroll.exe`

Compile and run Digital Payment Gateway:  
`g++ digital_payment_gateway.cpp -o digital_payment_gateway.exe`  
`.\digital_payment_gateway.exe`

Compile and run Vehicle Fleet Management:  
`g++ vehicle_fleet_management.cpp -o vehicle_fleet_management.exe`  
`.\vehicle_fleet_management.exe`

#### Mini-Project
`cd Mini_Project`

Compile and run Banking System:  
`g++ banking_system.cpp -o banking_system.exe`  
`.\banking_system.exe`

---

## Repository Structure

OOP-Cpp-Unit-II/  
├── .gitignore  
├── README.md  
├── Real_Time_Applications/  
│   ├── employee_payroll.cpp  
│   ├── digital_payment_gateway.cpp  
│   └── vehicle_fleet_management.cpp  
└── Mini_Project/  
    └── banking_system.cpp  

---

## Student Information

* **Course Code:** ADPC303  
* **Programme:** S.Y. B.Tech. (Artificial Intelligence & Data Science)  
* **Semester:** III  
