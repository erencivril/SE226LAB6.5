#include <iostream>
#include <string>

using namespace std;

// Question 1
int* same_elements_list(int list1[], int list1_size, int list2[], int list2_size, int& list3_size){
    int* list3 = new int[list1_size];
    int count = 0;
    for (int i = 0; i < list1_size; i++){
        for (int j = 0; j < list2_size; j++){
            if (list1[i] == list2[j]){
                list3[count] = list1[i];
                count++;
            }
        }
    }
    list3_size = count;
    return list3;
}

// Question 2
string* find_palindromes(string words[], int size, int& palindromes_size){
    string* palindromes_list = new string[size];
    int count = 0;
    for (int i = 0; i < size; i++){
        if (words[i] == string(words[i].rbegin(), words[i].rend())){
            palindromes_list[count] = words[i];
            count++;
        }
    }
    palindromes_size = count;
    return palindromes_list;
}

// Question 3
int* find_prime_numbers(int numbers[], int size, int& prime_size){
    int* prime_list = new int[size];
    int count = 0;
    for (int i = 0; i < size; i++){
        bool is_prime = true;
        if (numbers[i] < 2){
            is_prime = false;
        }
        for (int j = 2; j < numbers[i]; j++){
            if (numbers[i] % j == 0){
                is_prime = false;
                break;
            }
        }
        if (is_prime){
            prime_list[count] = numbers[i];
            count++;
        }
    }
    prime_size = count;
    return prime_list;
}

// Question 4
string* anagrams(string word, string wordlist[], int size, int& anagram_size){
    string* anagram_list = new string[size];
    int count = 0;
    string sorted_word = word;
    sort(sorted_word.begin(), sorted_word.end());
    for (int i = 0; i < size; i++){
        string inword = wordlist[i];
        inword.erase(remove(inword.begin(), inword.end(), ' '), inword.end());
        string sorted_inword = inword;
        sort(sorted_inword.begin(), sorted_inword.end());
        if (sorted_word == sorted_inword){
            anagram_list[count] = wordlist[i];
            count++;
        }
    }
    anagram_size = count;
    return anagram_list;
}

int main() {
    int list1[] = {1, 2, 56, 7, 12};
    int list2[] = {1, 6, 4, 2, 7, 15, 22, 12};
    int list1_length = sizeof(list1) / sizeof(int);
    int list2_length = sizeof(list2) / sizeof(int);
    int intersection_length;
    int* intersection = same_elements_list(list1, list1_length, list2, list2_length, intersection_length);
    cout << "Same Elements in List1 and List2: ";
    for (int i = 0; i < intersection_length; i++) {
        cout << intersection[i] << " ";
    }
    cout << endl;

    string words[] = {"racecar", "hello", "civic", "world", "level"};
    int words_length = sizeof(words) / sizeof(string);
    int palindrome_length;
    string* palindromes = find_palindromes(words, words_length, palindrome_length);
    cout << "Palindromes in Words List: ";
    for (int i = 0; i < palindrome_length; i++) {
        cout << palindromes[i] << " ";
    }
    cout << endl;

    int numbers[] = {2, 3, 7, 12, 15, 19, 23, 31, 40};
    int numbers_length = sizeof(numbers) / sizeof(int);
    int primes_length;
    int* primes = find_prime_numbers(numbers, numbers_length, primes_length);
    cout << "Prime Numbers in Numbers List: ";
    for (int i = 0; i < primes_length; i++) {
        cout << primes[i] << " ";
    }
    cout << endl;

    string word = "listen";
    string wordlist[] = {"enlists", "google", "inlets", "banana"};
    int wordlist_length = sizeof(wordlist) / sizeof(string);
    int anagram_length;
    string* anagram_list = anagrams(word, wordlist, wordlist_length, anagram_length);
    cout << "Anagrams of '" << word << "' in Word List: ";
    for (int i = 0; i < anagram_length; i++) {
        cout << anagram_list[i] << " ";
    }
    cout << endl;
    
    delete[] intersection;
    delete[] palindromes;
    delete[] primes;
    delete[] anagram_list;

    return 0;
}
