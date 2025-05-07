
# 📘 Library Management System

This is a basic C++ Library Management System that supports:

- Member management via a doubly linked list  
- Book inventory using a queue  
- Librarian data management  
- Book issuing with limits  
- Search functionality for members and books

---

## 🛠️ How to Compile and Run

### ✅ Prerequisites

- A C++ compiler (e.g., `g++`)
- C++11 or later

### 🔁 Compilation

To compile the program, run:

```bash
g++ -std=c++11 -o library_system main.cpp
```

Replace `main.cpp` with your file name if it's different.

### ▶️ Running the Program

After compilation, run:

```bash
./library_system
```

On Windows, use:

```bash
library_system.exe
```

---

## 💡 Features

- Add/search/display members
- Add/search books (by ID or title/author)
- Assign a librarian and update details
- Issue books to members (up to 5 per member)
- Basic error handling for invalid operations

---


## 🧹 Future Improvements

- Add support for returning books
- Save/load data from files (persistence)
- GUI frontend or web interface
