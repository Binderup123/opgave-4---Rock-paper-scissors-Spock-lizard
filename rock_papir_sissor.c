#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funktion til at vise menu
void showMenu() // en funktion for start menuen som gør det nemmer fremkalde når programmer skla køre
{
    printf("\nVælg en figur:\n");
    printf("1) Rock\n");
    printf("2) Paper\n");
    printf("3) Scissors\n");
    printf("4) Lizard\n");
    printf("5) Spock\n");
    printf("q) Afslut\n");
    printf("Dit valg: ");
}

int getWinner(int player, int computer)  // funtion der bestemmer vinderen ud fra det som er givet
{
    if (player == computer) return 0;

    // Alle vinder-regler
    if ((player == 1 && (computer == 3 || computer == 4)) || // Rock slår Scissors og Lizard
        (player == 2 && (computer == 1 || computer == 5)) || // Paper slår Rock og Spock
        (player == 3 && (computer == 2 || computer == 4)) || // Scissors slår Paper og Lizard
        (player == 4 && (computer == 2 || computer == 5)) || // Lizard slår Paper og Spock
        (player == 5 && (computer == 1 || computer == 3)))   // Spock slår Rock og Scissors
    {
        return 1; // Spiller vinder
    }

    return -1; // Computer vinder
}

const char* getName(int choice) ///laver brugeresnsvar og til text / en string
{
    switch (choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        case 4: return "Lizard";
        case 5: return "Spock";
        default: return "Ukendt";
    }
}

int main() {
    char input[10]; //
    int playerChoice, computerChoice;
    int playerScore = 0, computerScore = 0;

    printf("Velkommen til Rock, Paper, Scissors, Lizard, Spock!\n");

    int  spill = 1; // en variable der gør at spillet kan køre i en loop
    while (spill == 1) 
    {
        showMenu();
        if (!fgets(input, sizeof(input), stdin)) break;

        if (input[0] == 'q' || input[0] == 'Q') 
        {
            printf("Spillet afsluttes...\n");
            break; // gør bare at den stopper her og ikke køre resten af loopppet'
        }


        playerChoice = atoi(input); //konvertere fra tastatur til en variable nit

        if (playerChoice < 1 || playerChoice > 5)  // validere om dt intastede er under 0 eller over 5 og sikre at bruegn kun kans vare med 1-5 
        {
            system("cls");
            printf("Ugyldigt valg. Prøv igen.\n");
            continue;
        }
        
        system("cls");
        computerChoice = (rand() % 5) + 1; //generaere et random ral mellem 1 og 5 bestemt af at talet er modulos 5 og for at sikre det ikke er 0 siger vi så +1 
        printf("Du valgte: %s\n", getName(playerChoice));
        printf("Computeren valgte: %s\n", getName(computerChoice));

        int result = getWinner(playerChoice, computerChoice); // køre vores funktion til at finde vinderen fra tidligere

        if (result == 0) 
        {
            printf("Uafgjort!\n");
        } else if (result == 1) {
            printf("Du vandt denne runde!\n");
            playerScore++;
        } else {
            printf("Computeren vandt denne runde!\n");
            computerScore++;
        }

        printf("Score -> Spiller: %d | Computer: %d\n", playerScore, computerScore);
    }

    printf("\nSlutstilling -> Spiller: %d | Computer: %d\n", playerScore, computerScore);
    printf("Tak for spillet!\n");

    return 0;
    spill = 0; // gør at spillet stopper når
}
