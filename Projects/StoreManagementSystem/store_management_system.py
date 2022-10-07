import mysql.connector as mycon
from prettytable import PrettyTable
import datetime
from os import system
mydb = mycon.connect(host='localhost',user='root',password='123',database='store')
cur = mydb.cursor()
cur.execute("use store")

def clear():
    _=system('CLS')

def p_exists(a):
    code="select count(*) from products where p_id='{}'".format(a)
    cur.execute(code)
    for x in cur:
        c=x[0]
        if c==0:
            return False
        else:
            return True

def print_message(a):
    print('\n')
    print('\t\t\t\t\t','*'*(len(a)+6))
    print('\t\t\t\t\t','*'*(len(a)+6))
    print('\t\t\t\t\t','**',' '*(len(a)),'**')
    print('\t\t\t\t\t','**',a,'**')
    print('\t\t\t\t\t','**',' '*(len(a)),'**')
    print('\t\t\t\t\t','*'*(len(a)+6))
    print('\t\t\t\t\t','*'*(len(a)+6))

def add_prod():
    p_id=input("\n\n\t\t\t\t\tENTER PRODUCT ID : ")
    if p_exists(p_id):
        print_message(" A PRODUCT ALREADY EXISTS WITH THIS PRODUCT ID ")
    else:
        pname=input("\n\t\t\t\t\tENTER PRODUCT NAME : ")
        cat=input("\n\t\t\t\t\tENTER PRODUCT CATEGORY :")
        price=int(input("\n\t\t\t\t\tENTER THE PRICE OF THE PRODUCT : "))
        qty=int(input("\n\t\t\t\t\tENTER THE QUANTITY : "))
        remark=input("\n\t\t\t\t\tENTER PRODUCT REMARKS : ")
        query="insert into products values({},'{}','{}',{},{},'{}')".format(p_id,pname,cat,price,qty,remark)
        cur.execute(query)
        mydb.commit()
        print_message("  PRODUCT ADDED  ")

def disp_p_all():
    x=PrettyTable(['PRODUCT ID','PRODUCT','CATEGORY','PRICE','QUANTITY','REMARKS'])
    cur.execute("select * from products")
    res=cur.fetchall()
    if len(res)==0:
        print_message("  NO RECORDS  ")
    else:
        l=[]
        for i in res:
            l.append(i)
        x.add_rows(l)
    print_message(" ALL THE PRODUCTS PRESENT IN RECORDS ")
    print(x)

def disp_p_cat():
    cat=input("\n\t\t\t\t\tENTER PRODUCT CATEGORY TO VIEW CORRESPONDING PRODUCTS : ")
    query="select * from products where category='{}'".format(cat)
    cur.execute(query)
    res=cur.fetchall()
    if len(res)==0:
        print_message(" NO PRODUCTS FOUND WITH THE GIVEN CATEGORY ")
    else:
        x=PrettyTable()
        x.field_names=['PRODUCT ID','PRODUCT','CATEGORY','PRICE','QUANTITY','REMARKS']
        l=[]
        for i in res:
                l.append(i)
        x.add_rows(l)
    print_message(" PRODUCTS WITH GIVEN CATEGORY ")
    print(x)

def disp_p_remark():
    remark=input("\n\t\t\t\t\tENTER PRODUCT REMARK TO VIEW CORRESPONDING PRODUCTS : ")
    query="select * from products where remarks='{}'".format(remark)
    cur.execute(query)
    res=cur.fetchall()
    if len(res)==0:
        print_message(" NO PRODUCTS FOUND WITH THE GIVEN REMARK ")
    else:
        x=PrettyTable()
        x.field_names=['PRODUCT ID','PRODUCT','CATEGORY','PRICE','QUANTITY','REMARKS']
        l=[]
        for i in res:
                l.append(i)
        x.add_rows(l)
    print_message(" PRODUCTS WITH GIVEN REMARKS ")
    print(x)

def disp_p_id(p_id):
    x=PrettyTable()
    x.field_names=['PRODUCT ID','PRODUCT','CATEGORY','PRICE','QUANTITY','REMARKS']
    if not p_exists(p_id):
        print_message(" NO PRODUCT FOUND WITH GIVEN PRODUCT ID ")
    else:
        code="select * from products where p_id={}".format(p_id)
        cur.execute(code)
        res=cur.fetchall()
        l=[]
        for i in res:
            l.append(i)
        x.add_rows(l)
        print(x)
        return res

