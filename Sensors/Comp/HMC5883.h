#ifndef HMC5883_H
#define HMC5883_H

#define HMC5883_CONF_REG_A      0x00
#define HMC5883_CONF_REG_B      0x01
#define HMC5883_MODE_REG        0x02
#define HMC5883_DATA_OUT_X_MSB  0x03

// I2C addresses
#define HMC5883_ADDRESS 0x1E
#define I2CADR_W(ADR)           (ADR << 1&0xFE) // ADR & 1111 1110
#define I2CADR_R(ADR)           (ADR << 1|0x01) // ADR | 0000 0001

class HMC5883
{           
    public:
        HMC5883(PinName sda, PinName scl);
        
        //my
        float data[3];
        
        void read();
        
        void calibrate(int s);
        int Min[3];
        int Max[3];
        float scale[3];
        float offset[3];
        LocalFileSystem local;
        
        float get_angle();
         
    private:
        I2C i2c;
        
        // raw data and function to measure it
        int raw[3];
        void readraw();
        
        // I2C functions
        void writeReg(char address, char data);
        void readMultiReg(char address, char* output, int size);
        
};

#endif
