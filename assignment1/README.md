# Assignment 1

Dependencies
 - Python 2.7
  - bitarray
  - mmh3

To run, simply type `make`

Argument inputs can be set in `Makefile`

## Task 2 Question Set

1. What hash functions did you choose and why (Hint: Cryptographic or non-cryptographic)? What is the output range of the hash functions? What is the size of the Bloom filter in each case?
  - I choose to use Murmurhash (non-cryptographic) for two reasons. Firstly, I chose non-cryptographic as non-cryptographic hash functions focus on simply avoiding collisions over guaranteeing security properties. Because of this focus, what non-crytographic functions lack in security, they make up for in sheer speed. Secondly, I choose Murmurhash specifically as it seems well documented and fairly simple to use in Python. I calculated the size of the BloomFilter with the following equation: ![alt text](https://wikimedia.org/api/rest_v1/media/math/render/svg/25b30f6928fac097a6e25aa7b7870a7722b7aea0 "BloomFilter Size Equation"), which resulted in about [899545.] (https://www.wolframalpha.com/input/?i=-((623517ln+0.5)%2F+(ln2)+%5E2))
