#include <vector>
#include <iostream>
using namespace std;

vector<int> sum(vector<vector<int>>);
void print(vector<int>);
unsigned int dig_add(vector<int>);

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

vector<int> v(int n){
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

int main(int argc, char *argv[])
{
	const int MAX = 2014;
	std::vector<int> x= v(1);
	for (int i=2; i<MAX; i++){
		x = product(x, v(i));
	}
	cout << "Problem 6: " << dig_add(x) << endl;
	return 0;
}

unsigned int dig_add(vector<int> vec){
	unsigned int dig_sum = 0;
	for (int i=0; i<vec.size(); i++)
		dig_sum += vec[i];
	return dig_sum;
}