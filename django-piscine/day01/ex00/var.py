def my_var():
    var1 = 42
    var2 = "quarante-deux"
    var3 = 42.0
    var4 = True
    var5 = [42]
    var6 = {42: 42}
    var7 = (42,)
    var8 = set()
    var9 = frozenset()

    for i in range(1, 10):
        var = locals()[f"var{i}"] 
        print(var, "est de type", type(var))

def main():
    my_var()

if __name__ == '__main__':
    my_var()