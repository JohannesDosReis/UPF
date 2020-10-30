# JESUS TE AMA
# coding: utf-8
# author: Johannes Dos Reis
from os import system
from tabulate import tabulate


def get_var(args, cmp):
    while True:
        try:
            num = cmp(input(args))
            break
        except:
            print(" Valor Invalido\n Tente de Novo")
    return num


def show_dict(dic):
    for key, value in dic.items():
        print("%s: %.2f" % (key, value))
    print()


def del_dict(dic, name):
    try:
        del (dic[name])
    except:
        pass


def cost(dic, arg):
    while True:
        system('cls')
        print(arg)
        show_dict(dic)
        print("1: Adicionar ou alterar custo ")
        print("2: Remover custo")
        print("0: Voltar\n")
        op = input("Escolha uma opção: ")
        if op == '0':
            return
        elif op == '1':
            name = input("Digite o nome do custo: ")
            dic[name] = get_var("Digite o valor da custo: ", float)
        elif op == '2':
            name = input("Digite o nome da custo: ")
            del_dict(dic, name)


def expenses(dic, arg):
    while True:
        system('cls')
        print(arg)
        show_dict(dic)
        print("1: Adicionar ou alterar despesa ")
        print("2: Remover despesa")
        print("0: Voltar\n")
        op = input("Escolha uma opção: ")

        if op == '0':
            return
        elif op == '1':
            name = input("Digite o nome da despesa: ")
            dic[name] = get_var("Digite o valor da despesa: ", float)
        elif op == '2':
            name = input("Digite o nome da despesa: ")
            del_dict(dic, name)


class Product:
    def __init__(self, name, prod, units, value, eipe, efpe, eipa):
        self.name = name
        self.units = units
        self.value = value
        self.expense_list = {}
        self.cost_list = {}
        self.prod = prod
        self.eipe = eipe
        self.efpe = efpe
        self.eipa = eipa

    @property
    def cpp(self):
        sum = 0.00
        for i in self.cost_list.values():
            sum += i
        return sum * self.units

    @property
    def desp(self):
        sum = 0.00
        for i in self.expense_list.values():
            sum += i
        return sum

    @property
    def cpa(self):
        return self.cpp + self.eipe - self.efpe

    @property
    def cupa(self):
        return self.cpa / self.prod

    @property
    def efpa(self):
        return (self.prod - self.units) * self.cupa

    @property
    def cpv(self):
        return self.cpa + self.eipa - self.efpa

    @property
    def mc(self):
        return self.vl - self.cpv - self.desp

    @property
    def vl(self):
        return self.units * self.value


