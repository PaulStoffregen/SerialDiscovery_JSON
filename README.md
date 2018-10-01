# SerialDiscovery

A simple proof-of-concept board discovery tool with JSON output.  See Arduino issue #7942.

https://github.com/arduino/Arduino/pull/7942

# Sample JSON Output

This JSON output was generated with 3 boards connected, generating the first 3 JSON blocks.  Then one board was unplugged and reconnected, giving 2 more blocks for its disconnect and reconnect events.

```javascript
{
  "eventType": "add",
  "address": "_/dev/ttyUSB0",
  "label": "/dev/ttyUSB0 (FT232R USB UART)",
  "boardName": "FT232R USB UART",
  "prefs": {
    "vendorId": "0403",
    "productId": "6001",
    "serialNumber": "A800I6T1"
  },
  "protocol": "Serial Device"
}
{
  "eventType": "add",
  "address": "_/dev/ttyACM1",
  "label": "/dev/ttyACM1 (Arduino Zero)",
  "boardName": "Arduino Zero",
  "prefs": {
    "vendorId": "2341",
    "productId": "804d",
    "serialNumber": "48AA744C514D324848202020FF100A13"
  },
  "protocol": "Serial Device"
}
{
  "eventType": "add",
  "address": "_/dev/ttyACM0",
  "label": "/dev/ttyACM0 (USB Serial)",
  "boardName": "USB Serial",
  "prefs": {
    "vendorId": "16c0",
    "productId": "0483",
    "serialNumber": "3990740"
  },
  "protocol": "Serial Device"
}
{
  "eventType": "remove",
  "address": "_/dev/ttyACM1"
}
{
  "eventType": "add",
  "address": "_/dev/ttyACM1",
  "label": "/dev/ttyACM1 (Arduino Zero)",
  "boardName": "Arduino Zero",
  "prefs": {
    "vendorId": "2341",
    "productId": "804d",
    "serialNumber": "48AA744C514D324848202020FF100A13"
  },
  "protocol": "Serial Device"
}
```
