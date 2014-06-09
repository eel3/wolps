wolps (Wake On Lan Packet Sender)
=================================

command line tool to send wake on LAN packet.

License
-------

zlib License.

Set up
------

1. Install nc(1) (netcat). wolps need nc(1).
2. Put both wolps and wolp to a directory registered in PATH.

wolps need wolp.

wolp is a command line tool to make wake on LAN packet.
wolp is written in Bourne Shell, C, Perl. Choose one among them.

Usage
-----

Please check help message `wolps -h`

Example
-------

```sh
# Specify broadcast address and target MAC address.
wolps -i 192.0.2.255 -m AA-BB-CC-DD-EE-FF

# You can set UDP port number (default is 2304).
wolps -i 192.0.2.255 -m AA-BB-CC-DD-EE-FF -p 7

# Allowed MAC address style.
wolps -i 192.0.2.255 -m AA-BB-CC-DD-EE-FF
wolps -i 192.0.2.255 -m AA:BB:CC:DD:EE:FF
wolps -i 192.0.2.255 -m 'AA BB CC DD EE FF'
```
