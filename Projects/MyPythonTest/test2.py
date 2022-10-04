import random
def  find_number(x):
    print('=====================')
    print('bienvenido al juego')
    print('=====================')
    
    random_number = random.randint(1, x)

    prediction = 0

    while prediction != random_number:
        prediction = int(input(f'dime un numero  entre 1 y {x}: '))
        if prediction < random_number:
            print('numero muy pequeño')
        else:
            print('numero muy grande')

    print(f'felicidades el numero es {random_number}') 


choose_number = int(input('dime un numero: '))
find_number(choose_number)
