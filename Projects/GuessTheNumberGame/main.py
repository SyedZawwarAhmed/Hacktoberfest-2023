# Guess the number game

import math
import random

welcome = """

_ _ _ ____ _    ____ ____ _  _ ____    ___ ____    ___  _   _ ___ _  _ ____ _  _ 
| | | |___ |    |    |  | |\/| |___     |  |  |    |__]  \_/   |  |__| |  | |\ | 
|_|_| |___ |___ |___ |__| |  | |___     |  |__|    |      |    |  |  | |__| | \| 
                                                                                 

"""

title = """

____ _  _ ____ ____ ____    ___ _  _ ____    _  _ _  _ _  _ ___  ____ ____ 
| __ |  | |___ [__  [__      |  |__| |___    |\ | |  | |\/| |__] |___ |__/ 
|__] |__| |___ ___] ___]     |  |  | |___    | \| |__| |  | |__] |___ |  \ 
                                                                           

"""

game = """

____ ____ _  _ ____ 
| __ |__| |\/| |___ 
|__] |  | |  | |___ 
                    

"""

print(f"{welcome}\n{title}\n{game}")

# random number (below line of code generates a randome number in range [1, 20])
random_number = math.floor(random.random() * 20) + 1

# number of available guesses to the player
number_of_chances = 10

PLAYER_NAME = input("Enter your name: ")
print("Welcome " + PLAYER_NAME)

flag = False
while not flag:
    level_of_game = input("Choose the level of the game:\n(E) Easy\t(M) Medium\t(H) Hard\n")
    
    if (level_of_game == "e" or level_of_game == "m" or level_of_game == "h" or level_of_game == "E" or level_of_game == "H" or level_of_game == "M"):
        flag = True
    else:
        print("Enter a valid value")
    

if (level_of_game == "e" or level_of_game == "E"):
    print("Level of game is set to Easy\n")
elif (level_of_game == "m" or level_of_game == "M"):
    print("Level of game is set to Medium\n")
    number_of_chances = 7
else:
    print("Level of game is set to Hard\n")
    number_of_chances = 5
    
print("You have got " + str(number_of_chances) + " guesses")

is_game_over = False
while not is_game_over:
    if (number_of_chances == 0):
        is_game_over = True
        print("You Lose 😭, Better luck next time!")
    else:
        guess = int(input("Enter your guess:\t"))
        if (guess < random_number):
            print("Guess bigger number🔢\n")
            number_of_chances -= 1
        elif (guess > random_number):
            print("Guess smaller number🔢\n")
            number_of_chances -=1
        elif (guess == random_number):
            print("Congratulations!🥳, you guessed correctly")
            break