# documentation

## installation on Zorin OS

```sh
sudo apt-get install libncurses5-dev libncursesw5-dev
```

## compile

```sh
gcc main.c -o main -lncurses
# with modules example
gcc main.c seryio/seryio.c seryio-ncurses/seryio-ncurses.c -o main -lncurses 

gcc test.c -o test -lncurses
gcc test.c seryio/seryio.c seryio-ncurses/seryio-ncurses.c -o test -lncurses 
```

## pending tasks

1. refactor all code, comments and check if functions are pure
2. think naming standard for library elements