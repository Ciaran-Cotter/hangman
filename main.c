#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void guess_check(char guess[], char avl_letters[], char guessed_letters[]){/* Function to check if a guess has been made before and if not, add the guess to a list of guess letters. 
Inputs: Guess, available letters and guessed_letters array.
Output: nothing
*/

	if (strchr(guessed_letters, *guess) == NULL){ //checks if guess has already been used
		strncat(guessed_letters, guess, 1); // if not then adds to list of used letters
		int i = 0;
		for (i=0; i<=strlen(avl_letters); i++){ // And remove from alpha list
			if(avl_letters[i] == *guess){
				avl_letters[i] = ' '; 
				continue;
			}
		}
	}
}





int main(void) { // Start main loop


FILE *file_pntr; // Creates pointer to point to file
int x; // Will be used to interate between words

file_pntr = fopen("words.txt", "r"); // Initialises file to pointer

if (!file_pntr){ // Checks if it opened
			printf("Failed to open");
			
}	

char word[475869]; //Creates a buffer where a read string from the txt file can be loaded and printed from. 

char skip[] = " %*s";
char end[] = " %s";
char add[] = " %*s";

srand ( time(NULL) ); //Seed the rand() function with time staring at the beggining of time which provides a new seed every game. 

int n = rand() % 55900; // Chooses a random number of words to skip when reading file to buff based on maximum value of 



int z = 0; // Loop to concantonate string "Skip" with "add" to build directions to skip the number of words selected. 
for (z=0; z<=n; ++z){
	strcat(skip, add);
	}

strcat(skip, end); // Adds the final %s at the end of the string to chose a word after all the skipped words. Its not pretty but it works. 



fscanf(file_pntr, skip ,word); // reads the file and imports the word to "buff". 



fclose(file_pntr); // Closes the file. 



int len = strlen(word);

//Initialise values
int attempts = 6; 
int correct_guesses = 0;
int correct_letters = 0;
char display_letters[len+1]; // Should start with an array holding _ values
char alpha[] = "abcdefghijklmnopqrstuvwxyz"; // Available guesses
char guessed_letters[sizeof(alpha)-len];
//printf("\n%s", alpha); //DB

// Start the game
printf("Welcome to Hangman!\n\nI am thinking of a word with " "%d" " letters.\n\nI will give you six attempts to guess all of the letters in it!\n", len);

//Creates the blanked out display word 


int i;
for (i = 0; i<= len; i++){
			strcat(display_letters, "_ ");			
}

// Main loop of the game.

printf("The word is: %s", display_letters);

while (attempts > 0){


//Take guess, add it to a list of letters and check if it has already been used. If it has been used then reject and continue. 
	printf("\nLetters available: %s", alpha);
	printf("\nYou have %d attempts left.\n", attempts);
	char guess[2];
	printf("Please make a guess?: ");
	scanf("%s", guess);
	
	// Check if letter has been guessed yet and update guessed list or reject
	guess_check(guess, alpha, guessed_letters);

	// Now we need to check if it is a correct guess or not. 	
	if (strchr(word, *guess) == NULL){ //checks if guess has already been used.
		//If guess is not in word then remove attempt and print incorrect dialogue and restart loop
			attempts = attempts - 1;
		printf("\nOops, That letter does not feature in the word I am thinking of!\n\n**********************************\n\nYou have %d attempts left.\n", attempts);
		//Check if game is over and escape if all attempts are used up. 
		if (attempts <= 0){
			printf("GAME OVER....you lose!\nThe word was %s", word);
			break;
		}	

	
	//If the letter is in the word than increase correct guesses, print correct guess dialogue and check if they have won and restart loop or end game. 
	}else{
		correct_letters = 0;
		
		printf("\nLuck Guess!\n\n**********************************\n\n");
		for (i=0; i<=strlen(word); i++){ // checks which letter is equal to guess and replaces the corresponding letter in the hidden letters with the guess. 
			if(*guess == word[i]){
				display_letters[i] = *guess;
				correct_letters = correct_letters + 1;

			}
		}
		correct_guesses = correct_guesses + correct_letters;
	//Win condition. Succesful letter guesses are equal to number of letters	
		if (correct_guesses == len){
			printf("Congratulations, You beat me!\n\nThe word was %s", word);
			break;
		}
		}
}	
}		
			


