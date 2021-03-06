# fake-08

A Pico 8 player for 3ds (homebrew). Not related to or supported by Lexaloffle Software

## Usage:
Place the executable file (.3dsx for 3ds or .nro for Switch) in a directory where it can be executed from your homebrew menu. Place pico 8 cart files (\*.p8 text or \*.p8.png files) in the `/p8carts/` directory on the SD card of your homebrew capable 3ds or Switch console (no support offered here for modifying your console, but you can look at https://3ds.hacks.guide/ for a guide to installing custom firmware on the 3ds).

Launch the homebrew menu, then start Fake-08. Use left and right on the dpad or left stick to cycle through carts on the SD card. Choose a cart using the `A` button. To exit the currently running cart, press `Start` on 3ds or `+` on Switch. Press `R` to cycle between rendering sizes. Press `L` and `R` simultaneously to exit back to the homebrew menu.

## Building:
Install devkitpro tool chains for 3ds and switch (see https://devkitpro.org/wiki/Getting_Started), then call `make` to make both, or `make 3ds` or `make switch` to make one or the other. 

Building tested on windows using devkitpro's msys2 and Ubuntu WSL. Should work on other plaforms as well.

## Acknowledgements
 * Zep/Lexaloffle software for making pico 8. Buy a copy if you can. You won't regret it. https://www.lexaloffle.com/pico-8.php
 * Nintendo Homebrew Community, including but not limited to Smea, SciresM, yellows8, fincs, WinterMute, etc for making it possible for hobbyists like myself to make software for Nintendo's hardware
 * PicoLove (https://github.com/gamax92/picolove)- basis for my previous project - PicoLovePotion - and where I first learned the basics of Pico 8's API
 * tac08 (https://github.com/0xcafed00d/tac08) - a Pico 8 emulator that I leared a lot from. FAKE-08's sprite rendering and cart parsing is heavily based on tac08, and it uses 0xcafed00d's utf8-util to handle special characters in pico 8 carts
 * zepto8 (https://github.com/samhocevar/zepto8) - Probably the best Pico 8 emulator, without which I probably still wouldn't have sound support in FAKE-08. 
 * LovePotion (https://github.com/TurtleP/LovePotion) - an implementation of Love2d for 3ds and switch that served as the runtime for PicoLovePotion, and a great way to make homebrew games for the 3ds and switch. I also use their static Logger implementation

See LICENSE.MD for FAKE-08 license (MIT) as well as licenses of all other software used

## Known Issues:

Several functions not implemented yet (peek/poke, fillp, among others)

Png carts not supported yet

No support for new latest Pico 8 0.2 features yet (no tline, oval, new operators, etc)

Uses standard lua 5.3, which uses floating instead of fixed point numbers. I would like to rectify this (and some other related issues) by switching the Lua implemenation to z8Lua (used by Zepto 8) at some point in the future

Sound emulation is missing effects, and the noise implementation is wildly inaccurrate. Most of my sound implementation was ported over from Zepto 8 (a much more accurrate emulator) but I didn't want to bring over dependencies that were needed for those parts, and haven't otherwise implemented them yet

Sound currently not supported at all on Switch. Should be doable, but my switch isn't currently available for debugging so I haven't been able to iron out the details.

Games with lots of draw calls will have slowdowns on old 3ds consoles (possibly new ones too?). I think more optimizations are possible, but keep in mind that Pico 8 lists a raspberry pi 1 with a 700 MHz ARM11 professor as minimum spec, and the old 3ds's CPU is 268 MHz ARM11. Many games should be playable regardless. 

## Carts

You browse and download carts by using the `SPLORE()` function in Pico 8 (again, if you have $15 to spend, and you are interested in game dev, it is well worth your money). Once you have loaded a cart that you want to try on FAKE-08, type `save {{cartname}}.p8` to save the cart as a text file, then copy that file to your device's SD card.

You can also browse carts on the Pico-8 BBS website, but can only download complete carts in png format. As of pre release v0.0.1.1 Fake-08 should load and play png carts provided they don't use any other unsupported features. You can download p8.png carts from the `Cart` link in the lower left of the game view, and save it into your sdmc:/p8carts directory.

## Other Notes

I make no specific claims of compatibility at the present time. I think many carts _should_ work, but this is still a project in the very early stages, and it is my first real foray into C or C++ development and low level game dev in general. I'm doing this project for fun as a way to learn lower level languages than I've used before, as well as basic game engines etc. 

Feel free to write up any issues you come across, and attach as small of a cart as possible that reproduces the issue.

