# MCU name
MCU = atmega32u2

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable

ENCODER_ENABLE = yes
LTO_ENABLE = yes
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
COMBO_ENABLE = no
NKRO_ENABLE = no            # USB Nkey Rollover
AUDIO_ENABLE = no           # Audio output
KEY_OVERRIDE_ENABLE = no
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
LEADER_ENABLE = no
MIDI_ENABLE = no
UNICODE_ENABLE = no
BLUETOOTH_ENABLE = no       # Enable Bluetooth
SPLIT_KEYBOARD = no
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812