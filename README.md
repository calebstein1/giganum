# Giganum

![Image](image.jpg)

Giganum is a C library allowing for arithmetic operations on integers of an arbitrary size, unconstrained by the size limitations of standard number types.

Right now the only implemented functions are addition and subtraction, and only positive numbers are supported, but more functions are coming soon!

## Building

In your shell, do the following:

```Bash
git clone https://github.com/calebstein1/giganum
cd giganum
make
```

This will build libgiganum, place it in the `lib` directory, and run the tests in the 'test' directory.

## Usage

To use libgiganum in your program, you'll need to include `giganum.h` which can be found in the `include` directory, and you'll link against `libgiganum.so`.
Do note that a giganum cannot interact directly with regular number types, so you'll have to create a new giganum for each number that needs to be a part of your operation, even if that number could be represented by a standard number type.

### Functions

#### giga_init

In your code, you can create a new giganum using `giga_init`:

```C
giganum_t* my_giganum = giga_init("123456789123456789123456789");
```

The `giga_init` function takes a `char*` of digits and returns a pointer to a `giganum_t`, or `NULL` if something went wrong.
The `giganum_t` pointed to by the return value of `giga_init` is dynamically allocated by the function, and so it is your responsibility to free it when you're finished with it.

#### giga_print

The `giga_print` function takes a pointer to a `giganum_t` and simply prints the string representation of the value of the passed in `giganum_t` pointer.

```C
giganum_t* my_giganum = giga_init("12345678901234567890");
giga_print(my_giganum);
```

#### giga_add

The `giga_add` function takes two `giganum_t` pointers, adds the values, and returns a pointer to a new `giganum_t` containing the summed value.
Remember that all of these pointers will need to be freed separately.

```C
giganum_t* my_giganum1 = giga_init("123456789");
giganum_t* my_giganum2 = giga_init("9876543210");
giganum_t* sum_result = giga_add(my_giganum1, my_giganum2);
```

#### giga_subtract

The `giga_subtract` function takes two `giganum_t` pointers, subtracts the second from the first, and returns a pointer to a new `giganum_t` containing the difference.
The value of the second `giganum_t` but be less than or equal to the value of the first.
Because negative values are not supported by libgiganum at all, having the second value larger than the first is considered undefined behavior.
Don't do it.
And as always, remember to free your pointers.

```C
giganum_t* my_giganum1 = giga_init("9876543210");
giganum_t* my_giganum2 = giga_init("123456789");
giganum_t* sum_result = giga_subtract(my_giganum1, my_giganum2);
```