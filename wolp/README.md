wolp (Wake On Lan Packet generator)
===================================

Command line tool to generate wake on LAN packet.

License
-------

zlib License.

Target environments
-------------------

Windows, Cygwin, Linux, macOS.

Probably it works fine on other OS.

Set up
------

wolp is written in several programming languages. Choose one among them.

### For ANSI C89 implementation:

1. Compile wolp.c. Use make and Makefile.
2. Put wolp in a directory registered in PATH.

| toolset                            | Makefile                 |
|:-----------------------------------|:-------------------------|
| Linux                              | Makefile                 |
| Mac OS X                           | Makefile\_mac            |
| MinGW/TDM-GCC (with GNU make)      | Makefile\_mingw          |
| MinGW-w64/TDM64-GCC (32bit binary) | Makefile\_mingw64\_32bit |
| Microsoft Visual C++ (with NMAKE)  | Makefile\_vc\_nmake      |

### For Bourne Shell implementation:

1. Put wolp in a directory registered in PATH.

### For Perl 5 implementation:

1. Install Perl 5.14 or later.
2. Put wolp in a directory registered in PATH.

Usage
-----

Please check help message `wolp -h`

Example
-------

```sh
# Target MAC address is AA-BB-CC-DD-EE-FF.
wolp AA-BB-CC-DD-EE-FF > wol.bin

# Allowed MAC address style.
wolp AA-BB-CC-DD-EE-FF
wolp AA:BB:CC:DD:EE:FF
wolp 'AA BB CC DD EE FF'
```
