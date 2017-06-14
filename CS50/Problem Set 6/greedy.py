import cs50

def main():
    while True:
        print("O hai! How much change is owed?")
        amt = cs50.get_float()
        if amt >= 0:
            break
    
    num_of_coins = 0
    cents = int(round(amt * 100))
    
    num_of_coins += cents // 25
    cents %= 25
    
    num_of_coins += cents // 10
    cents %= 10
    
    num_of_coins += cents // 5
    cents %= 5
    
    num_of_coins += cents
    
    print("{}".format(num_of_coins))
    
if __name__ == "__main__":
    main()