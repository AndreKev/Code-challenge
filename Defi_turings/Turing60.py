notre_list = [ i for i in range(1, 2014)]

def delete7(index, notre_list):
    if len(notre_list) >= 7:
        i = index + 6
        while i < len(notre_list):
            del notre_list[i]
            i += 6
        i -= 6
    else:
        i = 7%len(notre_list)-1
        del notre_list[i]
    return i

def main():
    global notre_list
    while len(notre_list) != 1:
        position = delete7(0, notre_list)
        notre_list = notre_list[position:]+notre_list[:position]
    print(notre_list)

if __name__ == "__main__":
    main()
