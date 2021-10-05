#include<iostream>
#include<string>
using namespace std;


int counter = 1;

void friendsPairing(int i, int n, bool* visited, string asf)
{
    if(i > n){
        cout<<counter<<"."<<asf<<endl;
        counter++;
        return;
    }
    
    if(visited[i] == true){
        // simply move to the next friend, ith friend has already been paired up
        friendsPairing(i+1, n, visited, asf);
    }
    
    else{
        // at current level, immediately mark ith friend as visited
        visited[i] = true;
        
        // call for keeping "i" single (Don't mark i+1 visited here bcz not pairing up)
        friendsPairing(i + 1, n, visited, asf + "(" + to_string(i) + ") ");
        
        // call for pairing "i"
        // start j from i+1 & not 1 to avoid generating permutations
        for(int j = i+1; j <= n; j++){
            // if j isn't already paired
            if(visited[j] == false){
                // mark the jth friend visited just before pairing up with it
                visited[j] = true;
                
                friendsPairing(i+1, n, visited, asf + "(" + to_string(i) + "," + to_string(j) + ") ");
                
                // unvisit j on returning back
                visited[j] = false;
            }
        }
        
        // unvisit ith friend when all choices of i has been explored
        visited[i] = false;
    }
    
}


int main()
{
    int n;
    cin>>n;
    
    bool visited[n+1] = {false};
    
    friendsPairing(1, n, visited,"");
    
    return 0;
}