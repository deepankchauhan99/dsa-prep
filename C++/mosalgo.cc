// Mos algorithm candy example · CPP
/*
    MO'S ALGORITHM — explained like you're 5 years old, but in C++ 🍬
 
    STORY:
      You have a shelf of candy boxes (an array).
      Friends keep asking: "how many RED candies between box L and box R?"
      Instead of recounting every time (slow), we use two fingers
      (Lefty, Righty) and a basket that keeps a running count.
      We SLIDE the fingers instead of restarting — but we answer
      questions in a SMART ORDER so the fingers don't jiggle around
      too much.
 
    Compile:  g++ -O2 -std=c++17 mos_algorithm_candy_example.cpp -o mo
    Run:      ./mo
*/
 
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;
 
// -------------------------------------------------------------------
// A small struct to hold one query. We store the ORIGINAL index too,
// because we will REORDER the questions for solving, but we still want
// to print answers back in the order friends originally asked them.
// -------------------------------------------------------------------
struct Query {
    int left, right;   // the range friend asked about (0-indexed, inclusive)
    int originalIndex; // "this was friend's question number ___"
};
 
// -------------------------------------------------------------------
// Global-ish state for our sliding basket.
// (In competitive programming these are often globals for speed;
//  that's normal for Mo's algorithm.)
// -------------------------------------------------------------------
vector<char> candies;        // the shelf: 'R', 'B', 'G' etc.
int freqCount[128];          // freqCount[(int)'R'] = how many reds in basket right now
                              // (128 slots is enough to cover any ASCII character)
int redCountInBasket = 0;    // our "answer so far" for the current basket
 
int blockSize;                // neighborhood size = sqrt(n)
 
// -------------------------------------------------------------------
// BABY STEP: picking up ONE candy and putting it in the basket.
// -------------------------------------------------------------------
void addCandy(int position) {
    char color = candies[position];
    freqCount[(int)color]++;
    if (color == 'R') {
        redCountInBasket++;
    }
    cout << "    pick up box " << (position + 1) << " (" << color
         << ")  -> red count = " << redCountInBasket << "\n";
}
 
// -------------------------------------------------------------------
// BABY STEP: taking ONE candy OUT of the basket (dropping it back).
// -------------------------------------------------------------------
void removeCandy(int position) {
    char color = candies[position];
    freqCount[(int)color]--;
    if (color == 'R') {
        redCountInBasket--;
    }
    cout << "    drop box " << (position + 1) << " (" << color
         << ")    -> red count = " << redCountInBasket << "\n";
}
 
int main() {
    // -------------------------------------------------------------------
    // BABY STEP 1: Here's our shelf of candies.
    // Using 0-indexed array, so "box 1" in the story = index 0 here.
    // -------------------------------------------------------------------
    candies = {'R', 'B', 'R', 'R', 'G', 'B', 'R', 'G'};
    int n = candies.size();   // n = 8 boxes total
 
    // -------------------------------------------------------------------
    // BABY STEP 2: Here are the friends' questions (0-indexed, inclusive).
    //   Story's "box 2 to 5" -> index 1 to 4
    //   Story's "box 1 to 3" -> index 0 to 2
    //   Story's "box 6 to 8" -> index 5 to 7
    // -------------------------------------------------------------------
    vector<Query> queries = {
        {1, 4, 0},   // Q1 (original index 0)
        {0, 2, 1},   // Q2 (original index 1)
        {5, 7, 2},   // Q3 (original index 2)
    };
    int q = queries.size();
 
    // -------------------------------------------------------------------
    // BABY STEP 3: Decide neighborhood (block) size = sqrt(n).
    // -------------------------------------------------------------------
    blockSize = max(1, (int)sqrt((double)n));
    cout << "Block size (neighborhood size) = " << blockSize << "\n\n";
 
    // -------------------------------------------------------------------
    // BABY STEP 4: THE SORTING TRICK — the heart of Mo's algorithm.
    //
    // For each query, find which "neighborhood" its LEFT index falls into:
    //     neighborhood = left / blockSize
    //
    // Sort queries by:
    //   1st priority: neighborhood of L  (group nearby-L queries together)
    //   2nd priority: R (ascending)      (so Righty mostly creeps forward)
    // -------------------------------------------------------------------
    sort(queries.begin(), queries.end(), [](const Query &a, const Query &b) {
        int blockA = a.left / blockSize;
        int blockB = b.left / blockSize;
        if (blockA != blockB) {
            return blockA < blockB;   // group by neighborhood first
        }
        return a.right < b.right;     // then sort by R ascending
    });
 
    cout << "Smart answering order (not the order they were asked!):\n";
    for (auto &qu : queries) {
        cout << "  Answer Q" << (qu.originalIndex + 1)
             << " (boxes " << (qu.left + 1) << " to " << (qu.right + 1)
             << " in 1-indexed terms)\n";
    }
    cout << "\n";
 
    // -------------------------------------------------------------------
    // BABY STEP 5: Set up Lefty, Righty, and the empty basket.
    //
    // currentLeft, currentRight = where our two fingers currently sit.
    // We start with currentLeft = 0 and currentRight = -1, meaning
    // "the basket is empty, nothing picked up yet."
    // -------------------------------------------------------------------
    int currentLeft = 0;
    int currentRight = -1;   // -1 = empty range so far
    memset(freqCount, 0, sizeof(freqCount));
 
    vector<int> answers(q); // answers[originalIndex] = final answer for that query
 
    // -------------------------------------------------------------------
    // BABY STEP 6: THE MAIN LOOP — slide fingers to match each query,
    // in the SMART ORDER we just sorted. Never jump back to zero!
    // -------------------------------------------------------------------
    for (auto &query : queries) {
        int left = query.left;
        int right = query.right;
 
        cout << "Answering Q" << (query.originalIndex + 1)
             << ": need range [" << (left + 1) << ", " << (right + 1)
             << "] (1-indexed)\n";
 
        // --- Move RIGHTY outward (add candies) until it reaches 'right' ---
        while (currentRight < right) {
            currentRight++;
            addCandy(currentRight);
        }
 
        // --- Move RIGHTY inward (remove candies) if it overshot 'right' ---
        while (currentRight > right) {
            removeCandy(currentRight);
            currentRight--;
        }
 
        // --- Move LEFTY inward (add candies) if it needs to move left ---
        while (currentLeft > left) {
            currentLeft--;
            addCandy(currentLeft);
        }
 
        // --- Move LEFTY outward (remove candies) if it needs to move right ---
        while (currentLeft < left) {
            removeCandy(currentLeft);
            currentLeft++;
        }
 
        // Basket now EXACTLY matches [left, right] -> read off the answer
        answers[query.originalIndex] = redCountInBasket;
        cout << "  >> Answer to Q" << (query.originalIndex + 1)
             << " = " << redCountInBasket << "\n\n";
    }
 
    // -------------------------------------------------------------------
    // BABY STEP 7: Print final answers in the ORIGINAL order friends asked.
    // -------------------------------------------------------------------
    cout << "FINAL ANSWERS (in original question order):\n";
    vector<pair<int,int>> originalRanges = {{1, 4}, {0, 2}, {5, 7}};
    for (int i = 0; i < q; i++) {
        cout << "  Q" << (i + 1)
             << " (boxes " << (originalRanges[i].first + 1)
             << " to " << (originalRanges[i].second + 1) << "): "
             << answers[i] << " red candies\n";
    }
 
    return 0;
}