# Dice Betting Game

A simple command line dice betting game written in C.

The player starts with a balance and bets money on a number between 1 and 6.  
A dice is rolled randomly and if the player guesses correctly, they win money. Otherwise, they lose their bet.

## Features

- Random dice rolling
- Player betting system
- Balance tracking
- Input validation
- Game loop until player quits or runs out of money

## How It Works

1. The player starts with a balance of $200
2. The player chooses a number between 1 and 6
3. The player enters a bet amount
4. The program rolls a random dice
5. If the guess is correct:
   - Player wins 3x the bet
6. If incorrect:
   - Player loses the bet
7. The balance is updated after each round
8. The game continues until:
   - Player chooses 0 (quit)
   - Balance reaches 0

## Technologies

- C programming language
- Standard C libraries
- `stdlib.h` for random numbers
- `time.h` for random seed

## What I Learned

- Using functions to organize code
- Random number generation with `rand()`
- Input validation and loops
- Managing player balance
- Implementing game logic
- Using return values to update state

## Example

WELCOME TO DICE GAME!

Player balance: $200.00

Enter your chosen dice number: 3  
Enter your bet amount: $50  

Dice rolled: 3  

Congratulations! You won $150.00!  

Player balance: $350.00  

## Author

Software engineering student at ITS
