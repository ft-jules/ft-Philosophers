# Philosophers

The dining philosophers problem in C, with POSIX threads and mutexes, a 42 school project. N philosophers sit around a table with one fork between each pair. They eat, sleep and think in turn, and the program stops as soon as one of them starves, or once each has eaten a given number of times.

## How it is organised

Each philosopher is a thread and each fork is a mutex. Even philosophers take their right fork first and odd ones their left, so the waits can never close into a cycle and the table cannot deadlock. A monitor thread checks every millisecond or so whether a philosopher has gone longer than `time_to_die` without eating, and whether all of them have eaten enough. All shared state is behind mutexes, and output goes through a print lock so that lines never mix.

```
philo/inc/philo.h       the two structures (one philosopher, the shared table) and the prototypes
philo/srcs/philo.c      main: parse, start, clean up
philo/srcs/inits.c      argument parsing, forks and mutexes
philo/srcs/routine.c    the philosopher threads: take two forks, eat, sleep, think
philo/srcs/monitor.c    the monitor thread: deaths and meal count
philo/srcs/utils.c      time in ms, the locked print, freeing
```

## Build

A C compiler and pthreads, no other dependency. The Makefile builds with `-Wall -Wextra -Werror`.

```
cd philo
make
```

## Run

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [meals]
```

Times are in milliseconds. `meals` is optional: without it, the simulation runs until a philosopher dies. Each line of output is a timestamp in ms, the philosopher's number and what they do.

```
./philo 5 800 200 200       nobody should die
./philo 5 800 200 200 7     stops once each philosopher has eaten 7 times
./philo 4 310 200 100       a philosopher dies
./philo 1 800 200 200       one fork only: the philosopher dies at 800 ms
```