def update_p():
    p_id=input("\n\t\t\t\t\tENTER PRODUCT ID WHOSE RECORD YOU WANT TO UPDATE : ")
    print_message(" CURRENT PRODUCT DETAILS ")
    res=disp_p_id(p_id)
    if not p_exists(p_id):
        print_message("  NO RECORD FOUND WITH GIVEN PRODUCT ID ")
    else:
        ans=input("\n\t\t\t\t\tENTER (y) TO CHANGE LEAVE BLANK IF DONT WANT TO CHANGE : ")
        if ans.lower()=='y':
            try:
                p=int(input("\n\t\t\t\t\tENTER NEW PRODUCT QUANTITY, LEAVE BLANK IF DON'T WANT TO CHNAGE : "))
            except:
                p=res[0][3]
            try:
                q=int(input("\n\t\t\t\t\tENTER NEW PRODUCT PRICE, LEAVE BLANK IF DON'T WANT TO CHNAGE : "))
            except:
                q=res[0][4]
            r=input("\n\t\t\t\t\tENTER NEW PRODUCT REMARKS, LEAVE BLANK IF DON'T WANT TO CHNAGE : ")
            if r=="":
                r=i[0][5]
            query="update products set price={}, qty={}, remarks='{}' where p_id={}".format(p,q,r,p_id)
            cur.execute(query)
            mydb.commit()
            print_message("  PRODUCT DETAILS UPDATED  ")

def del_p():
    p_id=input("\n\t\t\t\t\tENTER PRODUCT ID TO DELETE PRODUCT : ")
    if not p_exists(p_id):
        print_message(" NO PRODUCT FOUND WITH GIVEN PRODUCT ID ")
    else:
        query="delete from products where p_id='{}'".format(p_id)
        cur.execute(query)
        mydb.commit()
        print_message(" PRODUCT DELETED SUCCESSFULLY ")

def disp_p():
    print("\n\t\t\t\t\tWHICH PRODUCTS DO YOU WANT TO SEE")
    print("\n\t\t\t\t\t1. DISPLAY ALL THE PRODUCTS ")
    print("\n\t\t\t\t\t2. DISPLAY PRODUCTS WITH SPECIFIC PRODUCT ID ")
    print("\n\t\t\t\t\t3. DISPLAY PRODUCTS WITH SPECIFIC CATEGORY ")
    print("\n\t\t\t\t\t4. DISPLAY PRODUCTS WITH SPECIFIC PRODUCT REMARK ")
    choice=int(input("\n\t\t\t\t\tPLEASE ENTER YOUR CHOICE "))
    if choice==1:
         disp_p_all()
    elif choice==2:
        p_id=(input("\n\t\t\t\t\tENTER PRODUCT ID TO VIEW PRODUCT DETAILS"))
        print_message(" PRODUCTS WITH GIVEN PRODUCT ID ")
        disp_p_id(p_id)
    elif choice==3:
        disp_p_cat()
    elif choice==4:
        disp_p_remark()
    
def products():
    ans='y'
    while  True:
        print_message("    PRODUCTS MANAGEMENT    ")
        print("\n\t\t\t\t\t1. ADD NEW PRODUCT ")
        print("\n\t\t\t\t\t2. VIEW THE PRODUCTS ")
        print("\n\t\t\t\t\t3. UPDATE A PRODUCT'S DETAILS ")
        print("\n\t\t\t\t\t4. DELETE A PRODUCT FROM RECORDS ")
        print("\n\t\t\t\t\tPRESS ANY OTHER KEY TO RETURN TO MAIN MENU ")
        choice=input("\n\n\t\t\t\t\tEnter your choice... ")
        if choice=='1':
            add_prod()
        elif choice=='2':
            disp_p()
        elif choice=='3':
            update_p()
        elif choice=='4':
            del_p()
        else:
            break

def r_exists(a):
    code="select count(*) from sales where c_id='{}'".format(a)
    cur.execute(code)
    for x in cur:
        c=x[0]
        if c==0:
            return False
        else:
            return True

def add_r():
    c_id=int(input("\n\t\t\t\t\tENTER THE CUSTOMER ID : "))
    if r_exists(c_id):
        print_message(" THIS CUSTOMER ID ALREADY EXISTS ")
    else:
        c_name=input("\n\t\t\t\t\tENTER NAME OF THE CUSTOMER : ")   
        p_id=int(input("\n\t\t\t\t\tENTER PRODUCT ID : "))
        pname=input("\n\t\t\t\t\tENTER NAME OF THE PRODUCT : ")
        cat=input("\n\t\t\t\t\tENTER PRODUCT CATEGORY : ")
        price=int(input("\n\t\t\t\t\tENTER PRICE OF THE PRODUCT : "))
        qty=int(input("\n\t\t\t\t\tENTER THE QUANTITY OF PRODUCT BROUGHT : "))
        dcnt=int(input("\n\t\t\t\t\tENTER THE DISCOUNT ON THE PRODUCT (enter '0' if no discount) : "))
        query="insert into sales values({},'{}',{},'{}','{}',{},{},{})".format(c_id,c_name,p_id,pname,cat,price,qty,dcnt)
        cur.execute(query)
        mydb.commit()
        print_message(" RECORD ADDDED SUCCESSFULLY ")

