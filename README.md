# documentation

## installation on Zorin OS

```sh
sudo apt-get install libncurses5-dev libncursesw5-dev
```

## compile

```sh
gcc main.c -o main -lncurses
# with module example
gcc main.c arithmetics/arithmetics.c -o main -lncurses 
```