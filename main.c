#include <stdio.h>
#include <string.h>

int main(void) { // Start main loop

char word[] = "Hangman";	// Assign main word as Hangman for now
printf("%s", word); //DB
int len = strlen(word);
printf("\n%d", len); //DB

//Initialise values
int attempts = 6; 
int correct_guesses = 0;
char guessed_letters[len+1]; // Should start with an array holding _ values
char alpha[] = "abcdefghijklmnopqrstuvwxyz"; // Available guesses
printf("\n%s", alpha); //DB

// Start the game
printf("Welcome to Hangman!\n\nI am thinking of a word with " "%d" " letters.\n\nI will give you six attempts to guess all of the letters in it!\n", len);

//Creates the blanked out display word 


int i;
for (i = 0; i<= len; i++){
			strcat(guessed_letters, "_ ");			
}

// MAin loop of the game.

printf("The word is: %s", guessed_letters);

while (attempts > 0){


//Take guess, add it to a list of letters and check if it has already been used. If it has been used then reject and continue. 
	printf("\nAvailable letters: %s",alpha);
	printf("\nYou have %d" ,attempts ,"attempts left.\n");
	char guess[2];
	scanf("Please make a guess?: %c", guess)
	if guess in guessed_letters:
		print ('\nYou have already used that letter! Try again.\n')
		continue
	else:
		guessed_letters += guess
		alpha = alpha.replace(guess, '')*/


}






/* Main game loop of guessing and updating the letters in the display word. 
while attempts > 0:


	

	#Checks if the guess is in the word or not and carries out the appropriate response.
	if word.find(guess) >= 0: 
		#Correct anwser response: Creates a list showing the index of correct letter guesses in the word then replaces the values in the blanked out display word with the correct letter guesses.
		print ('\nLucky Guess!.\n\n**********************************\n\n') 	
		correct_letters = ([i for i, char in enumerate(list_letters) if char == guess])
		for i in range(0, len(correct_letters)):
			display_letters[correct_letters[i]] = guess
		
		#Adds the correct letter found including multiples.
		correct_guesses += (1*(len(correct_letters)))
		
		#Win condition, Checks if all the letters have been guessed correctly and exits the loop.
		if correct_guesses == word_lenght:
			print('Congratulations, You beat me!\n\nThe word was', word)
			break

	#Incorrect answer response: Reduces the attempts by one. If the attempts have run out then then pronts Game over response and exits loop. 
	else:
		attempts -= 1
		print('\nOops, That letter does not feature in the word I am thinking of!\n\n**********************************\n\nYou have',attempts ,'attempts left.\n')
		if attempts <= 0:
			print('GAME OVER....you lose!\nThe word was', word)
			break */

		



}