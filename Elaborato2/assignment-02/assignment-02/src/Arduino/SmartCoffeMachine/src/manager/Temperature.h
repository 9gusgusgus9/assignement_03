#ifndef __TEMP__
#define __TEMP__

class Temperature{
    int pin;

    public:

    Temperature(int pin);
    double getTemperature();
    double convertTemperature(double data){
        double degree = (data/1024.0) * 5.0;
        degree -= .5;
        degree *= 100;
        return degree;
    }
};

#endif