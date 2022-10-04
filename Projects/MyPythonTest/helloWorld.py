#from datetime import timedelta
import datetime
print(datetime.date.today())

name = 'eric eladio'
print('hello ' + name)
print('hello {0}'.format(name))
print(f'hello {name}')
print(dir(name)) #dice los metodos
name.lower()
name.upper()
print(name.replace('eric', 'erik'))
name.count("e")
name.startswith('eladio')
name.endswith('eladio')
name.split()
name.split(',')
name.find('o')
name.isnumeric()
name.isalpha()
name[0] # e
len(name) #lenght
print(type('hello world'))
print(type(None))
print(type([10,20.30])) #list
print(type((10,20.30))) #tuple es inmutable
print(type({'nombre': 'eric', id:'0000'})) #dict


age = input('ínserta tu edad')
print(age)
int(age)

r = list(range(1,10)) #crea una lista
print( 1 in r)
r.append(100)
r.extend([101, 102])
r.insert(0 , 'numeros')
r.pop() # elimina el ultimo elemento
r.pop(23) # elimina por index
r.remove(100)
r.clear()
r.sort()
r.sort(reverse =true)
r.index('numeros')


#sets

colors = {'red','blue','green'} # no tienen indice
del colors # elimina colors

#dict
person = {
    'name':'eric',
    'id': 00
} 

person.keys()

if true :
    print('hi')
elif  !true :
    print('know')
else:
    print('bye') 

if 2 > 1 and 1 < 2
#if 2 > 1 or 1 < 2
#if (not(x == y))
    print('ok')

#loops
foods ['candy', 'bread' ,'pasta']

for food in foods:
    print(food)

while count <= 10:
    print(count)

# function 
def hi(name):
    print(f'hi {name}')

hi('eric')

add = lambda person, family : person + family


add(15, 10)
