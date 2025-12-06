# ALG-II-Projekt
A project that implements:
  * Binary search tree
  * AVL tree
  * Optimal binary search tree

## Build
```
make
```
## Usage
```
./trees <input_file>
```
## Example usage
```
./trees Test1.txt
```

## Example input
Anton\
Caesar\
Dora\
Caesar\
Caesar\
Bruno\
Bruno\
Dora\
Caesar\
Dora

## Example output
Reading source word...done.\
Number of words: 10

Binary search tree test\
Building tree...done.\
Number of unique words: 4\
Height of tree: 3\
All words found.\
Average search depth: 2.4

AVL tree test\
Building tree...done.\
Number of unique words: 4\
Height of tree: 3\
All words found.\
Average search depth: 1.8

Optimal binary search tree test\
Number of unique words: 4\
Height of tree: 3\
All words found.\
Average search depth: 1.7
