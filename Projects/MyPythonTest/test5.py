import random
import string

words_list = ['aire', 'ojos', 'dedo', 'diente', 'tierra']

def get_word(words):
    word = random.choice(words).upper()
    while '-' in word or ' ' in word:
        word = random.choice(words)
    return word.upper()


def game():
    print('+++++++++++++++++++++')
    print('     Bienvenido ')
    print('+++++++++++++++++++++')
    word = get_word(words_list)
    rest_words = set(word)
    get_words = set()
    abc = set(string.ascii_uppercase)
    lives = 7
    
    while len(rest_words) > 0 and  lives > 0 :
        print(f"Te quedan {lives} vidas y has usado estas letras: {' '.join(get_words)}")
        
        show_words = [letter if letter in get_words else '-' for letter in word]
        
        print(f"palabras: {' '.join(show_words)}")

        letter_user = input('escoge una letra : ').upper()

        if letter_user in abc  - get_words :
            get_words.add(letter_user)

            if letter_user in rest_words:
                rest_words.remove(letter_user)
                print('')
            else:
                lives = lives - 1
                print(f'\ntu letra, {letter_user} no esta en la palabra ')
        elif letter_user in get_words:
            print('ya has usado esta letra')
        else:
            print('caracter no valido')
    print(f'la palabra era {word}')
    if lives == 0:
        print('game over')
    else:
        print('Ganaste')

game()