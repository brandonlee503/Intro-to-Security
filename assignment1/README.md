# Assignment 1

## Install

Dependencies
 - Python 2.7
  - bitarray
  - mmh3
  
To install dependencies, run the following lines:
```
sudo pip install bitarray
sudo pip install mmh3
```

## Execute

To run, simply type `make`

Argument inputs can be set in `Makefile`

## Task 2 Question Set

1. What hash functions did you choose and why (Hint: Cryptographic or non-cryptographic)? What is the output range of the hash functions? What is the size of the Bloom filter in each case?
  - I choose to use Murmurhash (non-cryptographic) for two reasons. Firstly, I chose non-cryptographic as non-cryptographic hash functions focus on simply avoiding collisions over guaranteeing security properties. Because of this focus, what non-crytographic functions lack in security, they make up for in sheer speed. Secondly, I choose Murmurhash specifically as it seems well documented and fairly simple to use in Python. I calculated the size of the BloomFilter for both cases with the following equation: ![alt text](https://wikimedia.org/api/rest_v1/media/math/render/svg/25b30f6928fac097a6e25aa7b7870a7722b7aea0 "BloomFilter Size Equation"), which resulted in about [899545] (https://www.wolframalpha.com/input/?i=-((623517ln+0.5)%2F+(ln2)+%5E2)).

2. How long does it take for your Bloom Filter to check 1 password in each case? Why does one perform better than other?
  - For 3 hashes, it takes about 7.86e-06 seconds and for 5 hashes, it takes about 6.91e-06. I believe 5 hashes performs better than 3 due to the increase of performance when stacking hashes on top of each other.

3. What is the probability of False Positive in your Bloom Filter in each case? What is the probability of False Negative in your Bloom Filter?
  - The probability of false positives in a given Bloom Filter is the following equation: ![alt text] (https://wikimedia.org/api/rest_v1/media/math/render/svg/f2e6672519704bf66f07548db4ec356bbf43fdcc "BloomFilter FP Equation") Through some calculations, with 3 hashes, the probability is about [67%] (http://www.wolframalpha.com/input/?i=(1-e%5E((-3)(623517)%2F899545))%5E3). For 5 hashes, the probability is about [85%](http://www.wolframalpha.com/input/?i=(1-e%5E((-5)(623517)%2F899545))%5E5). False negatives are not a possibility in Bloom Filters.

4. How can you reduce the rate of False Positives?
 - To reduce the rate of false positives - as observed from the above equation and example, decrease the number of hashes.
