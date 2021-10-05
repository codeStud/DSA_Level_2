// NOTE: See the meaning of no. of ways of triangulation. It's NOT same as no. of triangles.

// Application of Catalan number

// Approach: 
// Take ONE side of the POLYGON and make ALL POSSIBLE trianges ON THAT BASE. 
// For EACH of the above possible triangles: -
// the triangle will have 2 unused sides to be considered as base for further triangle construction.
// So, for one of the remaining 2 sides- consider it base (=> 2 vertices) and see how many points are there on the opposite side of this base.
// Then take the last side, consider it base (=> 2 vertices) & check the count of points on the opposite side of this base.
// All the points on the OPPOSITE side of each of the 2 remaining bases will result in a Polygon with lesser number of sides.
// So, solve them as catalan numbers.

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int noOfSides;
    cin>>noOfSides;
    
    // no_of_ways of triangulation for "n" sided polygon = Catalan of (n - 2)
    // i.e for noOfSides = 2, ans = Catalan(0), for noOfSides = 3, ans = Catalan(1) ....
    
    // "n = 2" ka answer dp[0] pe hoga.
    // "n = 3" ka answer dp[1] pe hoga.
    // Thus, "n = noOfSides" ka answer dp[noOfSides - 2] pe hoga. Thus, do n = noOfSides - 2 in the beginning only.
    int n = noOfSides - 2;      
    
    vector <int> dp (n + 1);
    
    // for polygon with noOfSides = 2, 1 triangle possible (Empty triangle, base case)
    dp[0] = 1;
    // for polygon with noOfSides = 3, 1 triangle possible
    dp[1] = 1;
    
    // for polygon with noOfSides = 4, 5 ... (i.e i = 2, 3 ....)
    for(int i = 2; i <= n; i++){
        
        int leftTriangles = i - 1;
        int rightTriangles = 0;
        
        while(leftTriangles >= 0){
            dp[i] += dp[leftTriangles] * dp[rightTriangles];
            
            leftTriangles--;
            rightTriangles++;
        }
        
    }
    
    // dp[noOfSides - 2] == dp[n] will contain the final answer bcz -
    // No. of ways of triangulation of "n" sided polygon = Catalan of "n-2"
    cout<<dp[n]<<endl;
    
    return 0;
}