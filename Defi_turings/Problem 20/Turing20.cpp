#include <iostream>
#include <stack>

using namespace std;

class Hydre{
    public :
        Hydre(int int_heads)
        void attack();
        bool is_alive();
    
    private:
        stack<int> heads;
        unsigned int hits;
}
// Constructor of the class
Hydre::Hydre(int int_heads){
    heads.push(int_heads);
}
// Determine if the Hydra is still alive
bool Hydre::is_alive(){
    return (heads.size()!=0);
}
// Attack the hydra.
void Hydre::attack(){
    
}