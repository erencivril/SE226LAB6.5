#Question1
def same_elements_list(list1, list2):
    list3 = []
    for element in list1:
        if element in list2:
            list3.append(element)
    return list3

asd = [1,2,56,7,12]
bcd = [1,6,4,2,7,15,22,12]

print(same_elements_list(bcd, asd))

#Question2
def find_palindromes(words):
    palindromes_list = []
    for word in words:
        if word == word[::-1]:
            palindromes_list.append(word)
    return palindromes_list

#Question3
def find_prime_numbers(numbers):
    prime_list = numbers.copy()
    for number in numbers: #Firstly I'm checking if there is any negative number or 0 or 1
        if number < 2:
            prime_list.remove(number)

    for number in numbers:
        for i in range(2, number):
            if (number % i) == 0:
                prime_list.remove(number)
                break
    return prime_list

#Question4
def anagrams(word, wordlist): #I had to convert lists to set to get rid of duplicated characters and changed it back to list
    anagram_list = []
    word = word.lower().replace(" ", "")
    sorted_word = list(set(sorted(word)))
    for inword in wordlist:
        inword.lower().replace(" ", "")
        sorted_inword = list(set(sorted(inword)))
        if sorted_word == sorted_inword:
            anagram_list.append(inword)
    return anagram_list

print(anagrams("listen", ["enlists", "google", "inlets", "banana"]))
