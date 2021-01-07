# The 25% SuperMicro keyboard
## A full featured keymap on Gherkin, compatible with a pure "Alpha 26" layout

With this configuration the "SuperMicro" layout first experimented on the plank-like jj40 is being ported to a more proper board, and with the last changes, this layout has been made compatible also to a "26 keys" one. You can now choose to leave all 30 keys on the keyboard, or alternatively remove the two on the bottom line corners (to have the "old" and comfortable 28 keys layout), or remove also space and enter to have the simplest "pure alpha" one! And even the intermediate 27 keys one is an interesting compatible option.

With 9 layers, porting the number of keys to around 250, this keyboard is packed with features despite the limited size. The keymap is for a generic usage, trying to avoid as much gimmick as possible (considering the number of keys) and retain muscle memory from people used to the standard Qwerty 104 keys one.

Functions and numbers (with related symbols) are on the first row as expected; other examples of design coherency include the symbols on the central row laid out in the same order as you'll find on a standard full keyboard, and the cursor movement aligned to the common unix vi standard ("hjkl", and for symmetry "sdfg" for home/pgdn/pgup/end). I've personally used this layout for months on my home PC in parallel to my portable work PC. There are also five "special" layers dedicated to specific tasks (and can be personalized as needed or completely removed without losing any functionality): three of them are currently preloaded for cursors/mouse, numpad and media (activated with q, w and e respectively), on the fourth there is an experimental midi keyboard, and a little easter egg on the last one.

Mostly (and in the 26 keys configuration even only) relying just on the alphabetic keys, this layout can be also very easily ported and tested on any qmk supported keyboard (ok, butterstick excluded).

The image below explains the all the layers (*F* and *N* modifiers, on "C" and "V" keys for example, used to activate the main three ones).
![layers](https://raw.githubusercontent.com/stevexyz/qmk_firmware/master/keyboards/40percentclub/gherkin/keymaps/stevexyz/newlayout26272830.jpg)

![prototype](https://github.com/stevexyz/qmk_firmware/blob/master/keyboards/40percentclub/gherkin/keymaps/stevexyz/gherkin28.jpeg)

To make and flash:
- Make it with "```make 40percentclub/gherkin:stevexyz```"
- Flash it with "```bin/qmk flash -kb 40percentclub/gherkin -km stevexyz```" (initiate programming short-circuiting two consecutive times [RST and GND](https://cdn.sparkfun.com/assets/6/d/3/4/a/523c8e23757b7fbe5f8b4584.png))
- In case of issues you can try to remove "modem manager" package (I had to do it in Debian) or use "sudo" (I had to use it on Manjaro)

Happy hacking!

_Stefano
