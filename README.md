<h1 align="center">
	🚰 PIPEX

</h1>

<p align="center">
	<b><i>Reproduction of a Unix pipe command (|) in C</i></b><br>
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

This project is a multithreaded implementation of the classic Dining Philosophers problem. The Dining Philosophers problem is a classic concurrency problem dealing with synchronization. It is a great way to get hands-on experience with threads and mutexes.

The problem consists of five philosophers sitting at a round table who do nothing but think and eat. In the center of the table is a bowl of spaghetti. A fork is placed between each pair of adjacent philosophers, and as such, each philosopher has one fork to the left and one fork to the right. As spaghetti is difficult to serve and eat with a single fork, it is assumed that a philosopher must eat with two forks. The philosopher can only use the fork on his immediate right or immediate left.

The challenge is to design a protocol that allows each philosopher to periodically stop thinking and eat without causing a deadlock. Each philosopher is a separate thread, and each pair of forks can be accessed by two threads. The philosophers' names are numbers from 0 to 4 and the forks are numbers from 0 to 4, each shared by two philosophers. The threads are created in the main function. Each philosopher thinks, then eats, then sleeps, in a loop. The simulation stops when a philosopher dies or when each philosopher has eaten a certain number of times.

This project is a great way to learn about the challenges of concurrent programming and how to use synchronization primitives like mutexes to solve them.

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

## 📝 Evaluation Requirements

### 🧑‍💻 Peer Evaluations (3/3)

Here are some of the comments received during the peer evaluation of the `philosophers` project:

> **Peer 1**: "..."

> **Peer 2**: "..."

> **Peer 3**: "..."

## 📜 License

This project is licensed under the MIT License.