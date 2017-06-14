import cs50
import sys

def main():
    if len(sys.argv) != 2:
        print("You should provide a cmd line arguments!")
        exit(1)
    
    if sys.argv[1].isalpha() == False:
        print("You should provide valid keyword!")
        exit(1)
        
    msg = cs50.get_string()
    trans = []
    keyIndex = 0
    keylength = len(sys.argv[1])
    
    for symbl in msg:
        if symbl.isalpha():
            key = ord(sys.argv[1][keyIndex % keylength].lower()) - 97
            keyIndex += 1
            trans.append(caesar(symbl, key))
        else:
            trans.append(symbl)
    
    print("".join(trans))
    exit(0)
    
def caesar(char, key):
    if char.isupper():
        return chr(((ord(char) - 65 + key) % 26) + 65)
    else:
        return chr(((ord(char) - 97 + key) % 26) + 97)

if __name__ == "__main__":
    main()