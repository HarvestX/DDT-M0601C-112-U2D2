#include "usart.hpp"

int open_port(const std::string &port_name)
{
  int fd = open(port_name.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1)
  {
    printf("open_port: Unable to open %s. \n", port_name.c_str());
  }
  else
  {
    fcntl(fd, F_SETFL, 0);
    printf("[%d] port is open.\n", fd);
  }

  return fd;
} // open_port

void configure_port(const int fd)
{
  struct termios port_settings; // structure to store the port settings in

  cfsetispeed(&port_settings, B115200); // set baud rates
  cfsetospeed(&port_settings, B115200);

  port_settings.c_cflag &= ~PARENB;
  port_settings.c_cflag &= ~CSTOPB;
  port_settings.c_cflag &= ~CSIZE;
  port_settings.c_cflag |= CS8;
  port_settings.c_cflag &= ~CRTSCTS;

  port_settings.c_cc[VTIME] = 1;
  port_settings.c_cc[VMIN] = 0;

  if (tcsetattr(fd, TCSANOW, &port_settings) != 0)
  {
    printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
    exit(1);
  }

} // configure_port

int main()
{
  std::cout << "Start" << std::endl;
  const std::string port_name = "/dev/serial/by-id/usb-FTDI_USB__-__Serial_Converter_FT5NSMPU-if00-port0";

  auto serial_port = open_port(port_name);
  configure_port(serial_port);

  int16_t Speed = 0;   // Speed of motor
  uint8_t Acce = 0;    // Acceleration of motor
  uint8_t Brake_P = 0; // Brake position of motor
  uint8_t ID = 1;      // ID of Motor

  Receiver Receiv;

  auto motor_handler = MotorHandler(serial_port);

  // motor_handler.Check_Motor(&Receiv);
  int16_t SPEED_MAX = 330;
  int16_t SPEED_MIN = -330;

  motor_handler.Control_Motor(0, ID, Acce, Brake_P, &Receiv);

  while (true)
  {
    Speed++;
    usleep(10);
    printf("Speed: %d\n", Speed);
    motor_handler.Control_Motor(Speed, ID, Acce, Brake_P, &Receiv);
    if (Speed > int16_t(SPEED_MAX))
    {
      break;
    }
  }

  while (true)
  {
    Speed--;
    usleep(10);
    printf("Speed: %d\n", Speed);
    motor_handler.Control_Motor(Speed, ID, Acce, Brake_P, &Receiv);
    if (Speed < SPEED_MIN)
    {
      break;
    }
  }

  while (true)
  {
    Speed++;
    usleep(10);
    printf("Speed: %d\n", Speed);
    motor_handler.Control_Motor(Speed, ID, Acce, Brake_P, &Receiv);
    if (Speed > 0)
    {
      break;
    }
  }

  // Stop
  motor_handler.Control_Motor(0, ID, Acce, Brake_P, &Receiv);

  std::cout << "Exit" << std::endl;
  return EXIT_SUCCESS;
}
