import random
import string

WORDLIST_FILENAME = "words.txt"

def load_words():
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print ("Loading word list from file...")
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r')
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = line.split(" ")
    print ("  ", len(wordlist), "words loaded.\n\n**********************************\n\n")
    return wordlist

def choose_word(wordlist):
    """
    wordlist (list): list of words (strings)

    Returns a word from wordlist at random
    """
    return random.choice(wordlist)

wordlist = load_words()

#Selects the random word, calculates its lenght and convertes to a list. 
word = (random.choice(wordlist))
word_lenght = len(word)
list_letters = list(word)

#Initialise values
attempts = 6
correct_guesses = 0
guessed_letters = []
alpha = string.ascii_lowercase


#Start of the game 
print ('Welcome to Hangman!\n\nI am thinking of a word with', word_lenght ,'letters.\n\nI will give you six attempts to guess all of the letters in it!\n')

#Creates the blanked out display word 
letter = -1
display_letters = []
for i in range(0, len(word)):
	display_letters += ("_")

#Main game loop of guessing and updating the letters in the display word. 
while attempts > 0:

	print ('The word is: ',display_letters)

	#Take guess, add it to a list of letters and check if it has already been used. If it has been used then reject and continue. 
	print('Available letters:',alpha)
	print('\nYou have',attempts ,'attempts left.\n')
	guess = input('Please make a guess?: ')
	if guess in guessed_letters:
		print ('\nYou have already used that letter! Try again.\n')
		continue
	else:
		guessed_letters += guess
		alpha = alpha.replace(guess, '')

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
			break

		

print('Please play again.') 
	