def disp_r_all():
    x=PrettyTable(['CUSTOMER ID','NAME','PRODUCT ID','PRODUCT','CATEGORY','PRICE','QUANTITY','DISCOUNT(%)'])
    cur.execute("select * from sales")
    res=cur.fetchall()
    l=[]
    for i in res:
        l.append(i)
    x.add_rows(l)
    print_message("   ALL THE RECORDS   ")
    print(x)


def disp_r_cat():
    x=PrettyTable()
    x.field_names=['CUSTOMER ID','NAME','PRODUCT ID','PRODUCT','CATEGORY','PRICE','QUANTITY','DISCOUNT(%)']
    cat=input("\n\t\t\t\t\tENTER PRODUT CATEGORY TO VIEW RECORDS : ")
    query="select * from sales where category='{}'".format(cat)
    cur.execute(query)
    res=cur.fetchall()
    l=[]
    for i in res:
            l.append(i)
    x.add_rows(l)
    print_message(" RECORDS WITH GIVEN PRODUCT CATEGORY ")
    print(x)

def disp_r_name():
    x=PrettyTable()
    x.field_names=['CUSTOMER ID','NAME','PRODUCT ID','PRODUCT','CATEGORY','PRICE','QUANTITY','DISCOUNT(%)']
    name=input("\n\t\t\t\t\tENTER CUSTOMER NAME TO VIEW RECORDS : ")
    query="select * from sales where c_name='{}'".format(name)
    cur.execute(query)
    res=cur.fetchall()
    l=[]
    for i in res:
            l.append(i)
    x.add_rows(l)
    print_message(" RECORDS WITH GIVEN CUSTOMER NAME ")
    print(x)


def disp_r_id(c_id):
    x=PrettyTable()
    x.field_names=['CUSTOMER ID','NAME','PRODUCT ID','PRODUCT','CATEGORY','PRICE','QUANTITY','DISCOUNT(%)']
    if not r_exists(c_id):
        print_message(" NO CUSTOMER FOUND WITH GIVEN CUSTOMER ID ")
    else:
        code="select * from sales where c_id={}".format(c_id)
        cur.execute(code)
        res=cur.fetchall()
        l=[]
        for i in res:
            l.append(i)
        x.add_rows(l)
        print_message(" RECORDS WITH GIVEN CUSTOMER ID ")
        print(x)
        return res

def update_r():
    c_id=int(input("\n\t\t\t\t\tENTER CUSTOMER ID TO UPDATE IT'S RECORD : "))
    if not r_exists(c_id):
        print_message(" NO RECORD FOUND WITH GIVEN CUSTOMER ID ")
    else:
        res=disp_r_id(c_id)
        print_message("  CURRENT PRODUCT DETAILS  ")
        ans=input("\n\t\t\t\t\tDO YOU WANT TO CHANGE ? ENTER (y) : ")
        if ans.lower()=='y':
            print("\n\t\t\t\t\tYOU CAN ONLY CHNAGE PRODUCT ID, PRODUCT, PRICE, QUANTITY AND DISCOUNT AMOUNT.  ")
            c=input("\n\t\t\t\t\tENTER PRODUCT ID, LEAVE BLANK IF NOT WANT TO CHANGE : ")
            if c=="":
                c=res[0][2]
            n=input("\n\t\t\t\t\tENTER NEW PRODUCT, LEAVE BLANK IF DON'T WANT TO CHANGE : ")
            if n=="":
                n=res[0][3]
            cat=input("\n\t\t\t\t\tENTER NEW PRODUCT CATEGORY, LEAVE BLANK IF DON'T WANT TO CHANGE : ")
            if cat=="":
                cat=res[0][4]
            try:
                p=int(input("\n\t\t\t\t\tENTER NEW PRODUCT PRICE, LEAVE BLANK IF DON'T WANT TO CHANGE : "))
            except:
                p=res[0][5]
            try:
                q=int(input("\n\t\t\t\t\tENTER NEW PRODUCT QUANTITY, LEAVE BLANK IF DON'T WANT TO CHANGE : "))
            except:
                q=res[0][6]
            try:
                d=int(input("\n\t\t\t\t\tENTER NEW DISCOUNT AMOUNT, LEAVE BLANK IF DON'T WANT TO CHANGE : "))
            except:
                d=res[0][7]
            query="update sales set p_id={}, p_name='{}', category='{}', price={}, qty={}, discount={} where c_id='{}'".format(c,n,cat,p,q,d,c_id)
            cur.execute(query)
            mydb.commit()
            print_message("  RECORD UPDATED SUCCESSFULLY ")

