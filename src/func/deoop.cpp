
class Circle{
    private:
        double phi = 3.14159265358979323846;
    protected:
        double radius;
    public:
        void setRadius(double* ra);
        double getArea() { 
            return (phi * radius * radius);
        }
        Circle();
        ~Circle();

};

Circle::Circle(void) {
    cout << "Object Circle is being created" << endl;
}
Circle::~Circle(void) {
    cout << "Object Circle is being destroyed" << endl;
}

void Circle::setRadius(double* r) { 
            radius = (*r);
}
        
void deoop() {
    deoopbegin:
    cout << "Program to Find Area of Circle" << endl;
    cout << "==============================" << endl;
    cout << "Enter radius in meters : ";
    cin.sync();
    double rad;
    cin >> rad;
    if (cin.fail()) {
        cout << "Invalid input" << endl;
        sleep(2);
        cin.clear();
        cin.ignore();
        cout << "\033c";
        goto deoopbegin;
    } else {
        Circle circle;
        circle.setRadius(&rad);
        cout << "Area of circle is " << circle.getArea() << " meters squared." << endl;
    }

}
