#include <Arduino.h>
#include <microControllerID.h>

String readDeviceID() {
  String id = "";

  uint32_t *ptr = (uint32_t *)0x0080A00C;

  for (int i = 0; i < 4; i++) {
    char buf[9]; // 8 hex digits + null terminator
    sprintf(buf, "%08X", *ptr++);
    id += buf;
  }
  return id;
}
