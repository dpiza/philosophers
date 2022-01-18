# Philosophers

![42-Badge](https://img.shields.io/badge/%C3%89cole-42SP-blue)![C-Badge](https://img.shields.io/badge/Language-C-lightgrey)[![42Unlicense](https://img.shields.io/badge/License-42Unlicense-yellowgreen)](https://github.com/gcamerli/42unlicense)![WorkingProgress](https://img.shields.io/badge/WORK-IN%20PROGRESS-red)

## Description

This project is a multi-thread philosopher's life simulation.

## Goals

The objective of this project is to learn the basics of threading a process and the use of mutex.

## Global Rules

• Global variables are forbidden!

• Each philosopher has a number ranging from 1 to number_of_philosophers.

• Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.

• Your(s) program(s) should take the following arguments:


|Argument|Description|
|-|-|
|anumber_of_philosophers|The number of philosophers and also the number of forks.|
|time_to_die (in milliseconds)|If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.|
|time_to_eat (in milliseconds)|The time it takes for a philosopher to eat. During that time, they will need to hold two forks.|
|time_to_sleep (in milliseconds)| The time a philosopher will spend sleeping.|
|number_of_times_each_philosopher_must_eat (optional argument)|If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.|

### Logs

• A displayed state message should not be mixed up with another message.

• A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher.

• Any state change of a philosopher must be formatted as follows:

```Shell
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
```

## Mandatory

• Each philosopher should be a thread.

• There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.

• To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them.

## Bonus

• All the forks are put in the middle of the table.

• They have no states in memory but the number of available forks is represented by a semaphore.

• Each philosopher should be a process. But the main process should not be a philosopher.


## Usage

``WORK IN PROGRESS``

![](https://github.com/dpiza/resources/blob/master/gifs/jimc.gif?raw=true)

## License

This work is published under the terms of [42 Unlicense](https://github.com/gcamerli/42unlicense)