#ifndef I2C_H
#define I2C_H

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>

 class i2c
 {
 private:
 	int _fd;
 	bool set_address(uint8_t addr);
 	uint8_t _addr;
 	const char *_device;

public:
 	i2c(const char *device);
 	void begin();
 	void end();
 	uint8_t write(uint8_t addr, uint8_t len, uint8_t* data);
 	uint8_t write_register(uint8_t addr, uint8_t reg, uint8_t val);
 	uint8_t write_registers(uint8_t addr, uint8_t reg, uint8_t len, uint8_t* data);
 	uint8_t read(uint8_t addr, uint8_t len, uint8_t* data);
 	uint8_t read_register(uint8_t addr, uint8_t reg, uint8_t* val);
 	uint8_t read_registers(uint8_t addr, uint8_t reg, uint8_t len, uint8_t* data);
 };

#endif