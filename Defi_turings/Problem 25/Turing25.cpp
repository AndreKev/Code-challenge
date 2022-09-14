#include <vector>
#include <iostream>
#define MAXDIGIT 2013
using namespace std;

// Overload
ostream& operator<<(ostream& outstream, vector<int> vec){
    for (int i=vec.size(); i>0; i--)
        outstream << vec[i-1];
    return outstream;
}

vector<int> sum(vector<vector<int>>);
void print(vector<int>);
unsigned int dig_add(vector<int>);
vector<int> add(vector<int>, vector<int>);
vector<int> product(vector<int>, vector<int>);
vector<int> v(int);

int main(int argc, char *argv[])
{
	vector<int> a= v(1), b = v(1);
    vector<int> c = add(a, b);
    long long rank = 3;
    // Loop while the number of digits is not 2013
    while (c.size()!=MAXDIGIT){
        a = b;
        b = c;
        c = add(b, a);
        rank++;
    }
    cout << "Problem 25: " << rank << endl;
}

vector<int> product(vector<int> x, vector<int> y){
	vector <vector <int>> prods;
	for (int i=0; i<y.size(); i++){
		int aux = 0; vector<int> vaux;
		for (int k=0; k!=i; k++) 
			vaux.push_back(0);
		for (int j=0; j<x.size(); j++){
			int prod = x[j]*y[i]+aux;
			aux = prod / 10;
			prod %= 10;
			vaux.push_back(prod);
		}
		if (aux) vaux.push_back(aux);
		prods.push_back(vaux);
	}
	return sum(prods);
}

vector<int> sum(vector<vector<int>> prods){
	int aux=0, prod; vector<int> vsum;
	int N = prods[prods.size()-1].size();
	for (int i=0; i<N; i++){
		prod = aux;
		for (int j=0; j<prods.size(); j++){
			if (i<prods[j].size()) 
				prod+=prods[j][i];
		}
		aux = prod/10;
		prod %= 10;
		vsum.push_back(prod);
	}
	if (aux) vsum.push_back(aux);;
	return vsum;
}

vector<int> v(int n){	// to create a vector with a number
	vector<int> w;
	int prod=n, aux;
	while (prod){
		aux = prod%10;
		w.push_back(aux);
		prod/=10;
	}
	return w;
}

void print(vector<int> v){
	for (int i = v.size()-1; i>-1; i--)
		cout << v[i] << flush;
	cout << endl ;
}

bool equ(vector<int> vec, int integer){
	int prod = integer; int i=0;
	while (prod&&(i<vec.size())){
		int aux = prod%10;
		if (vec[i++]!=aux) return false;
		prod/=10;
	}
	return (i==vec.size())&&(prod==0);
}

unsigned int dig_add(vector<int> vec){
	unsigned int dig_sum = 0;
	for (int i=0; i<vec.size(); i++)
		dig_sum += vec[i];
	return dig_sum;
}

vector<int> add(vector<int> a, vector<int> b){
    return sum({b, a});
}