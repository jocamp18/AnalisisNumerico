#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double f(double x){
	return pow(M_E, -x) - x;
	//return pow(x, 3) - 4 * pow(x, 2) - 10;
	//return pow(M_E, -pow(x, 2) + 1) - 4 * pow(x, 3) + 25;
	//return pow(M_E, 3 * x - 12) + x * cos(3 * x) - pow(x, 2) + 4;
	//return pow(x, 3) + 4 * pow(x, 2) - 10;
}

double df(double x){
	return -pow(M_E, -x) -1;
}

double g(double x){
	return sqrt(10/(x + 4));
}

void incrementalSearches(){
	double x0, x1, fx0, fx1, delta;
	int niter, cont;
	cout << "Enter initial value of x" << endl;
	cin >> x0;
	cout << "Enter delta " << endl;
	cin >> delta;
	cout << "Enter maximum number of iterations" << endl;
	cin >> niter;
	fx0 = f(x0);
	if(fx0 == 0){
		cout << x0 << " is a root " << endl;
	}else if(niter == 0){
		cout << "Cannot continue because number of iteratios is 0" << endl;
	}else{
		x1 = x0 + delta;
		fx1 = f(x1);
		cont = 1;
		cout << "+-----------------------------------+" << endl;
		cout << '|'<< setw(11) << " iteration " << '|' << setw(11) << " x " << '|' << setw(11) << " f(x) " << '|' <<  endl;
		cout << "+-----------------------------------+" << endl;
		while(fx1 * fx0 > 0 && cont < niter){
			cout << '|'<< setw(11) << cont << '|' << setw(11) << x1 << '|' << setw(11) << fx1 <<  '|' << endl;
			cout << "+-----------------------------------+" << endl;
			x0 = x1;
			fx0 = fx1;
			x1 = x0 + delta;
			fx1 = f(x1);
			cont++;
		}
		cout << '|'<< setw(11) << cont << '|' << setw(11) << x1 << '|' << setw(11) << fx1 <<  '|' << endl;
		cout << "+-----------------------------------+" << endl;
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
	cout << "Enter maximum number of iterations" << endl;
	cin >>niter;
	fxi = f(xi);
	fxs = f(xs);
	if(fxi == 0){
		cout << xi << " is a root " << endl;
	}else if (fxs == 0){
		cout << xs << " is a root" << endl;
	}else if (niter == 0){
		cout << "Cannot continue because number of iteratios is 0" << endl;
	}else if (fxi*fxs < 0){
		xm = (xi + xs)/2;
		fxm = f(xm);
		cont = 1;
		error = tol + 1;
		cout << "+-----------------------------------------------------------------------------------------------------+" << endl;
		cout << '|' << setw(11) << "iteration" << '|' << setw(11) << "xi"  << '|' << setw(13) << "f(xi)" << '|' << setw(11) << "xs"  << '|' << setw(13) << "f(xs)" << '|' << setw(11) << "xm"  << '|' << setw(13) << "f(xm)" << '|' << setw(11) << "Error" << '|' << endl;
		cout << "+-----------------------------------------------------------------------------------------------------+" << endl;
		while( error > tol && fxm != 0 && cont < niter){
			cout << '|' << setw(11) << cont << '|' << setw(11) << xi  << '|' << setw(13) << fxi << '|' << setw(11) << xs  << '|' << setw(13) << fxs << '|' << setw(11) << xm  << '|' << setw(13) << fxm << '|' << setw(11) << error << '|' << endl;
			cout << "+-----------------------------------------------------------------------------------------------------+" << endl;
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
		cout << '|' << setw(11) << cont << '|' << setw(11) << xi  << '|' << setw(13) << fxi << '|' << setw(11) << xs  << '|' << setw(13) << fxs << '|' << setw(11) << xm  << '|' << setw(13) << fxm << '|' << setw(11) << error << '|' << endl;
        cout << "+-----------------------------------------------------------------------------------------------------+" << endl;
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
	cout << "Enter maximum number of iterations" << endl;
	cin >>niter;
	fxi = f(xi);
	fxs = f(xs);
	if(fxi == 0){
		cout << xi << " is a root " << endl;
	}else if (fxs == 0){
		cout << xs << " is a root" << endl;
	}else if (niter == 0){
		cout << "Cannot continue because number of iteratios is 0" << endl;
	}else if (fxi*fxs < 0){
		xm = xi -((fxi * (xs - xi))/(fxs -fxi));
		fxm = f(xm);
		cont = 1;
		error = tol + 1;
		cout << "+------------------------------------------------------------------------------------------------------+" << endl;
		cout << '|' << setw(11) << "iteration" << '|' << setw(11) << "xi"  << '|' << setw(13) << "f(xi)" << '|' << setw(11) << "xs"  << '|' << setw(13) << "f(xs)" << '|' << setw(11) << "xm"  << '|' << setw(13) << "f(xm)" << '|' << setw(11) << "Error" << '|' << endl;
		cout << "+------------------------------------------------------------------------------------------------------+" << endl;
		while( error > tol && fxm != 0 && cont < niter){
			cout << '|' << setw(11) << cont << '|' << setw(11) << xi  << '|' << setw(13) << fxi << '|' << setw(11) << xs  << '|' << setw(13) << fxs << '|' << setw(11) << xm  << '|' << setw(13) << fxm << '|' << setw(11) << error << '|' << endl;
			cout << "+-----------------------------------------------------------------------------------------------------+" << endl;
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
		cout << '|' << setw(11) << cont << '|' << setw(11) << xi  << '|' << setw(13) << fxi << '|' << setw(11) << xs  << '|' << setw(13) << fxs << '|' << setw(11) << xm  << '|' << setw(13) << fxm << '|' << setw(11) << error << '|' << endl;
        cout << "+-----------------------------------------------------------------------------------------------------+" << endl;
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

void fixedPoint(){
	double x0, tol, error, x1, fx0;
	int cont, niter;
	cout << "Enter initial value" << endl;
	cin >> x0;
	cout << "Enter the tolerance" << endl;
	cin >> tol;
	cout << "Enter maximum number of iterations" << endl;
	cin >> niter;
	fx0 = f(x0);
	if(fx0 == 0){
		cout << x0 << " is a root" << endl;
	}else if(niter <= 0){
		cout << "Cannot coninue because maximum number of iterations is incorrect" << endl;
	}else{
		error = tol + 1;
		cont = 0;
		while(error > tol && cont < niter and fx0 != 0){
			x1 = g(x0);
			error = abs(x1 - x0);
			x0 = x1;
			fx0 = f(x0);
			cont++;
		}
		if(fx0 == 0){
			cout << x0 << " is a root" << endl;
		}else if(error < tol){
			cout << x0 << " is near the root, with tolerance = " << tol << " and error = " << error << endl;
		}else{
			cout << "Sorry, it failed in" << niter << "iterations" << endl;
		}
	}
}

void newton(){
	double x0, x1, tol, error, fx, dfx;
	int niter, cont;
	cout << "Enter initial value" << endl;
	cin >> x0;
	cout << "Enter tolerance" << endl;
	cin >> tol;
	cout << "Enter maximum number of iterations" << endl;
	cin >> niter;
	dfx = df(x0);
	fx = f(x0);
	if(fx == 0){
		cout << x0 << " is a root" << endl;
	}else if(niter <= 0){
		cout << "Cannot continue because maximum number of iterations is incorrect" << endl;
	}else if(tol < 0){
		cout << "Invalid tolerance" << endl;
	}else{
		error = tol + 1;
		cont = 0;
		while(fx != 0 && error > tol && dfx != 0 && cont < niter){
			x1 = x0 - fx/dfx;
			cout << x1 << endl;
			fx = f(x1);
			dfx = df(x1);
			error = abs(x1 - x0);
			x0 = x1;;
			cont++;
		}
		if(fx == 0){
			cout << x0 << " is a root" << endl;
		}else if(error < tol){
			cout << x0 << " is near a root" << endl;
		}else if(dfx == 0){
			cout << x0 << " can be a multiple root" << endl;
		}else{
			cout << "Sorry, it failed" << endl;
		}
	}
}

void secant(){
	double x0, x1, x2, tol, error, fx0, fx1, den;
	int niter, cont;
	cout << "Enter initial value 1" << endl;
	cin >> x0;
	cout << "Enter initial value 2" << endl;
	cin >> x1;
	cout << "Enter tolerance" << endl;
	cin >> tol;
	cout << "Enter maximum number of iterations" << endl;
	cin >> niter;
	fx0 = f(x0);
	fx1 = f(x1);
	if(fx0 == 0){
		cout << x0 << " is a root" << endl;
	}else if(fx1 == 0){
		cout << x1 << " is a root" << endl;
	}else if(niter <= 0){
		cout << "Cannot continue because maximum number of iterations is incorrect" << endl;
	}else if(tol < 0){
		cout << "Invalid tolerance" << endl;
	}else{
		error = tol + 1;
		cont = 0;
		den = fx1 - fx0;
		while(fx1 != 0 && error > tol && den != 0 && cont < niter){
			x2 = x1 - (fx1*(x1 - x0))/den;
			cout << x2 << endl;
			error = abs(x2 - x1);
			x0 = x1;
			x1 = x2;
			fx1 = f(x1);
			fx0 = f(x0);
			den = fx1 - fx0;
			cont++;
		}
		if(fx1 == 0){
			cout << x0 << " is a root" << endl;
		}else if(error < tol){
			cout << x0 << " is near a root" << endl;
		}else if(den == 0){
			cout << x0 << " can be a multiple root" << endl;
		}else{
			cout << "Sorry, it failed" << endl;
		}
	}
}

void multipleRoots(){

}

int main(){
	while(cin){
		int methodNumber;
		cout << "Choose a method: \n"
			  << "1 ---- Incremental searches \n"
			  << "2 ---- Bisection \n"
			  << "3 ---- False Rule \n"
			  << "4 ---- Fixed Point \n"
			  << "5 ---- Newton \n"
			  << "6 ---- Secant \n"
			  << "7 ---- Multiple roots \n"
			  << "8 ---- Exit"
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
				fixedPoint();
				break;
			case 5:
				newton();
				break;
			case 6:
				secant();
				break;
			case 7:
				multipleRoots();
				break;
			case 8:
				return 0;
			default:
				cout << "Sorry, wrong number" << endl;
		}	
	}
	return 0;
}