def del_r():
    c_id=int(input("\n\t\t\t\t\tENTER CUSTOMER ID TO DELETE RECORD : "))
    if not r_exists(c_id):
        print_message(" NO RECORDS FOUND WITH GIVEN CUSTOMER ID ")
    else:
        query="delete from sales where c_id='{}'".format(c_id)
        cur.execute(query)
        mydb.commit()
        print_message(" RECORD DELETED SUCCESSFULLY ")

def disp_r():
    print("\n\t\t\t\t\tWHICH RECORDS DO YOU WANT TO SEE ")
    print("\n\t\t\t\t\t1. DISPLAY ALL RECORDS ")
    print("\n\t\t\t\t\t2. DISPLAY RECORDS WITH SPECIFIC CUSTOMER ID ")
    print("\n\t\t\t\t\t3. DISPLEY RECORDS WITH SPECIFIC CUSTOMER NAME ")
    print("\n\t\t\t\t\t4. DISPLAY ALL RECORDS SPECIFIC PRODUCT CATEGORY")
    print("\n\t\t\t\t\tPRESS ANY OTHER KEY TO RETURN TO MAIN MENU ")
    choice=int(input("\n\t\t\t\t\tPLEASE ENTER YOUR CHOICE : "))
    if choice==1:
        disp_r_all()
    elif choice==2:
        c_id=int(input("\n\t\t\t\t\tENTER CUSTOMER ID : "))
        disp_r_id(c_id)
    elif choice==3:
        disp_r_name()
    elif choice==4:
        disp_r_cat()

def invoice():
    c_name=input("\n\t\t\t\t\tENTER THE NAME OF CUSTOMER WHOSE INVOICE YOU WANT TO GENERATE : ")
    x=PrettyTable()
    x.field_names=['ITEM','PRICE','QUANTITY','DISCOUNT(%)','TOTAL']
    query="select * ,(price*qty)-(price*qty*discount/100) from sales where c_name = '{}' ".format(c_name)
    cur.execute(query)
    res=cur.fetchall()
    if len(res)==0:
        print_message(" NO CUSTOMER FOUND WITH THIS NAME ")
    else:
        c=0
        total=0
        for i in res:
            x.add_row([i[3],i[5],i[6],i[7],i[8]])
            c+=1
            total+=i[8]
        n=datetime.datetime.now()
        print("\n\n\t\t\t## INVOICE ##\n")
        print('DATE :', n.date(),end="\t\t\t")
        print('TIME :', n.time())
        print("CUSTOMER NAME : ",c_name)
        print(x)
        print('TOTAL ITEMS : ',c)
        print('TOTAL AMOUNT : ',total)
    
def sales():
    ans='y'
    while  True:
        print_message("     STORE'S SALES MANAGEMENT     ")
        print("\n\t\t\t\t\t1. ADD NEW SALES RECORD ")
        print("\n\t\t\t\t\t2. VIEW RECORDS ")
        print("\n\t\t\t\t\t3. UPDATE A RECORD ")
        print("\n\t\t\t\t\t4. DELETE A RECORD ")
        print("\n\t\t\t\t\t5. GENERATE CUSTOMER INVOICE ")
        print("\n\t\t\t\t\tPRESS ANY OTHER KEY TO RETURN TO MAIN MENU ")
        choice=input("\n\t\t\t\t\tENTER YOUR CHOICE : ")
        if choice=='1':
            add_r()
        elif choice=='2':
            disp_r()
        elif choice=='3':
            update_r()
        elif choice=='4':
            del_r()
        elif choice=='5':
            invoice()
        else:
            break

while True:
    clear()
    print_message("     STORE MANAGEMENT SYSTEM     ")
    print("\n\t\t\t\t\t1. PRODUCTS MANAGEMENT SYSTEM ")
    print("\n\t\t\t\t\t2. SALES MANAGEMENT SYSTEM ")
    print("\n\t\t\t\t\tPRESS ANY OTHER KEY TO EXIT ")
    choice=(input("\n\n\t\t\t\t\tENTER YOUR CHOICE  :  "))
    if choice=='1':
        products()
    elif choice=='2':
        sales()
    else:
        break
