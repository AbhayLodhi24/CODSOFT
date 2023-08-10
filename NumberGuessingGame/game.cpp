#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  int number, guess, nguess = 0;
  srand(time(0));
  number = rand() % 100 + 1;

  do {
    printf("Enter a number between 1 to 100\n");
    cin >> guess;
    if (guess < number) {
      cout << "Higher number please\n";
      nguess++;
    }
    if (guess > number) {
      cout << "Lower number please\n";
      nguess++;
    }
    if (guess == number) {
      nguess++;
      break;
    }
  } while (number != guess);

  cout << "Total number of  guesses is\t" << nguess;
  return 0;
}