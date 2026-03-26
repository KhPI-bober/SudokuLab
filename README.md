# Sudoku Project

This repository contains the course project for the **Programming Paradigms** course.

The goal of the project is to build a Sudoku processing system step by step while exploring different programming paradigms.

Each laboratory assignment extends or refactors this project.

---

## Project Idea

We start with a simple representation of a Sudoku board and gradually evolve the system by applying different programming paradigms:

- procedural programming
- object-oriented programming
- (later) more advanced techniques

The same problem is solved multiple times using different approaches.

---

## Current Functionality

At this stage, the program supports:

- reading a Sudoku board
- printing the board
- validating whether the board is correct

---

## Project Structure

```
Sudoku/
│
├── src/        # implementation (.cpp)
├── include/    # headers (.h)
├── data/       # input/output examples
│
└── README.md
```

---

## Build

Example using g++:

g++ -std=c++17 src/*.cpp -Iinclude -o sudoku

---

## Run

./sudoku

The program expects a Sudoku board from input (file or standard input, depending on implementation).

Example:

```
530070000
600195000
098000060
800060003
400803001
700020006
060000280
000419005
000080079
```

---

## Progress

This project evolves with each lab:

- Lab 1 — Procedural implementation (functions, decomposition)
- Lab 2 — Refactoring to OOP (Board class)
- Lab 3+ — Further extensions (solver, architecture improvements)

Each lab is implemented as a separate commit.

---

## Repository Usage

- All labs are implemented in this repository
- Each assignment corresponds to a specific commit
- The repository shows the evolution of the project over time
