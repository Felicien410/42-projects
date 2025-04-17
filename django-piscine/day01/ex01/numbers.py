
def main():
    with open("numbers.txt", "r") as file:
        all_numbers = file.read() 
        all_numbers = all_numbers.split(",")  
        for numbers in all_numbers :
            print(numbers)

if __name__ == '__main__':
    main()