#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNum();
float getBetAmount(float playerBalance);
void getPlayerBalance(float playerBalance);
int getPlayerChoice();
int getGameResult(int playerChoice, int diceNum, float betAmount);



int main()
{
    srand(time(NULL));


    float playerBalance = 200;


    printf("\nWELCOME TO DICE GAME!\n");
    printf("Enter a number (1 - 6) to bet, or 0 to quit.\n"); 
    getPlayerBalance(playerBalance);



    do
    {
        int diceNum = randomNum();

        int playerChoice = getPlayerChoice();
        if(playerChoice == 0)
        {
            break;
        
        }

        float betAmount = getBetAmount(playerBalance);
        printf("Dice rolled: %d\n", diceNum);
        
        float gameResult = getGameResult(playerChoice, diceNum, betAmount);

        playerBalance += gameResult;
        getPlayerBalance(playerBalance);

    } while (playerBalance > 0);

    if (playerBalance <= 0)
    {
        printf("\nGame over. Your balance is $0. Better luck next time!\n");
    }
    else
    {
        printf("\nCashing out... Final balance: $%.2f\n", playerBalance);
    }
    
    

    return 0;
}

int randomNum()
{
    return (rand() % 6) + 1;
}

void getPlayerBalance(float playerBalance)
{
    printf("Player balance: $%.2f\n", playerBalance);
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
        else if (betAmount <= 0)
        {
            printf("Bet must be greater than 0.\n");
        }
        
    } while (betAmount > playerBalance || betAmount <= 0);

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

    winAmount = betAmount * 3;
    loseAmount = betAmount;

    if(playerChoice == diceNum)
    {
        printf("\nCongratulations! You won $%.2f!\n", winAmount);
        return winAmount;
    }
    else
    {
        printf("\nYou lost $%.2f. Better luck next time.\n", betAmount);
        return -betAmount;
    }
}