#include <vector>
#include <iostream>
using namespace std;

vector<int> sum(vector<vector<int>>);
void print(vector<int>);
unsigned int dig_add(vector<int>);
vector<int> substract(vector<int>, vector<int>);

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
	if (vec.size()==1) if (vec.back()==integer) return true;
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
	const int M = 20;
    int N = 30;
    int limit = (M>N)? N: M;
	long long div = 0;
	// (M+N)! / M!
	std::vector<int> x= v(1);
	for (int i=M+N; i>limit; i--){
		x = product(x, v(i));
	}
	// N!
	std::vector<int> n= v(1);
	for (int i=M+N-limit; i>1; i--)
		n = product(n, v(i));
	
	/*while (!equ(x, 0)){
		x = substract(x, n);
		print(x);
		div += 1;
	}*/
	print(x); print(n);

	cout << "Problem 6: " << div << endl;
	return 0;
}

unsigned int dig_add(vector<int> vec){
	unsigned int dig_sum = 0;
	for (int i=0; i<vec.size(); i++)
		dig_sum += vec[i];
	return dig_sum;
}

vector<int> substract(vector<int> first, vector<int> second){
	int aux = 0;
	vector<int> output;
	for (int i=0; i< first.size(); i++){
		if (i>=second.size())
			second.push_back(0);

		if (first[i]<second[i]){
			first[i+1] -= 1;
			first[i] += 10;
		}
		if (first[i]>=second[i]){
			output.push_back(first[i]-second[i]);
		}
	}
	for (int i=second.size(); i<first.size(); i++)
		output.push_back(first[i]);
	while ((output.back()==0)&&(output.size()>1))
		output.pop_back();
	return output;
}

vector<int> division(vector<int> first, vector<int> second){
	vector<int> output;
	
}