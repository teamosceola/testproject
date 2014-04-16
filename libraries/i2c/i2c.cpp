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
{
    if (!set_address(addr)) 
    {
        return 1;
    }
    if (::write(_fd, data, len) != len) 
    {
        return 1;
    }
    return 0;
}

uint8_t i2c::write_register(uint8_t addr, uint8_t reg, uint8_t val)
{
	uint8_t len = 2;
	uint8_t buf[len];
	buf[0] = reg;
	buf[1] = val;
	return write(addr, len, buf);
}

uint8_t i2c::write_registers(uint8_t addr, uint8_t reg, uint8_t len, uint8_t* data)
{
	uint8_t buf[len+1];
    buf[0] = reg;
    if (len != 0) 
    {
        memcpy(&buf[1], data, len);
    }
    return write(addr, len+1, buf);
}

uint8_t i2c::read(uint8_t addr, uint8_t len, uint8_t* data)
{
	if (!set_address(addr)) 
	{
        return 1;
    }
    if (::read(_fd, data, len) != len) 
    {
        return 1;
    }
    return 0;
}

uint8_t i2c::read_register(uint8_t addr, uint8_t reg, uint8_t* val)
{
	if (write(addr, 1, &reg))
	{
		return 1;
	}
	if (read(addr, 1, val))
	{
		return 1;
	}
	return 0;
}

uint8_t i2c::read_registers(uint8_t addr, uint8_t reg, uint8_t len, uint8_t* data)
{
	if (write(addr, 1, &reg))
	{
		return 1;
	}
    if (read(addr, len, data)) 
    {
        return 1;
    }
    return 0;
}
