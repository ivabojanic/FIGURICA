#include <iostream>

using namespace std;

#include <cmath>

class Figura
{
    protected:
        double a;
        double b;
    public:
        virtual double Obim() = 0;
        virtual double Povrsina() = 0;
};
class Pravougaonik : public Figura
{
private:
    double a;
    double b;
public:
    Pravougaonik(){a = 10.00; b = 15.00;}
    Pravougaonik(double aa, double bb){a = aa; b = bb;}
    Pravougaonik(const Pravougaonik &P){ a = P.a; b = P.b;}

    double getA()const {return a;}
    double getB()const {return b;}

    void setA(double A){a = A;}
    void setB(double B){b = B;}

    double Povrsina()
    {
        double P = a*b;
        return P;
    }
    double Obim()
    {
        double O = 2*(a+b);
        return O;
    }
};
class Elipsa : public Figura
{
private:
    double a;
    double b;
public:
    Elipsa(){a = 2.00; b = 3.00;}
    Elipsa(double aa, double bb){a = aa; b = bb;}
    Elipsa(const Elipsa &E){ a = E.a; b = E.b;}

    double getA()const {return a;}
    double getB()const {return b;}

    void setA(double A){a = A;}
    void setB(double B){b = B;}

    double Povrsina()
    {
        double P = a*b*3.14;
        return P;
    }
    double Obim()
    {
        double O = 3.14*(3*(a + b)-sqrt((3*a + b)*(a + 3*b)));
        return O;
    }
};
class Kvadrat : public Pravougaonik
{
private:
    double stranicaA;
public:
    Kvadrat() : Pravougaonik(10.00,10.00){}
    Kvadrat(double x) : Pravougaonik(x,x){}
    Kvadrat(const Kvadrat &x) : Pravougaonik(x){}
};
class Krug : public Elipsa
{
public:
    Krug() : Elipsa(2.00,2.00){}
    Krug(double x) : Elipsa(x,x){}
    Krug(const Krug &x) : Elipsa(x){}
};
class Oblik
{
private:
    Kvadrat A;
    Krug B;
public:
    Oblik() : A(), B(){}
    Oblik(double x,double y) : A(x), B(y){}
    Oblik(const Oblik &O) : A(O.A), B(O.B){}

    double UkupniObim()
    {
        return A.Obim()+ B.Obim();
    }
    double UkupnaPovrsina()
    {
        return A.Povrsina()- B.Povrsina();
    }
};
int main()
{
     Pravougaonik P;
    Pravougaonik P1(10,12);
    Pravougaonik P2(P);
    cout<<P.Obim()<<","<<P.Povrsina()<<endl;
    cout<<P1.Obim()<<","<<P1.Povrsina()<<endl;
    cout<<P2.Obim()<<","<<P2.Povrsina()<<endl;

    Elipsa E;
    Elipsa E1(2,5);
    Elipsa E2(E);
    cout<<E.Obim()<<","<<E.Povrsina()<<endl;
    cout<<E1.Obim()<<","<<E1.Povrsina()<<endl;
    cout<<E2.Obim()<<","<<E2.Povrsina()<<endl;

    Kvadrat K;
    Kvadrat K1(5);
    Kvadrat K2(K);
    cout<<K.Obim()<<","<<K.Povrsina()<<endl;
    cout<<K1.Obim()<<","<<K1.Povrsina()<<endl;
    cout<<K2.Obim()<<","<<K2.Povrsina()<<endl;

    Krug G;
    Krug G1(10);
    Krug G2(G);
    cout<<G.Obim()<<","<<G.Povrsina()<<endl;
    cout<<G1.Obim()<<","<<G1.Povrsina()<<endl;
    cout<<G2.Obim()<<","<<G2.Povrsina()<<endl;

    Oblik O;
    Oblik O1(2,1);
    Oblik O2(O);
    cout<<O.UkupniObim()<<","<<O.UkupnaPovrsina()<<endl;
    cout<<O1.UkupniObim()<<","<<O1.UkupnaPovrsina()<<endl;
    cout<<O2.UkupniObim()<<","<<O2.UkupnaPovrsina()<<endl;
    return 0;
}
