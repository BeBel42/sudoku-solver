# sudoku-solver
A program that can solve Sudokus with any possible dimensions and characters.

## installation
- clone/download this repository.
- open the terminal in the directory.
- run ```make```

## usage
inout:

```./solve 530070000600195000098000060800060003400803001700020006060000280000419005000080079```

output:

```
|-----------|
|534|678|912|
|672|195|348|
|198|342|567|
|-----------|
|859|761|423|
|426|853|791|
|713|924|856|
|-----------|
|961|537|284|
|287|419|635|
|345|286|179|
|-----------|
```

Keep in mind that '0'(zero) is the character used to represent empty spaces.

The program ignores whitespace characters in the input, so this input is equivalent to the first one:

```
./solve "
530 070 000
600 195 000
098 000 060

800 060 003
400 803 001
700 020 006

060 000 280
000 419 005
000 080 079 
"
```

This program also accepts other dimensions and charcter lists:

Example of a 16x16 grid:

input:

```
./solve 123456789abcdefg 0eg040d7c010f0600d609000f00000009a08000g00053020b0003c002e000d0a0006a00b400c0090f8a00902e360d5104905000cg0b070e002bg100e000860400600b0000000003005006003097001bf040f50093b00c60d0g008001650007040040cb0090000g526082000004c003000c510460bd0008f9a09d2835070g00c6

```

output:

```
|-------------------|
|2eg3|4ad7|c81b|f965|
|5d64|92e8|fga3|bc71|
|9ac8|f1bg|76d5|342e|
|b1f7|3c56|2e49|8dga|
|-------------------|
|d7e6|a3fb|415c|g298|
|f8ac|g942|e367|d51b|
|4915|d68c|g2bf|7ae3|
|32bg|157e|da98|6f4c|
|-------------------|
|8679|bd24|acf1|5e3g|
|c5da|6eg3|8974|21bf|
|142f|57a9|3bge|c68d|
|eg3b|8fc1|652d|97a4|
|-------------------|
|734e|cb1d|9f86|ag52|
|6b82|eg9f|54ca|13d7|
|gc51|746a|bd32|e8f9|
|af9d|2835|17eg|4bc6|
|-------------------|

```

The first parameter is the used characters list. The second one is the grid.

The list cannot contain whitespace characters or the '0'(zero) character.

Have fun!

