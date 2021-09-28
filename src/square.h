class Square{
    double _sideLength;

    public:
    Square(double sideLength):_sideLength(sideLength){}
    double sideLength() const{
        return _sideLength;
    }
};