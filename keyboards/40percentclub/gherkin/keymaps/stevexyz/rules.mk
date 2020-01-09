# Build Options (yes/no)
#
BOOTMAGIC_ENABLE = lite      # Just bootloader enabled with keys(+?)
MOUSEKEY_ENABLE = yes        # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes        # Audio control and System control(+450)
CONSOLE_ENABLE = no          # Console for debug(+400)
COMMAND_ENABLE = no          # Commands for debug and configuration
BACKLIGHT_ENABLE = yes       # Enable keyboard backlight functionality on B7 by default
MIDI_ENABLE = no             # MIDI support (+2400 to 4200, depending on config)
UNICODE_ENABLE = no          # Unicode
BLUETOOTH_ENABLE = no        # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no            # Audio output on port C6
FAUXCLICKY_ENABLE = no       # Use buzzer to emulate clicky switches
HD44780_ENABLE = no          # Enable support for HD44780 based LCDs (+400)
TAP_DANCE_ENABLE = no
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend (it uses the same timer as BACKLIGHT_ENABLE)

MCU = atmega32u4
BOOTLOADER = caterina
SLEEP_LED_ENABLE = no   # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes           # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
RGBLIGHT_ENABLE = no

LAYOUTS = ortho_3x10

