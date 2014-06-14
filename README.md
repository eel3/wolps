wolps (Wake On Lan Packet Sender)
=================================

command line tool to send wake on LAN packet.

License
-------

zlib License.

Set up
------

1. Install nc(1) (netcat). wolps need nc(1).
2. Put both wolps and wolp in a directory registered in PATH.

wolps need wolp.

wolp is a command line tool to make wake on LAN packet.
wolp is written in Bourne Shell, C, Perl. Choose one among them.

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
