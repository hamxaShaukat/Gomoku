# Gomoku (C++ Console Game)

A terminal-based implementation of the classic **Gomoku (Five-in-a-Row)** game in C++.  
This project includes two modes:
- 👥 Human vs Human
- 🤖 Human vs AI

## 🎮 Features
- Choose win condition (`wincount`) from 3–19 (e.g., 3 in Tic-Tac-Toe, 5 in Gomoku).
- Choose custom board dimensions (rows = n, columns = n).
- Supports player name input.
- Turn-based gameplay with continuous prompts until a winner is found.
- Simple AI opponent in Human vs AI mode.
- Implemented entirely using **2D arrays** in C++.

## 🛠️ Tech Stack
- Language: C++  
- Paradigm: Procedural Programming  
- Tools: Console (terminal output/input)  

## 🚀 How to Run
1. Compile using g++:
   ```bash
   g++ main.cpp -o gomoku
   ./gomoku
