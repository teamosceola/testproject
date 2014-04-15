#include "i2c.h"

i2c::i2c(const char *device) :
	_fd(-1),
	_device(device)
{
}

void i2c::begin()
{
	if (_fd != -1)
	{
		close(_fd);
	}
	_fd = open(_device, O_RDWR);
}

void i2c::end()
{
	if (_fd != -1)
	{
		close(_fd);
		_fd = -1;
	}
}

bool i2c::set_address(uint8_t addr)
{
	if (_fd == -1)
	{
		return false;
	}
	if (_addr != addr)
	{
		ioctl(_fd, I2C_SLAVE, addr);
		_addr = addr;
	}
	return true;
}

uint8_t i2c::write(uint8_t addr, uint8_t len, uint8_t* data)
{}

uint8_t i2c::write_register(uint8_t addr, uint8_t reg, uint8_t val)
{}

uint8_t i2c::write_registers(uint8_t addr, uint8_t reg, uint8_t len, uint8_t* data)
{}

uint8_t i2c::read(uint8_t addr, uint8_t len, uint8_t* data)
{}

uint8_t i2c::read_register(uint8_t addr, uint8_t reg, uint8_t* val)
{}

uint8_t i2c::read_registers(uint8_t addr, uint8_t reg, uint8_t len, uint8_t* data)
{}