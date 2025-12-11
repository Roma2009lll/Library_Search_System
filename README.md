# 📚 Library Search System

Binary Search vs Linear Search performance comparison

## Features
- 1000+ books database
- Linear Search by name - O(n)
- Binary Search by ISBN - O(log n)
- Binary Search by year - O(log n)
- QuickSort implementation - O(n log n)
- Performance testing with 100M records
- Visual comparison of search algorithms

## Compilation
```bash
gcc -o library library.c
./library
```

## Big O Analysis
| Algorithm | Time Complexity | Space |
|-----------|----------------|-------|
| Linear Search | O(n) | O(1) |
| Binary Search | O(log n) | O(log n) |
| QuickSort | O(n log n) | O(log n) |

## Performance Results
Binary Search is **~1000x faster** on 100M records!

## Author
Student of Computational Intelligence & Smart Systems
```

### 7. **Додати .gitignore**
```
# Executables
*.exe
*.out
*.app

# Object files
*.o
*.obj

# Visual Studio
.vs/
*.vcxproj*
*.sln
x64/
Debug/
Release/

# Other
*.log
