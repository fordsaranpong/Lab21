#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber(real*c.real-imag*c.imag,real*c.imag+c.real*imag);
}
ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return ComplexNumber(((real*c.real)+(imag*c.imag))/((c.real*c.real)+(c.imag*c.imag)),((imag*c.real)-(real*c.imag))/((c.real*c.real)+(c.imag*c.imag)));
}
bool ComplexNumber::operator==(const ComplexNumber &a){
	if(real==a.real&&imag==a.imag)return 1;
	else return 0;
}



 ComplexNumber operator+(double s,const ComplexNumber &c){
	return ComplexNumber(s+c.real,+c.imag);
}

 ComplexNumber operator-(double s,const ComplexNumber &c){
	return ComplexNumber(s-c.real,-c.imag);
}
 ComplexNumber operator*(double s,const ComplexNumber &c){
	return ComplexNumber (s*c.real,s*c.imag);
}             
 ComplexNumber operator/(double s,const ComplexNumber &c){
	return ComplexNumber(((s*c.real))/((c.real*c.real)+(c.imag*c.imag)),-(s*c.imag)/((c.real*c.real)+(c.imag*c.imag)));
}

double ComplexNumber::abs(){
	double z;
	z=sqrt(real*real+imag*imag);
	return z;
}
double ComplexNumber::angle(){
	 double result = atan2 (imag,real)*180/M_PI;
	 return result;
}
bool operator==(double a,const ComplexNumber &b){
	if(a==b.real&&a==b.imag)return 1;
	else return 0;
}

ostream & operator<<(ostream &os, const ComplexNumber &c){
if(c.imag<0&&c.real>0)return os <<c.real<<c.imag<<"i";
if(c.imag<0&&c.real<0)return os <<c.real<<c.imag<<"i";
if(c.real==0&&c.imag!=0)return os<< c.imag<<"i";
if(c.imag==0&&c.real!=0)return os <<c.real;
if(c.imag-c.real==0) return os <<"0";
else return os <<c.real<<"+"<<c.imag<<"i";



}
ostream & operator<<(const ComplexNumber &c,ostream &os){
	return os<<c.real<<"+"<<c.imag<<"i";
}
