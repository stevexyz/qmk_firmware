# Build Options (yes/no)
#
BOOTMAGIC_ENABLE = lite  # Just bootloader enabled with keys
NKRO_ENABLE = yes        # USB Nkey Rollover (if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work)
MOUSEKEY_ENABLE = yes    # Mouse keys
EXTRAKEY_ENABLE = yes    # Audio control and System control
BACKLIGHT_ENABLE = yes   # Enable keyboard backlight functionality
MIDI_ENABLE = yes        # MIDI support 
JOYSTICK_ENABLE = no     # Joystick emulation (digital/analog)
CONSOLE_ENABLE = no      # Console for debug
COMMAND_ENABLE = no      # Commands for debug and configuration
UNICODE_ENABLE = no      # Unicode
BLUETOOTH_ENABLE = no    # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no        # Audio output on port C6
FAUXCLICKY_ENABLE = no   # Use buzzer to emulate clicky switches
TAP_DANCE_ENABLE = no    # tap dancing functions
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend (it uses the same timer as BACKLIGHT_ENABLE)
RGBLIGHT_ENABLE = yes    # keys lights
RGBLIGHT_DRIVER = WS2812B  #  check your type
RGB_DI_PIN = D5          # The pin connected to the data pin of the LEDs
RGBLED_NUM = 10          # The number of LEDs connected
