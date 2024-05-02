<h1 align="center">
	<img src="https://github.com/lkilpela/42-project-badges/blob/main/badges/philosopherse.png" />

</h1>

<p align="center">
	<b><i>A Multithreaded Solution to the Dining Philosophers Problem</i></b><br>
</p>

<p align="center">
    <img alt="score" src="https://img.shields.io/badge/score-0%2F100-brightgreen" />
<p align="center">
    <img alt="solo" src="https://img.shields.io/badge/solo-yellow" />
    <img alt="estimated time" src="https://img.shields.io/badge/estimation-50%20hours-blue" />
    <img alt="XP earned" src="https://img.shields.io/badge/XP-1142-orange" />
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/lkilpela/pipex?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/lkilpela/philosophers?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/lkilpela/philosophers?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/lkilpela/philosophers?color=green" />
</p>

## 🍝 About The Project
`philosophers` is a multithreaded implementation of the classic Dining Philosophers problem.

Problem:

- The Dining Philosophers problem is a classic concurrency problem dealing with synchronization.
- It involves one or more philosophers sitting at a round table.
- The philosophers alternatively __eat__, __think__, or __sleep__.
- A fork is placed between each pair of adjacent philosophers. Each philosopher has one fork to the left and one fork to the right.
- As spaghetti is difficult to serve and eat with a single fork, it is assumed that a philosopher must eat with two forks.
- The challenge is to design a protocol that allows each philosopher to periodically stop thinking and eat without causing a deadlock.

Solution:

- Each philosopher is represented by a separate thread.
- The forks are represented by mutexes that control access to the shared resources (the forks).
- A philosopher picks up the fork on their right, then the fork on their left, before they start eating.
- After eating, a philosopher puts down both forks, then starts thinking.
- The simulation stops when a philosopher dies or when each philosopher has eaten a certain number of times.

## 🏁 Getting Started

### Prerequisites

- `gcc` or `clang`
- `make`

### 🛠️ Installation & Setup

1. Clone the repository: 
```
git clone https://github.com/lkilpela/philosophers.git
```
2. Navigate into the project directory: `cd philosophers/philo`
3. Compile the project: `make`

### 🚀 How to Use

1. Run the program with five parameters:

- `num_of_philos`: The number of philosophers.
- `time_to_die`: The time in milliseconds a philosopher will die if they don't start eating.
- `time_to_eat`: The time in milliseconds a philosopher spends eating.
- `time_to_sleep`: The time in milliseconds a philosopher spends sleeping.
- `num_times_to_eat` (optional): The number of times each philosopher must eat before the simulation ends.

2. Example:

- Do not test with more than 200 philosophers.
- Do not test with time_to_die or time_to_eat or time_to_sleep set to values lower than 60 ms.
- Test 1 800 200 200. The philosopher should not eat and should die.
- Test 5 800 200 200. No philosopher should die.
- Test 5 800 200 200 7. No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times.
- Test 4 410 200 200. No philosopher should die.
- Test 4 310 200 100. One philosopher should die.
- Test with 2 philosophers and check the different times: a death delayed by more than 10 ms is unacceptable.
- Test with any values of your choice to verify all the requirements. Ensure philosophers die at the right time, that they don't steal forks, and so forth.

## 📝 Evaluation Requirements

### 🧑‍💻 Peer Evaluations (3/3)

Here are some of the comments received during the peer evaluation of the `philosophers` project:

> **Peer 1**: "..."

> **Peer 2**: "..."

> **Peer 3**: "..."

## 📜 License

This project is licensed under the MIT License.