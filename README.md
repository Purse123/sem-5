# sem-5
| Subject  | Programming language  |
|:--|:--|
| **DDA**  | `ADA` & `C++`  |


# Why ADA and not C/C++?
1. Because it is valid code.
```c++
void f(int& a, int& b) {   // <----- f(same_variable, same_variable);
    a = 1;
    b = 2;
}
```
2. Why not Rust You ask: F**rust**ation, *I would rather use Haskell*
   - `Box<T>` is owning pointer, It behaves like an object/value.
   - It is unique ownership of heap-allocated T.
   - It is similar to `std::unique_ptr<T>` in c++
   
3. Optimize for maximum correctness and local reasoning rather than assumptions.

4. C++ is design for freedom (CHAOOOOSSSSS). undefine behavior for
   - out-of-bounds access
   - use-after-free
   - data races *unsynchronized shared memory access*
   - race condition *all data race are race condition but not opposite*
   - uninitialized reads, etc
   
5. Side effect *I dont care about this*

## Refernce
- [learn ada programming](https://learn.adacore.com/pdf_books/learning-ada.pdf)
- [Emacs ada mode](https://github.com/tkurtbond/old-ada-mode)
