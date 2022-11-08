from collections import Counter

def ac_encode(txt):

    res = Counter(txt)
    chars = list(res.keys())
    freq = list(res.values())

    probability = []
    for i in freq:
        probability.append(i / len(txt))

    print(chars)
    print(probability)

    high = 1.0
    low = 0.0
    for c in txt:
        diff = high - low
        index = chars.index(c)
        for i in range(index):
            high = low + diff * probability[i]
            low = high

        high = low + diff * probability[index]
        print(f'char {c} -> Low: {low}   High: {high}')

    tag = (low+high)/2.0

   
    with open('encode.ac', 'w') as fw:
        for i in chars:
            fw.write(i + ' ')
        fw.write('\n')

        for i in probability:
            fw.write(str(i) + ' ')
        fw.write('\n')

        fw.write(str(tag))

    return chars, probability, tag


def ac_decode(chars, probability, tag):
    high = 1.0
    low = 0.0
    output = ''
    c = ''
    while (c != '$'):
        diff = high - low
        for i in range(len(chars)):
            high = low + diff * probability[i]
            if low < tag < high:
                break
            else:
                low = high

        c = chars[i]
        output += c

    return output


def arithmetic_coding(input):

    (chars, probability, tag) = ac_encode(input)
    output = ac_decode(chars, probability, tag)
    return 

txt = input("Wprowadź wiadomość do zakodowania: ")
arithmetic_coding(txt)
