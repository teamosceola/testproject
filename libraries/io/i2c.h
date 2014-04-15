#ifndef I2C_H
#define I2C_H

 class i2c
 {
 private:
 	static int fd;

 	i2c() {}
 	~i2c();
 	int open(int nValue);
 	int close();

public:
 	i2c(int nValue);
 	int write();
 	int write_register();
 	int read();
 	int read_register();
 };

#endif