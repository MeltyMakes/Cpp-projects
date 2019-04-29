#include <iostream>
using namespace std;
//-----------------------------------------------------------------------------
//Quicksort
//-----------------------------------------------------------------------------
//Runs quicksort: https://en.wikipedia.org/wiki/Quicksort
//Quicksort sorts an array by recursively pivoting and comparing values
//Made as refresher and practice since my 2013 implementation is lost
//Designed by Brendan Souksmlane 2018
//-----------------------------------------------------------------------------

void quicksort(int list[], int size) {
  //if the group is small the return the list
  if (size <= 1) {
    return;
  }
  //else run the code
  //Find a pivot at halfwayish mark
  int pivot = list[size/2];

  //define our > & < groups to be same size as parent
  //inefficient but safe
  int gThan[size];
  int lThan[size];
  int gSize = 0;
  int lSize = 0;

  //Sort the list into less than or greater than the pivot
  for (size_t i = 0; i < size; i++) {
    //skip over the pivot index
    if (i != size/2){
      if (list[i] <= pivot) {
        lThan[lSize] = list[i];
        lSize++;
      }
      if (list[i] > pivot) {
        gThan[gSize] = list[i];
        gSize++;
      }
    }
  }

  //Quicksort the two new groups
  if (gSize > 0){
    quicksort(gThan, gSize);
  }
  if (lSize > 0) {
    quicksort(lThan, lSize);
  }

  //Add the results of the quicksort to the new array
  int i = 0;
  int j;
  //insert the less than
  for (j = 0; j < lSize; j++) {
    list[i] = lThan[j];
    i++;
  }
  //Move pivot to the middle of the two
  list[i] = pivot;
  //insert the greater than
  for (j = 0; j < gSize; j++) {
    i++;
    list[i] = gThan[j];
  }
  //return the list
  return;
}

int main() {
    int length = 30;
    int list[length] = {5, 2, 4, 3, 1,
                        6, 3, 8, 3, 7,
                        3, 2, 5, 7, 9,
                        5, 3, 1, 3, 6,
                        8, 0, 3,12,14,
                        25,1, 7, 9, 5};

    cout << "Generating number list..." << endl;
    for (size_t i = 0; i < length; i++) {
      //random number gen; populate the list
      //!! add random number later
      cout << list[i] << endl;
    }
    cout << "----------------------------------------" << endl
         << "  List generated! Running Quicksort..." << endl
         << "----------------------------------------" << endl;
    quicksort(list, length);

    for (size_t i = 0; i < length; i++) {
      cout << list[i] << endl;
    }
    return 0;
}
