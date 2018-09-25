# SerialDiscovery

A simple proof-of-concept board discovery tool with JSON output.  See Arduino issue #7964.

https://github.com/arduino/Arduino/pull/7964

# Sample JSON Output

This JSON output was generated with 3 boards connected, generating the first 3 JSON blocks.  Then one board was unplugged and reconnected, giving 2 more blocks for its disconnect and reconnect events.

```javascript
{
  "address": "/dev/ttyUSB0",
  "online": true,
  "label": "/dev/ttyUSB0 (FT232R USB UART)",
  "boardName": "FT232R USB UART",
  "vid": "0403",
  "pid": "6001",
  "iserial": "A800I6T1",
  "protocol": "Serial Device"
}
{
  "address": "/dev/ttyACM1",
  "online": true,
  "label": "/dev/ttyACM1",
  "vid": "2341",
  "pid": "0043",
  "iserial": "954373130353517111C2",
  "protocol": "Serial Device"
}
{
  "address": "/dev/ttyACM0",
  "online": true,
  "label": "/dev/ttyACM0 (USB Serial)",
  "boardName": "USB Serial",
  "vid": "16c0",
  "pid": "0483",
  "iserial": "1235830",
  "protocol": "Serial Device"
}
{
  "address": "/dev/ttyACM1",
  "online": false
}
{
  "address": "/dev/ttyACM1",
  "online": true,
  "label": "/dev/ttyACM1",
  "vid": "2341",
  "pid": "0043",
  "iserial": "954373130353517111C2",
  "protocol": "Serial Device"
}
```
