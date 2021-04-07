# Smart Home Application

## Files Structure
- [Release](Release):	Contains the compiled version for the SLAVE micro controller.
- [Debug](Debug):	Contains the compiled version for the MASTER micro controller.
- [APP](APP):		Contains the logical application operations.
- [HAL](HAL):	Contains the components in the HAL layer.
	- [BTH](HAL/BTH):	Contains the Bluetooth module.
	- [LED](HAL/LED):	Contains the LED module.
- [MCAL](MCAL):	Contains the micro controller peripheral drivers in the MCAL layer.
	- [GPIO](MCAL/GPIO):	Contains the General purpose input/ouput module.
	- [SPI](MCAL/SPI):		Contains the Serial Peripheral Interface module.
	- [UART](MCAL/UART):	Contains the Universal Asynchronous Receiver-Transmitter module.
- [LIBS](LIBS):		Contains the libraries used allover the application.
- [main.c](main.c):	Contains the logical operations to run the whole application.
- [main_master.c](main_master.c):	Contains the logical operations to run the application in the master mode.
- [main_slave.c](main_slave.c):		Contains the logical operations to run the application in the slave mode.

## Note

In [main.c](main.c#L17) file (line 17), Uncomment below line/macro if the compiled version is going to be for the MASTER microcontroller

```c
/* Uncomment below line/macro if the compiled version is going to be for the MASTER microcontroller */
//#define MASTER_VERSION
```