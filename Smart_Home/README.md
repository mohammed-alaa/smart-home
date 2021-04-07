# Smart Home Application

## Files Structure
- [Release](Release):	Contains the compiled version for the SLAVE micro controller.
- [Debug](Debug):	Contains the compiled version for the MASTER micro controller.
- [APP](tree/master/APP):		Contains the logical application operations.
- [HAL](HAL):
	- [BTH](HAL/BTH):	Contains the Bluetooth module.
	- [LED](HAL/LED):	Contains the LED module.
- [MCAL](MCAL):
	- [GPIO](MCAL/GPIO):	Contains the General purpose input/ouput module.
	- [SPI](MCAL/SPI):	Contains the Serial Peripheral Interface module.
	- [UART](MCAL/UART):	Contains the Universal Asynchronous Receiver-Transmitter module.
- [LIBS](LIBS):		Contains the libraries
- [main.c](main.c):	Contains the logical operations to run the whole application.

### Note

In [main.c](main.c) file line 17, Uncomment below line/macro if the compiled version is going to be for the MASTER microcontroller

```c
/* Uncomment below line/macro if the compiled version is going to be for the MASTER microcontroller */
//#define MASTER_VERSION
```