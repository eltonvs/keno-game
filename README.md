# Keno Game

The **Keno Game** is a gambling game like a lottery or bingo.

This game consists in **set a bet** picking a set of, at most, 15 numbers in range `[1, 80]`, **set the number of rounds** and **set a wage** that will be equally divided between the rounds.

After that, you just need to pray for the best :pray:, because the algorithm is in charge of pick a set with twenty unique randomly generated numbers (in the same original range) and compare with your bet.

In this game, you leave with a positive balance according with your wage and the amount of correct bets in each round.

## How to Play
To play this game you just need to load your bet file into `data` folder (with your preferer plain text extension `.dat`, `.txt`, `.in`, ...), compile it and run the executable.

To compile, you just need to put this on terminal:

```shell
$ make
```

And to execute:
```shell
$ ./bin/keno your_bet_file.dat
```

** If no bet file was specified, the program will run with an demo bet file (located in `data/default_bet.dat`).

### Debugging
If you want to debug this game, use our debug version (with the `-g -O0` flags):

```shell
$ make debug
$ ./bin/debug your_bet_file.dat
```

So, after that you can use the gdb or valgrind just putting:
```shell
# To GDB
$ gdb bin/debug

# To valgrind
$ valgrind --leak-check=yes bin/debug
```

## Authors
 - Elton de Souza Vieira
 - Pedro Arthur Medeiros Fernandes

