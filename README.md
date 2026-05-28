# LeetCode Solutions (C++)

This repository contains worked solutions to LeetCode problems implemented in C++.
Each problem is placed in a dedicated folder named with the problem number and a short title.

**Goals:**
- Provide clear, idiomatic C++ solutions.
- Show typical approaches and complexity analysis.
- Serve as a reference and study aid for algorithm practice.

## Repository Structure

- Top-level folders are organized by problem number and short name, for example:
	- `0001-two-sum/` — contains one or more solutions and a problem README.
- Typical files inside a problem folder:
	- `solution.cpp` — primary solution implementation.
	- Additional variants: `brute_force.cpp`, `two_pointer.cpp`, `hashing.cpp`, `kadane.cpp`, etc.
	- `README.md` — problem-specific notes, approach, and complexity.

## Conventions

- Filenames: prefer descriptive names like `solution.cpp` or `two_pointer.cpp` when multiple approaches exist.
- Code: modern C++ (at least C++17) with readable variable names and minimal dependencies.
- Each problem folder should include a short `README.md` describing the approach and time/space complexity.

## Build & Run

You can compile an individual solution with `g++` (C++17). Example:

```bash
g++ -std=c++17 -O2 path/to/problem/solution.cpp -o solution && ./solution
```

If a solution reads input from `stdin`, provide input via redirection or a here-doc. Example:

```bash
./solution < input.txt
```

For Windows PowerShell (g++ in PATH):

```powershell
g++ -std=c++17 -O2 .\0001-two-sum\solution.cpp -o solution.exe; .\solution.exe
```

## How to Add a New Problem

1. Create a new folder named with a zero-padded problem number and short title, e.g. `0123-my-problem/`.
2. Add your solution file(s), preferably `solution.cpp` as the canonical solution.
3. Add a `README.md` inside the folder summarizing the approach, complexities, and any edge cases.
4. (Optional) Add multiple variants when relevant, labeling them clearly (e.g., `brute_force.cpp`, `dp.cpp`).

## Coding Style & Tips

- Prefer clarity over clever micro-optimizations.
- Comment non-obvious logic and explain tricky invariants in the problem README.
- Keep functions small and focused; implement helpers when appropriate.
- Use `std::vector`, `std::string`, `std::unordered_map`, and STL algorithms where applicable.

## Contribution

Contributions are welcome. To contribute:

- Fork the repo and create a branch for your changes.
- Add or update a problem folder with solution(s) and `README.md`.
- Open a pull request with a clear description of the approach.

## License

This repository does not include an explicit license. If you want to reuse or redistribute code, please contact the repo owner or add a license file.

---