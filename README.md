# 42 — C++ Modules

Ten modules working through object-oriented C++, from first classes to the STL.

Everything is **C++98** — no `auto`, no range-based `for`, no smart pointers, no `nullptr`.
The restriction is deliberate: without RAII helpers to lean on, every allocation has to be
paired by hand, which is exactly the point of the exercise. Compiled with
`-Wall -Wextra -Werror` throughout.

| Module | Subject | Built |
| :--- | :--- | :--- |
| **00** | Namespaces, classes, member functions, streams | `PhoneBook`, `Contact` |
| **01** | Memory allocation, pointers vs. references | `Zombie`, `Weapon`, `HumanA`/`HumanB`, `Harl` |
| **02** | Orthodox canonical form, operator overloading | `Fixed` |
| **03** | Inheritance | `ClapTrap` → `ScavTrap`, `FragTrap` |
| **04** | Polymorphism, abstract classes, deep copy | `Animal`, `Dog`, `Cat`, `Brain`, `AAnimal` |
| **05** | Exceptions | `Bureaucrat`, `AForm` and three concrete forms, `Intern` |
| **06** | Type conversion and C++ casts | `ScalarConverter`, `Serializer`, `Base`/`A`/`B`/`C` |
| **07** | Templates | `swap`/`min`/`max`, `iter`, `Array<T>` |
| **08** | STL containers, iterators, algorithms | `easyfind`, `Span`, `MutantStack` |
| **09** | STL in practice | `BitcoinExchange`, `RPN`, `PmergeMe` |

## What each module is actually about

**00–01 — Objects and memory.** A phone book with fixed-capacity storage, then the
difference between stack and heap lifetimes: `Zombie` exists in one version that must be
deleted by the caller and one that must not. `HumanA` holds a `Weapon` by reference and
`HumanB` by pointer, which forces the distinction between a member that must exist and one
that may not.

**02 — Canonical form.** `Fixed` implements fixed-point arithmetic and the full orthodox
canonical form: default constructor, copy constructor, copy assignment operator, destructor.
Every comparison, arithmetic, increment and decrement operator is overloaded, along with
`operator<<` for output.

**03 — Inheritance.** A chain of `ClapTrap` subclasses, where the interesting part is
constructor and destructor ordering — base constructed first, destroyed last — and which
members a derived class can actually reach.

**04 — Polymorphism.** `Animal` with virtual dispatch, then `Brain` to make copying
non-trivial: a shallow copy leaves two objects owning one allocation, so copy construction
and assignment have to allocate their own. `AAnimal` makes the base abstract so it cannot
be instantiated at all.

**05 — Exceptions.** `Bureaucrat` throws on out-of-range grades from both the constructor
and the increment operators. Forms are an abstract base with three concrete implementations,
each with its own signing and execution requirements, and exceptions defined as nested
classes deriving from `std::exception`.

**06 — Casts.** `ScalarConverter` parses a string and converts it to `char`, `int`, `float`
and `double`, handling the literals that have no valid conversion — `nan`, `inf`, values
outside the target range. `Serializer` round-trips a pointer through an integer with
`reinterpret_cast`. `Base`/`A`/`B`/`C` identifies a type at runtime using `dynamic_cast`,
including the reference version that throws instead of returning null.

**07 — Templates.** Function templates first, then `Array<T>`: a fixed-size container with
bounds-checked `operator[]` that throws, deep copy semantics, and correct behaviour for an
array of size zero.

**08 — STL.** `easyfind` over any container, `Span` for shortest and longest distances
across a large set of numbers, and `MutantStack` — an adapter that exposes iterators over
`std::stack`, which by design has none.

**09 — STL in practice.** A Bitcoin price lookup over a date-indexed database, a reverse
Polish notation evaluator, and `PmergeMe`: the Ford–Johnson merge-insertion sort implemented
against two different containers so their performance can be compared directly.

## Building

Each exercise is self-contained with its own Makefile:

```bash
cd cpp02/ex01 && make && ./a.out
```
