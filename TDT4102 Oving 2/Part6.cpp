int add(int a, int b){
    return a+b;
}
double add(double a, double b){
    return a+b;
}
void add(int &a, int &b, int &c, int &d){
    d=d+c+b+a;
    c=c+b+a;
    b+=a;
}
