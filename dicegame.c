#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int randomNum();
float getBetAmount(float playerBalance);
float getPlayerBalance(float playerBalance);
int getPlayerChoice();
int getGameResult(int playerChoice, int diceNum, float betAmount);

int winsCounter = 0;
int winStreak = 0;
int maxStreak = 0;
int gamesPlayed = 0;


int main()
{
    srand(time(NULL));

    float playerBalance = 0;
    float startingBalance;
    float maxBalance;

    printf("\nWELCOME TO DICE GAME!\n");
    printf("Enter a number (1 - 6) to bet, or 0 to quit. Minimum bet is $10.\n"); 

    playerBalance = getPlayerBalance(playerBalance);

    startingBalance = playerBalance;
    maxBalance = playerBalance;

    do
    {
        int diceNum = randomNum();

        int playerChoice = getPlayerChoice();
        if(playerChoice == 0)
        {
            break;
        }

        float betAmount = getBetAmount(playerBalance);

        printf("\nRolling the dice...\n");

        usleep(2000000);
        printf("Dice rolled: %d\n", diceNum);
        
        float gameResult = getGameResult(playerChoice, diceNum, betAmount);

        playerBalance += gameResult;
        if(playerBalance > maxBalance)
        {
            printf("\nNew peak balance reached: $%.2f!\n", playerBalance);
            maxBalance = playerBalance;
        }
        else
        {
            printf("Player balance: $%.2f\n", playerBalance);

        }
        

    } while (playerBalance > 0);


    if (gamesPlayed > 0)
    {
            if (playerBalance <= 0)
        {
            printf("\nGame over. Your balance is $0. Better luck next time!\n");
        }
        else if(playerBalance < startingBalance)
        {
            printf("\nCashing out... You started with $%.2f and lost $%.2f. Final balance: $%.2f.\n", startingBalance, startingBalance - playerBalance, playerBalance);
        } 
        else if (playerBalance > startingBalance)
        {
            printf("\nCashing out... Well played! You started with $%.2f and gained $%.2f. Final balance: $%.2f.\n", startingBalance, playerBalance - startingBalance, playerBalance);

        }
        else if (playerBalance == startingBalance)
        {
            printf("\nEven game. Your final balance remains $%.2f.\n", playerBalance);
        }

        printf("\n--- Session Summary ---\n");

        printf("Total rounds: %d\n", gamesPlayed);
        printf("Wins: %d\n", winsCounter);
        printf("Win percentage: %.2f%%\n", (float)winsCounter / gamesPlayed * 100);
        
        printf("\nHighest balance reached: $%.2f\n", maxBalance);
        printf("Longest win streak: %d\n", maxStreak);
        printf("\n");
    }
    else
    {
        printf("\nSession ended without any rounds played.\n");
    }
    
    return 0;
}

int randomNum()
{
    return (rand() % 6) + 1;
}

float getPlayerBalance(float playerBalance)
{
    do
    {
        printf("Set your starting balance (max $1000): $");
        scanf("%f", &playerBalance);
    } while (playerBalance > 1000);

    return playerBalance;

}

float getBetAmount(float playerBalance)
{
    float betAmount;

    do
    {
        printf("\nEnter your bet amount: $");
        scanf("%f", &betAmount);
        if(betAmount > playerBalance)
        {
            printf("Insufficient funds. Current balance: $%.2f\n", playerBalance);
        }
        else if (betAmount < 10)
        {
            printf("Bet must be at least $10.\n");
        }
        
    } while (betAmount > playerBalance || betAmount < 10);

    return betAmount;

}

int getPlayerChoice()
{
    int playerChoice;
    do
    {
        printf("\nEnter your chosen dice number: ");
        scanf("%d", &playerChoice);

    } while (playerChoice < 0 || playerChoice > 6);
    
    return playerChoice;

}

int getGameResult(int playerChoice, int diceNum, float betAmount)
{
    float winAmount;
    float loseAmount;


    gamesPlayed++;


    if(playerChoice == diceNum)
    {
        if (winStreak >= 2)
        {
            winAmount = betAmount * 5;
            winsCounter++;
            winStreak++;

            if(winStreak > maxStreak){
                maxStreak = winStreak;
            }

            printf("\n%d wins in a row! You earned a 5x bonus!\n", winStreak);
            printf("You won $%.2f!\n", winAmount);

            return winAmount;
        }
        
        winAmount = betAmount * 3;
        winsCounter++;
        winStreak++;

        if(winStreak > maxStreak){
            maxStreak = winStreak;
        }

        printf("\nCongratulations! You won $%.2f!\n", winAmount);

        return winAmount;
    }
    else if((playerChoice == diceNum + 1 || playerChoice == diceNum - 1) && winStreak >= 2)
    {

        winAmount = betAmount * 1.5;
        winStreak = 0;

        printf("\nSo close! Thanks to your streak, you receive a small bonus of $%.2f.\n", winAmount);
        return winAmount;

    }
    else
    {
        loseAmount = betAmount;
        winStreak = 0;
        printf("\nYou lost $%.2f. Better luck next time.\n", betAmount);

        return -loseAmount;
    }

}
