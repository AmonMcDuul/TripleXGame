#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "You are a hacker and need to hack into the mainframe..\n";
    std::cout << "You are on stage " << Difficulty << "\n";
    std::cout << "Enter the correct codes to continue...\n\n";
}

bool PlayGame(int level)
{
    PrintIntroduction(level);
    const int CodeA = rand() % level + level;
    const int CodeB = rand() % level + level;
    const int CodeC = rand() % level + level;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    //Rules
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add up to: " << CodeSum << "\n";
    std::cout << "+ The codes multiply to give: " << CodeProduct << "\n";

    //Player input
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check winconditions
    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "Code is correct. \n";
        return true;
    }
    else
    {
        std::cout << "The code is false. Mainframe is locked.\nTry again!\n\n";
        return false;
    }
}

void WinGame()
{
    std::cout << "\nYou have hacked all stages of the mainframe\nYou have won!!!";
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int MaxLevel = 5;
    while (LevelDifficulty <= MaxLevel)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();  //clears errors
        std::cin.ignore(); //discards buffer
        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    WinGame();
    return 0;
}
