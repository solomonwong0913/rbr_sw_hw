/*
File: q1.cpp
Triggered when a specific CAN frame is received
    Analog read PIN_PC0,
    Send the reading over CAN.
While this happens, make an LED turn on to indicate activity.
    This LED is connected to PIN_PD2.
The CAN frames are received and sent via an MCP2515 CAN controller.
    It is connected via SPI with CS on PIN_PB2.
    The crystal is 20MHz and the CAN speed is 500kbps.
*/

// include the necessary libraries
#include <Arduino.h>
#include <mcp2515.h>
#include <SPI.h>

// create MCP2515 object
/* todo 1 */
MCP2515 mcp2515(10);


void setup() {
    // set the pinMode on the input pin
    pinMode(PC0, INPUT);
    // set the pinMode on the LED pin
    pinMode(PD2, OUTPUT);
    // initialize the CAN controller at 500kbps
    mcp2515.reset();
    mcp2515.setBitrate(CAN_500KBPS, MCP_20MHZ);
    mcp2515.setNormalMode();
    
}

void loop() {
    // create CAN frame objects
    // make one for receiving, another for transmitting
    struct can_frame txFrame;
    struct can_frame rxFrame;

    // check if a CAN frame is received
    if (mcp2515.readMessage(&rxFrame) == MCP2515::ERROR_OK) {
        // check if the received frame is of ID 0x420 and first data byte is 0x69
        if ((rxFrame.can_id == 0x420) && (rxFrame.data[0] == 0x69)) {
            // turn on the LED to indicate activity
            digitalWrite(PD2, HIGH);

            // read the analog value from the input pin and store it as a variable
            uint16_t analogValue = analogRead(PC0);

            // prepare the CAN frame to send
            txFrame.can_id = 0x690; // replace with desired send ID
            txFrame.can_dlc = 2; // data length code
            txFrame.data[0] = (analogValue >> 8) & 0xFF; // high byte
            txFrame.data[1] = analogValue & 0xFF; // low byte

            // send the CAN frame
            mcp2515.sendMessage(&txFrame);

            // turn off the LED after sending
            digitalWrite(PD2, LOW);
        }
    }
}