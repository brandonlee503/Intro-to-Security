# Brandon Lee
# CS 370 Intro to Security
# Assignment 1

# Helpful Resources
# http://www.sanfoundry.com/cpp-program-implement-bloom-filter/
# http://blog.michaelschmatz.com/2016/04/11/how-to-write-a-bloom-filter-cpp/
# http://billmill.org/bloomfilter-tutorial/
# http://www.maxburstein.com/blog/creating-a-simple-bloom-filter/
# https://github.com/wc-duck/pymmh3

from bitarray import bitarray
import mmh3
import sys

# https://www.wolframalpha.com/input/?i=-((623517ln+0.5)%2F+(ln2)+%5E2)
BIT_ARRAY_SIZE  = 899545
DICTIONARY_SIZE = 623517

class BloomFilter(object):
    """BloomFilter Implementation"""
    def __init__(self, size, nHash):
        self.bitarray = bitarray(size)
        self.bitarray.setall(0)
        self.size = size
        self.nHash = nHash

    def add(self, password):
        for seed in range(self.nHash):
            result = mmh3.hash(password, seed) % self.size
            self.bitarray[result] = 1

    def search(self, password):
        for seed in range(self.nHash):
            result = mmh3.hash(password, seed) % self.size
            if self.bitarray[result] == 0:
                return "no"
        return "maybe"

def main():
    print "main()"
    inputList = open(sys.argv[4]).read().splitlines()

    # Pop first element (number of passwords)
    inputList.pop(0)
    for i in inputList:
        print i

    bloomFilter3 = BloomFilter(899545, 3)
    dictionary = open(sys.argv[2]).read().splitlines()
    for password in dictionary:
        bloomFilter3.add(password)
        # print password

    print bloomFilter3.search("password")
    print 'Number of arguments:', len(sys.argv), 'arguments.'
    print 'Argument List:', str(sys.argv)



if __name__ == "__main__": main()
