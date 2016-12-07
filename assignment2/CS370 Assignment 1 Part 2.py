def main():
    input1 = raw_input()
    inputList1 = list(input1)
    input2 = raw_input()
    inputList2 = list(input2)
    counter = 0
    for i in range(0, len(inputList1)):
        if inputList1[i] == inputList2[i]:
            counter += 1

    print counter

if __name__ == "__main__":
    main()
