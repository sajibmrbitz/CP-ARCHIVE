#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N,M,L,U;
    cin>>N>>M>>L>>U;
    vector<long long> A(N);
    long long mid=(L+U)/2;

    for(int i=0;i<N;i++){
        A[i]=mid;
        cout<<A[i]<<(i==N-1?'\n':' ');
    }
    cout.flush();

    vector<long long> B(M);
    for(int i=0;i<M;i++){
        cin>>B[i];
    }

    vector<long long> pilesum(M,0);
    vector<int> X(N);

    for(int i=0;i<N;i++){
        int bestpile=0;
        long long minerror=LLONG_MAX;

        for(int j=0;j<M;j++){
            long long newsum=pilesum[j]+A[i];
            long long error=abs(newsum-B[j]);
            if(error<minerror){
                minerror=error;
                bestpile=j;
            }
        }

        pilesum[bestpile]+=A[i];
        X[i]=bestpile+1;
    }

    for(int i=0;i<N;i++){
        cout<<X[i]<<(i==N-1?'\n':' ');
    }
    cout.flush();
    return 0;
}


/*
A - Random Sum Game 
Time Limit: 2 sec 
Memory Limit: 1024 MiB

Problem Statement
There are N blank cards, and a random number generator that generates M integers between L and U, inclusive, 
independently and uniformly at random.

Using these items, you play the following game.
First you choose arbitrary integers A1 ,…,AN between 1 and U, inclusive, and write A i on i-th card.
Then, using the random number generator, M integers B1 ,…,BM are generated.
You may discard any number of cards (possibly zero), and partition the remaining cards into 
M piles (possibly empty).
The objective of game is to make the sum of the integers on cards in j-th pile as close to Bj as possible.

Scoring
Let Sj be the sum of the integers written on cards in j-th pile, and define the error E by 
E=∑ (j=1 to M) ∣Sj−Bj∣. Then your score is round((20−log10 (1+E))×5×10^7).

Input and Output
First, 
N,M,L,U are given from Standard Input.

Let Ai be the integer you write on i-th card. Then output to Standard Output.

​
 
Then B1 ,…,BM are given from Standard Input. (Notice that you have to output A1,…,AN before reading B1,…,BM.)
​
 
Let Xi=0 if you decided to discard i-th card, and otherwise let Xi be the index of the pile to which 
i-th card belongs. Then output to Standard Output as follows.

X1  X2…XN
​
 
All the output must be followed by a new line, and you have to flush Standard Output. 
Otherwise, the submission might be judged as TLE.
*/