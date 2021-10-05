// Don't see this question as permutation or combination. We may be using those concepts here, 
// But read the question and then come up with a general solution like below steps -

// 1. For aabb, we have 4 spots - _ _ _ _
// 2. Each spot has 2 choices (a or b)  (=> for each spot, give all unique choices)
// 3. If you've already placed 2 a's, spots have only 1 option (b) to choose. (=> Use map)

// And then see whether you can apply permutation concepts or combination concepts.


#include<iostream>
#include<string>
#include<map>
using namespace std;


// Method: 1 - Here we are not actually filling the spots cuz there in no spots[].
// We are simply incrementing the curSpot (for base case) and appending char to asf.

// Also, note that we are BACTRACKING ONLY MAP and NOT asf BECAUSE - (we are making changes in asf during the function call) + (asf is passed by value & not reference).
// So, when recursion folds back, it's original state will be regained in the current execution context.
void permutation_words_1(int n, int curSpot, map<char, int>& hashMap, string asf)
{
    // if you have been through all the 0 to n-1 spots
    if(curSpot == n){
        cout<<asf<<endl;
        return;
    }
    
    // give curSpot all the UNIQUE choices
    for(auto i : hashMap){
        // remaining frequency must be > 0
        if(i.second > 0){
            // use this character => decrease the count
            hashMap[i.first]--;
            
            permutation_words_1(n, curSpot + 1, hashMap, asf + i.first);
            
            // BACKTRACK => can use curChar in other boxes & curSpot can try other chars
            hashMap[i.first]++;
        }
    }
}

// Method 2: Create an array spots[str.size()] and rather than putting characters in asf
// place it in the spots array. But don't forget to manually BACKTRACK map + spots[]

int main()
{
    string str;
    cin>>str;
    
    // Store the count of each character to achieve #3 functionality.
    map <char, int> hashMap;
    for(char c : str){
        hashMap[c]++;
    }
    
    permutation_words_1(str.size(), 0, hashMap, "");
    
    return 0;
}