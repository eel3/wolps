wolps (Wake On Lan Packet Sender)
=================================

Command line tool to send wake on LAN packet.

License
-------

zlib License.

Target environments
-------------------

Cygwin, Linux, Mac OS X.

wolps is shell script (sh), and so probably works fine on other Unix-like environment.

Set up
------

1. Install nc(1) (netcat). wolps need nc(1).
2. Install wolp. wolps need wolp. See wolp/README.md.
3. Put wolps in a directory registered in PATH.

Usage
-----

Please check help message `wolps -h`

Example
-------

```sh
# Target MAC address is AA-BB-CC-DD-EE-FF.
# In this case, wolps will send UDP packet to 255.255.255.255:2304
wolps AA-BB-CC-DD-EE-FF

# You can specify broadcast address.
# In this case, wolps will send UDP packet to 192.0.2.255:2304
wolps -a 192.0.2.255 AA-BB-CC-DD-EE-FF

# You can specify UDP port number.
# In this case, wolps will send UDP packet to 192.0.2.255:7
wolps -a 192.0.2.255 -p 7 AA-BB-CC-DD-EE-FF

# Allowed MAC address style.
wolps AA-BB-CC-DD-EE-FF
wolps AA:BB:CC:DD:EE:FF
wolps 'AA BB CC DD EE FF'
```