class Menu:
    def __init__(self):
        self.product_list = []
        self.cost_list = {}
        self.expense_list = {}

    def show_results(self):
        tab = []
        tab.append(['Itens'])

        for i in self.product_list:
            tab[-1].append('Produto ' + i.name)
        tab[-1].append('Total')
        tab.append(['Vendas Líquidas', ])
        sum = 0.00
        for i in self.product_list:
            tab[-1].append(i.vl)
            sum += i.vl
        tab[-1].append(sum)

        tab.append(['Custo de produção do periodo (CPP)'])
        sum = 0.00
        for i in self.product_list:
            tab[-1].append(i.cpp)
            sum += i.cpp
        tab[-1].append(sum)

        tab.append(['Custo de produção acabada (CPA)'])
        sum = 0.00
        for i in self.product_list:
            tab[-1].append(i.cpa)
            sum += i.cpa
        tab[-1].append(sum)

        tab.append(['Custo unitario de produção'])
        sum = 0.00
        for i in self.product_list:
            tab[-1].append(i.cupa)
            sum += i.cupa
        tab[-1].append(sum)

        tab.append(['Estoque final de produto acabado'])
        sum = 0.00
        for i in self.product_list:
            tab[-1].append(i.efpa)
            sum += i.efpa
        tab[-1].append(sum)

        tab.append(['Custo de produto vendido (CPV)'])
        sum = 0.00
        for i in self.product_list:
            tab[-1].append(i.cpv)
            sum += i.cpv
        tab[-1].append(sum)

        tab.append(['Despesas variáveis'])
        sum = 0.00
        for i in self.product_list:
            tab[-1].append(i.desp)
            sum += i.desp
        tab[-1].append(sum)

        tab.append(['Margem de contribuição'])
        sum = 0.00
        for i in self.product_list:
            tab[-1].append(i.mc)
            sum += i.mc
        tab[-1].append(sum)


        tab.append(['Custo fixo'] + [''] * len(self.product_list) + [self.custo])
        tab.append(['Despesa fixa'] + [''] * len(self.product_list) + [self.despesas])
        tab.append(['Lucro líquido'] + [''] * len(self.product_list) + [sum - self.custo - self.despesas])

        print(tabulate(tab, headers="firstrow", tablefmt="fancy_grid", numalign="right", floatfmt=".2f"))
        print()
        print()

    def run(self):
        while True:
            system('cls')
            self.show_results()
            print("1: Adcionar produto")
            print("2: Remover produto")
            if len(self.product_list):
                print("3: Custos variáveis")
                print("4: Despesas variáveis")
                print("5: Custos fixos")
                print("6: Despesas fixas")
            else:
                print("3: Custos fixos")
                print("4: Despesas fixas")

            print("0: Sair\n")
            op = input("Escolha uma opção: ")
            if op == '0':
                exit()
            elif op == '1':
                self.new_product()
            elif len(self.product_list):
                if op == '2':
                    self.del_product()
                elif op == '3':
                    cost(self.product.cost_list, "Lista de custos variáveis por unidade")
                elif op == '4':
                    expenses(self.product.expense_list, "Lista de despesas variáveis")
                elif op == '5':
                    cost(self.cost_list, "lista de custos fixos")
                elif op == '6':
                    expenses(self.expense_list, "Lista de despesas fixas")
            else:
                if op == '3':
                    cost(self.cost_list, "lista de custos fixos")
                elif op == '4':
                    expenses(self.expense_list, "Lista de despesas fixas")


    @property
    def product(self):
        if len(self.product_list) != 1:
            name = input("Digite o nome do produto: ")
            if self.exist(name):
                for i in self.product_list:
                    if name == i.name:
                        return i
            else:
                return self.product
        else:
            return self.product_list[0]

    def exist(self, name):
        for i in self.product_list:
            if name == i.name:
                return 1
        else:
            return 0

    def new_product(self):
        while True:
            name = input("Digite o nome do produto: ")
            if self.exist(name):
                print("Produto já existe, tente novamente")
            else:
                break
        prod = get_var("Digite quantas unidade foram acabadas: ", int)
        units = get_var("Digite quantas unidade foram vendidas: ", int)
        value = get_var("Digite o valor de cada produto: ", float)
        eipe = get_var("Digite o valor do estoque inicial de produto em elaboração: ", float)
        efpe = get_var("Digite o valor do estoque final de produto em elaboração: ", float)
        eipa = get_var("Digite o valor do estoque inicial de produto acabado: ", float)
        self.product_list.append(Product(name, prod, units, value, eipe, efpe, eipa))

    def del_product(self):
        name = input("Digite o nome do produto que deseja remover: ")
        for i in self.product_list:
            if i.name == name:
                self.product_list.remove(i)

    @property
    def cpp(self):
        sum = 0.00
        for i in self.product_list:
            sum += i.cpp
        return sum

    @property
    def custo(self):
        sum = 0.00
        for i in self.cost_list.values():
            sum += i
        return sum

    @property
    def despesas(self):
        sum = 0.00
        for i in self.expense_list.values():
            sum += i
        return sum


if __name__ == '__main__':
    menu = Menu()
    menu.run()






