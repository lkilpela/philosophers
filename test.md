# Error handling
1. less than 5 args
./philo 
2. Number of philos: less than/ equal 0 and larger than 200
./philo 0 800 200 200
./philo 201 800 200 200
3. Time to eat/sleep/die < 60
Time to die < 60
./philo 200 59 200 200

Time to eat < 60
./philo 200 60 59 200

Time to sleep < 60
./philo 200 60 200 59

4. Number of times each philo must eat (optional argument)
No input provided -> set a default value of 0 and return promp
Non-integer or <= 0 provide -> display error
./philo 200 60 200 200 f
./philo 200 60 200 200 -1
NEED TO CHECK IF OPTIONAL ARGUMENT 0 is valid input.

# philo code

Check there is one thread per philosopher.
Check there is only one fork per philosopher.
Check if there is a mutex per fork and that it's used to check the fork value and/or change it.
Check the outputs are never mixed up.
Check how the death of a philosopher is verified and if there is a mutex to prevent a philosopher from dying and starting eating at the same time.

# philo testing

Do not test with more than 200 philosophers.
Do not test with time_to_die or time_to_eat or time_to_sleep set to values lower than 60 ms.
Test 1 800 200 200. The philosopher should not eat and should die.
Test 5 800 200 200. No philosopher should die.
Test 5 800 200 200 7. No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times.
Test 4 410 200 200. No philosopher should die.
Test 4 310 200 100. One philosopher should die.
Test with 2 philosophers and check the different times: a death delayed by more than 10 ms is unacceptable.
Test with any values of your choice to verify all the requirements. Ensure philosophers die at the right time, that they don't steal forks, and so forth.

# philo_bonus testing
Do not test with more than 200 philosophers.
Do not test with time_to_die or time_to_eat or time_to_sleep set to values lower than 60 ms.
Test 5 800 200 200. No philosopher should die.
Test 5 800 200 200 7. No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times.
Test 4 410 200 200. No philosopher should die.
Test 4 310 200 100. One philosopher should die.
Test with 2 philosophers and check the different times: a death delayed by more than 10 ms is unacceptable.
Test with any values of your choice to verify all the requirements. Ensure philosophers die at the right time, that they don't steal forks, and so forth.
