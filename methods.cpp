#include <iostream>
#include <math.h>

using namespace std;

double f(double x){
	//return pow(x, 3) - 4 * pow(x, 2) - 10;
	//return pow(M_E, -pow(x, 2) + 1) - 4 * pow(x, 3) + 25;
	return pow(M_E, 3 * x - 12) + x * cos(3 * x) - pow(x, 2) + 4;
}

void incrementalSearches(){
	double x0, x1, fx0, fx1, delta;
	int niter, cont;
	cout << "Enter initial value of x" << endl;
	cin >> x0;
	cout << "Enter delta " << endl;
	cin >> delta;
	cout << "Enter number of iterations" << endl;
	cin >> niter;
	fx0 = f(x0);
	if(fx0 == 0){
		cout << x0 << " is a root " << endl;
	}else{
		x1 = x0 + delta;
		fx1 = f(x1);
		cont = 1;
		while(fx1 * fx0 > 0 && cont < niter){
			x0 = x1;
			fx0 = fx1;
			x1 = x0 + delta;
			fx1 = f(x1);
			cont++;
		}
		if(fx1 == 0){
			cout << x1 << " is a root" << endl;
		}else if(fx0 * fx1 < 0){
			cout << "There is a root between " << x0 << " and " << x1 << endl;
		}else{
			cout << "Sorry, it failed in " << niter << " iterations" << endl;
		}
	}

}

void bisection(){
	double xi, xs, tol, fxi, fxs, xm, fxm, error, xaux;
	int cont, niter;
	cout << "Enter lower limit" << endl;
	cin >> xi;
	cout << "Enter upper limit" << endl;
	cin >> xs;
	cout << "Enter tolerance" << endl;
	cin >> tol;
	cout << "Enter number of iterations" << endl;
	cin >>niter;
	fxi = f(xi);
	fxs = f(xs);
	if(fxi == 0){
		cout << xi << " is a root " << endl;
	}else if (fxs == 0){
		cout << xs << " is a root" << endl;
	}else if (fxi*fxs < 0){
		xm = (xi + xs)/2;
		fxm = f(xm);
		cont = 1;
		error = tol + 1;
		while( error > tol && fxm != 0 && cont < niter){
			if(fxi * fxm < 0){
				xs = xm;
				fxs = fxm;
			}else{
				xi = xm;
				fxi = fxm;
			}
			xaux = xm;
			xm = (xi + xs)/2;
			fxm = f(xm);
			error = abs(xm - xaux);
			cont++;
		}
		if (fxm == 0){
			cout << xm << " is a root " << endl;
		}else if(error < tol){
			cout << xm << " is near the root, with tolerance = " << tol << " and error = " << error << endl;
		}else{
			cout << "Sorry, it failed in " << niter << " iterations " << endl;
		}
	}else{
		cout << "The interval is inappropiate" << endl;
	}
}

void falseRule(){
	double xi, xs, tol, fxi, fxs, xm, fxm, error, xaux;
	int cont, niter;
	cout << "Enter lower limit" << endl;
	cin >> xi;
	cout << "Enter upper limit" << endl;
	cin >> xs;
	cout << "Enter tolerance" << endl;
	cin >> tol;
	cout << "Enter number of iterations" << endl;
	cin >>niter;
	fxi = f(xi);
	fxs = f(xs);
	if(fxi == 0){
		cout << xi << " is a root " << endl;
	}else if (fxs == 0){
		cout << xs << " is a root" << endl;
	}else if (fxi*fxs < 0){
		xm = xi -((fxi * (xs - xi))/(fxs -fxi));
		fxm = f(xm);
		cont = 1;
		error = tol + 1;
		while( error > tol && fxm != 0 && cont < niter){
			if(fxi * fxm < 0){
				xs = xm;
				fxs = fxm;
			}else{
				xi = xm;
				fxi = fxm;
			}
			xaux = xm;
			xm = xi -((fxi * (xs - xi))/(fxs -fxi));
			fxm = f(xm);
			error = abs(xm - xaux);
			cont++;
		}
		if (fxm == 0){
			cout << xm << " is a root " << endl;
		}else if(error < tol){
			cout << xm << " is near the root, with tolerance = " << tol << " and error = " << error << endl;
		}else{
			cout << "Sorry, it failed in " << niter << " iterations " << endl;
		}
	}else{
		cout << "The interval is inappropiate" << endl;
	}
}

int main(){
	while(cin){
		int methodNumber;
		cout << "Choose a method: \n"
			 <<	"1 ---- Incremental searches \n"
			 <<	"2 ---- Bisection \n"
			 << "3 ---- False Rule \n"
			 << "4 ---- Exit"
			 << endl;
		cin >> methodNumber;
		switch(methodNumber){
			case 1:
				incrementalSearches();
				break;
			case 2:
				bisection();
				break;
			case 3:
				falseRule();
				break;
			case 4:
				return 0;
			default:
				cout << "Sorry, wrong number" << endl;
		}	
	}
	return 0;
}