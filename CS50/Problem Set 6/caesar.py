import cs50
import sys

def main():
    if len(sys.argv) != 2:
        print("You should provide cmd line arguments!")
        exit(1)
    
    key = int(sys.argv[1])
    trans = []
    msg = cs50.get_string()
    for symbol in msg:
        if symbol.isalpha():
            trans.append(caesar(symbol, key))
        else:
            trans.append(symbol)
                
    print("".join(trans))
    exit(0)

def caesar(char, key):
    if char.isupper():
        return chr(((ord(char) - 65 + key) % 26) + 65)
    else:
        return chr(((ord(char) - 97 + key) % 26) + 97)
        
if __name__ == "__main__":
    main()