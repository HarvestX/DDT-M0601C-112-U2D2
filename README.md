# DDT-M0601C-112-U2D2
DDT-M0601C-112

## Requirements
- Ubuntu 20.04
- Serial -> RS485 Converter
  - [U2D2](https://emanual.robotis.com/docs/en/parts/interface/u2d2/)
   
## Build

Prepare repository.

```bash
git clone git@github.com:HarvestX/DDT-M0601C-112-U2D2.git
cd DDT-M0601C-112-U2D2
```

Change [here](https://github.com/HarvestX/DDT-M0601C-112-U2D2/blob/main/src/main.cpp#L46) for your serial device.
```src/main.cpp
const std::string port_name = "/dev/serial/by-id/usb-FTDI_USB__-__Serial_Converter_FT5NSMPU-if00-port0";
```

Then build it.
```bash
mkdir build; cd build
cmake ../
make
```
Now following excutable avaiable for rotation test.
```
./DDT_M0601C_112_U2D2
```
