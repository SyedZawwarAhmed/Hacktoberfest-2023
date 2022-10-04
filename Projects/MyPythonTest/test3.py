from pydoc import resolve
from pydoc_data.topics import topics


import random

def computer_number(x):

    print('++++++++++++++++++++++++++++')
    print('    bienvendio al juego ')
    print('++++++++++++++++++++++++++++')
    print(f'selecciona un numero entre 1 y {x} para que la computadora adivine ')

    base = 1
    top = x 

    resolve_number = ''
    while resolve_number !=  'c' :
        if  base != top:
            prediction = random.randint(base,top)
        else:
            prediction = base

        resolve_number = input(f'mi prediccion es {prediction}. si es muy alta ingresa (A), si es muy baja ingresa (B) y si es correcta ingresa (C): ').lower()    
        
        if resolve_number == 'a':
            top = prediction -1
        elif resolve_number == 'b':
            base = prediction + 1
    print(f'La computadora adivino el numero correcta mente : {prediction}')


computer_number(10)
        