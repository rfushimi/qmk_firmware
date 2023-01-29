#pragma once

#ifdef MCU_RP
/* Handedness.  Assume adapter v2 for personal boards. */
#    undef MASTER_RIGHT

// To use the handedness pin, resistors need to be installed on the adapter PCB.
#    define SPLIT_HAND_PIN GP15
#    define SPLIT_HAND_PIN_LOW_IS_LEFT // High -> right, Low -> left.

#    undef SOFT_SERIAL_PIN
#    define SERIAL_USART_FULL_DUPLEX // Enable full duplex operation mode.
#    define SERIAL_USART_TX_PIN GP1  // USART TX pin
#    define SERIAL_USART_RX_PIN GP14 // USART RX pin
#    define SERIAL_USART_PIN_SWAP
#endif
