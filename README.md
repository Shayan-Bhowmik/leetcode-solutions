# LeetCode Solutions (C++)

A collection of LeetCode problem solutions implemented in modern C++ (C++17+). Each problem lives in its own folder and may include multiple approach variants and a short problem README.

Quick start
- Build a single solution using `g++`:

```bash
g++ -std=c++17 -O2 path/to/problem/solution.cpp -o solution && ./solution
```

On Windows PowerShell (if `g++` is in PATH):

```powershell
g++ -std=c++17 -O2 .\0001-two-sum\solution.cpp -o solution.exe; .\solution.exe
```

Repository layout
- Top-level directories are named like `0001-two-sum/`, `0002-add-two-numbers/`, etc.
- Inside a problem folder you typically find:
	- `solution.cpp` — main solution
	- other variants (e.g. `brute_force.cpp`, `two_pointer.cpp`, `hashing.cpp`)
	- `README.md` — short explanation, approach and complexity

How to add a new problem
1. Create a folder with a zero-padded number and short name (e.g. `0123-my-problem/`).
2. Add `solution.cpp` (and other variants if needed).
3. Add `README.md` describing the approach, time and space complexity, and edge cases.

Notes and conventions
- Use readable, idiomatic C++ and prefer clarity over clever micro-optimizations.
- Solutions that require input should read from `stdin` so they can be tested with redirection.

Contributing
- Fork, add or update a problem folder, then open a pull request with a short description.

License
- No license is included. Add a `LICENSE` file if you want to set reuse terms.

That's it - simple, searchable C++ solutions intended for study and practice.