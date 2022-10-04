from operator import truediv
import random
def play ():
    user = input('escoge una opcion  pi = piedra pa = papel ti = tigera :\n').lower()
    computer = random.choice(['pi', 'pa', 'ti' ])
    print(f'la computadora escogio {computer}')

    if user == computer:
        return 'Empate'
    
    if player_win(user, computer):
        return 'Ganaste'

    return 'perdiste'    

def player_win(player,computer):
    if( (player == 'pi' and computer =='ti') 
        or ( player == 'ti' and computer =='pa' )
        or ( player == 'pa' and computer =='pi' )):
        return True
    else:
        return False

print(play())        