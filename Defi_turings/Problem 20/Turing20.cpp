#include <iostream>
#include <stack>

using namespace std;

class Hydre{
    public :
        Hydre(int int_heads);
        void attack();
        bool is_alive();
        long long get_hits();
    
    private:
        stack<int> heads;
        long long hits = 0;
};

// Constructor of the class
Hydre::Hydre(int int_heads){
    heads.push(int_heads);
}
// Determine if the Hydra is still alive
bool Hydre::is_alive(){
    return (heads.size()>0);
}
// Attack the hydra.
void Hydre::attack(){
    int back = heads.top(); heads.pop();
    if (back==1){
        hits += 1;
    } else if (back==2){
        hits += 1;
        hits = 2*hits+1;
    }
    else {
        back -= 1; hits += 1;
        for (int i=0; i<=hits; i++){
            heads.push(back);
        }
    }
}
// Getter method for hits
long long Hydre::get_hits(){
    return hits;
}

int main(){
    Hydre hydra = Hydre(4);
    while (hydra.is_alive()){
        hydra.attack();
    }
    cout << "Problem 20: " << hydra.get_hits() << endl;
}